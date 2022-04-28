/*
 *  Copyright (C) 2022 Team Kodi
 *  This file is part of Kodi - https://kodi.tv
 *
 *  SPDX-License-Identifier: GPL-2.0-or-later
 *  See LICENSES/README.md for more information.
 */

#include "Bundle.h"

#include "jutils-details.hpp"

using namespace jni;

CJNIArrayList<std::string> CJNIBundle::getStringArrayList(const std::string& key)
{
  return call_method<jhobject>(m_object, "getStringArrayList",
    "(Ljava/lang/String;)Ljava/util/ArrayList;", jcast<jhstring>(key));
}
