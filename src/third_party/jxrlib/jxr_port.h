/* PShare - building jxrlib (third_party/jxrlib) unchanged on the console, pshared and the PC.
 * Copyright (C) 2026 PShare contributors
 * SPDX-License-Identifier: GPL-3.0-or-later
 *
 * Each wrapper in this folder includes this, then one jxrlib source file, so
 * jxrlib's files stay as published and its macros stay in their own unit. */
#ifndef PSHARE_JXR_PORT_H
#define PSHARE_JXR_PORT_H

#define __ANSI__ 1
#define DISABLE_PERF_MEASUREMENT 1

#include <stddef.h>

/* strcodec.c defines it off Windows; segdec.c only forgets to declare it. */
unsigned int _byteswap_ulong(unsigned int bits);

/* Wide strings appear only in metadata PShare never writes: no libc wcslen needed. */
static inline size_t pshare_jxr_wcslen(const void *text)
{
    const unsigned short *s = (const unsigned short *)text;
    size_t n = 0;
    while (s[n] != 0)
        ++n;
    return n;
}
#define wcslen(s) pshare_jxr_wcslen(s)

#endif
