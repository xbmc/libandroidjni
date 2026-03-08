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

#include "JNIBase.h"
#include "jutils-details.hpp"

#include <algorithm>
#include <cassert>

using namespace jni;
int CJNIBase::m_sdk_version = -1;
int CJNIBase::RESULT_OK = -1;
int CJNIBase::RESULT_CANCELED = 0;

CJNIBase::CJNIBase(std::string className)
{
  // If starts with "/" add the base class name prefix (e.g. org/xbmc/kodi)
  if (!className.empty() && className.front() == '/')
  {
    assert(
        !m_baseClassName.empty() &&
        "SetBaseClassName() must be called before instantiating classes with a relative '/' path. "
        "The SetBaseClassName() should be set from CJNIContext or independently from CJNIBase.");
    className = GetBaseClassName() + className;
  }

  m_className = className;
}

CJNIBase::CJNIBase(const jhobject &object):
    m_object(object)
{
  m_object.setGlobal();
}

CJNIBase::~CJNIBase()
{
  if(!m_object)
    return;
}

std::string CJNIBase::GetClassNameAsPath() const
{
  std::string classPath = m_className;
  std::replace(classPath.begin(), classPath.end(), '.', '/');
  return classPath;
}

void CJNIBase::SetSDKVersion(int version)
{
  m_sdk_version = version;
}

int CJNIBase::GetSDKVersion()
{
  return m_sdk_version;
}

const std::string CJNIBase::GetBaseClassName()
{
  return m_baseClassName;
}

void CJNIBase::SetBaseClassName(const std::string& baseClassName)
{
  m_baseClassName = baseClassName;
  if (!m_baseClassName.empty() && m_baseClassName.back() == '/')
    m_baseClassName.pop_back();
}

std::string CJNIBase::ClassNameToPath(std::string className)
{
  std::replace(className.begin(), className.end(), '/', '.');
  return className;
}

std::string CJNIBase::ClassPathToName(std::string classPath)
{
  std::replace(classPath.begin(), classPath.end(), '.', '/');
  return classPath;
}

const std::string CJNIBase::ExceptionToString()
{
  JNIEnv* jenv = xbmc_jnienv();
  jhthrowable exception = (jhthrowable)jenv->ExceptionOccurred();
  if (!exception)
    return "";

  jenv->ExceptionClear();
  jhclass excClass = find_class(jenv, "java/lang/Throwable");
  jmethodID toStrMethod = get_method_id(jenv, excClass, "toString", "()Ljava/lang/String;");
  jhstring msg = call_method<jhstring>(exception, toStrMethod);
  return (jcast<std::string>(msg));
}
