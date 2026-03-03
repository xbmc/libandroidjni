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

#include "MediaDrmKeyStatus.h"
#include "jutils-details.hpp"

using namespace jni;

int CJNIMediaDrmKeyStatus::STATUS_USABLE = -1;
int CJNIMediaDrmKeyStatus::STATUS_EXPIRED = -1;
int CJNIMediaDrmKeyStatus::STATUS_OUTPUT_NOT_ALLOWED = -1;
int CJNIMediaDrmKeyStatus::STATUS_PENDING = -1;
int CJNIMediaDrmKeyStatus::STATUS_INTERNAL_ERROR = -1;
int CJNIMediaDrmKeyStatus::STATUS_USABLE_IN_FUTURE = -1;

const char* CJNIMediaDrmKeyStatus::m_classname = "android/media/MediaDrm$KeyStatus";

void CJNIMediaDrmKeyStatus::GetStaticValue(jhclass& c, int& field, const char* value)
{
  jfieldID id = get_static_field_id<jclass>(c, value, "I");
  if (id == NULL)
  {
    xbmc_jnienv()->ExceptionClear();
    return;
  }

  field = get_static_field<int>(c, value);
}

void CJNIMediaDrmKeyStatus::PopulateStaticFields()
{
  const int sdk = CJNIBase::GetSDKVersion();
  if (sdk < 23)
    return;

  jhclass c = find_class(m_classname);

  GetStaticValue(c, CJNIMediaDrmKeyStatus::STATUS_USABLE, "STATUS_USABLE");
  GetStaticValue(c, CJNIMediaDrmKeyStatus::STATUS_EXPIRED, "STATUS_EXPIRED");
  GetStaticValue(c, CJNIMediaDrmKeyStatus::STATUS_OUTPUT_NOT_ALLOWED, "STATUS_OUTPUT_NOT_ALLOWED");
  GetStaticValue(c, CJNIMediaDrmKeyStatus::STATUS_PENDING, "STATUS_PENDING");
  GetStaticValue(c, CJNIMediaDrmKeyStatus::STATUS_INTERNAL_ERROR, "STATUS_INTERNAL_ERROR");

  if (sdk >= 29)
  {
    GetStaticValue(c, CJNIMediaDrmKeyStatus::STATUS_USABLE_IN_FUTURE, "STATUS_USABLE_IN_FUTURE");
  }
}

std::vector<uint8_t> CJNIMediaDrmKeyStatus::getKeyId() const
{
  return jcast<std::vector<uint8_t>>(call_method<jni::jhbyteArray>(m_object, "getKeyId", "()[B"));
}

int CJNIMediaDrmKeyStatus::getStatusCode() const
{
  return call_method<jint>(m_object, "getStatusCode", "()I");
}
