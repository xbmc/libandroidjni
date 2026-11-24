#pragma once
/*
 *  Copyright (C) 2026 Team Kodi
 *  This file is part of Kodi - https://kodi.tv
 *
 *  SPDX-License-Identifier: GPL-2.0-or-later
 *  See LICENSES/README.md for more information.
 */

#include "JNIBase.h"

class CJNIMediaCodecCodecException : public CJNIBase
{
public:
  CJNIMediaCodecCodecException(const jni::jhobject& object) : CJNIBase(object) {}

  std::string getDiagnosticInfo() const;
  int getErrorCode() const;
  bool isRecoverable() const;
  bool isTransient() const;

protected:
  static const char* m_classname;
};
