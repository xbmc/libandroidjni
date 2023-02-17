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

class CJNIDrawable;
class CJNIResourcesTheme;

class CJNIResources : public CJNIBase
{
public:
  CJNIResources(const jni::jhobject &object) : CJNIBase(object) {};
  ~CJNIResources() {};

  // Deprecated in API level 22
  CJNIDrawable getDrawableForDensity(int id, int density);
  CJNIDrawable getDrawableForDensity(int id, int density, const CJNIResourcesTheme& theme);
  
  int getIdentifier(const std::string &name, const std::string &type, const std::string &package);

private:
  CJNIResources();
};

class CJNIResourcesTheme : public CJNIBase
{
public:
  CJNIResourcesTheme(const jni::jhobject& object) : CJNIBase(object) {};
  ~CJNIResourcesTheme() {};
};
