/*
 *      Copyright (C) 2013 Team XBMC
 *      http://xbmc.org
 *
 *  This Program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; either version 2, or (at your option)
 *  any later version.
 *
 *  This Program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with XBMC; see the file COPYING.  If not, see
 *  <http://www.gnu.org/licenses/>.
 *
 */

#include "AudioTrack.h"
#include "jutils-details.hpp"
#include "AudioFormat.h"
#include "ByteBuffer.h"

using namespace jni;

int CJNIAudioTrack::MODE_STREAM         = 0x00000001;
int CJNIAudioTrack::STATE_INITIALIZED   = 0x00000001;
int CJNIAudioTrack::PLAYSTATE_PLAYING   = 0x00000003;
int CJNIAudioTrack::PLAYSTATE_STOPPED   = 0x00000001;
int CJNIAudioTrack::PLAYSTATE_PAUSED    = 0x00000002;
int CJNIAudioTrack::WRITE_BLOCKING      = 0x00000000;
int CJNIAudioTrack::WRITE_NON_BLOCKING  = 0x00000001;

void CJNIAudioTrack::PopulateStaticFields()
{
  if (CJNIBase::GetSDKVersion() >= 3)
  {
    jhclass c = find_class("android/media/AudioTrack");
    CJNIAudioTrack::STATE_INITIALIZED = get_static_field<int>(c, "STATE_INITIALIZED");
    CJNIAudioTrack::PLAYSTATE_PLAYING = get_static_field<int>(c, "PLAYSTATE_PLAYING");
    CJNIAudioTrack::PLAYSTATE_STOPPED = get_static_field<int>(c, "PLAYSTATE_STOPPED");
    CJNIAudioTrack::PLAYSTATE_PAUSED = get_static_field<int>(c, "PLAYSTATE_PAUSED");
    if (CJNIBase::GetSDKVersion() >= 5)
    {
      CJNIAudioTrack::MODE_STREAM = get_static_field<int>(c, "MODE_STREAM");

      if (CJNIBase::GetSDKVersion() >= 21)
      {
        CJNIAudioTrack::WRITE_BLOCKING = get_static_field<int>(c, "WRITE_BLOCKING");
        CJNIAudioTrack::WRITE_NON_BLOCKING = get_static_field<int>(c, "WRITE_NON_BLOCKING");
      }
    }
  }
}

CJNIAudioTrack::CJNIAudioTrack(int streamType, int sampleRateInHz, int channelConfig, int audioFormat, int bufferSizeInBytes, int mode) throw(std::invalid_argument)
  : CJNIBase("android/media/AudioTrack")
{
  m_object = new_object(GetClassName(), "<init>", "(IIIIII)V",
                        streamType, sampleRateInHz, channelConfig,
                        audioFormat, bufferSizeInBytes, mode);

  /* AudioTrack constructor may throw IllegalArgumentException, pass it to
   * caller instead of getting us killed */
  JNIEnv* jenv = xbmc_jnienv();
  jthrowable exception = jenv->ExceptionOccurred();
  if (exception)
  {
    jenv->ExceptionClear();
    jhclass excClass = find_class(jenv, "java/lang/Throwable");
    jmethodID toStrMethod = get_method_id(jenv, excClass, "toString", "()Ljava/lang/String;");
    jhstring msg = call_method<jhstring>(exception, toStrMethod);
    throw std::invalid_argument(jcast<std::string>(msg));
  }
  m_object.setGlobal();
}

CJNIAudioTrack::CJNIAudioTrack(const CJNIAudioAttributes &attributes, const CJNIAudioFormat &format, int bufferSizeInBytes, int mode, int sessionId) throw(std::invalid_argument)
  : CJNIBase("android/media/AudioTrack")
{
  m_object = new_object(GetClassName(), "<init>", "(Landroid/media/AudioAttributes;Landroid/media/AudioFormat;III)V",
                        attributes.get_raw(), format.get_raw(), bufferSizeInBytes, mode, sessionId);

  /* AudioTrack constructor may throw IllegalArgumentException, pass it to
   * caller instead of getting us killed */
  JNIEnv* jenv = xbmc_jnienv();
  jthrowable exception = jenv->ExceptionOccurred();
  if (exception)
  {
    jenv->ExceptionClear();
    jhclass excClass = find_class(jenv, "java/lang/Throwable");
    jmethodID toStrMethod = get_method_id(jenv, excClass, "toString", "()Ljava/lang/String;");
    jhstring msg = call_method<jhstring>(exception, toStrMethod);
    throw std::invalid_argument(jcast<std::string>(msg));
  }
  m_object.setGlobal();
}

