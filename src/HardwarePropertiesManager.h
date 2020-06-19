#pragma once
/*
 *  Copyright (C) 2020 Team Kodi
 *  This file is part of Kodi - https://kodi.tv
 *
 *  SPDX-License-Identifier: GPL-2.0-or-later
 *  See LICENSES/README.md for more information.
 */

#include <vector>

#include "JNIBase.h"
#include "CpuUsageInfo.h"

class CJNIHardwarePropertiesManager : public CJNIBase
{
public:
  CJNIHardwarePropertiesManager();
  CJNIHardwarePropertiesManager(const jni::jhobject &object) : CJNIBase(object) {};
  ~CJNIHardwarePropertiesManager() {};

  std::vector<CJNICpuUsageInfo> getCpuUsages();
  std::vector<float> getDeviceTemperatures(int type, int source);
  std::vector<float> getFanSpeeds();

  static void  PopulateStaticFields();

  static int DEVICE_TEMPERATURE_CPU;
  static int DEVICE_TEMPERATURE_GPU;
  static int DEVICE_TEMPERATURE_BATTERY;
  static int DEVICE_TEMPERATURE_SKIN;

  static int TEMPERATURE_CURRENT;
  static int TEMPERATURE_THROTTLING;
  static int TEMPERATURE_SHUTDOWN;
  static int TEMPERATURE_THROTTLING_BELOW_VR_MIN;

  static float UNDEFINED_TEMPERATURE;
};
