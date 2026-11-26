/*
 *  Copyright (C) 2026 Team Kodi
 *  This file is part of Kodi - https://kodi.tv
 *
 *  SPDX-License-Identifier: GPL-2.0-or-later
 *  See LICENSES/README.md for more information.
 */

#include "MediaCodecCodecException.h"

#include "jutils-details.hpp"

using namespace jni;

const char* CJNIMediaCodecCodecException::m_classname = "android/media/MediaCodec$CodecException";

std::string CJNIMediaCodecCodecException::getDiagnosticInfo() const
{
  return jcast<std::string>(
      call_method<jhstring>(m_object, "getDiagnosticInfo", "()Ljava/lang/String;"));
}

int CJNIMediaCodecCodecException::getErrorCode() const
{
  return call_method<jint>(m_object, "getErrorCode", "()I");
}

bool CJNIMediaCodecCodecException::isRecoverable() const
{
  return call_method<jboolean>(m_object, "isRecoverable", "()Z");
}

bool CJNIMediaCodecCodecException::isTransient() const
{
  return call_method<jboolean>(m_object, "isTransient", "()Z");
}
