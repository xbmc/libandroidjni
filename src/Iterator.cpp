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

#include "Iterator.h"
#include "jutils-details.hpp"

using namespace jni;


template <typename T>
bool CJNIIterator<T>::hasNext()
{
  return call_method<jboolean>(m_object,
                               "hasNext", "()Z");
}

template <typename T>
T CJNIIterator<T>::next()
{
  return call_method<T>(m_object,
                               "next", "()Ljava/lang/Object;");
}

template <typename T>
void CJNIIterator<T>::remove()
{
  call_method<void>(m_object,
                    "remove", "()V");
}

template class CJNIIterator<jhstring>;