void CJNIAudioTrack::play()
{
  call_method<void>(m_object, "play", "()V");
}

void CJNIAudioTrack::pause()
{
  call_method<void>(m_object, "pause", "()V");
}

void CJNIAudioTrack::stop()
{
  call_method<void>(m_object, "stop", "()V");

  JNIEnv* jenv = xbmc_jnienv();

  // might toss an exception on release so catch it.
  jthrowable exception = jenv->ExceptionOccurred();
  if (exception)
  {
    jenv->ExceptionDescribe();
    jenv->ExceptionClear();
  }
}

void CJNIAudioTrack::flush()
{
  call_method<void>(m_object, "flush", "()V");
}

void CJNIAudioTrack::release()
{
  call_method<void>(m_object, "release", "()V");
}

int CJNIAudioTrack::write(const std::vector<float>& audioData, int offsetInFloats, int sizeInFloats, int writeMode)
{
  return call_method<int>(m_object, "write", "([FIII)I", 
                          jcast<jhfloatArray>(audioData), offsetInFloats, sizeInFloats, writeMode);
}

int CJNIAudioTrack::write(const std::vector<int16_t>& audioData, int offsetInShorts, int sizeInShorts)
{
  return call_method<int>(m_object, "write", "([SII)I", 
                          jcast<jhshortArray>(audioData), offsetInShorts, sizeInShorts);
}

int CJNIAudioTrack::write(const std::vector<char>& audioData, int offsetInBytes, int sizeInBytes)
{
  return call_method<int>(m_object, "write", "([BII)I", 
                          jcast<jhbyteArray>(audioData), offsetInBytes, sizeInBytes);
}

int CJNIAudioTrack::write(const CJNIByteBuffer& audioData, int sizeInBytes, int writeMode)
{
  return call_method<int>(m_object, "write", "(Ljava/nio/ByteBuffer;II)I", 
                          audioData.get_raw(), sizeInBytes, writeMode);
}

int CJNIAudioTrack::write(const CJNIByteBuffer& audioData, int sizeInBytes, int writeMode, int64_t timestamp)
{
  return call_method<int>(m_object, "write", "(Ljava/nio/ByteBuffer;IIJ)I", 
                          audioData.get_raw(), sizeInBytes, writeMode, timestamp);
}

int CJNIAudioTrack::write(const std::vector<int16_t>& audioData, int offsetInShorts, int sizeInShorts, int writeMode)
{
  return call_method<int>(m_object, "write", "([SIII)I", 
                          jcast<jhshortArray>(audioData), offsetInShorts, sizeInShorts, writeMode);
}

int CJNIAudioTrack::write(const std::vector<char>& audioData, int offsetInBytes, int sizeInBytes, int writeMode)
{
  return call_method<int>(m_object, "write", "([BIII)I", 
                          jcast<jhbyteArray>(audioData), offsetInBytes, sizeInBytes, writeMode);
}

int CJNIAudioTrack::getState()
{
  return call_method<int>(m_object, "getState", "()I");
}

int CJNIAudioTrack::getPlayState()
{
  return call_method<int>(m_object, "getPlayState", "()I");
}

int CJNIAudioTrack::getPlaybackHeadPosition()
{
  return call_method<int>(m_object, "getPlaybackHeadPosition", "()I");
}

bool CJNIAudioTrack::getTimestamp(CJNIAudioTimestamp &timestamp)
{
  return call_method<jboolean>(m_object, "getTimestamp", "(Landroid/media/AudioTimestamp;)Z",
                                    timestamp.get_raw());
}

// Can be used in v23 for comparing with the opened buffer amount
int CJNIAudioTrack::getBufferSizeInFrames()
{
  if (CJNIBase::GetSDKVersion() >= 23)
    return call_method<int>(m_object, "getBufferSizeInFrames", "()I");
  return -1;
}

int CJNIAudioTrack::getMinBufferSize(int sampleRateInHz, int channelConfig, int audioFormat)
{
  return call_static_method<int>( "android/media/AudioTrack", "getMinBufferSize", "(III)I",
                                  sampleRateInHz, channelConfig, audioFormat);
}

int CJNIAudioTrack::getNativeOutputSampleRate(int streamType)
{
  return call_static_method<int>( "android/media/AudioTrack", "getNativeOutputSampleRate", "(I)I",
                                  streamType);
}

