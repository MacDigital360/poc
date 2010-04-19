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
 * Undefines POC compiler macros potentially set by poc_compiler_def.h , see
 * poc_compiler.h and poc_compiler_def.h for more details.
 *
 * @attention This header doesn't have header guards to enable multiple inclusion.
 */

/* Only allow undef of POC compiler macros if poc_compiler.h hasn't been included in this 
 * compilation unit.
 */
#if !defined(POC_COMPILER_HEADER_DISABLE_DEF_UNDEF)

#undef POC_COMPILER_MSVC_VC6_STANDARDIZED_VERSION
#undef POC_COMPILER_MSVC_VC2003_STANDARDIZED_VERSION
#undef POC_COMPILER_MSVC_VC2005_STANDARDIZED_VERSION
#undef POC_COMPILER_MSVC_VC2008_STANDARDIZED_VERSION

#undef POC_COMPILER_GCC_GCC_2_9_STANDARDIZED_VERSION
#undef POC_COMPILER_GCC_GCC_3_0_STANDARDIZED_VERSION
#undef POC_COMPILER_GCC_GCC_3_1_STANDARDIZED_VERSION
#undef POC_COMPILER_GCC_GCC_3_2_STANDARDIZED_VERSION
#undef POC_COMPILER_GCC_GCC_3_3_STANDARDIZED_VERSION
#undef POC_COMPILER_GCC_GCC_3_4_STANDARDIZED_VERSION
#undef POC_COMPILER_GCC_GCC_4_0_STANDARDIZED_VERSION
#undef POC_COMPILER_GCC_GCC_4_1_STANDARDIZED_VERSION
#undef POC_COMPILER_GCC_GCC_4_2_STANDARDIZED_VERSION
#undef POC_COMPILER_GCC_GCC_4_3_STANDARDIZED_VERSION
#undef POC_COMPILER_GCC_GCC_4_4_STANDARDIZED_VERSION

#undef POC_COMPILER_ICC_ICC1000_STANDARDIZED_VERSION
#undef POC_COMPILER_ICC_ICC1100_STANDARDIZED_VERSION

#undef POC_COMPILER_LLVM_STANDARDIZED_VERSION
#undef POC_COMPILER_LLVM_CLANG_STANDARDIZED_VERSION


#undef POC_COMPILER
#undef POC_COMPILER_STRING
#undef POC_COMPILER_VERSION

#undef POC_COMPILER_UNKNOWN
#undef POC_COMPILER_UNKNOWN_ID
#undef POC_COMPILER_UNKNOWN_STRING
#undef POC_COMPILER_UNKNOWN_VERSION

#undef POC_COMPILER_GCC
#undef POC_COMPILER_GCC_ID
#undef POC_COMPILER_GCC_STRING
#undef POC_COMPILER_GCC_VERSION

#undef POC_COMPILER_MSVC
#undef POC_COMPILER_MSVC_ID
#undef POC_COMPILER_MSVC_STRING
#undef POC_COMPILER_MSVC_VERSION

#undef POC_COMPILER_ICC
#undef POC_COMPILER_ICC_ID
#undef POC_COMPILER_ICC_STRING
#undef POC_COMPILER_ICC_VERSION
#undef POC_COMPILER_ICC_HOST
#undef POC_COMPILER_ICC_HOST_STRING
#undef POC_COMPILER_ICC_HOST_VERSION
#undef POC_COMPILER_ICC_HOST_UNKNOWN
#undef POC_COMPILER_ICC_HOST_UNKNOWN_STRING
#undef POC_COMPILER_ICC_HOST_UNKNOWN_VERSION
#undef POC_COMPILER_ICC_HOST_GCC
#undef POC_COMPILER_ICC_HOST_GCC_STRING
#undef POC_COMPILER_ICC_HOST_GCC_VERSION
#undef POC_COMPILER_ICC_HOST_MSVC
#undef POC_COMPILER_ICC_HOST_MSVC_STRING
#undef POC_COMPILER_ICC_HOST_MSVC_VERSION

#undef POC_COMPILER_LLVM
#undef POC_COMPILER_LLVM_ID
#undef POC_COMPILER_LLVM_CLANG_ID
#undef POC_COMPILER_LLVM_STRING
#undef POC_COMPILER_LLVM_CLANG_STRING
#undef POC_COMPILER_LLVM_VERSION
#undef POC_COMPILER_LLVM_COMPATIBILITY_GCC
#undef POC_COMPILER_LLVM_COMPATIBILITY_GCC_STRING
#undef POC_COMPILER_LLVM_COMPATIBILITY_GCC_VERSION
#undef POC_COMPILER_LLVM_FRONTEND
#undef POC_COMPILER_LLVM_FRONTEND_STRING
#undef POC_COMPILER_LLVM_FRONTEND_VERSION
#undef POC_COMPILER_LLVM_FRONTEND_CLANG
#undef POC_COMPILER_LLVM_FRONTEND_CLANG_STRING
#undef POC_COMPILER_LLVM_FRONTEND_CLANG_VERSION
#undef POC_COMPILER_LLVM_FRONTEND_GCC
#undef POC_COMPILER_LLVM_FRONTEND_GCC_STRING
#undef POC_COMPILER_LLVM_FRONTEND_GCC_VERSION
#undef POC_COMPILER_LLVM_FRONTEND_UNKNOWN
#undef POC_COMPILER_LLVM_FRONTEND_UNKNOWN_STRING
#undef POC_COMPILER_LLVM_FRONTEND_UNKNOWN_VERSION


#endif /* !defined(POC_COMPILER_HEADER_DISABLE_DEF_UNDEF) */
