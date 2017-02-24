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

#include "IBinder.h"
#include "jutils-details.hpp"

#include "IInterface.h"
#include "FileDescriptor.h"
#include "Parcel.h"

using namespace jni;


void CJNIIBinderDeathRecipient::binderDied()
{
}

/*********************/

int CJNIIBinder::FIRST_CALL_TRANSACTION;

void CJNIIBinder::PopulateStaticFields()
{
  jhclass clazz = find_class("android/os/IBinder");
  FIRST_CALL_TRANSACTION  = (get_static_field<int>(clazz, "FIRST_CALL_TRANSACTION"));
}

void CJNIIBinder::dump(const CJNIFileDescriptor& fd, const std::vector<std::string>& args)
{
  call_method<void>(m_object,
                    "dump", "(Ljava/io/FileDescriptor;[Ljava/lang/String;)V",
                    fd.get_raw(), jcast<jhobjectArray>(args));
}

void CJNIIBinder::dumpAsync(const CJNIFileDescriptor& fd, const std::vector<std::string>& args)
{
  call_method<void>(m_object,
                    "dumpAsync", "(Ljava/io/FileDescriptor;[Ljava/lang/String;)V",
                    fd.get_raw(), jcast<jhobjectArray>(args));
}

std::string CJNIIBinder::getInterfaceDescriptor()
{
  return jcast<std::string>(call_method<jhstring>(m_object,
                                                  "getInterfaceDescriptor", "()Ljava/lang/String;"));
}

bool CJNIIBinder::isBinderAlive()
{
  return call_method<jboolean>(m_object,
                               "isBinderAlive", "()Z");
}

void CJNIIBinder::linkToDeath(const CJNIIBinderDeathRecipient& recipient, int flags)
{
  call_method<void>(m_object,
                    "linkToDeath", "(Landroid/os/IBinder$DeathRecipient;I)V",
                    recipient.get_raw(), flags);
}

bool CJNIIBinder::pingBinder()
{
  return call_method<jboolean>(m_object,
                               "pingBinder", "()Z");
}

CJNIIInterface CJNIIBinder::queryLocalInterface(const std::string& descriptor)
{
  return call_method<jhobject>(m_object,
                               "queryLocalInterface", "(Ljava/lang/String;)Landroid/os/IInterface;",
                               jcast<jhstring>(descriptor));
}

bool CJNIIBinder::transact(int code, const CJNIParcel& data, const CJNIParcel& reply, int flags)
{
  return call_method<jboolean>(m_object,
                               "transact", "(ILandroid/os/Parcel;Landroid/os/Parcel;I)Z",
                               code, data.get_raw(), reply.get_raw(), flags);
}

bool CJNIIBinder::unlinkToDeath(const CJNIIBinderDeathRecipient& recipient, int flags)
{
  return call_method<jboolean>(m_object,
                               "unlinkToDeath", "(Landroid/os/IBinder$DeathRecipient;I)Z",
                               recipient.get_raw(), flags);
}
