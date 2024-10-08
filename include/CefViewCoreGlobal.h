﻿/*
 * File: CefViewCoreGlobal.h
 * Project: include
 * Created: 30 May 2023
 * Author: Sheen Tian
 */
#ifndef CefViewCoreGlobal_h
#define CefViewCoreGlobal_h
#pragma once

#pragma region cef_headers
#include <include/cef_app.h>
#include <include/cef_version.h>
#pragma endregion cef_headers

#if CEF_VERSION_MAJOR < 122
using CefFrameId = int64_t;
#else
using CefFrameId = CefString;

template<>
struct std::hash<CefFrameId>
{
  std::size_t operator()(const CefFrameId& k) const
  {
    using std::hash;
    using std::string;
    return std::hash<std::string>()(k.ToString());
  }
};

// namespace std {
// static std::string
// to_string(const CefFrameId& k)
//{
//   return k.ToString();
// }
// } // namespace std

#endif

#endif
