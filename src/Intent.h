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

#include "JNIBase.h"
#include "ArrayList.h"
#include "Context.h"
#include "URI.h"

class CJNIURI;
class CJNIIntent : public CJNIBase
{
public:
  CJNIIntent(const std::string &action = "");
  CJNIIntent(const CJNIContext& context, const jni::jhclass& cls);
  CJNIIntent(const std::string &action, const CJNIURI& uri, const CJNIContext& packageContext, const jni::jhclass& cls);
  CJNIIntent(const jni::jhobject &intent) : CJNIBase(intent) {};
  ~CJNIIntent() {};

  std::string getAction() const;
  std::string getDataString() const ;
  std::string getPackage() const;
  std::string getType() const ;

  int getIntExtra(const std::string &name, int defaultValue) const;
  std::string getStringExtra(const std::string &name) const;
  // Deprecated in API level 33
  jni::jhobject getParcelableExtra(const std::string &name) const;

  bool hasExtra(const std::string &name) const;
  bool hasCategory(const std::string &category) const;

  CJNIIntent putExtra(const std::string &name, const std::string &value);

  CJNIIntent addFlags(int flags);
  CJNIIntent addCategory(const std::string &category);
  CJNIIntent setFlags(int flags);
  CJNIIntent setAction(const std::string &action);
  CJNIIntent setClassName(const std::string &packageName, const std::string &className);

  // Note that these are strings. We auto-convert to uri objects.
  CJNIIntent setDataAndType(const CJNIURI &uri, const std::string &type);
  CJNIIntent setData(const std::string &uri);

  CJNIIntent setPackage(const std::string &packageName);
  CJNIIntent setType(const std::string &type);
  CJNIURI getData() const;
  CJNIArrayList<std::string> getStringArrayListExtra(const std::string &key) const;

  static void PopulateStaticFields();
  static std::string EXTRA_KEY_EVENT;
  static std::string ACTION_OPEN_DOCUMENT_TREE;
};
