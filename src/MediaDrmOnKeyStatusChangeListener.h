/*
 *      Copyright (C) 2026 Team Kodi
 *      http://kodi.tv
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
 *  along with KODI; see the file COPYING.  If not, see
 *  <http://www.gnu.org/licenses/>.
 *
 */

#pragma once

#include "JNIBase.h"
#include "List.h"
#include "MediaDrmKeyStatus.h"

class CJNIMediaDrm;
class CJNIClassLoader;

class CJNIMediaDrmOnKeyStatusChangeListener : public CJNIBase, public CJNIInterfaceImplem<CJNIMediaDrmOnKeyStatusChangeListener>
{
public:
  CJNIMediaDrmOnKeyStatusChangeListener(CJNIClassLoader &loader);
  explicit CJNIMediaDrmOnKeyStatusChangeListener(const jni::jhobject &object) : CJNIBase(object) {}
  virtual ~CJNIMediaDrmOnKeyStatusChangeListener();

  // virtual called when key status changes
  virtual void onKeyStatusChange(const CJNIMediaDrm& mediaDrm,
                                 const std::vector<char>& sessionId,
                                 const CJNIList<CJNIMediaDrmKeyStatus>& keyInformation,
                                 bool hasNewUsableKey) = 0;

protected:
  static void _onKeyStatusChange(JNIEnv* env, jobject thiz, jobject mediaDrm, jbyteArray sessionId, jobject keyInformation, jboolean hasNewUsableKey);
};
