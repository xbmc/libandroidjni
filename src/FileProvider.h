#pragma once
/*
 *  Copyright (C) 2024 Team Kodi
 *  This file is part of Kodi - https://kodi.tv
 *
 *  SPDX-License-Identifier: GPL-2.0-or-later
 *  See LICENSES/README.md for more information.
 */

#include "JNIBase.h"
#include "Context.h"
#include "File.h"
#include "URI.h"

class CJNIFileProvider : public CJNIBase
{
public:
  static const CJNIURI getUriForFile(const CJNIContext& context, const std::string& authority, const CJNIFile& file);

private:
  static const std::string m_classname;
};
