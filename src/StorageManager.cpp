/*
 *      Copyright (C) 2015 Team Kodi
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

#include "StorageManager.h"

#include "jutils-details.hpp"

using namespace jni;

CJNIStorageVolume CJNIStorageManager::getPrimaryStorageVolume()
{
  return call_method<jhobject>(m_object, "getPrimaryStorageVolume",
    "()Landroid/os/storage/StorageVolume;");
}

CJNIList<CJNIStorageVolume> CJNIStorageManager::getStorageVolumes()
{
  if (GetSDKVersion() >= 24)
    return call_method<jhobject>(m_object, "getStorageVolumes", "()Ljava/util/List;");

  return CJNIList<CJNIStorageVolume>(jhobject());
}
