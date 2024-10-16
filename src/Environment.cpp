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

#include "Environment.h"
#include "File.h"
#include "jutils-details.hpp"

using namespace jni;

std::string CJNIEnvironment::DIRECTORY_DCIM;
std::string CJNIEnvironment::DIRECTORY_DOWNLOADS;
std::string CJNIEnvironment::DIRECTORY_MOVIES;
std::string CJNIEnvironment::DIRECTORY_MUSIC;
std::string CJNIEnvironment::DIRECTORY_PICTURES;

std::string CJNIEnvironment::MEDIA_MOUNTED;
std::string CJNIEnvironment::MEDIA_MOUNTED_READ_ONLY;

void CJNIEnvironment::PopulateStaticFields()
{
  jhclass c = find_class("android/os/Environment");
  DIRECTORY_DCIM = jcast<std::string>(get_static_field<jhstring>(c, "DIRECTORY_DCIM"));
  DIRECTORY_DOWNLOADS = jcast<std::string>(get_static_field<jhstring>(c, "DIRECTORY_DOWNLOADS"));
  DIRECTORY_MOVIES = jcast<std::string>(get_static_field<jhstring>(c, "DIRECTORY_MOVIES"));
  DIRECTORY_MUSIC = jcast<std::string>(get_static_field<jhstring>(c, "DIRECTORY_MUSIC"));
  DIRECTORY_PICTURES = jcast<std::string>(get_static_field<jhstring>(c, "DIRECTORY_PICTURES"));

  MEDIA_MOUNTED = jcast<std::string>(get_static_field<jhstring>(c,"MEDIA_MOUNTED"));
  MEDIA_MOUNTED_READ_ONLY = jcast<std::string>(get_static_field<jhstring>(c,"MEDIA_MOUNTED_READ_ONLY"));
}

std::string CJNIEnvironment::getExternalStorageState()
{
  return jcast<std::string>(call_static_method<jhstring>("android/os/Environment",
    "getExternalStorageState", "()Ljava/lang/String;"));
}

CJNIFile CJNIEnvironment::getExternalStorageDirectory()
{
  return (CJNIFile)call_static_method<jhobject>("android/os/Environment",
    "getExternalStorageDirectory", "()Ljava/io/File;");
}

CJNIFile CJNIEnvironment::getExternalStoragePublicDirectory(const std::string &type)
{
  return (CJNIFile)call_static_method<jhobject>("android/os/Environment",
    "getExternalStoragePublicDirectory", "(Ljava/lang/String;)Ljava/io/File;",
    jcast<jhstring>(type));
}
