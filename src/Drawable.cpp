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

#include "Drawable.h"

#include "Canvas.h"
#include "jutils-details.hpp"

using namespace jni;

int CJNIDrawable::getIntrinsicWidth()
{
  return call_method<int>(m_object, "getIntrinsicWidth", "()I");
}

int CJNIDrawable::getIntrinsicHeight()
{
  return call_method<int>(m_object, "getIntrinsicHeight", "()I");
}

void CJNIDrawable::setBounds(int left, int top, int right, int bottom)
{
  call_method<void>(m_object, "setBounds", "(IIII)V", left, top, right, bottom);
}

void CJNIDrawable::draw(const CJNICanvas& canvas)
{
  call_method<void>(m_object, "draw", "(Landroid/graphics/Canvas;)V", canvas.get_raw());
}
