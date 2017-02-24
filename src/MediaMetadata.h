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

#include "CharSequence.h"
#include "Bitmap.h"

class CJNIMediaMetadata : public CJNIBase
{
public:
  CJNIMediaMetadata(const CJNIMediaMetadata& other) : CJNIBase(other) {}
  CJNIMediaMetadata(const jni::jhobject &object) : CJNIBase(object) {}
  virtual ~CJNIMediaMetadata(){}

  static std::string METADATA_KEY_ALBUM;
  static std::string METADATA_KEY_ALBUM_ART;
  static std::string METADATA_KEY_ALBUM_ARTIST;
  static std::string METADATA_KEY_ALBUM_ART_URI;
  static std::string METADATA_KEY_ART;
  static std::string METADATA_KEY_ARTIST;
  static std::string METADATA_KEY_ART_URI;
  static std::string METADATA_KEY_AUTHOR;
  static std::string METADATA_KEY_COMPILATION;
  static std::string METADATA_KEY_COMPOSER;
  static std::string METADATA_KEY_DATE;
  static std::string METADATA_KEY_DISC_NUMBER;
  static std::string METADATA_KEY_DISPLAY_DESCRIPTION;
  static std::string METADATA_KEY_DISPLAY_ICON;
  static std::string METADATA_KEY_DISPLAY_ICON_URI;
  static std::string METADATA_KEY_DISPLAY_SUBTITLE;
  static std::string METADATA_KEY_DISPLAY_TITLE;
  static std::string METADATA_KEY_DURATION;
  static std::string METADATA_KEY_GENRE;
  static std::string METADATA_KEY_MEDIA_ID;
  static std::string METADATA_KEY_NUM_TRACKS;
  static std::string METADATA_KEY_RATING;
  static std::string METADATA_KEY_TITLE;
  static std::string METADATA_KEY_TRACK_NUMBER;
  static std::string METADATA_KEY_USER_RATING;
  static std::string METADATA_KEY_WRITER;
  static std::string METADATA_KEY_YEAR;

  static void PopulateStaticFields();

protected:
  CJNIMediaMetadata();
};

class CJNIMediaMetadataBuilder : public CJNIBase
{
public:
  CJNIMediaMetadataBuilder();
  CJNIMediaMetadataBuilder(const CJNIMediaMetadataBuilder& other) : CJNIBase(other) {}
  CJNIMediaMetadataBuilder(const jni::jhobject &object) : CJNIBase(object){}
  virtual ~CJNIMediaMetadataBuilder() {}

  CJNIMediaMetadataBuilder putText(const std::string& key, const CJNICharSequence& value);
  CJNIMediaMetadataBuilder putString(const std::string& key, const std::string& value);
  CJNIMediaMetadataBuilder putLong(const std::string& key, int64_t value);
  //CJNIMediaMetadataBuilder putRating(const std::string& key, const CJNIMediaRating& value);
  CJNIMediaMetadataBuilder putBitmap(const std::string& key, const CJNIBitmap& value);
  CJNIMediaMetadata build();
};
