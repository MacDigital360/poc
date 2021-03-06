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
 * See poc_endian.h for details.
 *
 * @attention This header doesn't have header guards to allow successive inclusion of it and its sibling 
 *            poc_endian_undef.h . If header guards are wanted or needed use 
 *            poc.h or poc_endian.h instead.
 *
 * See http://en.wikipedia.org/wiki/Endianness
 *
 * @todo TODO: How to handle bi-endian architectures? Does an app on a PowerPC
 *       change its endianess at run-time or is it set at compile-time?
 */

/* Only allow definition of POC endienness macros if poc_endian.h hasn't been included 
 * in this compilation unit.
 */
#if !defined(POC_ENDIAN_HEADER_DISABLE_DEF_UNDEF)



/* Include POC_ARCH prefixed preprocessor symbols
 */
#include "poc_arch_def.h"

/***************************************************************************//**
 * @name Endianness ids
 ******************************************************************************/
/*@{*/
#define POC_ENDIAN_UNKNOWN_ID 0
#define POC_ENDIAN_LITTLE_ID 1
#define POC_ENDIAN_BIG_ID 2
/*@}*/

/***************************************************************************//**
 * @name Endianness strings
 ******************************************************************************/
/*@{*/
#define POC_ENDIAN_UNKNOWN_STRING "Unknown endian"
#define POC_ENDIAN_LITTLE_STRING "Little endian"
#define POC_ENDIAN_BIG_STRING "Big endian"
/*@}*/


#if !defined(POC_ENDIAN_DISABLE_AUTODETECT) && !defined(POC_DISABLE_AUTODETECT)

/*******************************************************************************
 * Detect endianness.
 ******************************************************************************/

/* Detect little endianness
 */
#if defined(__LITTLE_ENDIAN__) || defined (__ENDIAN_LITTLE__) || defined(POC_ARCH_X86) || defined(INIGMA_ARCH_X86_32) || defined(POC_ARCH_X86_64)
#   define POC_ENDIAN_LITTLE POC_ENDIAN_LITTLE_ID
#endif

/* Detect big endianness
 *
 * On the CELL BE platform big endianness is used. Additionally: the most
 * significant bit in a byte is stored at bit 0. See http://www-01.ibm.com/chips/techlib/techlib.nsf/techdocs/FC857AE550F7EB83872571A80061F788/$file/CBE_Programming_Tutorial_v3.0.pdf .
 *
 */
#if defined(__BIG_ENDIAN__) || \
(defined(_BIG_ENDIAN) || \
defined(POC_ARCH_CELL_PPU) || \
defined(POC_ARCH_CELL_SPU) || \
defined(POC_ARCH_CELL_SPU_EDP) || \
(defined(__OPENCL_VERSION__) && !defined(__ENDIAN_LITTLE__)))
#   define POC_ENDIAN_BIG POC_ENDIAN_BIG_ID
#endif


/*******************************************************************************
 * Detect @c POC_ENDIAN_ID and @c POC_ENDIAN_STRING
 ******************************************************************************/

#if defined(POC_ENDIAN_LITTLE)
#   define POC_ENDIAN POC_ENDIAN_LITTLE_ID
#   define POC_ENDIAN_STRING POC_ENDIAN_LITTLE_STRING
#endif

#if defined(POC_ENDIAN_BIG)
#   define POC_ENDIAN POC_ENDIAN_BIG_ID
#   define POC_ENDIAN_STRING POC_ENDIAN_BIG_STRING
#   error Untested. Remove error preprocessor directive after having ported and tested the code to the platform.
#endif


#endif /* !defined(POC_ENDIAN_DISABLE_AUTODETECT) && !defined(POC_DISABLE_AUTODETECT) */


/* Endianness unknown
 */

#if !defined(POC_ENDIAN)
#   define POC_ENDIAN_UNKNOWN POC_ENDIAN_UNKNOWN_ID
#   define POC_ENDIAN POC_ENDIAN_UNKNOWN_ID
#   error Unknown endian.
#endif

#if !defined(POC_ENDIAN_STRING)
#   define POC_ENDIAN_STRING POC_ENDIAN_UNKNOWN_STRING
#   error Unknown endian string.
#endif

/*******************************************************************************
 * Detect erroreneous declaration of little and big endianness at the same time
 ******************************************************************************/

/**
 * @todo TODO: How to handle bi-endian architectures?
 */

#if defined(POC_ENDIAN_LITTLE) && (defined(POC_ENDIAN_BIG) || defined(POC_ENDIAN_UNKNOWN))
#   error Little and big endianness mustn't be active at the same time.
#   error Endienness must be little or big.
#elif defined(POC_ENDIAN_BIG) && (defined(POC_ENDIAN_LITTLE) || defined(POC_ENDIAN_UNKNOWN))
#   error Little and big endianness mustn't be active at the same time.
#   error Endienness must be little or big.
#elif defined(POC_ENDIAN_UNKNOWN) && (defined(POC_ENDIAN_BIG) || defined(POC_ENDIAN_LITTLE))
#   error Little and big endianness mustn't be active at the same time.
#   error Endienness must be little or big.
#endif



#endif /* !defined(POC_ENDIAN_HEADER_DISABLE_DEF_UNDEF) */
