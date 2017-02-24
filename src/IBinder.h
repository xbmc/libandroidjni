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

namespace jni
{

class CJNIIInterface;
class CJNIParcel;
class CJNIFileDescriptor;

class CJNIIBinderDeathRecipient : public CJNIBase
{
public:
  virtual void binderDied();
};

class CJNIIBinder : public CJNIBase
{
public:
  CJNIIBinder() : CJNIBase() {}
  CJNIIBinder(const jni::jhobject &object) : CJNIBase(object) {}
  virtual ~CJNIIBinder() {}

  static void PopulateStaticFields();
  static int FIRST_CALL_TRANSACTION;

  void dump(const CJNIFileDescriptor& fd, const std::vector<std::string>& args);
  void dumpAsync(const CJNIFileDescriptor& fd, const std::vector<std::string>& args);
  std::string getInterfaceDescriptor();
  bool isBinderAlive();
  void linkToDeath(const CJNIIBinderDeathRecipient& recipient, int flags);
  bool pingBinder();
  CJNIIInterface queryLocalInterface(const std::string& descriptor);
  bool transact(int code, const CJNIParcel& data, const CJNIParcel& reply, int flags);
  bool unlinkToDeath(const CJNIIBinderDeathRecipient& recipient, int flags);
};

}
