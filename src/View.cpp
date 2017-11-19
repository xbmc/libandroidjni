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

#include "View.h"
#include "Display.h"

#include "jutils-details.hpp"

using namespace jni;

/************************************************************************/
/************************************************************************/
int CJNIViewInputDeviceMotionRange::getAxis() const
{
  return call_method<int>(m_object,
    "getAxis", "()I");
}

float CJNIViewInputDeviceMotionRange::getFlat() const
{
  return call_method<jfloat>(m_object,
    "getFlat", "()F");
}

float CJNIViewInputDeviceMotionRange::getFuzz() const
{
  return call_method<jfloat>(m_object,
    "getFuzz", "()F");
}

float	CJNIViewInputDeviceMotionRange::getMax() const
{
  return call_method<jfloat>(m_object,
    "getMax", "()F");
}

float	CJNIViewInputDeviceMotionRange::getMin() const
{
  return call_method<jfloat>(m_object,
    "getMin", "()F");
}

float	CJNIViewInputDeviceMotionRange::getRange() const
{
  return call_method<jfloat>(m_object,
    "getRange", "()F");
}

float CJNIViewInputDeviceMotionRange::getResolution() const
{
  return call_method<jfloat>(m_object,
    "getResolution", "()F");
}

int CJNIViewInputDeviceMotionRange::getSource() const
{
  return call_method<int>(m_object,
    "getSource", "()I");
}

bool CJNIViewInputDeviceMotionRange::isFromSource(int source) const
{
  return call_method<jboolean>(m_object,
    "isFromSource", "(I)Z",
    source);
}

/************************************************************************/
/************************************************************************/
int CJNIViewInputDevice::SOURCE_ANY = 0;
int CJNIViewInputDevice::SOURCE_BLUETOOTH_STYLUS = 0;
int CJNIViewInputDevice::SOURCE_CLASS_BUTTON = 0;
int CJNIViewInputDevice::SOURCE_CLASS_JOYSTICK = 0;
int CJNIViewInputDevice::SOURCE_CLASS_MASK = 0;
int CJNIViewInputDevice::SOURCE_CLASS_NONE = 0;
int CJNIViewInputDevice::SOURCE_CLASS_POINTER = 0;
int CJNIViewInputDevice::SOURCE_CLASS_POSITION = 0;
int CJNIViewInputDevice::SOURCE_CLASS_TRACKBALL = 0;
int CJNIViewInputDevice::SOURCE_DPAD = 0;
int CJNIViewInputDevice::SOURCE_GAMEPAD = 0;
int CJNIViewInputDevice::SOURCE_HDMI = 0;
int CJNIViewInputDevice::SOURCE_JOYSTICK = 0;
int CJNIViewInputDevice::SOURCE_KEYBOARD = 0;
int CJNIViewInputDevice::SOURCE_MOUSE = 0;
int CJNIViewInputDevice::SOURCE_MOUSE_RELATIVE = 0;
int CJNIViewInputDevice::SOURCE_ROTARY_ENCODER = 0;
int CJNIViewInputDevice::SOURCE_STYLUS = 0;
int CJNIViewInputDevice::SOURCE_TOUCHPAD = 0;
int CJNIViewInputDevice::SOURCE_TOUCHSCREEN = 0;
int CJNIViewInputDevice::SOURCE_TOUCH_NAVIGATION = 0;
int CJNIViewInputDevice::SOURCE_TRACKBALL = 0;
int CJNIViewInputDevice::SOURCE_UNKNOWN = 0;

const char *CJNIViewInputDevice::m_classname = "android/view/InputDevice";

const CJNIViewInputDevice CJNIViewInputDevice::getDevice(int id)
{
  return call_static_method<jhobject>(m_classname,
    "getDevice", "(I)Landroid/view/InputDevice;",
    id);
}

int CJNIViewInputDevice::getControllerNumber() const
{
  return call_method<int>(m_object,
    "getControllerNumber", "()I");
}

std::string CJNIViewInputDevice::getDescriptor() const
{
  return jcast<std::string>(call_method<jhstring>(m_object,
    "getDescriptor", "()Ljava/lang/String;"));
}

