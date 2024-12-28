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

#include "Intent.h"
#include "jutils-details.hpp"
#include "URI.h"
#include "ArrayList.h"

using namespace jni;

std::string CJNIIntent::ACTION_BATTERY_CHANGED;
std::string CJNIIntent::ACTION_BOOT_COMPLETED;
std::string CJNIIntent::ACTION_DREAMING_STOPPED;
std::string CJNIIntent::ACTION_GET_CONTENT;
std::string CJNIIntent::ACTION_HEADSET_PLUG;
std::string CJNIIntent::ACTION_MAIN;
std::string CJNIIntent::ACTION_MEDIA_BUTTON;
std::string CJNIIntent::ACTION_MEDIA_MOUNTED;
std::string CJNIIntent::ACTION_MEDIA_REMOVED;
std::string CJNIIntent::ACTION_MEDIA_SHARED;
std::string CJNIIntent::ACTION_MEDIA_UNMOUNTABLE;
std::string CJNIIntent::ACTION_MEDIA_UNMOUNTED;
std::string CJNIIntent::ACTION_OPEN_DOCUMENT_TREE;
std::string CJNIIntent::ACTION_SCREEN_ON;
std::string CJNIIntent::ACTION_SCREEN_OFF;
std::string CJNIIntent::ACTION_SEARCH;
std::string CJNIIntent::ACTION_VIEW;
std::string CJNIIntent::EXTRA_KEY_EVENT;
int CJNIIntent::FLAG_GRANT_READ_URI_PERMISSION;
int CJNIIntent::FLAG_GRANT_WRITE_URI_PERMISSION;

static std::string s_className = "android/content/Intent";

void CJNIIntent::PopulateStaticFields()
{
  jhclass clazz = find_class(s_className.c_str());
  ACTION_BATTERY_CHANGED = jcast<std::string>(get_static_field<jhstring>(clazz,"ACTION_BATTERY_CHANGED"));
  ACTION_BOOT_COMPLETED = jcast<std::string>(get_static_field<jhstring>(clazz,"ACTION_BOOT_COMPLETED"));
  ACTION_DREAMING_STOPPED = jcast<std::string>(get_static_field<jhstring>(clazz,"ACTION_DREAMING_STOPPED"));
  ACTION_GET_CONTENT = jcast<std::string>(get_static_field<jhstring>(clazz,"ACTION_GET_CONTENT"));
  ACTION_HEADSET_PLUG = jcast<std::string>(get_static_field<jhstring>(clazz,"ACTION_HEADSET_PLUG"));
  ACTION_MAIN = jcast<std::string>(get_static_field<jhstring>(clazz,"ACTION_MAIN"));
  ACTION_MEDIA_BUTTON = jcast<std::string>(get_static_field<jhstring>(clazz,"ACTION_MEDIA_BUTTON"));
  ACTION_MEDIA_MOUNTED = jcast<std::string>(get_static_field<jhstring>(clazz,"ACTION_MEDIA_MOUNTED"));
  ACTION_MEDIA_REMOVED = jcast<std::string>(get_static_field<jhstring>(clazz,"ACTION_MEDIA_REMOVED"));
  ACTION_MEDIA_SHARED = jcast<std::string>(get_static_field<jhstring>(clazz,"ACTION_MEDIA_SHARED"));
  ACTION_MEDIA_UNMOUNTABLE = jcast<std::string>(get_static_field<jhstring>(clazz,"ACTION_MEDIA_UNMOUNTABLE"));
  ACTION_MEDIA_UNMOUNTED = jcast<std::string>(get_static_field<jhstring>(clazz,"ACTION_MEDIA_UNMOUNTED"));
  ACTION_OPEN_DOCUMENT_TREE  = jcast<std::string>(get_static_field<jhstring>(clazz,"ACTION_OPEN_DOCUMENT_TREE"));
  ACTION_SCREEN_ON = jcast<std::string>(get_static_field<jhstring>(clazz,"ACTION_SCREEN_ON"));
  ACTION_SCREEN_OFF = jcast<std::string>(get_static_field<jhstring>(clazz,"ACTION_SCREEN_OFF"));
  ACTION_SEARCH = jcast<std::string>(get_static_field<jhstring>(clazz,"ACTION_SEARCH"));
  ACTION_VIEW = jcast<std::string>(get_static_field<jhstring>(clazz,"ACTION_VIEW"));
  EXTRA_KEY_EVENT  = jcast<std::string>(get_static_field<jhstring>(clazz,"EXTRA_KEY_EVENT"));
  FLAG_GRANT_READ_URI_PERMISSION = (get_static_field<int>(clazz, "FLAG_GRANT_READ_URI_PERMISSION"));
  FLAG_GRANT_WRITE_URI_PERMISSION = (get_static_field<int>(clazz, "FLAG_GRANT_WRITE_URI_PERMISSION"));
}

CJNIIntent::CJNIIntent(const std::string &action)
  : CJNIBase(s_className)
{
  if(action.empty())
    m_object = new_object(s_className);
  else
    m_object = new_object(s_className,
      "<init>", "(Ljava/lang/String;)V",
                          jcast<jhstring>(action));
  m_object.setGlobal();
}

CJNIIntent::CJNIIntent(const CJNIContext& context, const jhclass& cls)
  : CJNIBase(s_className)
{
  m_object = new_object(s_className,
                        "<init>", "(Landroid/content/Context;Ljava/lang/Class;)V",
                        context.get_raw(), cls);
  m_object.setGlobal();
}

