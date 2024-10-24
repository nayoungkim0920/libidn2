#include "config.h"
/* GLIB - Library of useful routines for C programming
 * Copyright (C) 2006-2019 Free Software Foundation, Inc.
 *
 * This file is not part of the GNU gettext program, but is used with
 * GNU gettext.
 *
 * The original copyright notice is as follows:
 */

/* GLIB - Library of useful routines for C programming
 * Copyright (C) 1995-1997  Peter Mattis, Spencer Kimball and Josh MacDonald
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the
 * Free Software Foundation, Inc., 59 Temple Place - Suite 330,
 * Boston, MA 02111-1307, USA.
 */

/*
 * Modified by the GLib Team and others 1997-2000.  See the AUTHORS
 * file for a list of people on the GLib Team.  See the ChangeLog
 * files for a list of changes.  These files are distributed with
 * GLib at ftp://ftp.gtk.org/pub/gtk/. 
 */

/*
 * Modified by Bruno Haible for use as a gnulib module.
 */

#ifndef __G_STRFUNCS_H__
#define __G_STRFUNCS_H__

#include <stdarg.h>
#include <glib/gtypes.h>

G_BEGIN_DECLS

/* Functions like the ones in <ctype.h> that are not affected by locale. */
typedef enum {
  G_ASCII_ALNUM  = 1 << 0,
  G_ASCII_ALPHA  = 1 << 1,
  G_ASCII_CNTRL  = 1 << 2,
  G_ASCII_DIGIT  = 1 << 3,
  G_ASCII_GRAPH  = 1 << 4,
  G_ASCII_LOWER  = 1 << 5,
  G_ASCII_PRINT  = 1 << 6,
  G_ASCII_PUNCT  = 1 << 7,
  G_ASCII_SPACE  = 1 << 8,
  G_ASCII_UPPER  = 1 << 9,
  G_ASCII_XDIGIT = 1 << 10
} GAsciiType;

GLIB_VAR const guint16 * const g_ascii_table;

#define g_ascii_isalnum(c) \
  ((g_ascii_table[(guchar) (c)] & G_ASCII_ALNUM) != 0)

#define g_ascii_isalpha(c) \
  ((g_ascii_table[(guchar) (c)] & G_ASCII_ALPHA) != 0)

#define g_ascii_iscntrl(c) \
  ((g_ascii_table[(guchar) (c)] & G_ASCII_CNTRL) != 0)

#define g_ascii_isdigit(c) \
  ((g_ascii_table[(guchar) (c)] & G_ASCII_DIGIT) != 0)

#define g_ascii_isgraph(c) \
  ((g_ascii_table[(guchar) (c)] & G_ASCII_GRAPH) != 0)

#define g_ascii_islower(c) \
  ((g_ascii_table[(guchar) (c)] & G_ASCII_LOWER) != 0)

#define g_ascii_isprint(c) \
  ((g_ascii_table[(guchar) (c)] & G_ASCII_PRINT) != 0)

#define g_ascii_ispunct(c) \
  ((g_ascii_table[(guchar) (c)] & G_ASCII_PUNCT) != 0)

#define g_ascii_isspace(c) \
  ((g_ascii_table[(guchar) (c)] & G_ASCII_SPACE) != 0)

#define g_ascii_isupper(c) \
  ((g_ascii_table[(guchar) (c)] & G_ASCII_UPPER) != 0)

#define g_ascii_isxdigit(c) \
  ((g_ascii_table[(guchar) (c)] & G_ASCII_XDIGIT) != 0)

#if 0
gchar                 g_ascii_tolower  (gchar        c) G_GNUC_CONST;
#endif
gchar                 g_ascii_toupper  (gchar        c) G_GNUC_CONST;

#if 0
gint                  g_ascii_digit_value  (gchar    c) G_GNUC_CONST;
gint                  g_ascii_xdigit_value (gchar    c) G_GNUC_CONST;

/* String utility functions that modify a string argument or
 * return a constant string that must not be freed.
 */
#define	 G_STR_DELIMITERS	"_-|> <."
gchar*	              g_strdelimit     (gchar	     *string,
					const gchar  *delimiters,
					gchar	      new_delimiter);
gchar*	              g_strcanon       (gchar        *string,
					const gchar  *valid_chars,
					gchar         substitutor);
G_CONST_RETURN gchar* g_strerror       (gint	      errnum) G_GNUC_CONST;
G_CONST_RETURN gchar* g_strsignal      (gint	      signum) G_GNUC_CONST;
gchar*	              g_strreverse     (gchar	     *string);
gsize	              g_strlcpy	       (gchar	     *dest,
					const gchar  *src,
					gsize         dest_size);
gsize	              g_strlcat        (gchar	     *dest,
					const gchar  *src,
					gsize         dest_size);
#endif
gchar *               g_strstr_len     (const gchar  *haystack,
					gssize        haystack_len,
					const gchar  *needle);
#if 0
gchar *               g_strrstr        (const gchar  *haystack,
					const gchar  *needle);
gchar *               g_strrstr_len    (const gchar  *haystack,
					gssize        haystack_len,
					const gchar  *needle);

gboolean              g_str_has_suffix (const gchar  *str,
					const gchar  *suffix);
gboolean              g_str_has_prefix (const gchar  *str,
					const gchar  *prefix);

/* String to/from double conversion functions */

gdouble	              g_strtod         (const gchar  *nptr,
					gchar	    **endptr);
