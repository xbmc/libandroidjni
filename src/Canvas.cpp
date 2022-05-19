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

#include "Canvas.h"

#include "Bitmap.h"
#include "jutils-details.hpp"

using namespace jni;

static std::string s_className = "android/graphics/Canvas";

CJNICanvas::CJNICanvas(const CJNIBitmap& bitmap) : CJNIBase(s_className)
{
  m_object = new_object(s_className, "<init>", "(Landroid/graphics/Bitmap;)V", bitmap.get_raw());
}

int CJNICanvas::getWidth()
{
  return call_method<int>(m_object, "getWidth", "()I");
}

int CJNICanvas::getHeight()
{
  return call_method<int>(m_object, "getHeight", "()I");
}
