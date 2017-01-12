/*
 *      Copyright (C) 2017 Christian Browet
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

#include "PlaybackState.h"
#include "jutils/jutils-details.hpp"

using namespace jni;

/*
int64_t CJNIPlaybackState::ACTION_FAST_FORWARD;
int64_t CJNIPlaybackState::ACTION_PAUSE;
int64_t CJNIPlaybackState::ACTION_PLAY;
int64_t CJNIPlaybackState::ACTION_PLAY_FROM_MEDIA_ID;
int64_t CJNIPlaybackState::ACTION_PLAY_FROM_SEARCH;
int64_t CJNIPlaybackState::ACTION_PLAY_PAUSE;
int64_t CJNIPlaybackState::ACTION_REWIND;
int64_t CJNIPlaybackState::ACTION_SEEK_TO;
int64_t CJNIPlaybackState::ACTION_SET_RATING;
int64_t CJNIPlaybackState::ACTION_SKIP_TO_NEXT;
int64_t CJNIPlaybackState::ACTION_SKIP_TO_PREVIOUS;
int64_t CJNIPlaybackState::ACTION_SKIP_TO_QUEUE_ITEM;
int64_t CJNIPlaybackState::ACTION_STOP;
*/
int64_t CJNIPlaybackState::PLAYBACK_POSITION_UNKNOWN;
int CJNIPlaybackState::STATE_BUFFERING;
int CJNIPlaybackState::STATE_CONNECTING;
int CJNIPlaybackState::STATE_ERROR;
int CJNIPlaybackState::STATE_FAST_FORWARDING;
int CJNIPlaybackState::STATE_NONE;
int CJNIPlaybackState::STATE_PAUSED;
int CJNIPlaybackState::STATE_PLAYING;
int CJNIPlaybackState::STATE_REWINDING;
int CJNIPlaybackState::STATE_SKIPPING_TO_NEXT;
int CJNIPlaybackState::STATE_SKIPPING_TO_PREVIOUS;
int CJNIPlaybackState::STATE_SKIPPING_TO_QUEUE_ITEM;
int CJNIPlaybackState::STATE_STOPPED;

static std::string s_className = "android/media/session/PlaybackState";


void CJNIPlaybackState::PopulateStaticFields()
{
  jhclass clazz = find_class(s_className.c_str());
  /*
  ACTION_FAST_FORWARD = get_static_field<jlong>(clazz, "ACTION_FAST_FORWARD");
  ACTION_PAUSE = get_static_field<jlong>(clazz, "ACTION_PAUSE");
  ACTION_PLAY = get_static_field<jlong>(clazz, "ACTION_PLAY");
  ACTION_PLAY_FROM_MEDIA_ID = get_static_field<jlong>(clazz, "ACTION_PLAY_FROM_MEDIA_ID");
  ACTION_PLAY_FROM_SEARCH = get_static_field<jlong>(clazz, "ACTION_PLAY_FROM_SEARCH");
  ACTION_PLAY_PAUSE = get_static_field<jlong>(clazz, "ACTION_PLAY_PAUSE");
  ACTION_REWIND = get_static_field<jlong>(clazz, "ACTION_REWIND");
  ACTION_SEEK_TO = get_static_field<jlong>(clazz, "ACTION_SEEK_TO");
  ACTION_SET_RATING = get_static_field<jlong>(clazz, "ACTION_SET_RATING");
  ACTION_SKIP_TO_NEXT = get_static_field<jlong>(clazz, "ACTION_SKIP_TO_NEXT");
  ACTION_SKIP_TO_PREVIOUS = get_static_field<jlong>(clazz, "ACTION_SKIP_TO_PREVIOUS");
  ACTION_SKIP_TO_QUEUE_ITEM = get_static_field<jlong>(clazz, "ACTION_SKIP_TO_QUEUE_ITEM");
  ACTION_STOP = get_static_field<jlong>(clazz, "ACTION_STOP");
  */
  PLAYBACK_POSITION_UNKNOWN = get_static_field<jlong>(clazz, "PLAYBACK_POSITION_UNKNOWN");
  STATE_BUFFERING = get_static_field<jint>(clazz, "STATE_BUFFERING");
  STATE_CONNECTING = get_static_field<jint>(clazz, "STATE_CONNECTING");
  STATE_ERROR = get_static_field<jint>(clazz, "STATE_ERROR");
  STATE_FAST_FORWARDING = get_static_field<jint>(clazz, "STATE_FAST_FORWARDING");
  STATE_NONE = get_static_field<jint>(clazz, "STATE_NONE");
  STATE_PAUSED = get_static_field<jint>(clazz, "STATE_PAUSED");
  STATE_PLAYING = get_static_field<jint>(clazz, "STATE_PLAYING");
  STATE_REWINDING = get_static_field<jint>(clazz, "STATE_REWINDING");
  STATE_SKIPPING_TO_NEXT = get_static_field<jint>(clazz, "STATE_SKIPPING_TO_NEXT");
  STATE_SKIPPING_TO_PREVIOUS = get_static_field<jint>(clazz, "STATE_SKIPPING_TO_PREVIOUS");
  STATE_SKIPPING_TO_QUEUE_ITEM = get_static_field<jint>(clazz, "STATE_SKIPPING_TO_QUEUE_ITEM");
  STATE_STOPPED = get_static_field<jint>(clazz, "STATE_STOPPED");
}


