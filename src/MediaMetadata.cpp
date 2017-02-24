/*
 *      Copyright (C) 2017 Christian Browet
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

#include "MediaMetadata.h"
#include "jutils-details.hpp"

using namespace jni;

std::string CJNIMediaMetadata::METADATA_KEY_ALBUM;
std::string CJNIMediaMetadata::METADATA_KEY_ALBUM_ART;
std::string CJNIMediaMetadata::METADATA_KEY_ALBUM_ARTIST;
std::string CJNIMediaMetadata::METADATA_KEY_ALBUM_ART_URI;
std::string CJNIMediaMetadata::METADATA_KEY_ART;
std::string CJNIMediaMetadata::METADATA_KEY_ARTIST;
std::string CJNIMediaMetadata::METADATA_KEY_ART_URI;
std::string CJNIMediaMetadata::METADATA_KEY_AUTHOR;
std::string CJNIMediaMetadata::METADATA_KEY_COMPILATION;
std::string CJNIMediaMetadata::METADATA_KEY_COMPOSER;
std::string CJNIMediaMetadata::METADATA_KEY_DATE;
std::string CJNIMediaMetadata::METADATA_KEY_DISC_NUMBER;
std::string CJNIMediaMetadata::METADATA_KEY_DISPLAY_DESCRIPTION;
std::string CJNIMediaMetadata::METADATA_KEY_DISPLAY_ICON;
std::string CJNIMediaMetadata::METADATA_KEY_DISPLAY_ICON_URI;
std::string CJNIMediaMetadata::METADATA_KEY_DISPLAY_SUBTITLE;
std::string CJNIMediaMetadata::METADATA_KEY_DISPLAY_TITLE;
std::string CJNIMediaMetadata::METADATA_KEY_DURATION;
std::string CJNIMediaMetadata::METADATA_KEY_GENRE;
std::string CJNIMediaMetadata::METADATA_KEY_MEDIA_ID;
std::string CJNIMediaMetadata::METADATA_KEY_NUM_TRACKS;
std::string CJNIMediaMetadata::METADATA_KEY_RATING;
std::string CJNIMediaMetadata::METADATA_KEY_TITLE;
std::string CJNIMediaMetadata::METADATA_KEY_TRACK_NUMBER;
std::string CJNIMediaMetadata::METADATA_KEY_USER_RATING;
std::string CJNIMediaMetadata::METADATA_KEY_WRITER;
std::string CJNIMediaMetadata::METADATA_KEY_YEAR;

static std::string s_className = "android/media/MediaMetadata";


void CJNIMediaMetadata::PopulateStaticFields()
{
  jhclass clazz = find_class(s_className.c_str());
  METADATA_KEY_ALBUM = jcast<std::string>(get_static_field<jhstring>(clazz, "METADATA_KEY_ALBUM"));
  METADATA_KEY_ALBUM_ART = jcast<std::string>(get_static_field<jhstring>(clazz, "METADATA_KEY_ALBUM_ART"));
  METADATA_KEY_ALBUM_ARTIST = jcast<std::string>(get_static_field<jhstring>(clazz, "METADATA_KEY_ALBUM_ARTIST"));
  METADATA_KEY_ALBUM_ART_URI = jcast<std::string>(get_static_field<jhstring>(clazz, "METADATA_KEY_ALBUM_ART_URI"));
  METADATA_KEY_ART = jcast<std::string>(get_static_field<jhstring>(clazz, "METADATA_KEY_ART"));
  METADATA_KEY_ARTIST = jcast<std::string>(get_static_field<jhstring>(clazz, "METADATA_KEY_ARTIST"));
  METADATA_KEY_ART_URI = jcast<std::string>(get_static_field<jhstring>(clazz, "METADATA_KEY_ART_URI"));
  METADATA_KEY_AUTHOR = jcast<std::string>(get_static_field<jhstring>(clazz, "METADATA_KEY_AUTHOR"));
  METADATA_KEY_COMPILATION = jcast<std::string>(get_static_field<jhstring>(clazz, "METADATA_KEY_COMPILATION"));
  METADATA_KEY_COMPOSER = jcast<std::string>(get_static_field<jhstring>(clazz, "METADATA_KEY_COMPOSER"));
  METADATA_KEY_DATE = jcast<std::string>(get_static_field<jhstring>(clazz, "METADATA_KEY_DATE"));
  METADATA_KEY_DISC_NUMBER = jcast<std::string>(get_static_field<jhstring>(clazz, "METADATA_KEY_DISC_NUMBER"));
  METADATA_KEY_DISPLAY_DESCRIPTION = jcast<std::string>(get_static_field<jhstring>(clazz, "METADATA_KEY_DISPLAY_DESCRIPTION"));
  METADATA_KEY_DISPLAY_ICON = jcast<std::string>(get_static_field<jhstring>(clazz, "METADATA_KEY_DISPLAY_ICON"));
  METADATA_KEY_DISPLAY_ICON_URI = jcast<std::string>(get_static_field<jhstring>(clazz, "METADATA_KEY_DISPLAY_ICON_URI"));
  METADATA_KEY_DISPLAY_SUBTITLE = jcast<std::string>(get_static_field<jhstring>(clazz, "METADATA_KEY_DISPLAY_SUBTITLE"));
  METADATA_KEY_DISPLAY_TITLE = jcast<std::string>(get_static_field<jhstring>(clazz, "METADATA_KEY_DISPLAY_TITLE"));
  METADATA_KEY_DURATION = jcast<std::string>(get_static_field<jhstring>(clazz, "METADATA_KEY_DURATION"));
  METADATA_KEY_GENRE = jcast<std::string>(get_static_field<jhstring>(clazz, "METADATA_KEY_GENRE"));
  METADATA_KEY_MEDIA_ID = jcast<std::string>(get_static_field<jhstring>(clazz, "METADATA_KEY_MEDIA_ID"));
  METADATA_KEY_NUM_TRACKS = jcast<std::string>(get_static_field<jhstring>(clazz, "METADATA_KEY_NUM_TRACKS"));
  METADATA_KEY_RATING = jcast<std::string>(get_static_field<jhstring>(clazz, "METADATA_KEY_RATING"));
  METADATA_KEY_TITLE = jcast<std::string>(get_static_field<jhstring>(clazz, "METADATA_KEY_TITLE"));
  METADATA_KEY_TRACK_NUMBER = jcast<std::string>(get_static_field<jhstring>(clazz, "METADATA_KEY_TRACK_NUMBER"));
  METADATA_KEY_USER_RATING = jcast<std::string>(get_static_field<jhstring>(clazz, "METADATA_KEY_USER_RATING"));
  METADATA_KEY_WRITER = jcast<std::string>(get_static_field<jhstring>(clazz, "METADATA_KEY_WRITER"));
  METADATA_KEY_YEAR = jcast<std::string>(get_static_field<jhstring>(clazz, "METADATA_KEY_YEAR"));
}


static std::string s_builderclassName = "android/media/MediaMetadata$Builder";

CJNIMediaMetadataBuilder::CJNIMediaMetadataBuilder()
  : CJNIBase(s_builderclassName)
{
  m_object = new_object(s_builderclassName);
  m_object.setGlobal();
}

CJNIMediaMetadataBuilder CJNIMediaMetadataBuilder::putText(const std::string& key, const CJNICharSequence& value)
{
  return (CJNIMediaMetadataBuilder)call_method<jhobject>(m_object,
                                                         "putText", "(Ljava/lang/String;Ljava/lang/CharSequence;)Landroid/media/MediaMetadata$Builder;",
                                                         jcast<jhstring>(key), value.get_raw());
}

CJNIMediaMetadataBuilder CJNIMediaMetadataBuilder::putString(const std::string& key, const std::string& value)
{
  return (CJNIMediaMetadataBuilder)call_method<jhobject>(m_object,
                                                         "putString", "(Ljava/lang/String;Ljava/lang/String;)Landroid/media/MediaMetadata$Builder;",
                                                         jcast<jhstring>(key), jcast<jhstring>(value));
}

CJNIMediaMetadataBuilder CJNIMediaMetadataBuilder::putLong(const std::string& key, int64_t value)
{
  return (CJNIMediaMetadataBuilder)call_method<jhobject>(m_object,
                                                         "putLong", "(Ljava/lang/String;J)Landroid/media/MediaMetadata$Builder;",
                                                         jcast<jhstring>(key), value);
}

CJNIMediaMetadataBuilder CJNIMediaMetadataBuilder::putBitmap(const std::string& key, const CJNIBitmap& value)
{
  return (CJNIMediaMetadataBuilder)call_method<jhobject>(m_object,
                                                         "putBitmap", "(Ljava/lang/String;Landroid/graphics/Bitmap;)Landroid/media/MediaMetadata$Builder;",
                                                         jcast<jhstring>(key), value.get_raw());
}

CJNIMediaMetadata CJNIMediaMetadataBuilder::build()
{
  return (CJNIMediaMetadata)call_method<jhobject>(m_object,
                                                         "build", "()Landroid/media/MediaMetadata;");
}
