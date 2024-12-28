/*
 *  Copyright (C) 2024 Team Kodi
 *  This file is part of Kodi - https://kodi.tv
 *
 *  SPDX-License-Identifier: GPL-2.0-or-later
 *  See LICENSES/README.md for more information.
 */

#include "FileProvider.h"

#include "jutils-details.hpp"

using namespace jni;

const std::string CJNIFileProvider::m_classname = "androidx/core/content/FileProvider";

const CJNIURI CJNIFileProvider::getUriForFile(const CJNIContext& context, const std::string& authority, const CJNIFile& file)
{
  const jhclass clazz = CJNIContext::getClassLoader().loadClass(m_classname);

  return call_static_method<jhobject>(clazz,
    "getUriForFile", "(Landroid/content/Context;Ljava/lang/String;Ljava/io/File;)Landroid/net/Uri;",
     context.get_raw(), jcast<jhstring>(authority), file.get_raw());
};
