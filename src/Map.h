#pragma once
/*
 *      Copyright (C) 2016 Christian Browet
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

#include "Set.h"

namespace jni
{

template <typename K, typename V>
class CJNIMap : public CJNIBase
{
public:
  CJNIMap(const jni::jhobject &object) : CJNIBase(object) {}
  virtual ~CJNIMap() {}

  virtual void clear();
  virtual bool containsKey(const K& key);
  virtual bool containsValue(const V& value);
  virtual bool equals(const CJNIMap<K, V>& o);
  virtual V get(const K& key);
  virtual int hashCode();
  virtual bool isEmpty();
  virtual CJNISet<K> keySet() ;
  virtual V put(const K& key, const V& value);
  virtual V remove(const K& key);
  virtual int size();
};

}