gdouble	              g_ascii_strtod   (const gchar  *nptr,
					gchar	    **endptr);
guint64		      g_ascii_strtoull (const gchar *nptr,
					gchar      **endptr,
					guint        base);
gint64		      g_ascii_strtoll  (const gchar *nptr,
					gchar      **endptr,
					guint        base);
#endif
/* 29 bytes should enough for all possible values that
 * g_ascii_dtostr can produce.
 * Then add 10 for good measure */
#define G_ASCII_DTOSTR_BUF_SIZE (29 + 10)
gchar *               g_ascii_dtostr   (gchar        *buffer,
					gint          buf_len,
					gdouble       d);
gchar *               g_ascii_formatd  (gchar        *buffer,
					gint          buf_len,
					const gchar  *format,
					gdouble       d);

#if 0
/* removes leading spaces */
gchar*                g_strchug        (gchar        *string);
/* removes trailing spaces */
gchar*                g_strchomp       (gchar        *string);
/* removes leading & trailing spaces */
#define g_strstrip( string )	g_strchomp (g_strchug (string))
#endif

gint                  g_ascii_strcasecmp  (const gchar *s1,
					   const gchar *s2);
#if 0
gint                  g_ascii_strncasecmp (const gchar *s1,
					   const gchar *s2,
					   gsize        n);
gchar*                g_ascii_strdown     (const gchar *str,
					   gssize       len) G_GNUC_MALLOC;
#endif
gchar*                g_ascii_strup       (const gchar *str,
					   gssize       len) G_GNUC_MALLOC;

#if 0

#ifndef G_DISABLE_DEPRECATED

/* The following four functions are deprecated and will be removed in
 * the next major release. They use the locale-specific tolower and
 * toupper, which is almost never the right thing.
 */

gint	              g_strcasecmp     (const gchar *s1,
					const gchar *s2);
gint	              g_strncasecmp    (const gchar *s1,
					const gchar *s2,
					guint        n);
gchar*	              g_strdown	       (gchar	     *string);
gchar*	              g_strup	       (gchar	     *string);

#endif /* G_DISABLE_DEPRECATED */

#endif

/* String utility functions that return a newly allocated string which
 * ought to be freed with g_free from the caller at some point.
 */
gchar*	              g_strdup	       (const gchar *str) G_GNUC_MALLOC;
gchar*	              g_strdup_printf  (const gchar *format,
					...) G_GNUC_PRINTF (1, 2) G_GNUC_MALLOC;
#if 0
gchar*	              g_strdup_vprintf (const gchar *format,
					va_list      args) G_GNUC_MALLOC;
#endif
gchar*	              g_strndup	       (const gchar *str,
					gsize        n) G_GNUC_MALLOC;  
#if 0
gchar*	              g_strnfill       (gsize        length,  
					gchar        fill_char) G_GNUC_MALLOC;
#endif
gchar*	              g_strconcat      (const gchar *string1,
					...) G_GNUC_MALLOC G_GNUC_NULL_TERMINATED;
#if 0
gchar*                g_strjoin	       (const gchar  *separator,
					...) G_GNUC_MALLOC G_GNUC_NULL_TERMINATED;

/* Make a copy of a string interpreting C string -style escape
 * sequences. Inverse of g_strescape. The recognized sequences are \b
 * \f \n \r \t \\ \" and the octal format.
 */
gchar*                g_strcompress    (const gchar *source) G_GNUC_MALLOC;

/* Copy a string escaping nonprintable characters like in C strings.
 * Inverse of g_strcompress. The exceptions parameter, if non-NULL, points
 * to a string containing characters that are not to be escaped.
 *
 * Deprecated API: gchar* g_strescape (const gchar *source);
 * Luckily this function wasn't used much, using NULL as second parameter
 * provides mostly identical semantics.
 */
gchar*                g_strescape      (const gchar *source,
					const gchar *exceptions) G_GNUC_MALLOC;

gpointer              g_memdup	       (gconstpointer mem,
					guint	       byte_size) G_GNUC_MALLOC;

/* NULL terminated string arrays.
 * g_strsplit(), g_strsplit_set() split up string into max_tokens tokens
 * at delim and return a newly allocated string array.
 * g_strjoinv() concatenates all of str_array's strings, sliding in an
 * optional separator, the returned string is newly allocated.
 * g_strfreev() frees the array itself and all of its strings.
 * g_strdupv() copies a NULL-terminated array of strings
 * g_strv_length() returns the length of a NULL-terminated array of strings
 */
gchar**	              g_strsplit       (const gchar  *string,
					const gchar  *delimiter,
					gint          max_tokens) G_GNUC_MALLOC;
gchar **	      g_strsplit_set   (const gchar *string,
					const gchar *delimiters,
					gint         max_tokens) G_GNUC_MALLOC;
gchar*                g_strjoinv       (const gchar  *separator,
					gchar       **str_array) G_GNUC_MALLOC;
void                  g_strfreev       (gchar       **str_array);
gchar**               g_strdupv        (gchar       **str_array) G_GNUC_MALLOC;
guint                 g_strv_length    (gchar       **str_array);

gchar*                g_stpcpy         (gchar        *dest,
                                        const char   *src);

G_CONST_RETURN gchar *g_strip_context  (const gchar *msgid, 
					const gchar *msgval);

#endif

G_END_DECLS

#endif /* __G_STRFUNCS_H__ */
