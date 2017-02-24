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

#include "InetAddress.h"
#include "Parcel.h"
#include "Map.h"

namespace jni
{

class CJNINsdServiceInfo : public CJNIBase
{
public:
  CJNINsdServiceInfo();
  CJNINsdServiceInfo(const jni::jhobject &object) : CJNIBase(object) {}
  virtual ~CJNINsdServiceInfo() {}

  int describeContents() const;
  CJNIMap<jhstring, jhbyteArray> getAttributes() const;
  CJNIInetAddress getHost() const;
  int getPort() const;
  std::string getServiceName() const;
  std::string getServiceType() const;
  void removeAttribute(const std::string& key);
  void setAttribute(const std::string& key, const std::string& value);
  void setHost(const CJNIInetAddress& s);
  void setPort(int p);
  void setServiceName(const std::string& s);
  void setServiceType(const std::string& s);
  std::string toString() const;
  void writeToParcel(const CJNIParcel& dest, int flags);
};

}

