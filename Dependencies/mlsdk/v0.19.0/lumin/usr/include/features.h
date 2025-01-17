/*
 * Copyright (C) 2008 The Android Open Source Project
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *  * Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 *  * Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in
 *    the documentation and/or other materials provided with the
 *    distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS
 * FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE
 * COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,
 * BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS
 * OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED
 * AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
 * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT
 * OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
 * SUCH DAMAGE.
 */
#ifndef _FEATURES_H_
#define _FEATURES_H_

#include <sys/cdefs.h>

/* certain Linux-specific programs expect a <features.h> header file
 * that defines various features macros
 */

/* we do include a number of BSD extensions */
#define  _BSD_SOURCE  1

/* we do include a number of GNU extensions */
#define  _GNU_SOURCE  1

/* C95 support */
#undef __USE_ISOC95
#if defined __STDC_VERSION__ && __STDC_VERSION__ >= 199409L
# define __USE_ISOC95   1
#endif

/* C99 support */
#undef __USE_ISOC99
#if defined __STDC_VERSION__ && __STDC_VERSION__ >= 199901L
# define __USE_ISOC99   1
#endif

/* Posix support */
#define  __USE_POSIX   1
#define  __USE_POSIX2  1
#define  __USE_XPG     1

#endif /* _FEATURES_H_ */
