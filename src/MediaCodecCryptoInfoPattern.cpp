/*
 *      Copyright (C) 2022 Team Kodi
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
 *  along with Kodi; see the file COPYING.  If not, see
 *  <http://www.gnu.org/licenses/>.
 *
 */

#include "jutils-details.hpp"
#include "MediaCodecCryptoInfoPattern.h"

using namespace jni;

CJNIMediaCodecCryptoInfoPattern::CJNIMediaCodecCryptoInfoPattern(int blocksToEncrypt,
                                                                 int blocksToSkip)
  : CJNIBase("android/media/MediaCodec$CryptoInfo$Pattern")
{
  if(GetSDKVersion() >= 24)
  {
    m_object = new_object(GetClassName(), "<init>", "(II)V", blocksToEncrypt, blocksToSkip);
    m_object.setGlobal();
  }
}
