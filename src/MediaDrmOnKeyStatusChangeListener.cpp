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

#include "MediaDrmOnKeyStatusChangeListener.h"

#include "ClassLoader.h"
#include "MediaDrm.h"
#include "jlog.hpp"
#include "jutils-details.hpp"

using namespace jni;

static std::string s_className =  "/interfaces/XBMCMediaDrmOnKeyStatusChangeListener";

CJNIMediaDrmOnKeyStatusChangeListener::CJNIMediaDrmOnKeyStatusChangeListener(CJNIClassLoader &loader)
  : CJNIBase(s_className)
{
  jhclass clazz = loader.loadClass(GetClassNameAsPath());

  JNINativeMethod methods[] = 
  {
    {"_onKeyStatusChange", "(Landroid/media/MediaDrm;[BLjava/util/List;Z)V", (void*)&CJNIMediaDrmOnKeyStatusChangeListener::_onKeyStatusChange}
  };

  const int rc = xbmc_jnienv()->RegisterNatives(clazz, methods, sizeof(methods) / sizeof(methods[0]));
  if (rc != JNI_OK)
  {
    LOGERROR("Cannot register natives to XBMCMediaDrmOnKeyStatusChangeListener");
    return;
  }

  m_object = new_object(clazz);
  m_object.setGlobal();

  add_instance(m_object, this);
}

CJNIMediaDrmOnKeyStatusChangeListener::~CJNIMediaDrmOnKeyStatusChangeListener()
{
  remove_instance(this);
}

void CJNIMediaDrmOnKeyStatusChangeListener::_onKeyStatusChange(JNIEnv* env, jobject thiz, jobject mediaDrm, jbyteArray sessionId, jobject keyInformation, jboolean hasNewUsableKey)
{
  CJNIMediaDrmOnKeyStatusChangeListener *inst = find_instance(thiz);
  if (inst)
  {
    jhobject keyInfoObject = jhobject::fromJNI(keyInformation);

    inst->onKeyStatusChange(CJNIMediaDrm(jhobject::fromJNI(mediaDrm)),
                            jcast<std::vector<char>>(sessionId),
                            CJNIList<CJNIMediaDrmKeyStatus>(keyInfoObject),
                            hasNewUsableKey != 0);
  }
}
