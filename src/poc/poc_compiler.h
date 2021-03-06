/*
 * Copyright (c) 2009-2010, Bjoern Knafla
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without 
 * modification, are permitted provided that the following conditions are met:
 *
 * - Redistributions of source code must retain the above copyright notice, this 
 *   list of conditions and the following disclaimer.
 * - Redistributions in binary form must reproduce the above copyright notice, 
 *   this list of conditions and the following disclaimer in the documentation 
 *   and/or other materials provided with the distribution.
 * - Neither the name of the Bjoern Knafla nor the names of its contributors may 
 *   be used to endorse or promote products derived from this software without 
 *   specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" 
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE 
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE 
 * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE 
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR 
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF 
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS 
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN 
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) 
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE 
 * POSSIBILITY OF SUCH DAMAGE.
 */

/**
 * @file
 *
 * Collection of @c POC_COMPILER (prefixed) preprocessor macros to identify the compiler compiling with.
 * 
 * For example if the code is compiled with GNU GCC @c POC_COMPILER_GCC_ID is stored in @c POC_COMPILER
 * and also the macro @c POC_COMPILER_GCC is defined with the previous id value. In this case @c POC_COMPILER_STRING is 
 * set to @c POC_COMPILER_GCC_STRING . @c POC_COMPILER_VERSION is set to the compiler verison, an integral value.
 *
 * If the compiler identified is Intel's C/C++ compiler the macros @c POC_COMPILER_ICC_HOST, 
 * @c POC_COMPILER_ICC_HOST_STRING, @c POC_COMPILER_ICC_HOST_VERSION are defined because Intel's compiler uses the
 * infrastructure (headers, tools, etc.) of a host compiler. If GNU GCC is the host compiler of Intel's compiler, then
 * @c POC_COMPILER_ICC_HOST_GCC, @c POC_COMPILER_ICC_HOST_GCC_STRING, and @c POC_COMPILER_ICC_HOST_VERSION are defined
 * additionally.
 *
 * For convenience include this header and don't use poc_compiler_def.h directly. Use the 
 * @c _def.h and @c _undef.h files for fine grained control of the parts in the code where 
 * @c POC_ prefixed macros are defined (or undefined) but keep care for yourself that macros aren't redefined.
 * By including the POC headers without the @c _def.h or @c _undef.h postfix the defined macros
 * exist throughout the whole compilation unit and can't be undefined by including the corresponding 
 * @c _undef.h anymore.
 */

/**
 * @def POC_COMPILER
 * Stores a predefined value representing the compiler used or @c POC_COMPILER_UNKNOWN_ID if the
 * compiler can't be identified (is unknown).
 */

/**
 * @def POC_COMPILER_STRING
 *
 * Stores a C character string describing the identified compiler.
 */
 
/**
 * @def POC_COMPILER_VERSION
 *
 * Stores the found compiler version as an integral value (an integer value).
 */

#ifndef POC_poc_compiler_H
#define POC_poc_compiler_H

#include "poc_compiler_def.h"

/* Disable macro undefines via including poc_compiler_undef.h and prevent re-defines from accidential
 * includes of poc_compiler_def.h .
 */
#define POC_COMPILER_HEADER_DISABLE_DEF_UNDEF

#endif /* POC_poc_compiler_H */
