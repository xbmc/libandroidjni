/*
 *  Copyright (C) 2005-2018 Team Kodi
 *  This file is part of Kodi - https://kodi.tv
 *
 *  SPDX-License-Identifier: GPL-2.0-or-later
 *  See LICENSES/README.md for more information.
 */

#include "CpuUsageInfo.h"

#include "jutils-details.hpp"

using namespace jni;

  int64_t getActive();
  int64_t getTotal();


int64_t CJNICpuUsageInfo::getActive()
{
  return call_method<jlong>(m_object,
    "getActive", "()J");
}

int64_t CJNICpuUsageInfo::getTotal()
{
  return call_method<jlong>(m_object,
    "getTotal", "()J");
}
