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

class CJNIDhcpInfo;
class CJNIWifiInfo;
class CJNIScanResult;
class CJNIWifiConfiguration;
class CJNIWifiManagerMulticastLock;

class CJNIWifiManager : public CJNIBase
{
friend class CJNIContext;
public:
  CJNIWifiManager(const jni::jhobject &object) : CJNIBase(object){};

  // Deprecated in API level 29
  CJNIList<CJNIWifiConfiguration> getConfiguredNetworks();
  // Deprecated in API level 29
  int addNetwork(const CJNIWifiConfiguration &config);
  // Deprecated in API level 29
  int updateNetwork(const CJNIWifiConfiguration &config);
  // Deprecated in API level 29
  bool removeNetwork(int);
  // Deprecated in API level 29
  bool enableNetwork(int, bool);
  // Deprecated in API level 29
  bool disableNetwork(int);
  // Deprecated in API level 29
  bool disconnect();
  // Deprecated in API level 29
  bool reconnect();
  // Deprecated in API level 29
  bool reassociate();
  // Deprecated in API level 26
  bool pingSupplicant();
  // Deprecated in API level 28
  bool startScan();
  // Deprecated in API level 31
  CJNIWifiInfo getConnectionInfo();
  CJNIList<CJNIScanResult> getScanResults();
  // Deprecated in API level 26
  bool saveConfiguration();
  // Deprecated in API level 31
  CJNIDhcpInfo getDhcpInfo();
  // Deprecated in API level 29
  bool setWifiEnabled(bool);
  int  getWifiState();
  bool isWifiEnabled();
  static int calculateSignalLevel(int, int);
  static int compareSignalLevel(int, int);
  CJNIWifiManagerMulticastLock createMulticastLock(const std::string &tag);

private:
  CJNIWifiManager();
};
