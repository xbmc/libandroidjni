#pragma once
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

#include <stdexcept>

#include "JNIBase.h"
#include "ByteBuffer.h"
#include "AudioTimestamp.h"
#include "AudioFormat.h"
#include "AudioAttributes.h"

#include <vector>

namespace jni
{

class CJNIAudioTrack : public CJNIBase
{
  public:
    // Deprecated in API level 26
    CJNIAudioTrack(int streamType, int sampleRateInHz, int channelConfig, int audioFormat, int bufferSizeInBytes, int mode) noexcept(false);
    CJNIAudioTrack (const CJNIAudioAttributes &attributes, const CJNIAudioFormat &format, int bufferSizeInBytes, int mode, int sessionId) noexcept(false);

    void  play();
    void  pause();
    void  stop();
    void  flush();
    void  release();
    int   write(const std::vector<float>& audioData, int offsetInFloats, int sizeInFloats, int writeMode);
    int   write(const std::vector<int16_t>& audioData, int offsetInShorts, int sizeInShorts);
    int   write(const std::vector<char>& audioData, int offsetInBytes, int sizeInBytes);
    int   write(const CJNIByteBuffer& audioData, int sizeInBytes, int writeMode);
    int   write(const CJNIByteBuffer& audioData, int sizeInBytes, int writeMode, int64_t timestamp);
    int   write(const std::vector<int16_t>& audioData, int offsetInShorts, int sizeInShorts, int writeMode);
    int   write(const std::vector<char>& audioData, int offsetInBytes, int sizeInBytes, int writeMode);
    int   getState();
    int   getPlayState();
    int   getPlaybackHeadPosition();
    bool  getTimestamp (CJNIAudioTimestamp &timestamp);
    int   getBufferSizeInFrames();

    static int  MODE_STREAM;
    static int  STATE_INITIALIZED;
    static int  PLAYSTATE_PLAYING;
    static int  PLAYSTATE_STOPPED;
    static int  PLAYSTATE_PAUSED;
    static int  WRITE_BLOCKING;
    static int  WRITE_NON_BLOCKING;

    static void PopulateStaticFields();
    static int  getMinBufferSize(int sampleRateInHz, int channelConfig, int audioFormat);
    static int  getNativeOutputSampleRate(int streamType);
};

};

