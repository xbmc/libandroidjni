#pragma once
/*
 *  Copyright (C) 2022 Team Kodi
 *  This file is part of Kodi - https://kodi.tv
 *
 *  SPDX-License-Identifier: GPL-2.0-or-later
 *  See LICENSES/README.md for more information.
 */

#include "JNIBase.h"
#include "Bundle.h"
#include "Context.h"
#include "Intent.h"

class CJNISpeechRecognitionListener : virtual public CJNIBase
{
public:
  virtual void onReadyForSpeech(CJNIBundle bundle) = 0;
  virtual void onError(int i) = 0;
  virtual void onResults(CJNIBundle bundle) = 0;
};

class CJNISpeechRecognizer : public CJNIBase
{
public:
  CJNISpeechRecognizer(const jni::jhobject &object) : CJNIBase(object) {};
  ~CJNISpeechRecognizer() {};
  
  static void PopulateStaticFields();
  
  static int ERROR_AUDIO;
  static int ERROR_CLIENT;
  static int ERROR_INSUFFICIENT_PERMISSIONS;
  static int ERROR_NETWORK;
  static int ERROR_NETWORK_TIMEOUT;
  static int ERROR_NO_MATCH;
  static int ERROR_RECOGNIZER_BUSY;
  static int ERROR_SERVER;
  static int ERROR_SPEECH_TIMEOUT;
  static std::string RESULTS_RECOGNITION;
  
  static bool isRecognitionAvailable (const CJNIContext& context);
  static CJNISpeechRecognizer createSpeechRecognizer(const CJNIContext& context);
  void setRecognitionListener(const CJNISpeechRecognitionListener& listener);
  void startListening(const CJNIIntent& intent);
};