CJNIIntent::CJNIIntent(const std::string& action, const CJNIURI& uri, const CJNIContext& packageContext, const jhclass& cls)
  : CJNIBase(s_className)
{
  m_object = new_object(s_className,
                        "<init>", "(Ljava/lang/String;Landroid/net/Uri;Landroid/content/Context;Ljava/lang/Class;)V",
                        jcast<jhstring>(action), uri.get_raw(), packageContext.get_raw(), cls);
  m_object.setGlobal();
}

std::string CJNIIntent::getAction() const
{
  return jcast<std::string>(call_method<jhstring>(m_object,
    "getAction", "()Ljava/lang/String;"));
}

std::string CJNIIntent::getDataString() const
{
  return jcast<std::string>(call_method<jhstring>(m_object,
    "getDataString", "()Ljava/lang/String;"));
}

std::string CJNIIntent::getPackage() const
{
  return jcast<std::string>(call_method<jhstring>(m_object,
    "getPackage", "()Ljava/lang/String;"));
}

std::string CJNIIntent::getType() const
{
  return jcast<std::string>(call_method<jhstring>(m_object,
    "getType", "()Ljava/lang/String;"));
}

int CJNIIntent::getIntExtra(const std::string &name, int defaultValue) const
{
  return call_method<jint>(m_object,
    "getIntExtra", "(Ljava/lang/String;I)I",
    jcast<jhstring>(name), defaultValue);
}

std::string CJNIIntent::getStringExtra(const std::string &name) const
{
  return jcast<std::string>(call_method<jhstring>(m_object,
    "getStringExtra", "(Ljava/lang/String;I)Ljava/lang/String;",
    jcast<jhstring>(name)));
}

jni::jhobject CJNIIntent::getParcelableExtra(const std::string &name) const
{
  return call_method<jhobject>(m_object,
    "getParcelableExtra", "(Ljava/lang/String;)Landroid/os/Parcelable;",
    jcast<jhstring>(name));
}

bool CJNIIntent::hasExtra(const std::string &name) const
{
  return call_method<jboolean>(m_object,
    "hasExtra", "(Ljava/lang/String;)Z",
    jcast<jhstring>(name));
}

bool CJNIIntent::hasCategory(const std::string &category) const
{
  return call_method<jboolean>(m_object,
    "hasCategory", "(Ljava/lang/String;)Z",
                               jcast<jhstring>(category));
}

CJNIIntent CJNIIntent::putExtra(const std::string &name, const std::string &value)
{
  return static_cast<CJNIIntent>(call_method<jhobject>(m_object,
    "putExtra", "(Ljava/lang/String;Ljava/lang/String;)Landroid/content/Intent;",
    jcast<jhstring>(name), jcast<jhstring>(value)));
}

CJNIIntent CJNIIntent::addFlags(int flags)
{
  return static_cast<CJNIIntent>(call_method<jhobject>(m_object,
    "addFlags", "(I)Landroid/content/Intent;",
    flags));
}

CJNIIntent CJNIIntent::addCategory(const std::string &category)
{
  return static_cast<CJNIIntent>(call_method<jhobject>(m_object,
    "addCategory", "(Ljava/lang/String;)Landroid/content/Intent;",
    jcast<jhstring>(category)));
}

CJNIIntent CJNIIntent::setAction(const std::string &action)
{
  return static_cast<CJNIIntent>(call_method<jhobject>(m_object,
    "setAction", "(Ljava/lang/String;)Landroid/content/Intent;",
    jcast<jhstring>(action)));
}

CJNIIntent CJNIIntent::setClassName(const std::string &packageName, const std::string &className)
{
  return static_cast<CJNIIntent>(call_method<jhobject>(m_object,
    "setClassName", "(Ljava/lang/String;Ljava/lang/String;)Landroid/content/Intent;",
    jcast<jhstring>(packageName), jcast<jhstring>(className)));
}

CJNIIntent CJNIIntent::setData(const std::string &uri)
{
  return static_cast<CJNIIntent>(call_method<jhobject>(m_object,
    "setData", "(Landroid/net/Uri;)Landroid/content/Intent;",
    jcast<jhstring>(uri)));
}

CJNIIntent CJNIIntent::setDataAndType(const CJNIURI &uri, const std::string &type)
{
  return static_cast<CJNIIntent>(call_method<jhobject>(m_object,
    "setDataAndType", "(Landroid/net/Uri;Ljava/lang/String;)Landroid/content/Intent;",
    uri.get_raw(), jcast<jhstring>(type)));
}

CJNIIntent CJNIIntent::setFlags(int flags)
{
  return static_cast<CJNIIntent>(call_method<jhobject>(m_object,
    "setFlags", "(I)Landroid/content/Intent;",
    flags));
}

CJNIIntent CJNIIntent::setPackage(const std::string &packageName)
{
  return static_cast<CJNIIntent>(call_method<jhobject>(m_object,
    "setPackage", "(Ljava/lang/String;)Landroid/content/Intent;",
    jcast<jhstring>(packageName)));
}

CJNIIntent CJNIIntent::setType(const std::string &type)
{
  return static_cast<CJNIIntent>(call_method<jhobject>(m_object,
    "setType", "(Ljava/lang/String;)Landroid/content/Intent;",
    jcast<jhstring>(type)));
}

CJNIURI CJNIIntent::getData() const
{
  return static_cast<CJNIURI>(call_method<jhobject>(m_object,
    "getData","()Landroid/net/Uri;"));
}

CJNIArrayList<std::string> CJNIIntent::getStringArrayListExtra(const std::string &key) const
{
  return call_method<jhobject>(m_object,
    "getStringArrayListExtra","(Ljava/lang/String;)Ljava/util/ArrayList;", jcast<jhstring>(key));
}
