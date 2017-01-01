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

#include "NsdServiceInfo.h"

namespace jni
{

class CJNINsdManagerDiscoveryListener : virtual public CJNIBase
{
public:
  virtual void onDiscoveryStarted(const std::string& serviceType) = 0;
  virtual void onDiscoveryStopped(const std::string& serviceType) = 0;
  virtual void onServiceFound(const CJNINsdServiceInfo& serviceInfo) = 0;
  virtual void onServiceLost(const CJNINsdServiceInfo& serviceInfo) = 0;
  virtual void onStartDiscoveryFailed(const std::string& serviceType, int errorCode) = 0;
  virtual void onStopDiscoveryFailed(const std::string& serviceType, int errorCode) = 0;
};

class CJNINsdManagerRegistrationListener : virtual public CJNIBase
{
public:
  virtual void onRegistrationFailed(const CJNINsdServiceInfo& serviceInfo, int errorCode) = 0;
  virtual void onServiceRegistered(const CJNINsdServiceInfo& serviceInfo) = 0;
  virtual void onServiceUnregistered(const CJNINsdServiceInfo& serviceInfo) = 0;
  virtual void onUnregistrationFailed(const CJNINsdServiceInfo& serviceInfo, int errorCode)  = 0;
};

class CJNINsdManagerResolveListener : virtual public CJNIBase
{
public:
  virtual void onResolveFailed(const CJNINsdServiceInfo& serviceInfo, int errorCode) = 0;
  virtual void onServiceResolved(const CJNINsdServiceInfo& serviceInfo) = 0;
};

class CJNINsdManager : public CJNIBase
{
public:
  CJNINsdManager() : CJNIBase() {}
  CJNINsdManager(const jni::jhobject &object) : CJNIBase(object) {}
  virtual ~CJNINsdManager() {}

  void discoverServices(const std::string& serviceType, int protocolType, const CJNINsdManagerDiscoveryListener& listener);
  void registerService(const CJNINsdServiceInfo& serviceInfo, int protocolType, const CJNINsdManagerRegistrationListener& listener);
  void resolveService(const CJNINsdServiceInfo& serviceInfo, const CJNINsdManagerResolveListener& listener);
  void stopServiceDiscovery(const CJNINsdManagerDiscoveryListener& listener);
  void unregisterService(const CJNINsdManagerRegistrationListener& listener);
};

}

