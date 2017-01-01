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

#include "NsdServiceInfo.h"
#include "jutils/jutils-details.hpp"

#include "Context.h"

using namespace jni;

static std::string s_className = "android/net/nsd/NsdServiceInfo";


CJNINsdServiceInfo::CJNINsdServiceInfo()
  : CJNIBase(s_className)
{
  m_object = new_object(s_className);
  m_object.setGlobal();
}

int CJNINsdServiceInfo::describeContents() const
{
  return call_method<jint>(m_object,
                           "describeContents", "()I");
}

CJNIMap<jhstring, jhbyteArray> CJNINsdServiceInfo::getAttributes() const
{
  return call_method<jhobject>(m_object,
                               "getAttributes", "()Ljava/util/Map;");
}

CJNIInetAddress CJNINsdServiceInfo::getHost() const
{
  return call_method<jhobject>(m_object,
                               "getHost", "()Ljava/net/InetAddress;");
}

int CJNINsdServiceInfo::getPort() const
{
  return call_method<jint>(m_object,
                           "getPort", "()I");
}

std::string CJNINsdServiceInfo::getServiceName() const
{
  return jcast<std::string>(call_method<jhstring>(m_object,
                                                  "getServiceName", "()Ljava/lang/String;"));
}

std::string CJNINsdServiceInfo::getServiceType() const
{
  return jcast<std::string>(call_method<jhstring>(m_object,
                                                  "getServiceType", "()Ljava/lang/String;"));
}

void CJNINsdServiceInfo::removeAttribute(const std::string& key)
{
  call_method<void>(m_object,
                    "removeAttribute", "(Ljava/lang/String;)V",
                    jcast<jhstring>(key));
}

void CJNINsdServiceInfo::setAttribute(const std::string& key, const std::string& value) 
{
  call_method<void>(m_object,
                    "setAttribute", "(Ljava/lang/String;Ljava/lang/String;)V",
                    jcast<jhstring>(key), jcast<jhstring>(value));
}

void CJNINsdServiceInfo::setHost(const CJNIInetAddress& s)
{
  call_method<void>(m_object,
                    "setHost", "(Ljava/net/InetAddress;)V",
                    s.get_raw());
}

void CJNINsdServiceInfo::setPort(int p)
{
  call_method<void>(m_object,
                    "setPort", "(I)V",
                    p);
}

void CJNINsdServiceInfo::setServiceName(const std::string& s)
{
  call_method<void>(m_object,
                    "setServiceName", "(Ljava/lang/String;)V",
                    jcast<jhstring>(s));
}

void CJNINsdServiceInfo::setServiceType(const std::string& s)
{
  call_method<void>(m_object,
                    "setServiceType", "(Ljava/lang/String;)V",
                    jcast<jhstring>(s));
}

std::string CJNINsdServiceInfo::toString() const
{
  return jcast<std::string>(call_method<jhstring>(m_object,
                                                  "toString", "()Ljava/lang/String;"));
}

void CJNINsdServiceInfo::writeToParcel(const CJNIParcel& dest, int flags)
{
  call_method<void>(m_object,
                    "writeToParcel", "(Landroid/os/Parcel;I)V",
                    dest.get_raw(), flags);
}