int CJNIViewInputDevice::getId() const
{
  return call_method<int>(m_object,
    "getId", "()I");
}

std::string CJNIViewInputDevice::getName() const
{
  return jcast<std::string>(call_method<jhstring>(m_object,
    "getName", "()Ljava/lang/String;"));
}

int CJNIViewInputDevice::getProductId() const
{
  return call_method<int>(m_object,
    "getProductId", "()I");
}

int CJNIViewInputDevice::getSources() const
{
  return call_method<int>(m_object,
    "getSources", "()I");
}

int CJNIViewInputDevice::getVendorId() const
{
  return call_method<int>(m_object,
    "getVendorId", "()I");
}

const CJNIOsVibrator CJNIViewInputDevice::getVibrator() const
{
  return call_method<jhobject>(m_object,
    "getVibrator", "()Landroid/os/Vibrator;");
}

std::vector<bool> CJNIViewInputDevice::hasKeys(const std::vector<int> &keys) const
{
  JNIEnv *env = xbmc_jnienv();
  jsize size  = keys.size();
  jintArray intArray = env->NewIntArray(size);
  env->SetIntArrayRegion(intArray, 0, size, keys.data());

  auto ret = jcast<std::vector<bool>>(call_method<jhbooleanArray>(m_object,
    "hasKeys", "([I)[Z", intArray));

  env->DeleteLocalRef(intArray);

  return ret;
}

bool CJNIViewInputDevice::hasMicrophone() const
{
  return call_method<jboolean>(m_object,
    "hasMicrophone", "()Z");
}

bool CJNIViewInputDevice::isVirtual() const
{
  return call_method<jboolean>(m_object,
    "isVirtual", "()Z");
}

bool CJNIViewInputDevice::supportsSource(int source) const
{
  return call_method<jboolean>(m_object,
    "supportsSource", "(I)Z",
    source);
}

const CJNIList<CJNIViewInputDeviceMotionRange> CJNIViewInputDevice::getMotionRanges() const
{
  return call_method<jhobject>(m_object,
    "getMotionRanges", "()Ljava/util/List;");
}

const CJNIViewInputDeviceMotionRange CJNIViewInputDevice::getMotionRange(int axis) const
{
  return call_method<jhobject>(m_object,
    "getMotionRange", "(I)Landroid/view/InputDevice$MotionRange;",
    axis);
}

const CJNIViewInputDeviceMotionRange CJNIViewInputDevice::getMotionRange(int axis, int source) const
{
  return call_method<jhobject>(m_object,
    "getMotionRange", "(II)Landroid/view/InputDevice$MotionRange;",
    axis, source);
}

void CJNIViewInputDevice::PopulateStaticFields()
{
  jhclass clazz = find_class(m_classname);

  SOURCE_ANY = get_static_field<int>(clazz, "SOURCE_ANY");
  if (GetSDKVersion() >= 23)
    SOURCE_BLUETOOTH_STYLUS = get_static_field<int>(clazz, "SOURCE_BLUETOOTH_STYLUS");
  SOURCE_CLASS_BUTTON = get_static_field<int>(clazz, "SOURCE_CLASS_BUTTON");
  SOURCE_CLASS_JOYSTICK = get_static_field<int>(clazz, "SOURCE_CLASS_JOYSTICK");
  SOURCE_CLASS_MASK = get_static_field<int>(clazz, "SOURCE_CLASS_MASK");
  if (GetSDKVersion() >= 18)
    SOURCE_CLASS_NONE = get_static_field<int>(clazz, "SOURCE_CLASS_NONE");
  SOURCE_CLASS_POINTER = get_static_field<int>(clazz, "SOURCE_CLASS_POINTER");
  SOURCE_CLASS_POSITION = get_static_field<int>(clazz, "SOURCE_CLASS_POSITION");
  SOURCE_CLASS_TRACKBALL = get_static_field<int>(clazz, "SOURCE_CLASS_TRACKBALL");
  SOURCE_DPAD = get_static_field<int>(clazz, "SOURCE_DPAD");
  SOURCE_GAMEPAD = get_static_field<int>(clazz, "SOURCE_GAMEPAD");
  if (GetSDKVersion() >= 21)
    SOURCE_HDMI = get_static_field<int>(clazz, "SOURCE_HDMI");
  SOURCE_JOYSTICK = get_static_field<int>(clazz, "SOURCE_JOYSTICK");
  SOURCE_KEYBOARD = get_static_field<int>(clazz, "SOURCE_KEYBOARD");
  SOURCE_MOUSE = get_static_field<int>(clazz, "SOURCE_MOUSE");
  if (GetSDKVersion() >= 26)
    SOURCE_MOUSE_RELATIVE = get_static_field<int>(clazz, "SOURCE_MOUSE_RELATIVE");
  if (GetSDKVersion() >= 26)
    SOURCE_ROTARY_ENCODER = get_static_field<int>(clazz, "SOURCE_ROTARY_ENCODER");
  SOURCE_STYLUS = get_static_field<int>(clazz, "SOURCE_STYLUS");
  SOURCE_TOUCHPAD = get_static_field<int>(clazz, "SOURCE_TOUCHPAD");
  SOURCE_TOUCHSCREEN = get_static_field<int>(clazz, "SOURCE_TOUCHSCREEN");
  if (GetSDKVersion() >= 18)
    SOURCE_TOUCH_NAVIGATION = get_static_field<int>(clazz, "SOURCE_TOUCH_NAVIGATION");
  SOURCE_TRACKBALL = get_static_field<int>(clazz, "SOURCE_TRACKBALL");
  SOURCE_UNKNOWN = get_static_field<int>(clazz, "SOURCE_UNKNOWN");
}

