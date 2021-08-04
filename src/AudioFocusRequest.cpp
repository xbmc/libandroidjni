/*
 *  Copyright (C) 2021- Team Kodi
 *  This file is part of Kodi - https://kodi.tv
 *
 *  SPDX-License-Identifier: GPL-2.0-or-later
 *  See LICENSES/README.md for more information.
 */

#include "AudioFocusRequest.h"

#include "AudioManager.h"
#include "ClassLoader.h"

#include "jutils-details.hpp"

using namespace jni;

const char* CJNIAudioFocusRequestClass::m_classname = "android/media/AudioFocusRequest";
const char* CJNIAudioFocusRequestClassBuilder::m_classname = "android/media/AudioFocusRequest$Builder";

CJNIAudioFocusRequestClassBuilder::CJNIAudioFocusRequestClassBuilder(int focusgain)
  : CJNIBase(CJNIAudioFocusRequestClassBuilder::m_classname)
{
  m_object = new_object(GetClassName(), "<init>", "(I)V", focusgain);

  m_object.setGlobal();
}

CJNIAudioFocusRequestClass CJNIAudioFocusRequestClassBuilder::build()
{
  return call_method<jhobject>(m_object,
   "build", "()Landroid/media/AudioFocusRequest;");
}

CJNIAudioFocusRequestClassBuilder CJNIAudioFocusRequestClassBuilder::setAcceptsDelayedFocusGain(bool acceptsDelayedFocusGain)
{
  return call_method<jhobject>(m_object,
   "setAcceptsDelayedFocusGain", "(Z)Landroid/media/AudioFocusRequest$Builder;", acceptsDelayedFocusGain);
}

CJNIAudioFocusRequestClassBuilder CJNIAudioFocusRequestClassBuilder::setAudioAttributes(CJNIAudioAttributes attributes)
{
  return call_method<jhobject>(m_object,
   "setAudioAttributes", "(Landroid/media/AudioAttributes;)Landroid/media/AudioFocusRequest$Builder;", attributes.get_raw());
}

CJNIAudioFocusRequestClassBuilder CJNIAudioFocusRequestClassBuilder::setFocusGain(int focusGain)
{
  return call_method<jhobject>(m_object,
   "setFocusGain", "(I)Landroid/media/AudioFocusRequest$Builder;", focusGain);
}

CJNIAudioFocusRequestClassBuilder CJNIAudioFocusRequestClassBuilder::setForceDucking(bool forceDucking)
{
  return call_method<jhobject>(m_object,
   "setForceDucking", "(Z)Landroid/media/AudioFocusRequest$Builder;", forceDucking);
}

CJNIAudioFocusRequestClassBuilder CJNIAudioFocusRequestClassBuilder::setWillPauseWhenDucked(bool pauseOnDuck)
{
  return call_method<jhobject>(m_object,
   "setWillPauseWhenDucked", "(Z)Landroid/media/AudioFocusRequest$Builder;", pauseOnDuck);
}

CJNIAudioFocusRequestClassBuilder CJNIAudioFocusRequestClassBuilder::setOnAudioFocusChangeListener(const CJNIAudioManagerAudioFocusChangeListener& listener)
{
  return call_method<jhobject>(m_object,
   "setOnAudioFocusChangeListener", "(Landroid/media/AudioManager$OnAudioFocusChangeListener;)Landroid/media/AudioFocusRequest$Builder;", listener.get_raw());
}
