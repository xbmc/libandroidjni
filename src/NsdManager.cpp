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

#include "NsdManager.h"
#include "jutils-details.hpp"

#include "NsdServiceInfo.h"

using namespace jni;

void CJNINsdManager::discoverServices(const std::string& serviceType, int protocolType, const CJNINsdManagerDiscoveryListener& listener)
{
  call_method<void>(m_object,
                    "discoverServices", "(Ljava/lang/String;ILandroid/net/nsd/NsdManager$DiscoveryListener;)V",
                    jcast<jhstring>(serviceType), protocolType, listener.get_raw());
}

void CJNINsdManager::registerService(const CJNINsdServiceInfo& serviceInfo, int protocolType, const CJNINsdManagerRegistrationListener& listener)
{
  call_method<void>(m_object,
                    "registerService", "(Landroid/net/nsd/NsdServiceInfo;ILandroid/net/nsd/NsdManager$RegistrationListener;)V",
                    serviceInfo.get_raw(), protocolType, listener.get_raw());
}

void CJNINsdManager::resolveService(const CJNINsdServiceInfo& serviceInfo, const CJNINsdManagerResolveListener& listener)
{
  call_method<void>(m_object,
                    "resolveService", "(Landroid/net/nsd/NsdServiceInfo;Landroid/net/nsd/NsdManager$ResolveListener;)V",
                    serviceInfo.get_raw(), listener.get_raw());
}

void CJNINsdManager::stopServiceDiscovery(const CJNINsdManagerDiscoveryListener& listener)
{
  call_method<void>(m_object,
                    "stopServiceDiscovery", "(Landroid/net/nsd/NsdManager$DiscoveryListener;)V",
                    listener.get_raw());
}

void CJNINsdManager::unregisterService(const CJNINsdManagerRegistrationListener& listener)
{
  call_method<void>(m_object,
                    "unregisterService", "(Landroid/net/nsd/NsdManager$RegistrationListener;)V",
                    listener.get_raw());
}
