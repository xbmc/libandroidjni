/*
 *      Copyright (C) 2018 Team Kodi
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

#include "MediaDrmKeyRequest.h"
#include "jutils-details.hpp"

using namespace jni;

CJNIMediaDrmKeyRequest::CJNIMediaDrmKeyRequest()
  : CJNIBase("android/media/MediaDrm$KeyRequest")
{
  m_object = new_object(GetClassName(), "<init>", "()V");
  m_object.setGlobal();
}

std::vector<char> CJNIMediaDrmKeyRequest::getData() const
{
  JNIEnv *env = xbmc_jnienv();
  jhbyteArray array = call_method<jhbyteArray>(m_object,
    "getData", "()[B");

  jsize size = env->GetArrayLength(array.get());

  std::vector<char> result;
  result.resize(size);
  env->GetByteArrayRegion(array.get(), 0, size, (jbyte*)result.data());

  return result;
}

int CJNIMediaDrmKeyRequest::getRequestType() const
{
  return call_method<jint>(m_object, "getRequestType", "()I");
}
