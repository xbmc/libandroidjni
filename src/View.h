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

#include "JNIBase.h"
#include "List.h"
#include "Os.h"

class CJNIDisplay;

class CJNIViewInputDeviceMotionRange : public CJNIBase
{
public:
  CJNIViewInputDeviceMotionRange(const jni::jhobject &object) : CJNIBase(object) {};
 ~CJNIViewInputDeviceMotionRange() {};

  int   getAxis() const;
  float getFlat() const;
  float getFuzz() const;
  float	getMax() const;
  float	getMin() const;
  float	getRange() const;
  float getResolution() const;
  int   getSource() const;
  bool  isFromSource(int source) const;

private:
  CJNIViewInputDeviceMotionRange();
};

class CJNIViewInputDevice : public CJNIBase
{
public:
  CJNIViewInputDevice(const jni::jhobject &object) : CJNIBase(object) {};
 ~CJNIViewInputDevice() {};

  static const CJNIViewInputDevice getDevice(int id);

  int          getControllerNumber() const;
  std::string  getDescriptor() const;
  int          getId() const;
  const CJNIViewInputDeviceMotionRange getMotionRange(int axis, int source) const;
  const CJNIViewInputDeviceMotionRange getMotionRange(int axis) const;
  const CJNIList<CJNIViewInputDeviceMotionRange> getMotionRanges() const;
  std::string  getName() const;
  int          getProductId() const;
  int          getSources() const;
  int          getVendorId() const;
  const CJNIOsVibrator getVibrator() const;
  bool         hasMicrophone() const;
  bool         isVirtual() const;
  bool         supportsSource(int source) const;

  static void PopulateStaticFields();

  static int SOURCE_ANY;
  static int SOURCE_BLUETOOTH_STYLUS;
  static int SOURCE_CLASS_BUTTON;
  static int SOURCE_CLASS_JOYSTICK;
  static int SOURCE_CLASS_MASK;
  static int SOURCE_CLASS_NONE;
  static int SOURCE_CLASS_POINTER;
  static int SOURCE_CLASS_POSITION;
  static int SOURCE_CLASS_TRACKBALL;
  static int SOURCE_DPAD;
  static int SOURCE_GAMEPAD;
  static int SOURCE_HDMI;
  static int SOURCE_JOYSTICK;
  static int SOURCE_KEYBOARD;
  static int SOURCE_MOUSE;
  static int SOURCE_MOUSE_RELATIVE;
  static int SOURCE_ROTARY_ENCODER;
  static int SOURCE_STYLUS;
  static int SOURCE_TOUCHPAD;
  static int SOURCE_TOUCHSCREEN;
  static int SOURCE_TOUCH_NAVIGATION;
  static int SOURCE_TRACKBALL;
  static int SOURCE_UNKNOWN;

private:
  CJNIViewInputDevice();

  static const char *m_classname;
};

class CJNIView : public CJNIBase
{
public:
  CJNIView(const jni::jhobject &object) : CJNIBase(object) {};
  ~CJNIView() {};

  void setSystemUiVisibility(int visibility);
  int	 getSystemUiVisibility();
  CJNIDisplay getDisplay();

  static void PopulateStaticFields();
  static int SYSTEM_UI_FLAG_FULLSCREEN;
  static int SYSTEM_UI_FLAG_HIDE_NAVIGATION;
  static int SYSTEM_UI_FLAG_LAYOUT_FULLSCREEN;
  static int SYSTEM_UI_FLAG_LAYOUT_HIDE_NAVIGATION;
  static int SYSTEM_UI_FLAG_LAYOUT_STABLE;
  static int SYSTEM_UI_FLAG_LOW_PROFILE;
  static int SYSTEM_UI_FLAG_VISIBLE;
};
