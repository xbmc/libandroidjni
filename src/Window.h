#pragma once
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

#include "JNIBase.h"

class CJNIView;
class CJNIWindowManagerLayoutParams;

class CJNIWindow : public CJNIBase
{
public:
  CJNIWindow(const jni::jhobject &object) : CJNIBase(object) {};
  ~CJNIWindow() {};

  CJNIWindowManagerLayoutParams getAttributes();
  void setAttributes(const CJNIWindowManagerLayoutParams& attributes);
  const jni::jhobject getCallback();
  void setCallback(const jni::jhobject &object);

  CJNIView getDecorView();

  void addFlags (int flags);
  void clearFlags (int flags);
};
