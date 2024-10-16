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

class CJNIFile;

class CJNIEnvironment : public CJNIBase
{
public:
  static void PopulateStaticFields();

  static std::string DIRECTORY_DCIM;
  static std::string DIRECTORY_DOWNLOADS;
  static std::string DIRECTORY_MOVIES;
  static std::string DIRECTORY_MUSIC;
  static std::string DIRECTORY_PICTURES;

  static std::string MEDIA_MOUNTED;
  static std::string MEDIA_MOUNTED_READ_ONLY;

  static std::string  getExternalStorageState();
  // Deprecated in API level 29
  static CJNIFile     getExternalStorageDirectory();
  // Deprecated in API level 29
  static CJNIFile     getExternalStoragePublicDirectory(const std::string &type);

protected:
  CJNIEnvironment();
  ~CJNIEnvironment(){};
};
