/*
 *  Copyright (C) 2005-2018 Team Kodi
 *  This file is part of Kodi - https://kodi.tv
 *
 *  SPDX-License-Identifier: GPL-2.0-or-later
 *  See LICENSES/README.md for more information.
 */

#include "HardwarePropertiesManager.h"

#include "jutils-details.hpp"

using namespace jni;

int CJNIHardwarePropertiesManager::DEVICE_TEMPERATURE_CPU = -1;
int CJNIHardwarePropertiesManager::DEVICE_TEMPERATURE_GPU = -1;
int CJNIHardwarePropertiesManager::DEVICE_TEMPERATURE_BATTERY = -1;
int CJNIHardwarePropertiesManager::DEVICE_TEMPERATURE_SKIN = -1;

int CJNIHardwarePropertiesManager::TEMPERATURE_CURRENT = -1;
int CJNIHardwarePropertiesManager::TEMPERATURE_THROTTLING = -1;
int CJNIHardwarePropertiesManager::TEMPERATURE_SHUTDOWN = -1;
int CJNIHardwarePropertiesManager::TEMPERATURE_THROTTLING_BELOW_VR_MIN = -1;

float CJNIHardwarePropertiesManager::UNDEFINED_TEMPERATURE = -1;


CJNIHardwarePropertiesManager::CJNIHardwarePropertiesManager()
 : CJNIBase("android.os.HardwarePropertiesManager")
{
}

std::vector<CJNICpuUsageInfo> CJNIHardwarePropertiesManager::getCpuUsages()
{
  if (GetSDKVersion() >= 24)
  {
    jhclass clazz = get_class(m_object);
    jmethodID id = get_method_id(clazz, "getCpuUsages", "()[Landroid/os/CpuUsageInfo;");
    if (id != NULL)
      return jcast<std::vector<CJNICpuUsageInfo> >(call_method<jhobjectArray>(m_object, id));
    else
      xbmc_jnienv()->ExceptionClear();
  }
  return std::vector<CJNICpuUsageInfo>();
}

std::vector<float> CJNIHardwarePropertiesManager::getDeviceTemperatures(int type, int source)
{
  if (GetSDKVersion() >= 24)
    return jcast<std::vector<float>>(
      call_method<jhfloatArray>(m_object, "getDeviceTemperatures", "(II)[F", type, source));
  else
    return std::vector<float>();
}

std::vector<float> CJNIHardwarePropertiesManager::getFanSpeeds()
{
  if (GetSDKVersion() >= 24)
    return jcast<std::vector<float>>(
      call_method<jhfloatArray>(m_object, "getFanSpeeds", "()[F"));
  else
    return std::vector<float>();
}

void CJNIHardwarePropertiesManager::PopulateStaticFields()
{
  jhclass clazz;
  if(GetSDKVersion() >= 24)
  {
    clazz = find_class("android/os/HardwarePropertiesManager");
    DEVICE_TEMPERATURE_CPU = get_static_field<int>(clazz, "DEVICE_TEMPERATURE_CPU");
    DEVICE_TEMPERATURE_GPU = get_static_field<int>(clazz, "DEVICE_TEMPERATURE_GPU");
    DEVICE_TEMPERATURE_BATTERY = get_static_field<int>(clazz, "DEVICE_TEMPERATURE_BATTERY");
    DEVICE_TEMPERATURE_SKIN = get_static_field<int>(clazz, "DEVICE_TEMPERATURE_SKIN");

    TEMPERATURE_CURRENT = get_static_field<int>(clazz, "TEMPERATURE_CURRENT");
    TEMPERATURE_THROTTLING = get_static_field<int>(clazz, "TEMPERATURE_THROTTLING");
    TEMPERATURE_SHUTDOWN = get_static_field<int>(clazz, "TEMPERATURE_SHUTDOWN");
    TEMPERATURE_THROTTLING_BELOW_VR_MIN = get_static_field<int>(clazz, "TEMPERATURE_THROTTLING_BELOW_VR_MIN");

    UNDEFINED_TEMPERATURE = get_static_field<float>(clazz, "UNDEFINED_TEMPERATURE");
  }
}
