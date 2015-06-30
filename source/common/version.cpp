/*****************************************************************************
 * Copyright (C) 2013 x265 project
 *
 * Authors: Steve Borho <steve@borho.org>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02111, USA.
 *
 * This program is also available under a commercial proprietary license.
 * For more information, contact us at license @ x265.com.
 *****************************************************************************/

#include "x265.h"
#include "common.h"
#include "primitives.h"

#define XSTR(x) STR(x)
#define STR(x) #x

#if defined(__clang__)
#define COMPILEDBY  "[clang " XSTR(__clang_major__) "." XSTR(__clang_minor__) "." XSTR(__clang_patchlevel__) "]"
#ifdef __IA64__
#define ONARCH    "[on 64-bit] "
#else
#define ONARCH    "[on 32-bit] "
#endif
#endif

#if defined(__GNUC__) && !defined(__INTEL_COMPILER) && !defined(__clang__)
#define COMPILEDBY  "[GCC " XSTR(__GNUC__) "." XSTR(__GNUC_MINOR__) "." XSTR(__GNUC_PATCHLEVEL__) "]"
#ifdef __IA64__
#define ONARCH    "[on 64-bit] "
#else
#define ONARCH    "[on 32-bit] "
#endif
#endif

#ifdef __INTEL_COMPILER
#define COMPILEDBY "[ICC " XSTR(__INTEL_COMPILER) "]"
#elif  _MSC_VER
#define COMPILEDBY "[MSVC " XSTR(_MSC_VER) "]"
#endif

#ifndef COMPILEDBY
#define COMPILEDBY "[Unk-CXX]"
#endif

#ifdef _WIN32
#define ONOS    "[Windows]"
#elif  __linux
#define ONOS    "[Linux]"
#elif __OpenBSD__
#define ONOS    "[OpenBSD]"
#elif  __CYGWIN__
#define ONOS    "[Cygwin]"
#elif __APPLE__
#define ONOS    "[Mac OS X]"
#else
#define ONOS    "[Unk-OS]"
#endif

#if X86_64
#define BITS    "[64 bit]"
#else
#define BITS    "[32 bit]"
#endif

#if defined(ENABLE_ASSEMBLY)
#define ASM     ""
#else
#define ASM     "[noasm]"
#endif
 
#if CHECKED_BUILD
#define CHECKED "[CHECKED] "
#else
#define CHECKED " "
#endif

#if HIGH_BIT_DEPTH
#define BITDEPTH "10bit"
const int PFX(max_bit_depth) = 10;
#else
#define BITDEPTH "8bit"
const int PFX(max_bit_depth) = 8;
#endif

const char* PFX(version_str) = XSTR(X265_VERSION);
const char* PFX(build_info_str) = ONOS COMPILEDBY BITS ASM CHECKED BITDEPTH;
