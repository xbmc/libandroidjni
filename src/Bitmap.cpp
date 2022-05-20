/*
 *      Copyright (C) 2022 Team Kodi
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
 *  along with XBMC; see the file COPYING.  If not, see
 *  <http://www.gnu.org/licenses/>.
 *
 */

#include "Bitmap.h"

#include "jutils-details.hpp"

using namespace jni;

CJNIBitmap CJNIBitmap::createBitmap(int width, int height, CJNIBitmap::Config config)
{
  JNIEnv* env = xbmc_jnienv();
  jclass enum_clazz = env->FindClass("android/graphics/Bitmap$Config");

  std::string enumName;
  switch (config)
  {
    case ALPHA_8:
      enumName = "ALPHA_8";
      break;
    case ARGB_4444:
      enumName = "ARGB_4444";
      break;
    case ARGB_8888:
      enumName = "ARGB_8888";
      break;
    case HARDWARE:
      enumName = "HARDWARE";
      break;
    case RGBA_1010102:
      enumName = "RGBA_1010102";
      break;
    case RGBA_F16:
      enumName = "RGBA_F16";
      break;
    case RGB_565:
      enumName = "RGB_565";
      break;
  }

  jfieldID value_fid =
      env->GetStaticFieldID(enum_clazz, enumName.c_str(), "Landroid/graphics/Bitmap$Config;");
  jobject configValue = env->GetStaticObjectField(enum_clazz, value_fid);

  return static_cast<CJNIBitmap>(call_static_method<jhobject>(
      "android/graphics/Bitmap", "createBitmap",
      "(IILandroid/graphics/Bitmap$Config;)Landroid/graphics/Bitmap;", width, height, configValue));
}
