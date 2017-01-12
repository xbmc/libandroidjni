#pragma once
/*
 *      Copyright (C) 2016 Christian Browet
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

#include "JNIBase.h"

class CJNIPlaybackState : public CJNIBase
{
public:
  CJNIPlaybackState(const CJNIPlaybackState& other) : CJNIBase(other) {}
  CJNIPlaybackState(const jni::jhobject &object) : CJNIBase(object) {}
  virtual ~CJNIPlaybackState(){}

  /* Clash with internal macro
  static int64_t ACTION_FAST_FORWARD;
  static int64_t ACTION_PAUSE;
  static int64_t ACTION_PLAY;
  static int64_t ACTION_PLAY_FROM_MEDIA_ID;
  static int64_t ACTION_PLAY_FROM_SEARCH;
  static int64_t ACTION_PLAY_PAUSE;
  static int64_t ACTION_REWIND;
  static int64_t ACTION_SEEK_TO;
  static int64_t ACTION_SET_RATING;
  static int64_t ACTION_SKIP_TO_NEXT;
  static int64_t ACTION_SKIP_TO_PREVIOUS;
  static int64_t ACTION_SKIP_TO_QUEUE_ITEM;
  static int64_t ACTION_STOP;
  */
  static int64_t PLAYBACK_POSITION_UNKNOWN;
  static int STATE_BUFFERING;
  static int STATE_CONNECTING;
  static int STATE_ERROR;
  static int STATE_FAST_FORWARDING;
  static int STATE_NONE;
  static int STATE_PAUSED;
  static int STATE_PLAYING;
  static int STATE_REWINDING;
  static int STATE_SKIPPING_TO_NEXT;
  static int STATE_SKIPPING_TO_PREVIOUS;
  static int STATE_SKIPPING_TO_QUEUE_ITEM;
  static int STATE_STOPPED;

  static void PopulateStaticFields();

protected:
  CJNIPlaybackState();
};

class CJNIPlaybackStateBuilder : public CJNIBase
{
public:
  CJNIPlaybackStateBuilder();
  CJNIPlaybackStateBuilder(const CJNIPlaybackStateBuilder& other) : CJNIBase(other) {}
  CJNIPlaybackStateBuilder(const jni::jhobject &object) : CJNIBase(object){}
  virtual ~CJNIPlaybackStateBuilder() {}

  CJNIPlaybackStateBuilder setState(int state, int64_t position, float playbackSpeed, int64_t updateTime);
  CJNIPlaybackStateBuilder setActions(int64_t actions);
  CJNIPlaybackStateBuilder addCustomAction(const std::string& action, const std::string& name, int icon);
  //CJNIPlaybackStateBuilder addCustomAction(android.media.session.PlaybackState$CustomAction);
  CJNIPlaybackStateBuilder setBufferedPosition(int64_t bufferedPosition);
  CJNIPlaybackStateBuilder setActiveQueueItemId(int64_t id);
  //CJNIPlaybackStateBuilder setErrorMessage(java.lang.CharSequence);
  CJNIPlaybackState build();
};
