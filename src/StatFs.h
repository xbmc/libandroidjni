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

class CJNIStatFs : public CJNIBase
{
public:
  CJNIStatFs(const std::string &path);
  CJNIStatFs(const jni::jhobject &object) : CJNIBase(object) {};
  ~CJNIStatFs() {};

  void  restat(const std::string &path);
  // Deprecated in API level 18
  int   getBlockSize();
  // Deprecated in API level 18
  int   getBlockCount();
  // Deprecated in API level 18
  int   getFreeBlocks();
  int   getAvailableBlocks();
};
