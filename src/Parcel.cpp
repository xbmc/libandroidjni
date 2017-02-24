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

#include "Parcel.h"
#include "jutils-details.hpp"

using namespace jni;




CJNIParcel CJNIParcel::obtain()
{
  return call_static_method<jhobject>("android/os/Parcel",
                                      "obtain", "()Landroid/os/Parcel;");
}

void CJNIParcel::recycle()
{
  call_method<void>(m_object,
                    "recycle", "()V");
}

void CJNIParcel::writeInterfaceToken(const std::string& interfaceName)
{
  call_method<void>(m_object,
                    "writeInterfaceToken", "(Ljava/lang/String;)V",
                    jcast<jhstring>(interfaceName));
}

void CJNIParcel::writeString(const std::string& val)
{
  call_method<void>(m_object,
                    "writeString", "(Ljava/lang/String;)V",
                    jcast<jhstring>(val));
}

std::string CJNIParcel::readString()
{
  return jcast<std::string>(call_method<jhstring>(m_object,
                                                  "readString", "()Ljava/lang/String;"));
}
