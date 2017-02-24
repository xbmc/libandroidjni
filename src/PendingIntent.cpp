/*
 *      Copyright (C) 2017 Christian Browet
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

#include "PendingIntent.h"
#include "jutils-details.hpp"

#include "Context.h"
#include "Intent.h"

using namespace jni;

static std::string s_className = "android/app/PendingIntent";

CJNIPendingIntent::CJNIPendingIntent()
  : CJNIBase(s_className)
{
  m_object = new_object(s_className);
  m_object.setGlobal();
}

bool CJNIPendingIntent::equals(const CJNIPendingIntent& other)
{
  return call_method<jboolean>(m_object,
    "equals", "(Ljava/lang/Object;)Z", other.get_raw());
}

std::string CJNIPendingIntent::toString() const
{
  return jcast<std::string>(call_method<jhstring>(m_object,
    "toString", "()Ljava/lang/String;"));
}

int CJNIPendingIntent::describeContents() const
{
  return call_method<jint>(m_object,
                           "describeContents", "()I");
}

CJNIPendingIntent CJNIPendingIntent::getActivity(const CJNIContext& context, int requestCode, const CJNIIntent& intent, int flags)
{
  return call_static_method<jhobject>(s_className.c_str(),
                                      "getActivity", "(Landroid/content/Context;ILandroid/content/Intent;I)Landroid/app/PendingIntent;",
                                      context.get_raw(), requestCode, intent.get_raw(), flags);
}

