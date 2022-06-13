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

#include <string>
#include <vector>

#include "JNIBase.h"

class CJNINetwork;
class CJNINetworkInfo;
class CJNILinkProperties;

class CJNIConnectivityManager : public CJNIBase
{
public:
  CJNIConnectivityManager(const jni::jhobject &object) : CJNIBase(object) {};

  // Deprecated in API level 21
  bool isNetworkTypeValid(int);
  // Deprecated in API level 21
  void setNetworkPreference(int);
  // Deprecated in API level 21
  int  getNetworkPreference();
  CJNINetwork getActiveNetwork();
  // Deprecated in API level 29
  CJNINetworkInfo getActiveNetworkInfo();
  // Deprecated in API level 23
  CJNINetworkInfo getNetworkInfo(int);
  // Deprecated in API level 29
  CJNINetworkInfo getNetworkInfo(const CJNINetwork& network);
  CJNILinkProperties getLinkProperties(const CJNINetwork& network);
  // Deprecated in API level 31
  std::vector<CJNINetwork> getAllNetworks();
  // Deprecated in API level 23
  std::vector<CJNINetworkInfo> getAllNetworkInfo();
  // Deprecated in API level 21
  int  startUsingNetworkFeature(int, std::string);
  // Deprecated in API level 21
  int  stopUsingNetworkFeature(int, std::string);
  // Deprecated in API level 21
  bool requestRouteToHost(int, int);
  // Deprecated in API level 15
  bool getBackgroundDataSetting();

  static void PopulateStaticFields();
  // Deprecated in API level 28
  static int TYPE_MOBILE;
  // Deprecated in API level 28
  static int TYPE_WIFI;
  // Deprecated in API level 23
  static int TYPE_MOBILE_MMS;
  // Deprecated in API level 23
  static int TYPE_MOBILE_SUPL;
  // Deprecated in API level 28
  static int TYPE_MOBILE_DUN;
  // Deprecated in API level 23
  static int TYPE_MOBILE_HIPRI;
  // Deprecated in API level 28
  static int TYPE_WIMAX;
  // Deprecated in API level 28
  static int TYPE_BLUETOOTH;
  // Deprecated in API level 28
  static int TYPE_DUMMY;
  // Deprecated in API level 28
  static int TYPE_ETHERNET;
  static int DEFAULT_NETWORK_PREFERENCE;


private:
  CJNIConnectivityManager();
};
