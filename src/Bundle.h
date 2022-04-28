#pragma once
/*
 *  Copyright (C) 2022 Team Kodi
 *  This file is part of Kodi - https://kodi.tv
 *
 *  SPDX-License-Identifier: GPL-2.0-or-later
 *  See LICENSES/README.md for more information.
 */

#include "JNIBase.h"
#include "ArrayList.h"

class CJNIBundle : public CJNIBase
{
public:
  CJNIBundle(jni::jhobject const& object) : CJNIBase(object) {};
  ~CJNIBundle() {};

  CJNIArrayList<std::string> getStringArrayList(const std::string& key);
};
