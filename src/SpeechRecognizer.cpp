/*
 *  Copyright (C) 2022 Team Kodi
 *  This file is part of Kodi - https://kodi.tv
 *
 *  SPDX-License-Identifier: GPL-2.0-or-later
 *  See LICENSES/README.md for more information.
 */

#include "SpeechRecognizer.h"

#include "jutils-details.hpp"

using namespace jni;

static std::string s_className = "android/speech/SpeechRecognizer";

int CJNISpeechRecognizer::ERROR_AUDIO;
int CJNISpeechRecognizer::ERROR_CLIENT;
int CJNISpeechRecognizer::ERROR_INSUFFICIENT_PERMISSIONS;
int CJNISpeechRecognizer::ERROR_NETWORK;
int CJNISpeechRecognizer::ERROR_NETWORK_TIMEOUT;
int CJNISpeechRecognizer::ERROR_NO_MATCH;
int CJNISpeechRecognizer::ERROR_RECOGNIZER_BUSY;
int CJNISpeechRecognizer::ERROR_SERVER;
int CJNISpeechRecognizer::ERROR_SPEECH_TIMEOUT;
std::string CJNISpeechRecognizer::RESULTS_RECOGNITION;

void CJNISpeechRecognizer::PopulateStaticFields()
{
  jhclass clazz = find_class(s_className.c_str());

  ERROR_AUDIO =                     get_static_field<int>(clazz, "ERROR_AUDIO");
  ERROR_CLIENT =                    get_static_field<int>(clazz, "ERROR_CLIENT");
  ERROR_INSUFFICIENT_PERMISSIONS =  get_static_field<int>(clazz, "ERROR_INSUFFICIENT_PERMISSIONS");
  ERROR_NETWORK =                   get_static_field<int>(clazz, "ERROR_NETWORK");
  ERROR_NETWORK_TIMEOUT =           get_static_field<int>(clazz, "ERROR_NETWORK_TIMEOUT");
  ERROR_NO_MATCH =                  get_static_field<int>(clazz, "ERROR_NO_MATCH");
  ERROR_RECOGNIZER_BUSY =           get_static_field<int>(clazz, "ERROR_RECOGNIZER_BUSY");
  ERROR_SERVER =                    get_static_field<int>(clazz, "ERROR_SERVER");
  ERROR_SPEECH_TIMEOUT =            get_static_field<int>(clazz, "ERROR_SPEECH_TIMEOUT");

  RESULTS_RECOGNITION = jcast<std::string>(get_static_field<jhstring>(clazz, "RESULTS_RECOGNITION"));
}

bool CJNISpeechRecognizer::isRecognitionAvailable (const CJNIContext& context)
{
  return call_static_method<jboolean>(s_className.c_str(), "isRecognitionAvailable",
    "(Landroid/content/Context;)Z", context.get_raw());
}

CJNISpeechRecognizer CJNISpeechRecognizer::createSpeechRecognizer(const CJNIContext& context)
{
  return call_static_method<jhobject>(s_className.c_str(), "createSpeechRecognizer",
    "(Landroid/content/Context;)Landroid/speech/SpeechRecognizer;", context.get_raw());
}

void CJNISpeechRecognizer::setRecognitionListener(const CJNIRecognitionListener& listener)
{
  call_method<void>(m_object, "setRecognitionListener", 
    "(Landroid/speech/RecognitionListener;)V", listener.get_raw());
}

void CJNISpeechRecognizer::startListening(const CJNIIntent& intent)
{
  call_method<void>(m_object, "startListening", "(Landroid/content/Intent;)V", intent.get_raw());
}
