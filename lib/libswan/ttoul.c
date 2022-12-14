/*
 * convert from text form of unsigned long to binary
 *
 * Copyright (C) 2000  Henry Spencer.
 *
 * This library is free software; you can redistribute it and/or modify it
 * under the terms of the GNU Library General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or (at your
 * option) any later version.  See <https://www.gnu.org/licenses/lgpl-2.1.txt>.
 *
 * This library is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY
 * or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU Library General Public
 * License for more details.
 */

#include <limits.h>		/* for ULONG_MAX */
#include <string.h>

#include "ttodata.h"

/*
 * ttoul - convert text substring to unsigned long number
 *
 * NULL for success, else static string literal
 */
static err_t ttoul(const char *src, size_t srclen,
		   int base,		/* 0 means figure it out */
		   unsigned long *resultp)
{
	const char *stop;
	static const char hex[] = "0123456789abcdef";
	static const char uchex[] = "0123456789ABCDEF";
	int d;
	char c;
	const char *p;
	unsigned long r;
	unsigned long rlimit;
	int dlimit;

	if (srclen == 0)
		return "empty string";

	if (base == 0) {
		if (srclen > 2 && *src == '0' &&
			(*(src + 1) == 'x' || *(src + 1) == 'X'))
			return ttoul(src + 2, srclen - 2, 16, resultp);

		if (srclen > 1 && *src == '0')
			return ttoul(src + 1, srclen - 1, 8, resultp);

		return ttoul(src, srclen, 10, resultp);
	}
	if (base != 8 && base != 10 && base != 16)
		return "unsupported number base";

	r = 0;
	stop = src + srclen;
	if (base == 16) {
		while (src < stop) {
			c = *src++;
			p = strchr(hex, c);
			if (p != NULL) {
				d = p - hex;
			} else {
				p = strchr(uchex, c);
				if (p == NULL)
					return "non-hex digit in hex number";

				d = p - uchex;
			}
			r = (r << 4) | d;
		}
		/* defer length check to catch invalid digits first */
		if (srclen > sizeof(unsigned long) * 2)
			return "hex number too long";
	} else {
		rlimit = ULONG_MAX / base;
		dlimit = (int)(ULONG_MAX - rlimit * base);
		while (src < stop) {
			c = *src++;
			d = c - '0';
			if (d < 0 || d >= base)
				return "non-digit in number";

			if (r > rlimit || (r == rlimit && d > dlimit))
				return "unsigned-long overflow";

			r = r * base + d;
		}
	}

	*resultp = r;
	return NULL;
}

/* NULL for success, else string literal */
err_t ttoulb(const char *src,
	     size_t srclen,	/* 0 means strlen(src) */
	     int base,		/* 0 means figure it out */
	     unsigned long upb,	/* upper bound */
	     unsigned long *resultp)
{
	if (srclen == 0)
		srclen = strlen(src);

	const char *ugh = ttoul(src, srclen, base, resultp);

	return ugh != NULL ? ugh : *resultp > upb ? "too large" : NULL;
}
