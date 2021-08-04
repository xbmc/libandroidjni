#pragma once
/*
 *  Copyright (C) 2021- Team Kodi
 *  This file is part of Kodi - https://kodi.tv
 *
 *  SPDX-License-Identifier: GPL-2.0-or-later
 *  See LICENSES/README.md for more information.
 */

#include "JNIBase.h"

#include "AudioAttributes.h"

class CJNIAudioManagerAudioFocusChangeListener;

namespace jni
{

class CJNIAudioFocusRequestClass : public CJNIBase
{
public:
  CJNIAudioFocusRequestClass(const CJNIAudioFocusRequestClass& other) : CJNIBase(other) {}
  CJNIAudioFocusRequestClass(const jni::jhobject &object) : CJNIBase(object) {}

protected:
  static const char *m_classname;

};

class CJNIAudioFocusRequestClassBuilder : public CJNIBase
{
public:
  CJNIAudioFocusRequestClassBuilder(int focusgain);
  CJNIAudioFocusRequestClassBuilder(const CJNIAudioFocusRequestClassBuilder& other) : CJNIBase(other) {}
  CJNIAudioFocusRequestClassBuilder(const jni::jhobject &object) : CJNIBase(object) {}

  CJNIAudioFocusRequestClass build();

  CJNIAudioFocusRequestClassBuilder setAcceptsDelayedFocusGain(bool acceptsDelayedFocusGain);
  CJNIAudioFocusRequestClassBuilder setAudioAttributes(CJNIAudioAttributes attributes);
  CJNIAudioFocusRequestClassBuilder setFocusGain(int focusGain);
  CJNIAudioFocusRequestClassBuilder setForceDucking(bool forceDucking);
  CJNIAudioFocusRequestClassBuilder setWillPauseWhenDucked(bool pauseOnDuck);

  CJNIAudioFocusRequestClassBuilder setOnAudioFocusChangeListener(const CJNIAudioManagerAudioFocusChangeListener& listener);
//  CJNIAudioFocusRequestClassBuilder setOnAudioFocusChangeListener(const CJNIAudioManagerAudioFocusChangeListener& listener, Handler handler)

protected:
  static const char *m_classname;
};
} // namespace jni
