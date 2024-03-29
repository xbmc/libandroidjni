/*
 *      Copyright (C) 2013 Team XBMC
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

#include "MediaCodecList.h"
#include "MediaCodecInfo.h"

#include "jutils-details.hpp"

using namespace jni;

const char* CJNIMediaCodecList::m_classname = "android/media/MediaCodecList";

int CJNIMediaCodecList::ALL_CODECS;
int CJNIMediaCodecList::REGULAR_CODECS;

void CJNIMediaCodecList::PopulateStaticFields()
{
  jhclass clazz = find_class(m_classname);

  ALL_CODECS = get_static_field<int>(clazz, "ALL_CODECS");
  REGULAR_CODECS = get_static_field<int>(clazz, "REGULAR_CODECS");
}

CJNIMediaCodecList::CJNIMediaCodecList(int kind) : CJNIBase(m_classname)
{
  m_object = new_object(m_classname,
    "<init>", "(I)V", kind);

  m_object.setGlobal();
}

int CJNIMediaCodecList::getCodecCount()
{
  return call_static_method<int>(m_classname,
    "getCodecCount", "()I");
}

const CJNIMediaCodecInfo CJNIMediaCodecList::getCodecInfoAt(int index)
{
  return call_static_method<jhobject>(m_classname,
    "getCodecInfoAt", "(I)Landroid/media/MediaCodecInfo;",
    index);
}

std::vector<CJNIMediaCodecInfo> CJNIMediaCodecList::getCodecInfos()
{
  jhclass clazz = get_class(m_object);
  jmethodID id = get_method_id(clazz, "getCodecInfos", "()[Landroid/media/MediaCodecInfo;");
  if (id != NULL)
    return jcast<CJNIMediaCodecInfos>(call_method<jhobjectArray>(m_object, id));
  else
  {
    xbmc_jnienv()->ExceptionClear();
    return CJNIMediaCodecInfos();
  }
}

