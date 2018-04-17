#pragma once
/*
 *      Copyright (C) 2018 Team Kodi
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

#include "JNIBase.h"
#include "MediaDrmKeyRequest.h"
#include "MediaDrmProvisionRequest.h"
#include "MediaDrmCryptoSession.h"
#include <map>

class CJNIUUID;
class CJNIMediaDrmOnEventListener;

class CJNIMediaDrm : public CJNIBase
{
public:
  static const int KEY_TYPE_STREAMING = 1;
  static const int KEY_TYPE_OFFLINE = 2;
  static const int KEY_TYPE_RELEASE = 3;

  static const int EVENT_PROVISION_REQUIRED = 1;
  static const int EVENT_KEY_REQUIRED = 2;
  static const int EVENT_KEY_EXPIRED = 3;
  static const int EVENT_VENDOR_DEFINED = 4;
  static const int EVENT_SESSION_RECLAIMED = 5;

  CJNIMediaDrm(const jni::jhobject &object) : CJNIBase(object) {};
  CJNIMediaDrm(const CJNIUUID& uuid);
  ~CJNIMediaDrm() {};

  void release() const;

  std::vector<char> openSession() const;
  void closeSession(const std::vector<char> & sessionId) const;

  std::string getPropertyString(const std::string &propertyName) const;
  void setPropertyString(const std::string &propertyName, const std::string &value) const;
  void setPropertyByteArray(const std::string &propertyName, const std::vector<char> &value) const;

  CJNIMediaDrmCryptoSession getCryptoSession(const std::vector<char> &sessionId,
    const std::string &cipherAlgorithm, const std::string &macAlgorithm) const;

  CJNIMediaDrmKeyRequest getKeyRequest(const std::vector<char> &scope,
    const std::vector<char> &init, const std::string &mimeType, int keyType,
    const std::map<std::string, std::string> &optionalParameters) const;
  std::vector<char> provideKeyResponse(const std::vector<char> &scope, const std::vector<char> &response) const;

  CJNIMediaDrmProvisionRequest getProvisionRequest() const;
  void provideProvisionResponse(const std::vector<char> &response) const;

  void restoreKeys(const std::vector<char> &sessionId, const std::vector<char> &keySetId) const;
  void removeKeys(const std::vector<char> &sessionId) const;

  void setOnEventListener(const CJNIMediaDrmOnEventListener &listener) const;
};


