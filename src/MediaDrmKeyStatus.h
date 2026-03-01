/*
 *      Copyright (C) 2026 Team Kodi
 *      http://kodi.tv
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
 *  along with KODI; see the file COPYING.  If not, see
 *  <http://www.gnu.org/licenses/>.
 *
 */

#pragma once

#include "JNIBase.h"

#include <cstdint>

class CJNIMediaDrmKeyStatus : public CJNIBase
{
public:
  CJNIMediaDrmKeyStatus() {}
  CJNIMediaDrmKeyStatus(const jni::jhobject &object) : CJNIBase(object) {}

  static void PopulateStaticFields();

  static int STATUS_USABLE;
  static int STATUS_EXPIRED;
  static int STATUS_OUTPUT_NOT_ALLOWED;
  static int STATUS_PENDING;
  static int STATUS_INTERNAL_ERROR;
  static int STATUS_USABLE_IN_FUTURE; // API level 29

  std::vector<uint8_t> getKeyId() const;

  int getStatusCode() const;

protected:
  static void GetStaticValue(jni::jhclass &c, int &field, const char *value);

  static const char* m_classname;
};
