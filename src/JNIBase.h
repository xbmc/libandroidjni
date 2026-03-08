#pragma once
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

#include "jutils.hpp"

#include <list>

class CJNIBase
{
  friend class CJNIContext; //for SetSDKVersion()

  typedef void (CJNIBase::*safe_bool_type)();
  void non_null_object() {}

public:
  operator safe_bool_type() const { return !m_object ?  0 : &CJNIBase::non_null_object; }
  const jni::jhobject& get_raw() const { return m_object; }
  static int GetSDKVersion();
  static void SetSDKVersion(int);

  /*!
   * \brief Get fully qualified "base" class name path.
   * \return The fully qualified base class name path (this/is/an/example)
   */
  static const std::string GetBaseClassName();

  /*!
   * \brief Set the fully qualified "base" class name path (e.g. Kodi package name).
   * \param baseClassName The base class name (this/is/an/example)
   */
  static void SetBaseClassName(const std::string& baseClassName);

  const static std::string ExceptionToString();

  static int RESULT_OK;
  static int RESULT_CANCELED;

protected:
  CJNIBase() {}
  CJNIBase(jni::jhobject const& object);

  /*!
   * \brief Construct CJNIBase by class name.
   * \param className Can be a class name, or relative class name,
   *                  so when begin with "/" will be automatically added the "base" class name prefix e.g. org/xbmc/kodi
   */
  CJNIBase(std::string className);
  virtual ~CJNIBase();

  const std::string& GetClassName() const {return m_className;}

  /*!
   * \brief Get class name as fully qualified class name path.
   * \return The fully qualified class name path (this.is.an.example)
   */
  std::string GetClassNameAsPath() const;

  /*!
   * \brief Convert a class name to a fully qualified class name path.
   * \param className The class name (this/is/an/example)
   * \return The fully qualified class name path (this.is.an.example)
   */
  static std::string ClassNameToPath(std::string className);

  /*!
   * \brief Convert a fully qualified class name path to class name.
   * \param classPath The fully qualified class name path (this.is.an.example)
   * \return The class name (this/is/an/example)
   */
  static std::string ClassPathToName(std::string classPath);

  jni::jhobject m_object;

private:
  std::string m_className;
  static inline std::string m_baseClassName{};
  static int m_sdk_version;
};

template <typename I>
class CJNIInterfaceImplem
{
protected:
  static std::list<std::pair<jni::jhobject, I*>> s_object_map;  

  static void add_instance(const jni::jhobject& o, I* inst)
  {
    s_object_map.push_back(std::pair<jni::jhobject, I*>(o, inst));
  }

  static I* find_instance(const jobject& o)
  {
    for( auto it = s_object_map.begin(); it != s_object_map.end(); ++it )
    {
      if (it->first == o)
        return it->second;
    }
    return nullptr;
  }
  
  static void remove_instance(I* inst)
  {
    for( auto it = s_object_map.begin(); it != s_object_map.end(); ++it )
    {
      if (it->second == inst)
      {
        s_object_map.erase(it);
        break;
      }
    }
  }
};

template <typename I> std::list<std::pair<jni::jhobject, I*>> CJNIInterfaceImplem<I>::s_object_map;  
