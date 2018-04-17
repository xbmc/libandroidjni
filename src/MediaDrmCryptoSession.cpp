/*
 *      Copyright (C) 2005-2018 Team Kodi
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

#include "MediaDrmCryptoSession.h"
#include "jutils-details.hpp"

using namespace jni;


std::vector<char> CJNIMediaDrmCryptoSession::decrypt(const std::vector<char> &keyid, const std::vector<char> &input, const std::vector<char> &iv) const
{
  return jcast<std::vector<char> >(call_method<jhbyteArray>(m_object,
    "decrypt", "([B[B[B)[B", jcast<jhbyteArray>(keyid), jcast<jhbyteArray>(input), jcast<jhbyteArray>(iv)));
}

std::vector<char> CJNIMediaDrmCryptoSession::encrypt(const std::vector<char> &keyid, const std::vector<char> &input, const std::vector<char> &iv) const
{
  return jcast<std::vector<char> >(call_method<jhbyteArray>(m_object,
    "encrypt", "([B[B[B)[B", jcast<jhbyteArray>(keyid), jcast<jhbyteArray>(input), jcast<jhbyteArray>(iv)));
}

std::vector<char> CJNIMediaDrmCryptoSession::sign(const std::vector<char> &keyid, const std::vector<char> &message) const
{
  return jcast<std::vector<char> >(call_method<jhbyteArray>(m_object,
    "sign", "([B[B)[B", jcast<jhbyteArray>(keyid), jcast<jhbyteArray>(message)));
}


bool CJNIMediaDrmCryptoSession::verify(const std::vector<char> &keyid, const std::vector<char> &message, const std::vector<char> &signature) const
{
  return call_method<jboolean>(m_object,
    "verify", "([B[B[B)Z", jcast<jhbyteArray>(keyid), jcast<jhbyteArray>(message), jcast<jhbyteArray>(signature));
}
