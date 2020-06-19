#pragma once
/*
 *  Copyright (C) 2020 Team Kodi
 *  This file is part of Kodi - https://kodi.tv
 *
 *  SPDX-License-Identifier: GPL-2.0-or-later
 *  See LICENSES/README.md for more information.
 */

#include "JNIBase.h"

class CJNICpuUsageInfo : public CJNIBase
{
public:
  ~CJNICpuUsageInfo() {};
  CJNICpuUsageInfo(const jni::jhobject &object) : CJNIBase(object) {};

  int64_t getActive();
  int64_t getTotal();

protected:
  CJNICpuUsageInfo();
};

