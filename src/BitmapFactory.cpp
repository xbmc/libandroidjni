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

#include "Bitmap.h"
#include "BitmapFactory.h"
#include "jutils-details.hpp"

using namespace jni;

const char* CJNIBitmapFactory::m_classname = "android/graphics/BitmapFactory";

CJNIBitmap CJNIBitmapFactory::decodeFile(const std::string& pathName)
{
  return CJNIBitmap(call_static_method<jhobject>(m_classname,
                                                 "decodeFile", "(Ljava/lang/String;)Landroid/graphics/Bitmap;",
                                                 jcast<jhstring>(pathName)));
}
