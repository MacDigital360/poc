/*
 * Copyright (c) 2009, Bjoern Knafla
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without modification, are permitted provided that the 
 * following conditions are met:
 *
 * - Redistributions of source code must retain the above copyright notice, this list of conditions and the following 
 *   disclaimer.
 * - Redistributions in binary form must reproduce the above copyright notice, this list of conditions and the following 
 *   disclaimer in the documentation and/or other materials provided with the distribution.
 * - Neither the name of the Bjoern Knafla nor the names of its contributors may be used to 
 *   endorse or promote products derived from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, 
 * INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE 
 * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, 
 * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR 
 * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, 
 * WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE 
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

/**
 * @file
 *
 * Helper macros to allow portable and compiler-independent declaration of stack memory alignment of types, symbol import 
 * and export from libraries (not usable yet), and usage of C keywords like @c inline (@c POC_INLINE) or 
 * @c restrict (@c POC_RESTRICT). See @code poc_portability_macros.h @endcode for details.
 *
 * Macro definitions that can be easily undefined by including @code poc_portability_macros_undef.h @endcode if
 * the less error-prone and convinient @code poc_portability_macros.h @endcode hasn't been included before in the
 * compilation unit.
 *
 * @TODO: Add @c POC_LONG_LONG_TYPE, @c POC_UNSIGNED_LONG_LONG_TYPE, @c POC_LONG_DOUBLE_TYPE .
 * @TODO: Add macros for different bit-sized integral and floating point types to simplify implementing @c stdint.h ?
 * @TODO: Handle @c wchar_t .
 * @TODO: Handle library import/export alas visible/hidden qualifiers.
 */

#if !defined(POC_PORTABILITY_MACROS_HEADER_DISABLE_DEF_UNDEF)


#include "poc_compiler_def.h"
#include "poc_lang_def.h"

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// Macros for @c POC_INLINE and @c POC_RESTRICT are defined if the compiler supports these keywords.
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#if defined(POC_LANG_C_C99)
#   define POC_INLINE inline
#   define POC_RESTRICT restrict
#elif defined(POC_LANG_CPP)
#   define POC_INLINE inline
#   define POC_RESTRICT
#else
#   define POC_INLINE
#   define POC_RESTRICT
#endif


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// Byte-sized stack memory alignment directives @c POC_ALIGN_BEGIN and @c POC_ALIGN_END .
/// 
/// Be carefull when using the alignment values that the value of @c POC_ALIGN_BEGIN( val ) and the value of the
/// corresponding @c POC_ALIGN_END( val ) are equal.
/// 
/// @TODO: Add tests.
/// @TODO: Add checks in macros for alignment values that don't work on specific compilers.
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#if defined(POC_COMPILER_GCC)
#   define POC_ALIGN_BEGIN( ALIGN )
#   define POC_ALIGN_END( ALIGN ) __attribute__((__aligned__( ALIGN )))
#elif defined(POC_COMPILER_ICC)
#   define POC_ALIGN_BEGIN( ALIGN ) __declspec(align( ALIGN ))
#   define POC_ALIGN_END( ALIGN )
#   error Untested. Remove error preprocessor directive after having ported and tested the code to the platform.
#elif defined(POC_COMPILER_MSVC)
#   define POC_ALIGN_BEGIN( ALIGN ) __declspec(align( ALIGN ))
#   define POC_ALIGN_END( ALIGN )
#else
#   error Unknown compiler. Alignment macros not implemented.
#endif




#endif // !defined(POC_PORTABILITY_MACROS_HEADER_DISABLE_DEF_UNDEF)
