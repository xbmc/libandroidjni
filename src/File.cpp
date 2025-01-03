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

#include "File.h"
#include "jutils-details.hpp"

using namespace jni;

CJNIFile::CJNIFile(const std::string& pathname) : CJNIBase("java/io/File")
{
  m_object = new_object(GetClassName(), "<init>", "(Ljava/lang/String;)V", jcast<jhstring>(pathname));
  m_object.setGlobal();
}

bool CJNIFile::exists()
{
  return call_method<jboolean>(m_object, "exists", "()Z");
}

std::string CJNIFile::getAbsolutePath()
{
  return jcast<std::string>(call_method<jhstring>(m_object,
                                                  "getAbsolutePath", "()Ljava/lang/String;"));
}

int64_t CJNIFile::getUsableSpace()
{
  return call_method<jlong>(m_object,
                            "getUsableSpace", "()J");
}