/************************************************************************/
/************************************************************************/
int CJNIView::SYSTEM_UI_FLAG_FULLSCREEN(0);
int CJNIView::SYSTEM_UI_FLAG_HIDE_NAVIGATION(0);
int CJNIView::SYSTEM_UI_FLAG_LAYOUT_FULLSCREEN(0);
int CJNIView::SYSTEM_UI_FLAG_LAYOUT_HIDE_NAVIGATION(0);
int CJNIView::SYSTEM_UI_FLAG_LAYOUT_STABLE(0);
int CJNIView::SYSTEM_UI_FLAG_LOW_PROFILE(0);
int CJNIView::SYSTEM_UI_FLAG_VISIBLE(0);

void CJNIView::PopulateStaticFields()
{
  jhclass clazz = find_class("android/view/View");
  if(GetSDKVersion() >= 16)
  {
    SYSTEM_UI_FLAG_FULLSCREEN              = (get_static_field<int>(clazz, "SYSTEM_UI_FLAG_FULLSCREEN"));
    SYSTEM_UI_FLAG_LAYOUT_FULLSCREEN       = (get_static_field<int>(clazz, "SYSTEM_UI_FLAG_LAYOUT_FULLSCREEN"));
    SYSTEM_UI_FLAG_LAYOUT_HIDE_NAVIGATION  = (get_static_field<int>(clazz, "SYSTEM_UI_FLAG_LAYOUT_HIDE_NAVIGATION"));
    SYSTEM_UI_FLAG_LAYOUT_STABLE           = (get_static_field<int>(clazz, "SYSTEM_UI_FLAG_LAYOUT_STABLE"));
  }
  SYSTEM_UI_FLAG_HIDE_NAVIGATION           = (get_static_field<int>(clazz, "SYSTEM_UI_FLAG_HIDE_NAVIGATION"));
  SYSTEM_UI_FLAG_LOW_PROFILE               = (get_static_field<int>(clazz, "SYSTEM_UI_FLAG_LOW_PROFILE"));
  SYSTEM_UI_FLAG_VISIBLE                   = (get_static_field<int>(clazz, "SYSTEM_UI_FLAG_VISIBLE"));
}

void CJNIView::setSystemUiVisibility(int visibility)
{
  call_method<void>(m_object,
    "setSystemUiVisibility", "(I)V", visibility);
}

int CJNIView::getSystemUiVisibility()
{
  return call_method<int>(m_object,
    "getSystemUiVisibility", "()I");
}

CJNIDisplay CJNIView::getDisplay()
{
  if (GetSDKVersion() >= 17)
    return call_method<jhobject>(m_object,
      "getDisplay", "()Landroid/view/Display;");
  else
    return jhobject();
}