static std::string s_builderclassName = "android/media/session/PlaybackState$Builder";

CJNIPlaybackStateBuilder::CJNIPlaybackStateBuilder()
  : CJNIBase(s_builderclassName)
{
  m_object = new_object(s_builderclassName);
  m_object.setGlobal();
}

CJNIPlaybackStateBuilder CJNIPlaybackStateBuilder::setState(int state, int64_t position, float playbackSpeed, int64_t updateTime)
{
  return (CJNIPlaybackStateBuilder)call_method<jhobject>(m_object,
                                                         "setState", "(IJFJ)Landroid/media/session/PlaybackState$Builder;",
                                                         state, position, playbackSpeed, updateTime);
}

CJNIPlaybackStateBuilder CJNIPlaybackStateBuilder::setActions(int64_t actions)
{
  return (CJNIPlaybackStateBuilder)call_method<jhobject>(m_object,
                                                         "setActions", "(J)Landroid/media/session/PlaybackState$Builder;",
                                                         actions);
}

CJNIPlaybackStateBuilder CJNIPlaybackStateBuilder::addCustomAction(const std::string& action, const std::string& name, int icon)
{
  return (CJNIPlaybackStateBuilder)call_method<jhobject>(m_object,
                                                         "addCustomAction", "(Ljava/lang/String;Ljava/lang/String;I)Landroid/media/session/PlaybackState$Builder;",
                                                         jcast<jhstring>(action), jcast<jhstring>(name), icon);
}

CJNIPlaybackStateBuilder CJNIPlaybackStateBuilder::setBufferedPosition(int64_t bufferedPosition)
{
  return (CJNIPlaybackStateBuilder)call_method<jhobject>(m_object,
                                                         "setBufferedPosition", "(J)Landroid/media/session/PlaybackState$Builder;",
                                                         bufferedPosition);
}

CJNIPlaybackStateBuilder CJNIPlaybackStateBuilder::setActiveQueueItemId(int64_t id)
{
  return (CJNIPlaybackStateBuilder)call_method<jhobject>(m_object,
                                                         "setActiveQueueItemId", "(J)Landroid/media/session/PlaybackState$Builder;",
                                                         id);
}
CJNIPlaybackState CJNIPlaybackStateBuilder::build()
{
  return (CJNIPlaybackState)call_method<jhobject>(m_object,
                                                         "build", "()Landroid/media/session/PlaybackState;");
}
