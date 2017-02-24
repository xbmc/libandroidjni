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

#include "Map.h"
#include "jutils-details.hpp"

using namespace jni;


template <typename K, typename V>
void CJNIMap<K, V>::clear()
{
  call_method<void>(m_object,
                    "clear", "()V");
}

template <typename K, typename V>
bool CJNIMap<K, V>::containsKey(const K& key)
{
  return call_method<jboolean>(m_object,
                               "containsKey", "(Ljava/lang/Object;)Z",
                               key);
}

template <typename K, typename V>
bool CJNIMap<K, V>::containsValue(const V& value)
{
  return call_method<jboolean>(m_object,
                               "containsValue", "(Ljava/lang/Object;)Z",
                               value);
}

template <typename K, typename V>
bool CJNIMap<K, V>::equals(const CJNIMap<K, V>& o)
{
  return call_method<jboolean>(m_object,
                               "equals", "(Ljava/lang/Object;)Z",
                               o.get_raw());
}

template <typename K, typename V>
V CJNIMap<K, V>::get(const K& key)
{
  return call_method<V>(m_object,
                               "get", "(Ljava/lang/Object;)Ljava/lang/Object;",
                               key);
}

template <typename K, typename V>
int CJNIMap<K, V>::hashCode()
{
  return call_method<jint>(m_object,
                           "hashCode", "()I");
}

template <typename K, typename V>
bool CJNIMap<K, V>::isEmpty()
{
  return call_method<jboolean>(m_object,
                               "isEmpty", "()Z");
}

template <typename K, typename V>
CJNISet<K> CJNIMap<K, V>::keySet()
{
  return call_method<jhobject>(m_object,
                               "keySet", "()Ljava/util/Set;");
}

template <typename K, typename V>
V CJNIMap<K, V>::put(const K& key, const V& value)
{
  return call_method<V>(m_object,
                               "put", "(Ljava/lang/Object;Ljava/lang/Object;)Ljava/lang/Object;",
                               key, value);
}

template <typename K, typename V>
V CJNIMap<K, V>::remove(const K& key)
{
  return call_method<V>(m_object,
                               "remove", "(Ljava/lang/Object;)Ljava/lang/Object;",
                               key);
}

template <typename K, typename V>
int CJNIMap<K, V>::size()
{
  return call_method<jint>(m_object,
                           "size", "()I");
}

template class CJNIMap<jhstring, jhbyteArray>;
