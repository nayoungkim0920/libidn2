#ifndef _LIBTEXTSTYLE_CONFIG_H
#define _LIBTEXTSTYLE_CONFIG_H 1
 
/* libtextstyle-config.h. Generated automatically at end of configure. */
/* config.h.  Generated from config.h.in by configure.  */
/* config.h.in.  Generated from configure.ac by autoheader.  */

/* Witness that <config.h> has been included.  */
#ifndef LIBTEXTSTYLE__GL_CONFIG_H_INCLUDED
#define LIBTEXTSTYLE__GL_CONFIG_H_INCLUDED 1
#endif


/* Define to the number of bits in type 'ptrdiff_t'. */
/* #undef BITSIZEOF_PTRDIFF_T */

/* Define to the number of bits in type 'sig_atomic_t'. */
/* #undef BITSIZEOF_SIG_ATOMIC_T */

/* Define to the number of bits in type 'size_t'. */
/* #undef BITSIZEOF_SIZE_T */

/* Define to the number of bits in type 'wchar_t'. */
/* #undef BITSIZEOF_WCHAR_T */

/* Define to the number of bits in type 'wint_t'. */
/* #undef BITSIZEOF_WINT_T */

/* Define to 1 if using 'alloca.c'. */
/* #undef C_ALLOCA */

/* Define to nothing for non-Windows platforms */
#ifndef LIBTEXTSTYLE_DLL_VARIABLE
#define LIBTEXTSTYLE_DLL_VARIABLE __declspec(dllexport)
#endif

/* Define to 1 if // is a file system root distinct from /. */
#ifndef LIBTEXTSTYLE_DOUBLE_SLASH_IS_DISTINCT_ROOT
#define LIBTEXTSTYLE_DOUBLE_SLASH_IS_DISTINCT_ROOT 1
#endif

/* Define to 1 if translation of program messages to the user's native
   language is requested. */
/* #undef ENABLE_NLS */

/* Define this to 1 if F_DUPFD behavior does not match POSIX */
/* #undef FCNTL_DUPFD_BUGGY */

/* Define to a C preprocessor expression that evaluates to 1 or 0, depending
   whether the gnulib module close shall be considered present. */
#ifndef LIBTEXTSTYLE_GNULIB_CLOSE
#define LIBTEXTSTYLE_GNULIB_CLOSE 1
#endif

/* Define to a C preprocessor expression that evaluates to 1 or 0, depending
   whether the gnulib module fscanf shall be considered present. */
#ifndef LIBTEXTSTYLE_GNULIB_FSCANF
#define LIBTEXTSTYLE_GNULIB_FSCANF 1
#endif

/* Define to a C preprocessor expression that evaluates to 1 or 0, depending
   whether the gnulib module fstat shall be considered present. */
#ifndef LIBTEXTSTYLE_GNULIB_FSTAT
#define LIBTEXTSTYLE_GNULIB_FSTAT 1
#endif

/* Define to a C preprocessor expression that evaluates to 1 or 0, depending
   whether the gnulib module msvc-nothrow shall be considered present. */
#ifndef LIBTEXTSTYLE_GNULIB_MSVC_NOTHROW
#define LIBTEXTSTYLE_GNULIB_MSVC_NOTHROW 1
#endif

/* Define to 1 if printf and friends should be labeled with attribute
   "__gnu_printf__" instead of "__printf__" */
#ifndef LIBTEXTSTYLE_GNULIB_PRINTF_ATTRIBUTE_FLAVOR_GNU
#define LIBTEXTSTYLE_GNULIB_PRINTF_ATTRIBUTE_FLAVOR_GNU 1
#endif

/* Define if safe-write module is used */
#ifndef LIBTEXTSTYLE_GNULIB_SAFE_WRITE
#define LIBTEXTSTYLE_GNULIB_SAFE_WRITE 1
#endif

/* Define to a C preprocessor expression that evaluates to 1 or 0, depending
   whether the gnulib module scanf shall be considered present. */
#ifndef LIBTEXTSTYLE_GNULIB_SCANF
#define LIBTEXTSTYLE_GNULIB_SCANF 1
#endif

/* Define to a C preprocessor expression that evaluates to 1 or 0, depending
   whether the gnulib module stat shall be considered present. */
#ifndef LIBTEXTSTYLE_GNULIB_STAT
#define LIBTEXTSTYLE_GNULIB_STAT 1
#endif

/* Define to a C preprocessor expression that evaluates to 1 or 0, depending
   whether the gnulib module strerror shall be considered present. */
#ifndef LIBTEXTSTYLE_GNULIB_STRERROR
#define LIBTEXTSTYLE_GNULIB_STRERROR 1
#endif

/* Define to 1 when the gnulib module cloexec should be tested. */
#ifndef LIBTEXTSTYLE_GNULIB_TEST_CLOEXEC
#define LIBTEXTSTYLE_GNULIB_TEST_CLOEXEC 1
#endif

/* Define to 1 when the gnulib module close should be tested. */
#ifndef LIBTEXTSTYLE_GNULIB_TEST_CLOSE
#define LIBTEXTSTYLE_GNULIB_TEST_CLOSE 1
#endif

/* Define to 1 when the gnulib module dup2 should be tested. */
#ifndef LIBTEXTSTYLE_GNULIB_TEST_DUP2
#define LIBTEXTSTYLE_GNULIB_TEST_DUP2 1
#endif

/* Define to 1 when the gnulib module fcntl should be tested. */
#ifndef LIBTEXTSTYLE_GNULIB_TEST_FCNTL
#define LIBTEXTSTYLE_GNULIB_TEST_FCNTL 1
#endif

/* Define to 1 when the gnulib module fgetc should be tested. */
#ifndef LIBTEXTSTYLE_GNULIB_TEST_FGETC
#define LIBTEXTSTYLE_GNULIB_TEST_FGETC 1
#endif

/* Define to 1 when the gnulib module fgets should be tested. */
#ifndef LIBTEXTSTYLE_GNULIB_TEST_FGETS
#define LIBTEXTSTYLE_GNULIB_TEST_FGETS 1
#endif

/* Define to 1 when the gnulib module fprintf should be tested. */
#ifndef LIBTEXTSTYLE_GNULIB_TEST_FPRINTF
#define LIBTEXTSTYLE_GNULIB_TEST_FPRINTF 1
#endif

/* Define to 1 when the gnulib module fputc should be tested. */
#ifndef LIBTEXTSTYLE_GNULIB_TEST_FPUTC
#define LIBTEXTSTYLE_GNULIB_TEST_FPUTC 1
#endif

/* Define to 1 when the gnulib module fputs should be tested. */
#ifndef LIBTEXTSTYLE_GNULIB_TEST_FPUTS
#define LIBTEXTSTYLE_GNULIB_TEST_FPUTS 1
#endif

/* Define to 1 when the gnulib module fread should be tested. */
#ifndef LIBTEXTSTYLE_GNULIB_TEST_FREAD
#define LIBTEXTSTYLE_GNULIB_TEST_FREAD 1
#endif

/* Define to 1 when the gnulib module fscanf should be tested. */
#ifndef LIBTEXTSTYLE_GNULIB_TEST_FSCANF
#define LIBTEXTSTYLE_GNULIB_TEST_FSCANF 1
#endif

/* Define to 1 when the gnulib module fstat should be tested. */
#ifndef LIBTEXTSTYLE_GNULIB_TEST_FSTAT
#define LIBTEXTSTYLE_GNULIB_TEST_FSTAT 1
#endif

/* Define to 1 when the gnulib module fwrite should be tested. */
#ifndef LIBTEXTSTYLE_GNULIB_TEST_FWRITE
#define LIBTEXTSTYLE_GNULIB_TEST_FWRITE 1
#endif

/* Define to 1 when the gnulib module getc should be tested. */
#ifndef LIBTEXTSTYLE_GNULIB_TEST_GETC
#define LIBTEXTSTYLE_GNULIB_TEST_GETC 1
#endif

/* Define to 1 when the gnulib module getchar should be tested. */
#ifndef LIBTEXTSTYLE_GNULIB_TEST_GETCHAR
#define LIBTEXTSTYLE_GNULIB_TEST_GETCHAR 1
#endif

/* Define to 1 when the gnulib module getdtablesize should be tested. */
#ifndef LIBTEXTSTYLE_GNULIB_TEST_GETDTABLESIZE
#define LIBTEXTSTYLE_GNULIB_TEST_GETDTABLESIZE 1
#endif

/* Define to 1 when the gnulib module getprogname should be tested. */
#ifndef LIBTEXTSTYLE_GNULIB_TEST_GETPROGNAME
#define LIBTEXTSTYLE_GNULIB_TEST_GETPROGNAME 1
#endif

/* Define to 1 when the gnulib module open should be tested. */
#ifndef LIBTEXTSTYLE_GNULIB_TEST_OPEN
#define LIBTEXTSTYLE_GNULIB_TEST_OPEN 1
#endif

/* Define to 1 when the gnulib module printf should be tested. */
#ifndef LIBTEXTSTYLE_GNULIB_TEST_PRINTF
#define LIBTEXTSTYLE_GNULIB_TEST_PRINTF 1
#endif

/* Define to 1 when the gnulib module putc should be tested. */
#ifndef LIBTEXTSTYLE_GNULIB_TEST_PUTC
#define LIBTEXTSTYLE_GNULIB_TEST_PUTC 1
#endif

/* Define to 1 when the gnulib module putchar should be tested. */
#ifndef LIBTEXTSTYLE_GNULIB_TEST_PUTCHAR
#define LIBTEXTSTYLE_GNULIB_TEST_PUTCHAR 1
#endif

/* Define to 1 when the gnulib module puts should be tested. */
#ifndef LIBTEXTSTYLE_GNULIB_TEST_PUTS
#define LIBTEXTSTYLE_GNULIB_TEST_PUTS 1
#endif

/* Define to 1 when the gnulib module scanf should be tested. */
#ifndef LIBTEXTSTYLE_GNULIB_TEST_SCANF
#define LIBTEXTSTYLE_GNULIB_TEST_SCANF 1
#endif

/* Define to 1 when the gnulib module stat should be tested. */
#ifndef LIBTEXTSTYLE_GNULIB_TEST_STAT
#define LIBTEXTSTYLE_GNULIB_TEST_STAT 1
#endif

/* Define to 1 when the gnulib module strerror should be tested. */
#ifndef LIBTEXTSTYLE_GNULIB_TEST_STRERROR
#define LIBTEXTSTYLE_GNULIB_TEST_STRERROR 1
#endif

/* Define to 1 when the gnulib module vfprintf should be tested. */
#ifndef LIBTEXTSTYLE_GNULIB_TEST_VFPRINTF
#define LIBTEXTSTYLE_GNULIB_TEST_VFPRINTF 1
#endif

/* Define to 1 when the gnulib module vprintf should be tested. */
#ifndef LIBTEXTSTYLE_GNULIB_TEST_VPRINTF
#define LIBTEXTSTYLE_GNULIB_TEST_VPRINTF 1
#endif

/* Define if tputs module is used */
#ifndef LIBTEXTSTYLE_GNULIB_TPUTS
#define LIBTEXTSTYLE_GNULIB_TPUTS 1
#endif

/* Define for gnulib xalloc */
#ifndef LIBTEXTSTYLE_GNULIB_XALLOC
#define LIBTEXTSTYLE_GNULIB_XALLOC 1
#endif

/* Define if xalloc_die is available */
#ifndef LIBTEXTSTYLE_GNULIB_XALLOC_DIE
#define LIBTEXTSTYLE_GNULIB_XALLOC_DIE 1
#endif

/* Define if xstrdup module is used */
#ifndef LIBTEXTSTYLE_GNULIB_XSTRDUP
#define LIBTEXTSTYLE_GNULIB_XSTRDUP 1
#endif

/* Define to 1 if you have 'alloca' after including <alloca.h>, a header that
   may be supplied by this distribution. */
#ifndef LIBTEXTSTYLE_HAVE_ALLOCA
#define LIBTEXTSTYLE_HAVE_ALLOCA 1
#endif

/* Define to 1 if <alloca.h> works. */
/* #undef HAVE_ALLOCA_H */

/* Define to 1 if you have the 'argz_add' function. */
/* #undef HAVE_ARGZ_ADD */

/* Define to 1 if you have the 'argz_append' function. */
/* #undef HAVE_ARGZ_APPEND */

/* Define to 1 if you have the 'argz_count' function. */
/* #undef HAVE_ARGZ_COUNT */

/* Define to 1 if you have the 'argz_create_sep' function. */
/* #undef HAVE_ARGZ_CREATE_SEP */

/* Define to 1 if you have the <argz.h> header file. */
/* #undef HAVE_ARGZ_H */

/* Define to 1 if you have the 'argz_insert' function. */
/* #undef HAVE_ARGZ_INSERT */

/* Define to 1 if you have the 'argz_next' function. */
/* #undef HAVE_ARGZ_NEXT */

/* Define to 1 if you have the 'argz_stringify' function. */
/* #undef HAVE_ARGZ_STRINGIFY */

/* Define to 1 if C11 is supported. */
#ifndef LIBTEXTSTYLE_HAVE_C11
#define LIBTEXTSTYLE_HAVE_C11 1
#endif

/* Define to 1 if you have the Mac OS X function
   CFLocaleCopyPreferredLanguages in the CoreFoundation framework. */
/* #undef HAVE_CFLOCALECOPYPREFERREDLANGUAGES */

/* Define to 1 if you have the Mac OS X function CFPreferencesCopyAppValue in
   the CoreFoundation framework. */
/* #undef HAVE_CFPREFERENCESCOPYAPPVALUE */

/* Define to 1 if you have the 'closedir' function. */
#ifndef LIBTEXTSTYLE_HAVE_CLOSEDIR
#define LIBTEXTSTYLE_HAVE_CLOSEDIR 1
#endif

/* Define to 1 if C++17 is supported. */
#ifndef LIBTEXTSTYLE_HAVE_CPP17
#define LIBTEXTSTYLE_HAVE_CPP17 1
#endif

/* Define to 1 if bool, true and false work as per C2023. */
/* #undef HAVE_C_BOOL */

/* Define to 1 if the static_assert keyword works. */
/* #undef HAVE_C_STATIC_ASSERT */

/* Define to 1 if C supports variable-length arrays. */
#ifndef LIBTEXTSTYLE_HAVE_C_VARARRAYS
#define LIBTEXTSTYLE_HAVE_C_VARARRAYS 1
#endif

/* Define if the GNU dcgettext() function is already present or preinstalled.
   */
/* #undef HAVE_DCGETTEXT */

/* Define to 1 if you have the declaration of 'cygwin_conv_path', and to 0 if
   you don't. */
#ifndef LIBTEXTSTYLE_HAVE_DECL_CYGWIN_CONV_PATH
#define LIBTEXTSTYLE_HAVE_DECL_CYGWIN_CONV_PATH 0
#endif

/* Define to 1 if you have the declaration of 'ecvt', and to 0 if you don't.
   */
#ifndef LIBTEXTSTYLE_HAVE_DECL_ECVT
#define LIBTEXTSTYLE_HAVE_DECL_ECVT 1
#endif

/* Define to 1 if you have the declaration of 'execvpe', and to 0 if you
   don't. */
#ifndef LIBTEXTSTYLE_HAVE_DECL_EXECVPE
#define LIBTEXTSTYLE_HAVE_DECL_EXECVPE 1
#endif

/* Define to 1 if you have the declaration of 'fcloseall', and to 0 if you
   don't. */
#ifndef LIBTEXTSTYLE_HAVE_DECL_FCLOSEALL
#define LIBTEXTSTYLE_HAVE_DECL_FCLOSEALL 1
#endif

/* Define to 1 if you have the declaration of 'fcvt', and to 0 if you don't.
   */
#ifndef LIBTEXTSTYLE_HAVE_DECL_FCVT
#define LIBTEXTSTYLE_HAVE_DECL_FCVT 1
#endif

/* Define to 1 if you have the declaration of 'gcvt', and to 0 if you don't.
   */
#ifndef LIBTEXTSTYLE_HAVE_DECL_GCVT
#define LIBTEXTSTYLE_HAVE_DECL_GCVT 1
#endif

/* Define to 1 if you have the declaration of 'getdtablesize', and to 0 if you
   don't. */
#ifndef LIBTEXTSTYLE_HAVE_DECL_GETDTABLESIZE
#define LIBTEXTSTYLE_HAVE_DECL_GETDTABLESIZE 0
#endif

/* Define to 1 if you have the declaration of 'getw', and to 0 if you don't.
   */
#ifndef LIBTEXTSTYLE_HAVE_DECL_GETW
#define LIBTEXTSTYLE_HAVE_DECL_GETW 1
#endif

/* Define to 1 if you have the declaration of 'program_invocation_name', and
   to 0 if you don't. */
#ifndef LIBTEXTSTYLE_HAVE_DECL_PROGRAM_INVOCATION_NAME
#define LIBTEXTSTYLE_HAVE_DECL_PROGRAM_INVOCATION_NAME 0
#endif

/* Define to 1 if you have the declaration of 'program_invocation_short_name',
   and to 0 if you don't. */
#ifndef LIBTEXTSTYLE_HAVE_DECL_PROGRAM_INVOCATION_SHORT_NAME
#define LIBTEXTSTYLE_HAVE_DECL_PROGRAM_INVOCATION_SHORT_NAME 0
#endif

/* Define to 1 if you have the declaration of 'putw', and to 0 if you don't.
   */
#ifndef LIBTEXTSTYLE_HAVE_DECL_PUTW
#define LIBTEXTSTYLE_HAVE_DECL_PUTW 1
#endif

/* Define to 1 if you have the declaration of 'strerror_r', and to 0 if you
   don't. */
#ifndef LIBTEXTSTYLE_HAVE_DECL_STRERROR_R
#define LIBTEXTSTYLE_HAVE_DECL_STRERROR_R 0
#endif

/* Define to 1 if you have the declaration of '__argv', and to 0 if you don't.
   */
#ifndef LIBTEXTSTYLE_HAVE_DECL___ARGV
#define LIBTEXTSTYLE_HAVE_DECL___ARGV 1
#endif

/* Define to 1 if you have the <dirent.h> header file. */
#ifndef LIBTEXTSTYLE_HAVE_DIRENT_H
#define LIBTEXTSTYLE_HAVE_DIRENT_H 1
#endif

/* Define if you have the GNU dld library. */
/* #undef HAVE_DLD */

/* Define to 1 if you have the <dld.h> header file. */
/* #undef HAVE_DLD_H */

/* Define to 1 if you have the 'dlerror' function. */
/* #undef HAVE_DLERROR */

/* Define to 1 if you have the <dlfcn.h> header file. */
/* #undef HAVE_DLFCN_H */

/* Define to 1 if you have the <dl.h> header file. */
/* #undef HAVE_DL_H */

/* Define if you have the _dyld_func_lookup function. */
/* #undef HAVE_DYLD */

/* Define to 1 if you have the `error' function. */
/* #undef HAVE_ERROR */

/* Define to 1 if you have the <error.h> header file. */
#ifndef LIBTEXTSTYLE_HAVE_ERROR_H
#define LIBTEXTSTYLE_HAVE_ERROR_H 1
#endif

/* Define to 1 if the system has the type 'error_t'. */
/* #undef HAVE_ERROR_T */

/* Define to 1 if you have the 'fchdir' function. */
/* #undef HAVE_FCHDIR */

/* Define to 1 if you have the 'fcntl' function. */
/* #undef HAVE_FCNTL */

/* Define to 1 if you have the 'getdtablesize' function. */
/* #undef HAVE_GETDTABLESIZE */

/* Define to 1 if you have the 'getexecname' function. */
/* #undef HAVE_GETEXECNAME */

/* Define to 1 if you have the `getprogname' function. */
/* #undef HAVE_GETPROGNAME */

/* Define if the GNU gettext() function is already present or preinstalled. */
/* #undef HAVE_GETTEXT */

/* Define if you have the iconv() function and it works. */
#ifndef LIBTEXTSTYLE_HAVE_ICONV
#define LIBTEXTSTYLE_HAVE_ICONV 1
#endif

/* Define to 1 if you have the <inttypes.h> header file. */
#ifndef LIBTEXTSTYLE_HAVE_INTTYPES_H
#define LIBTEXTSTYLE_HAVE_INTTYPES_H 1
#endif

/* Define if you have <langinfo.h> and nl_langinfo(CODESET). */
/* #undef HAVE_LANGINFO_CODESET */

/* Define if you have the libdl library or equivalent. */
/* #undef HAVE_LIBDL */

/* Define if libdlloader will be built on this platform */
#ifndef LIBTEXTSTYLE_HAVE_LIBDLLOADER
#define LIBTEXTSTYLE_HAVE_LIBDLLOADER 1
#endif

/* Define to 1 if you have the <limits.h> header file. */
#ifndef LIBTEXTSTYLE_HAVE_LIMITS_H
#define LIBTEXTSTYLE_HAVE_LIMITS_H 1
#endif

/* Define to 1 if the system has the type 'long long int'. */
#ifndef LIBTEXTSTYLE_HAVE_LONG_LONG_INT
#define LIBTEXTSTYLE_HAVE_LONG_LONG_INT 1
#endif

/* Define to 1 if you have the 'lstat' function. */
/* #undef HAVE_LSTAT */

/* Define this if a modern libltdl is already installed */
/* #undef HAVE_LTDL */

/* Define to 1 if you have the <mach-o/dyld.h> header file. */
/* #undef HAVE_MACH_O_DYLD_H */

/* Define to 1 if you have the <minix/config.h> header file. */
/* #undef HAVE_MINIX_CONFIG_H */

/* Define to 1 on MSVC platforms that have the "invalid parameter handler"
   concept. */
#ifndef LIBTEXTSTYLE_HAVE_MSVC_INVALID_PARAMETER_HANDLER
#define LIBTEXTSTYLE_HAVE_MSVC_INVALID_PARAMETER_HANDLER 1
#endif

/* Define to 1 if you have the 'opendir' function. */
#ifndef LIBTEXTSTYLE_HAVE_OPENDIR
#define LIBTEXTSTYLE_HAVE_OPENDIR 1
#endif

/* Define if libtool can extract symbol lists from object files. */
#ifndef LIBTEXTSTYLE_HAVE_PRELOADED_SYMBOLS
#define LIBTEXTSTYLE_HAVE_PRELOADED_SYMBOLS 1
#endif

/* Define to 1 if you have the 'readdir' function. */
#ifndef LIBTEXTSTYLE_HAVE_READDIR
#define LIBTEXTSTYLE_HAVE_READDIR 1
#endif

/* Define to 1 if you have the <sdkddkver.h> header file. */
#ifndef LIBTEXTSTYLE_HAVE_SDKDDKVER_H
#define LIBTEXTSTYLE_HAVE_SDKDDKVER_H 1
#endif

/* Define to 1 if you have the 'setdtablesize' function. */
/* #undef HAVE_SETDTABLESIZE */

/* Define if you have the shl_load function. */
/* #undef HAVE_SHL_LOAD */

/* Define to 1 if 'sig_atomic_t' is a signed integer type. */
/* #undef HAVE_SIGNED_SIG_ATOMIC_T */

/* Define to 1 if 'wchar_t' is a signed integer type. */
/* #undef HAVE_SIGNED_WCHAR_T */

/* Define to 1 if 'wint_t' is a signed integer type. */
/* #undef HAVE_SIGNED_WINT_T */

/* Define to 1 if you have the <stdbool.h> header file. */
#ifndef LIBTEXTSTYLE_HAVE_STDBOOL_H
#define LIBTEXTSTYLE_HAVE_STDBOOL_H 1
#endif

/* Define to 1 if you have the <stdckdint.h> header file. */
#ifndef LIBTEXTSTYLE_HAVE_STDCKDINT_H
#define LIBTEXTSTYLE_HAVE_STDCKDINT_H 1
#endif

/* Define to 1 if you have the <stdint.h> header file. */
#ifndef LIBTEXTSTYLE_HAVE_STDINT_H
#define LIBTEXTSTYLE_HAVE_STDINT_H 1
#endif

/* Define to 1 if you have the <stdio.h> header file. */
#ifndef LIBTEXTSTYLE_HAVE_STDIO_H
#define LIBTEXTSTYLE_HAVE_STDIO_H 1
#endif

/* Define to 1 if you have the <stdlib.h> header file. */
#ifndef LIBTEXTSTYLE_HAVE_STDLIB_H
#define LIBTEXTSTYLE_HAVE_STDLIB_H 1
#endif

/* Define to 1 if you have the `strerror_r' function. */
/* #undef HAVE_STRERROR_R */

/* Define to 1 if you have the <strings.h> header file. */
#ifndef LIBTEXTSTYLE_HAVE_STRINGS_H
#define LIBTEXTSTYLE_HAVE_STRINGS_H 1
#endif

/* Define to 1 if you have the <string.h> header file. */
#ifndef LIBTEXTSTYLE_HAVE_STRING_H
#define LIBTEXTSTYLE_HAVE_STRING_H 1
#endif

/* Define to 1 if you have the 'strlcat' function. */
/* #undef HAVE_STRLCAT */

/* Define to 1 if you have the 'strlcpy' function. */
/* #undef HAVE_STRLCPY */

/* Define to 1 if 'st_atimensec' is a member of 'struct stat'. */
/* #undef HAVE_STRUCT_STAT_ST_ATIMENSEC */

/* Define to 1 if 'st_atimespec.tv_nsec' is a member of 'struct stat'. */
/* #undef HAVE_STRUCT_STAT_ST_ATIMESPEC_TV_NSEC */

/* Define to 1 if 'st_atim.st__tim.tv_nsec' is a member of 'struct stat'. */
/* #undef HAVE_STRUCT_STAT_ST_ATIM_ST__TIM_TV_NSEC */

/* Define to 1 if 'st_atim.tv_nsec' is a member of 'struct stat'. */
/* #undef HAVE_STRUCT_STAT_ST_ATIM_TV_NSEC */

/* Define to 1 if 'st_birthtimensec' is a member of 'struct stat'. */
/* #undef HAVE_STRUCT_STAT_ST_BIRTHTIMENSEC */

/* Define to 1 if 'st_birthtimespec.tv_nsec' is a member of 'struct stat'. */
/* #undef HAVE_STRUCT_STAT_ST_BIRTHTIMESPEC_TV_NSEC */

/* Define to 1 if 'st_birthtim.tv_nsec' is a member of 'struct stat'. */
/* #undef HAVE_STRUCT_STAT_ST_BIRTHTIM_TV_NSEC */

/* Define to 1 if you have the 'symlink' function. */
/* #undef HAVE_SYMLINK */

/* Define to 1 if you have the <sys/bitypes.h> header file. */
/* #undef HAVE_SYS_BITYPES_H */

/* Define to 1 if you have the <sys/dl.h> header file. */
/* #undef HAVE_SYS_DL_H */

/* Define to 1 if you have the <sys/inttypes.h> header file. */
/* #undef HAVE_SYS_INTTYPES_H */

/* Define to 1 if you have the <sys/param.h> header file. */
#ifndef LIBTEXTSTYLE_HAVE_SYS_PARAM_H
#define LIBTEXTSTYLE_HAVE_SYS_PARAM_H 1
#endif

/* Define to 1 if you have the <sys/socket.h> header file. */
/* #undef HAVE_SYS_SOCKET_H */

/* Define to 1 if you have the <sys/stat.h> header file. */
#ifndef LIBTEXTSTYLE_HAVE_SYS_STAT_H
#define LIBTEXTSTYLE_HAVE_SYS_STAT_H 1
#endif

/* Define to 1 if you have the <sys/time.h> header file. */
#ifndef LIBTEXTSTYLE_HAVE_SYS_TIME_H
#define LIBTEXTSTYLE_HAVE_SYS_TIME_H 1
#endif

/* Define to 1 if you have the <sys/types.h> header file. */
#ifndef LIBTEXTSTYLE_HAVE_SYS_TYPES_H
#define LIBTEXTSTYLE_HAVE_SYS_TYPES_H 1
#endif

/* Define to 1 if you have the <unistd.h> header file. */
#ifndef LIBTEXTSTYLE_HAVE_UNISTD_H
#define LIBTEXTSTYLE_HAVE_UNISTD_H 1
#endif

/* Define to 1 if the system has the type 'unsigned long long int'. */
#ifndef LIBTEXTSTYLE_HAVE_UNSIGNED_LONG_LONG_INT
#define LIBTEXTSTYLE_HAVE_UNSIGNED_LONG_LONG_INT 1
#endif

/* Define if you have a global __progname variable */
/* #undef HAVE_VAR___PROGNAME */

/* Define to 1 if you have the <wchar.h> header file. */
#ifndef LIBTEXTSTYLE_HAVE_WCHAR_H
#define LIBTEXTSTYLE_HAVE_WCHAR_H 1
#endif

/* Define to 1 if you have Windows consoles. */
#ifndef LIBTEXTSTYLE_HAVE_WINDOWS_CONSOLES
#define LIBTEXTSTYLE_HAVE_WINDOWS_CONSOLES 1
#endif

/* Define to 1 if you have the <winsock2.h> header file. */
#ifndef LIBTEXTSTYLE_HAVE_WINSOCK2_H
#define LIBTEXTSTYLE_HAVE_WINSOCK2_H 1
#endif

/* Define if you have the 'wint_t' type. */
#ifndef LIBTEXTSTYLE_HAVE_WINT_T
#define LIBTEXTSTYLE_HAVE_WINT_T 1
#endif

/* This value is set to 1 to indicate that the system argz facility works */
/* #undef HAVE_WORKING_ARGZ */

/* Define to 1 if O_NOATIME works. */
#ifndef LIBTEXTSTYLE_HAVE_WORKING_O_NOATIME
#define LIBTEXTSTYLE_HAVE_WORKING_O_NOATIME 0
#endif

/* Define to 1 if O_NOFOLLOW works. */
#ifndef LIBTEXTSTYLE_HAVE_WORKING_O_NOFOLLOW
#define LIBTEXTSTYLE_HAVE_WORKING_O_NOFOLLOW 0
#endif

/* Define to 1 if you have the <xalloc.h> header file. */
/* #undef HAVE_XALLOC_H */

/* Define to 1 if you have the '_set_invalid_parameter_handler' function. */
#ifndef LIBTEXTSTYLE_HAVE__SET_INVALID_PARAMETER_HANDLER
#define LIBTEXTSTYLE_HAVE__SET_INVALID_PARAMETER_HANDLER 1
#endif

/* Define to 1 if ctype.h defines __header_inline. */
/* #undef HAVE___HEADER_INLINE */

/* Please see the Gnulib manual for how to use these macros.

   Suppress extern inline with HP-UX cc, as it appears to be broken; see
   <https://lists.gnu.org/r/bug-texinfo/2013-02/msg00030.html>.

   Suppress extern inline with Sun C in standards-conformance mode, as it
   mishandles inline functions that call each other.  E.g., for 'inline void f
   (void) { } inline void g (void) { f (); }', c99 incorrectly complains
   'reference to static identifier "f" in extern inline function'.
   This bug was observed with Oracle Developer Studio 12.6
   (Sun C 5.15 SunOS_sparc 2017/05/30).

   Suppress extern inline (with or without __attribute__ ((__gnu_inline__)))
   on configurations that mistakenly use 'static inline' to implement
   functions or macros in standard C headers like <ctype.h>.  For example,
   if isdigit is mistakenly implemented via a static inline function,
   a program containing an extern inline function that calls isdigit
   may not work since the C standard prohibits extern inline functions
   from calling static functions (ISO C 99 section 6.7.4.(3).
   This bug is known to occur on:

     OS X 10.8 and earlier; see:
     https://lists.gnu.org/r/bug-gnulib/2012-12/msg00023.html

     DragonFly; see
     http://muscles.dragonflybsd.org/bulk/clang-master-potential/20141111_102002/logs/ah-tty-0.3.12.log

     FreeBSD; see:
     https://lists.gnu.org/r/bug-gnulib/2014-07/msg00104.html

   OS X 10.9 has a macro __header_inline indicating the bug is fixed for C and
   for clang but remains for g++; see <https://trac.macports.org/ticket/41033>.
   Assume DragonFly and FreeBSD will be similar.

   GCC 4.3 and above with -std=c99 or -std=gnu99 implements ISO C99
   inline semantics, unless -fgnu89-inline is used.  It defines a macro
   __GNUC_STDC_INLINE__ to indicate this situation or a macro
   __GNUC_GNU_INLINE__ to indicate the opposite situation.
   GCC 4.2 with -std=c99 or -std=gnu99 implements the GNU C inline
   semantics but warns, unless -fgnu89-inline is used:
     warning: C99 inline functions are not supported; using GNU89
     warning: to disable this warning use -fgnu89-inline or the gnu_inline function attribute
   It defines a macro __GNUC_GNU_INLINE__ to indicate this situation.
 */
#if (((defined __APPLE__ && defined __MACH__) \
      || defined __DragonFly__ || defined __FreeBSD__) \
     && (defined HAVE___HEADER_INLINE \
         ? (defined __cplusplus && defined __GNUC_STDC_INLINE__ \
            && ! defined __clang__) \
         : ((! defined _DONT_USE_CTYPE_INLINE_ \
             && (defined __GNUC__ || defined __cplusplus)) \
            || (defined _FORTIFY_SOURCE && 0 < _FORTIFY_SOURCE \
                && defined __GNUC__ && ! defined __cplusplus))))
# define _GL_EXTERN_INLINE_STDHEADER_BUG
#endif
#if ((__GNUC__ \
      ? (defined __GNUC_STDC_INLINE__ && __GNUC_STDC_INLINE__ \
         && !defined __PCC__) \
      : (199901L <= __STDC_VERSION__ \
         && !defined __HP_cc \
         && !defined __PGI \
         && !(defined __SUNPRO_C && __STDC__))) \
     && !defined _GL_EXTERN_INLINE_STDHEADER_BUG)
# define _GL_INLINE inline
# define _GL_EXTERN_INLINE extern inline
# define _GL_EXTERN_INLINE_IN_USE
#elif (2 < __GNUC__ + (7 <= __GNUC_MINOR__) && !defined __STRICT_ANSI__ \
       && !defined __PCC__ \
       && !defined _GL_EXTERN_INLINE_STDHEADER_BUG)
# if defined __GNUC_GNU_INLINE__ && __GNUC_GNU_INLINE__
   /* __gnu_inline__ suppresses a GCC 4.2 diagnostic.  */
#  define _GL_INLINE extern inline __attribute__ ((__gnu_inline__))
# else
#  define _GL_INLINE extern inline
# endif
# define _GL_EXTERN_INLINE extern
# define _GL_EXTERN_INLINE_IN_USE
#else
# define _GL_INLINE _GL_UNUSED static
# define _GL_EXTERN_INLINE _GL_UNUSED static
#endif

/* In GCC 4.6 (inclusive) to 5.1 (exclusive),
   suppress bogus "no previous prototype for 'FOO'"
   and "no previous declaration for 'FOO'" diagnostics,
   when FOO is an inline function in the header; see
   <https://gcc.gnu.org/bugzilla/show_bug.cgi?id=54113> and
   <https://gcc.gnu.org/bugzilla/show_bug.cgi?id=63877>.  */
#if __GNUC__ == 4 && 6 <= __GNUC_MINOR__
# if defined __GNUC_STDC_INLINE__ && __GNUC_STDC_INLINE__
#  define _GL_INLINE_HEADER_CONST_PRAGMA
# else
#  define _GL_INLINE_HEADER_CONST_PRAGMA \
     _Pragma ("GCC diagnostic ignored \"-Wsuggest-attribute=const\"")
# endif
# define _GL_INLINE_HEADER_BEGIN /**/
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wmissing-prototypes\"") \
    _Pragma ("GCC diagnostic ignored \"-Wmissing-declarations\"") \
    _GL_INLINE_HEADER_CONST_PRAGMA
# define _GL_INLINE_HEADER_END /**/
    _Pragma ("GCC diagnostic pop")
#else
# define _GL_INLINE_HEADER_BEGIN /**/
# define _GL_INLINE_HEADER_END /**/
#endif

/* Define to 1 if you have the '__xpg_strerror_r' function. */
/* #undef HAVE___XPG_STRERROR_R */

/* Define if the OS needs help to load dependent libraries for dlopen(). */
#ifndef LIBTEXTSTYLE_LTDL_DLOPEN_DEPLIBS
#define LIBTEXTSTYLE_LTDL_DLOPEN_DEPLIBS 1
#endif

/* Define to the system default library search path. */
#ifndef LIBTEXTSTYLE_LT_DLSEARCH_PATH
#define LIBTEXTSTYLE_LT_DLSEARCH_PATH "/lib:/usr/lib"
#endif

/* The archive extension */
#ifndef LIBTEXTSTYLE_LT_LIBEXT
#define LIBTEXTSTYLE_LT_LIBEXT ""
#endif

/* The archive prefix */
#ifndef LIBTEXTSTYLE_LT_LIBPREFIX
#define LIBTEXTSTYLE_LT_LIBPREFIX "lib"
#endif

/* Define to the extension used for runtime loadable modules, say, ".so". */
#ifndef LIBTEXTSTYLE_LT_MODULE_EXT
#define LIBTEXTSTYLE_LT_MODULE_EXT ".dll"
#endif

/* Define to the name of the environment variable that determines the run-time
   module search path. */
#ifndef LIBTEXTSTYLE_LT_MODULE_PATH_VAR
#define LIBTEXTSTYLE_LT_MODULE_PATH_VAR "PATH"
#endif

/* Define to the sub-directory where libtool stores uninstalled libraries. */
#ifndef LIBTEXTSTYLE_LT_OBJDIR
#define LIBTEXTSTYLE_LT_OBJDIR ".libs/"
#endif

/* Define to the shared library suffix, say, ".dylib". */
/* #undef LT_SHARED_EXT */

/* Define to the shared archive member specification, say "(shr.o)". */
/* #undef LT_SHARED_LIB_MEMBER */

/* If malloc(0) is != NULL, define this to 1. Otherwise define this to 0. */
#ifndef LIBTEXTSTYLE_MALLOC_0_IS_NONNULL
#define LIBTEXTSTYLE_MALLOC_0_IS_NONNULL 1
#endif

/* Use GNU style printf and scanf.  */
#ifndef __USE_MINGW_ANSI_STDIO
# define __USE_MINGW_ANSI_STDIO 1
#endif


/* Define to 1 on musl libc. */
/* #undef MUSL_LIBC */

/* Define if dlsym() requires a leading underscore in symbol names. */
/* #undef NEED_USCORE */

/* Define to 1 if open() fails to recognize a trailing slash. */
/* #undef OPEN_TRAILING_SLASH_BUG */

/* Name of package */
#ifndef LIBTEXTSTYLE_PACKAGE
#define LIBTEXTSTYLE_PACKAGE "libtextstyle"
#endif

/* Define to the address where bug reports for this package should be sent. */
#ifndef LIBTEXTSTYLE_PACKAGE_BUGREPORT
#define LIBTEXTSTYLE_PACKAGE_BUGREPORT "bug-libtextstyle@example.com"
#endif

/* Define to the full name of this package. */
#ifndef LIBTEXTSTYLE_PACKAGE_NAME
#define LIBTEXTSTYLE_PACKAGE_NAME "libtextstyle"
#endif

/* Define to the full name and version of this package. */
#ifndef LIBTEXTSTYLE_PACKAGE_STRING
#define LIBTEXTSTYLE_PACKAGE_STRING "libtextstyle 1.0"
#endif

/* Define to the one symbol short name of this package. */
#ifndef LIBTEXTSTYLE_PACKAGE_TARNAME
#define LIBTEXTSTYLE_PACKAGE_TARNAME "libtextstyle"
#endif

/* Define to the home page for this package. */
#ifndef LIBTEXTSTYLE_PACKAGE_URL
#define LIBTEXTSTYLE_PACKAGE_URL ""
#endif

/* Define to the version of this package. */
#ifndef LIBTEXTSTYLE_PACKAGE_VERSION
#define LIBTEXTSTYLE_PACKAGE_VERSION "1.0"
#endif

/* Define to the type that is the result of default argument promotions of
   type mode_t. */
#ifndef LIBTEXTSTYLE_PROMOTED_MODE_T
#define LIBTEXTSTYLE_PROMOTED_MODE_T int
#endif

/* Define to l, ll, u, ul, ull, etc., as suitable for constants of type
   'ptrdiff_t'. */
/* #undef PTRDIFF_T_SUFFIX */

/* Define to 1 if stat needs help when passed a file name with a trailing
   slash */
/* #undef REPLACE_FUNC_STAT_FILE */

/* Define to 1 if strerror(0) does not return a message implying success. */
/* #undef REPLACE_STRERROR_0 */

/* Define to l, ll, u, ul, ull, etc., as suitable for constants of type
   'sig_atomic_t'. */
/* #undef SIG_ATOMIC_T_SUFFIX */

/* Define to l, ll, u, ul, ull, etc., as suitable for constants of type
   'size_t'. */
/* #undef SIZE_T_SUFFIX */

/* If using the C implementation of alloca, define if you know the
   direction of stack growth for your system; otherwise it will be
   automatically deduced at runtime.
	STACK_DIRECTION > 0 => grows toward higher addresses
	STACK_DIRECTION < 0 => grows toward lower addresses
	STACK_DIRECTION = 0 => direction of growth unknown */
/* #undef STACK_DIRECTION */

/* Define to 1 if the 'S_IS*' macros in <sys/stat.h> do not work properly. */
/* #undef STAT_MACROS_BROKEN */

/* Define to 1 if all of the C89 standard headers exist (not just the ones
   required in a freestanding environment). This macro is provided for
   backward compatibility; new code need not use it. */
#ifndef LIBTEXTSTYLE_STDC_HEADERS
#define LIBTEXTSTYLE_STDC_HEADERS 1
#endif

/* Define to 1 if strerror_r returns char *. */
/* #undef STRERROR_R_CHAR_P */

/* Define to 1 if the type of the st_atim member of a struct stat is struct
   timespec. */
/* #undef TYPEOF_STRUCT_STAT_ST_ATIM_IS_STRUCT_TIMESPEC */

/* Define to enable the declarations of ISO C 23 Annex K types and functions.  */
#if !(defined __STDC_WANT_LIB_EXT1__ && __STDC_WANT_LIB_EXT1__)
#undef/**/__STDC_WANT_LIB_EXT1__
#ifndef LIBTEXTSTYLE___STDC_WANT_LIB_EXT1__
#define LIBTEXTSTYLE___STDC_WANT_LIB_EXT1__ 1
#endif
#endif


/* Enable extensions on AIX, Interix, z/OS.  */
#ifndef _ALL_SOURCE
# define _ALL_SOURCE 1
#endif
/* Enable general extensions on macOS.  */
#ifndef _DARWIN_C_SOURCE
# define _DARWIN_C_SOURCE 1
#endif
/* Enable general extensions on Solaris.  */
#ifndef __EXTENSIONS__
# define __EXTENSIONS__ 1
#endif
/* Enable GNU extensions on systems that have them.  */
#ifndef _GNU_SOURCE
# define _GNU_SOURCE 1
#endif
/* Enable X/Open compliant socket functions that do not require linking
   with -lxnet on HP-UX 11.11.  */
#ifndef _HPUX_ALT_XOPEN_SOCKET_API
# define _HPUX_ALT_XOPEN_SOCKET_API 1
#endif
/* Identify the host operating system as Minix.
   This macro does not affect the system headers' behavior.
   A future release of Autoconf may stop defining this macro.  */
#ifndef _MINIX
/* # undef _MINIX */
#endif
/* Enable general extensions on NetBSD.
   Enable NetBSD compatibility extensions on Minix.  */
#ifndef _NETBSD_SOURCE
# define _NETBSD_SOURCE 1
#endif
/* Enable OpenBSD compatibility extensions on NetBSD.
   Oddly enough, this does nothing on OpenBSD.  */
#ifndef _OPENBSD_SOURCE
# define _OPENBSD_SOURCE 1
#endif
/* Define to 1 if needed for POSIX-compatible behavior.  */
#ifndef _POSIX_SOURCE
/* # undef _POSIX_SOURCE */
#endif
/* Define to 2 if needed for POSIX-compatible behavior.  */
#ifndef _POSIX_1_SOURCE
/* # undef _POSIX_1_SOURCE */
#endif
/* Enable POSIX-compatible threading on Solaris.  */
#ifndef _POSIX_PTHREAD_SEMANTICS
# define _POSIX_PTHREAD_SEMANTICS 1
#endif
/* Enable extensions specified by ISO/IEC TS 18661-5:2014.  */
#ifndef __STDC_WANT_IEC_60559_ATTRIBS_EXT__
# define __STDC_WANT_IEC_60559_ATTRIBS_EXT__ 1
#endif
/* Enable extensions specified by ISO/IEC TS 18661-1:2014.  */
#ifndef __STDC_WANT_IEC_60559_BFP_EXT__
# define __STDC_WANT_IEC_60559_BFP_EXT__ 1
#endif
/* Enable extensions specified by ISO/IEC TS 18661-2:2015.  */
#ifndef __STDC_WANT_IEC_60559_DFP_EXT__
# define __STDC_WANT_IEC_60559_DFP_EXT__ 1
#endif
/* Enable extensions specified by C23 Annex F.  */
#ifndef __STDC_WANT_IEC_60559_EXT__
# define __STDC_WANT_IEC_60559_EXT__ 1
#endif
/* Enable extensions specified by ISO/IEC TS 18661-4:2015.  */
#ifndef __STDC_WANT_IEC_60559_FUNCS_EXT__
# define __STDC_WANT_IEC_60559_FUNCS_EXT__ 1
#endif
/* Enable extensions specified by C23 Annex H and ISO/IEC TS 18661-3:2015.  */
#ifndef __STDC_WANT_IEC_60559_TYPES_EXT__
# define __STDC_WANT_IEC_60559_TYPES_EXT__ 1
#endif
/* Enable extensions specified by ISO/IEC TR 24731-2:2010.  */
#ifndef __STDC_WANT_LIB_EXT2__
# define __STDC_WANT_LIB_EXT2__ 1
#endif
/* Enable extensions specified by ISO/IEC 24747:2009.  */
#ifndef __STDC_WANT_MATH_SPEC_FUNCS__
# define __STDC_WANT_MATH_SPEC_FUNCS__ 1
#endif
/* Enable extensions on HP NonStop.  */
#ifndef _TANDEM_SOURCE
# define _TANDEM_SOURCE 1
#endif
/* Enable X/Open extensions.  Define to 500 only if necessary
   to make mbstate_t available.  */
#ifndef _XOPEN_SOURCE
/* # undef _XOPEN_SOURCE */
#endif


/* Version number of package */
#ifndef LIBTEXTSTYLE_VERSION
#define LIBTEXTSTYLE_VERSION "0.22.5"
#endif

/* Define to l, ll, u, ul, ull, etc., as suitable for constants of type
   'wchar_t'. */
/* #undef WCHAR_T_SUFFIX */

/* Define to l, ll, u, ul, ull, etc., as suitable for constants of type
   'wint_t'. */
/* #undef WINT_T_SUFFIX */

/* Number of bits in a file offset, on hosts where this is settable. */
#ifndef LIBTEXTSTYLE__FILE_OFFSET_BITS
#define LIBTEXTSTYLE__FILE_OFFSET_BITS 64
#endif

/* Define as empty if __attribute__((nonnull(1))) is not supported */
#ifndef LIBTEXTSTYLE__GL_ARG_NONNULL_1
#define LIBTEXTSTYLE__GL_ARG_NONNULL_1 /**/
#endif

/* Define as empty if __attribute__((nonnull(1,2))) is not supported */
#ifndef LIBTEXTSTYLE__GL_ARG_NONNULL_1_2
#define LIBTEXTSTYLE__GL_ARG_NONNULL_1_2 /**/
#endif

/* Define as empty if __attribute__((nonnull(1,3))) is not supported */
#ifndef LIBTEXTSTYLE__GL_ARG_NONNULL_1_3
#define LIBTEXTSTYLE__GL_ARG_NONNULL_1_3 /**/
#endif

/* Define as empty if __attribute__((nonnull(3))) is not supported */
#ifndef LIBTEXTSTYLE__GL_ARG_NONNULL_3
#define LIBTEXTSTYLE__GL_ARG_NONNULL_3 /**/
#endif

/* Define to __attribute__((cold)) */
#ifndef LIBTEXTSTYLE__GL_ATTRIBUTE_COLD
#define LIBTEXTSTYLE__GL_ATTRIBUTE_COLD __attribute__((cold))
#endif

/* Define as empty if __attribute__((__malloc__ (f, i))) is not supported */
#ifndef LIBTEXTSTYLE__GL_ATTRIBUTE_DEALLOC
#define LIBTEXTSTYLE__GL_ATTRIBUTE_DEALLOC(f, i) /**/
#endif

/* Define to _GL_ATTRIBUTE_SPEC_PRINTF_ERROR */
#ifndef LIBTEXTSTYLE__GL_ATTRIBUTE_FORMAT
#define LIBTEXTSTYLE__GL_ATTRIBUTE_FORMAT _GL_ATTRIBUTE_SPEC_PRINTF_ERROR
#endif

/* Define for format attribute with index 5, 6 */
#ifndef LIBTEXTSTYLE__GL_ATTRIBUTE_FORMAT_ERROR_AT_LINE
#define LIBTEXTSTYLE__GL_ATTRIBUTE_FORMAT_ERROR_AT_LINE __attribute__((format(printf, 5, 6)))
#endif

/* Define to use printf format attribute with parameters (1, 2) */
#ifndef LIBTEXTSTYLE__GL_ATTRIBUTE_FORMAT_PRINTF_STANDARD_1_2
#define LIBTEXTSTYLE__GL_ATTRIBUTE_FORMAT_PRINTF_STANDARD_1_2 __attribute__((format(printf, 1, 2)))
#endif

/* Define to use printf format attribute with parameters (2, 0) */
#ifndef LIBTEXTSTYLE__GL_ATTRIBUTE_FORMAT_PRINTF_STANDARD_2_0
#define LIBTEXTSTYLE__GL_ATTRIBUTE_FORMAT_PRINTF_STANDARD_2_0 __attribute__((format(printf, 2, 0)))
#endif

/* Define to use printf format attribute with parameters (2, 3) */
#ifndef LIBTEXTSTYLE__GL_ATTRIBUTE_FORMAT_PRINTF_STANDARD_2_3
#define LIBTEXTSTYLE__GL_ATTRIBUTE_FORMAT_PRINTF_STANDARD_2_3 __attribute__((format(printf, 2, 3)))
#endif

/* Define to use printf format attribute with parameters (3, 0) */
#ifndef LIBTEXTSTYLE__GL_ATTRIBUTE_FORMAT_PRINTF_STANDARD_3_0
#define LIBTEXTSTYLE__GL_ATTRIBUTE_FORMAT_PRINTF_STANDARD_3_0 __attribute__((format(printf, 3, 0)))
#endif

/* Define to use printf format attribute with parameters (3, 4) */
#ifndef LIBTEXTSTYLE__GL_ATTRIBUTE_FORMAT_PRINTF_STANDARD_3_4
#define LIBTEXTSTYLE__GL_ATTRIBUTE_FORMAT_PRINTF_STANDARD_3_4 __attribute__((format(printf, 3, 4)))
#endif

/* Define to use printf format attribute with parameters (1, 0) */
#ifndef LIBTEXTSTYLE__GL_ATTRIBUTE_FORMAT_PRINTF_SYSTEM_1_0
#define LIBTEXTSTYLE__GL_ATTRIBUTE_FORMAT_PRINTF_SYSTEM_1_0 __attribute__((format(printf, 1, 0)))
#endif

/* Define to use printf format attribute with parameters (2, 3) */
#ifndef LIBTEXTSTYLE__GL_ATTRIBUTE_FORMAT_PRINTF_SYSTEM_2_3
#define LIBTEXTSTYLE__GL_ATTRIBUTE_FORMAT_PRINTF_SYSTEM_2_3 __attribute__((format(printf, 2, 3)))
#endif

/* Define as empty if __attribute__((__malloc__)) is not supported */
#ifndef LIBTEXTSTYLE__GL_ATTRIBUTE_MALLOC
#define LIBTEXTSTYLE__GL_ATTRIBUTE_MALLOC /**/
#endif

/* Define to __attribute__((unused)) */
#ifndef LIBTEXTSTYLE__GL_ATTRIBUTE_MAYBE_UNUSED
#define LIBTEXTSTYLE__GL_ATTRIBUTE_MAYBE_UNUSED __attribute__((unused))
#endif

/* Define to __attribute__((format(printf, 3, 4))) */
#ifndef LIBTEXTSTYLE__GL_ATTRIBUTE_SPEC_PRINTF_ERROR
#define LIBTEXTSTYLE__GL_ATTRIBUTE_SPEC_PRINTF_ERROR __attribute__((format(printf, 3, 4)))
#endif

/* Define for format attribute with index 3, 0 */
#ifndef LIBTEXTSTYLE__GL_ATTRIBUTE_SPEC_PRINTF_STANDARD_ERROR
#define LIBTEXTSTYLE__GL_ATTRIBUTE_SPEC_PRINTF_STANDARD_ERROR __attribute__((format(printf, 3, 0)))
#endif

/* Define for format attribute with index 5, 0 */
#ifndef LIBTEXTSTYLE__GL_ATTRIBUTE_SPEC_PRINTF_STANDARD_ERROR_AT_LINE
#define LIBTEXTSTYLE__GL_ATTRIBUTE_SPEC_PRINTF_STANDARD_ERROR_AT_LINE __attribute__((format(printf, 5, 0)))
#endif

/* Define to prevent multiple inclusion */
#ifndef LIBTEXTSTYLE__GL_CONFIG_H_INCLUDED
#define LIBTEXTSTYLE__GL_CONFIG_H_INCLUDED 1
#endif

/* True if the compiler says it groks GNU C version MAJOR.MINOR.
    Except that
      - clang groks GNU C 4.2, even on Windows, where it does not define
        __GNUC__.
      - The OpenMandriva-modified clang compiler pretends that it groks
        GNU C version 13.1, but it doesn't: It does not support
        __attribute__ ((__malloc__ (f, i))), nor does it support
        __attribute__ ((__warning__ (message))) on a function redeclaration.
      - Users can make clang lie as well, through the -fgnuc-version option.  */
#if defined __GNUC__ && defined __GNUC_MINOR__ && !defined __clang__
# define _GL_GNUC_PREREQ(major, minor) \
    ((major) < __GNUC__ + ((minor) <= __GNUC_MINOR__))
#elif defined __clang__
  /* clang really only groks GNU C 4.2.  */
# define _GL_GNUC_PREREQ(major, minor) \
    ((major) < 4 + ((minor) <= 2))
#else
# define _GL_GNUC_PREREQ(major, minor) 0
#endif


/* Define for inline header start */
#ifndef LIBTEXTSTYLE__GL_INLINE_HEADER_BEGIN
#define LIBTEXTSTYLE__GL_INLINE_HEADER_BEGIN /**/
#endif

/* Define for inline header end */
#ifndef LIBTEXTSTYLE__GL_INLINE_HEADER_END
#define LIBTEXTSTYLE__GL_INLINE_HEADER_END /**/
#endif

/* Define for list inline */
#ifndef LIBTEXTSTYLE__GL_LIST_INLINE
#define LIBTEXTSTYLE__GL_LIST_INLINE inline
#endif

/* Define to enable the declarations of ISO C 11 types and functions. */
/* #undef _ISOC11_SOURCE */

/* Define to 1 on platforms where this makes off_t a 64-bit type. */
/* #undef _LARGE_FILES */

/* Define so that AIX headers are more compatible with GNU/Linux. */
#ifndef LIBTEXTSTYLE__LINUX_SOURCE_COMPAT
#define LIBTEXTSTYLE__LINUX_SOURCE_COMPAT 1
#endif

/* The _Noreturn keyword of C11.  */
#ifndef _Noreturn
# if (defined __cplusplus \
      && ((201103 <= __cplusplus && !(__GNUC__ == 4 && __GNUC_MINOR__ == 7)) \
          || (defined _MSC_VER && 1900 <= _MSC_VER)) \
      && 0)
    /* [[noreturn]] is not practically usable, because with it the syntax
         extern _Noreturn void func (...);
       would not be valid; such a declaration would only be valid with 'extern'
       and '_Noreturn' swapped, or without the 'extern' keyword.  However, some
       AIX system header files and several gnulib header files use precisely
       this syntax with 'extern'.  */
#  define _Noreturn [[noreturn]]
# elif (defined __clang__ && __clang_major__ < 16 \
        && defined _GL_WORK_AROUND_LLVM_BUG_59792)
   /* Compile with -D_GL_WORK_AROUND_LLVM_BUG_59792 to work around
      that rare LLVM bug, though you may get many false-alarm warnings.  */
#  define _Noreturn
# elif ((!defined __cplusplus || defined __clang__) \
        && (201112 <= (defined __STDC_VERSION__ ? __STDC_VERSION__ : 0) \
            || (!defined __STRICT_ANSI__ \
                && (_GL_GNUC_PREREQ (4, 7) \
                    || (defined __apple_build_version__ \
                        ? 6000000 <= __apple_build_version__ \
                        : 3 < __clang_major__ + (5 <= __clang_minor__))))))
   /* _Noreturn works as-is.  */
# elif _GL_GNUC_PREREQ (2, 8) || defined __clang__ || 0x5110 <= __SUNPRO_C
#  define _Noreturn __attribute__ ((__noreturn__))
# elif 1200 <= (defined _MSC_VER ? _MSC_VER : 0)
#  define _Noreturn __declspec (noreturn)
# else
#  define _Noreturn
# endif
#endif


/* Number of bits in time_t, on hosts where this is settable. */
/* #undef _TIME_BITS */

/* For standard stat data types on VMS. */
#ifndef LIBTEXTSTYLE__USE_STD_STAT
#define LIBTEXTSTYLE__USE_STD_STAT 1
#endif

/* Define to 1 on platforms where this makes time_t a 64-bit type. */
/* #undef __MINGW_USE_VC2005_COMPAT */

/* Define to 1 if the system <stdint.h> predates C++11. */
/* #undef __STDC_CONSTANT_MACROS */

/* Define to 1 if the system <stdint.h> predates C++11. */
/* #undef __STDC_LIMIT_MACROS */

/* Define to 1 if C does not support variable-length arrays, and if the
   compiler does not already define this. */
/* #undef __STDC_NO_VLA__ */

/* Define so that glibc/gnulib argp.h does not typedef error_t. */
#ifndef LIBTEXTSTYLE___error_t_defined
#define LIBTEXTSTYLE___error_t_defined 1
#endif

/* The _GL_ASYNC_SAFE marker should be attached to functions that are
   signal handlers (for signals other than SIGABRT, SIGPIPE) or can be
   invoked from such signal handlers.  Such functions have some restrictions:
     * All functions that it calls should be marked _GL_ASYNC_SAFE as well,
       or should be listed as async-signal-safe in POSIX
       <https://pubs.opengroup.org/onlinepubs/9699919799/functions/V2_chap02.html#tag_15_04>
       section 2.4.3.  Note that malloc(), sprintf(), and fwrite(), in
       particular, are NOT async-signal-safe.
     * All memory locations (variables and struct fields) that these functions
       access must be marked 'volatile'.  This holds for both read and write
       accesses.  Otherwise the compiler might optimize away stores to and
       reads from such locations that occur in the program, depending on its
       data flow analysis.  For example, when the program contains a loop
       that is intended to inspect a variable set from within a signal handler
           while (!signal_occurred)
             ;
       the compiler is allowed to transform this into an endless loop if the
       variable 'signal_occurred' is not declared 'volatile'.
   Additionally, recall that:
     * A signal handler should not modify errno (except if it is a handler
       for a fatal signal and ends by raising the same signal again, thus
       provoking the termination of the process).  If it invokes a function
       that may clobber errno, it needs to save and restore the value of
       errno.  */
#ifndef LIBTEXTSTYLE__GL_ASYNC_SAFE
#define LIBTEXTSTYLE__GL_ASYNC_SAFE
#endif


/* Attributes.  */
/* Define _GL_HAS_ATTRIBUTE only once, because on FreeBSD, with gcc < 5, if
   <config.h> gets included once again after <sys/cdefs.h>, __has_attribute(x)
   expands to 0 always, and redefining _GL_HAS_ATTRIBUTE would turn off all
   attributes.  */
#ifndef _GL_HAS_ATTRIBUTE
# if (defined __has_attribute \
      && (!defined __clang_minor__ \
          || (defined __apple_build_version__ \
              ? 7000000 <= __apple_build_version__ \
              : 5 <= __clang_major__)))
#  define _GL_HAS_ATTRIBUTE(attr) __has_attribute (__##attr##__)
# else
#  define _GL_HAS_ATTRIBUTE(attr) _GL_ATTR_##attr
#  define _GL_ATTR_alloc_size _GL_GNUC_PREREQ (4, 3)
#  define _GL_ATTR_always_inline _GL_GNUC_PREREQ (3, 2)
#  define _GL_ATTR_artificial _GL_GNUC_PREREQ (4, 3)
#  define _GL_ATTR_cold _GL_GNUC_PREREQ (4, 3)
#  define _GL_ATTR_const _GL_GNUC_PREREQ (2, 95)
#  define _GL_ATTR_deprecated _GL_GNUC_PREREQ (3, 1)
#  define _GL_ATTR_diagnose_if 0
#  define _GL_ATTR_error _GL_GNUC_PREREQ (4, 3)
#  define _GL_ATTR_externally_visible _GL_GNUC_PREREQ (4, 1)
#  define _GL_ATTR_fallthrough _GL_GNUC_PREREQ (7, 0)
#  define _GL_ATTR_format _GL_GNUC_PREREQ (2, 7)
#  define _GL_ATTR_leaf _GL_GNUC_PREREQ (4, 6)
#  define _GL_ATTR_malloc _GL_GNUC_PREREQ (3, 0)
#  ifdef _ICC
#   define _GL_ATTR_may_alias 0
#  else
#   define _GL_ATTR_may_alias _GL_GNUC_PREREQ (3, 3)
#  endif
#  define _GL_ATTR_noinline _GL_GNUC_PREREQ (3, 1)
#  define _GL_ATTR_nonnull _GL_GNUC_PREREQ (3, 3)
#  define _GL_ATTR_nonstring _GL_GNUC_PREREQ (8, 0)
#  define _GL_ATTR_nothrow _GL_GNUC_PREREQ (3, 3)
#  define _GL_ATTR_packed _GL_GNUC_PREREQ (2, 7)
#  define _GL_ATTR_pure _GL_GNUC_PREREQ (2, 96)
#  define _GL_ATTR_reproducible 0 /* not yet supported, as of GCC 14 */
#  define _GL_ATTR_returns_nonnull _GL_GNUC_PREREQ (4, 9)
#  define _GL_ATTR_sentinel _GL_GNUC_PREREQ (4, 0)
#  define _GL_ATTR_unsequenced 0 /* not yet supported, as of GCC 14 */
#  define _GL_ATTR_unused _GL_GNUC_PREREQ (2, 7)
#  define _GL_ATTR_warn_unused_result _GL_GNUC_PREREQ (3, 4)
# endif
#endif

/* Use __has_c_attribute if available.  However, do not use with
   pre-C23 GCC, which can issue false positives if -Wpedantic.  */
#if (defined __has_c_attribute \
     && ! (_GL_GNUC_PREREQ (4, 6) \
           && (defined __STDC_VERSION__ ? __STDC_VERSION__ : 0) <= 201710))
# define _GL_HAVE___HAS_C_ATTRIBUTE 1
#else
# define _GL_HAVE___HAS_C_ATTRIBUTE 0
#endif

/* Attributes in bracket syntax [[...]] vs. attributes in __attribute__((...))
   syntax, in function declarations.  There are two problems here.
   (Last tested with gcc/g++ 14 and clang/clang++ 18.)

   1) We want that the _GL_ATTRIBUTE_* can be cumulated on the same declaration
      in any order.
      =========================== foo.c = foo.cc ===========================
      __attribute__ ((__deprecated__)) [[__nodiscard__]] int bar1 (int);
      [[__nodiscard__]] __attribute__ ((__deprecated__)) int bar2 (int);
      ======================================================================
      This gives a syntax error
        - in C mode with gcc
          <https://gcc.gnu.org/bugzilla/show_bug.cgi?id=108796>, and
        - in C++ mode with clang++ version < 16, and
        - in C++ mode, inside extern "C" {}, still in newer clang++ versions
          <https://github.com/llvm/llvm-project/issues/101990>.
 */
/* Define if, in a function declaration, the attributes in bracket syntax
   [[...]] must come before the attributes in __attribute__((...)) syntax.
   If this is defined, it is best to avoid the bracket syntax, so that the
   various _GL_ATTRIBUTE_* can be cumulated on the same declaration in any
   order.  */
#ifdef __cplusplus
# if defined __clang__
#  define _GL_BRACKET_BEFORE_ATTRIBUTE 1
# endif
#else
# if defined __GNUC__ && !defined __clang__
#  define _GL_BRACKET_BEFORE_ATTRIBUTE 1
# endif
#endif
/*
   2) We want that the _GL_ATTRIBUTE_* can be placed in a declaration
        - without 'extern', in C as well as in C++,
        - with 'extern', in C,
        - with 'extern "C"', in C++
      in the same position.  That is, we don't want to be forced to use a
      macro which arranges for the attribute to come before 'extern' in
      one case and after 'extern' in the other case, because such a macro
      would make the source code of .h files pretty ugly.
      =========================== foo.c = foo.cc ===========================
      #ifdef __cplusplus
      # define CC "C"
      #else
      # define CC
      #endif

      #define ND   [[__nodiscard__]]
      #define WUR  __attribute__((__warn_unused_result__))

      #ifdef __cplusplus
      extern "C" {
      #endif
                                        // gcc   clang  g++   clang++

      ND int foo (int);
      int ND foo (int);                 // warn  error  warn  error
      int foo ND (int);
      int foo (int) ND;                 // warn  error  warn  error

      WUR int foo (int);
      int WUR foo (int);
      int fo1 WUR (int);                // error error  error error
      int foo (int) WUR;

      #ifdef __cplusplus
      }
      #endif

                                        // gcc   clang  g++   clang++

      ND extern CC int foo (int);       //              error error
      extern CC ND int foo (int);       // error error
      extern CC int ND foo (int);       // warn  error  warn  error
      extern CC int foo ND (int);
      extern CC int foo (int) ND;       // warn  error  warn  error

      WUR extern CC int foo (int);      //              warn
      extern CC WUR int foo (int);
      extern CC int WUR foo (int);
      extern CC int foo WUR (int);      // error error  error error
      extern CC int foo (int) WUR;

      ND EXTERN_C_FUNC int foo (int);   //              error error
      EXTERN_C_FUNC ND int foo (int);
      EXTERN_C_FUNC int ND foo (int);   // warn  error  warn  error
      EXTERN_C_FUNC int foo ND (int);
      EXTERN_C_FUNC int foo (int) ND;   // warn  error  warn  error

      WUR EXTERN_C_FUNC int foo (int);  //              warn
      EXTERN_C_FUNC WUR int foo (int);
      EXTERN_C_FUNC int WUR foo (int);
      EXTERN_C_FUNC int fo2 WUR (int);  // error error  error error
      EXTERN_C_FUNC int foo (int) WUR;
      ======================================================================
      So, if we insist on using the 'extern' keyword ('extern CC' idiom):
        * If _GL_ATTRIBUTE_* expands to bracket syntax [[...]]
          in both C and C++, there is one available position:
            - between the function name and the parameter list.
        * If _GL_ATTRIBUTE_* expands to __attribute__((...)) syntax
          in both C and C++, there are several available positions:
            - before the return type,
            - between return type and function name,
            - at the end of the declaration.
        * If _GL_ATTRIBUTE_* expands to bracket syntax [[...]] in C and to
          __attribute__((...)) syntax in C++, there is no available position:
          it would need to come before 'extern' in C but after 'extern "C"'
          in C++.
        * If _GL_ATTRIBUTE_* expands to __attribute__((...)) syntax in C and
          to bracket syntax [[...]] in C++, there is one available position:
            - before the return type.
      Whereas, if we use the 'EXTERN_C_FUNC' idiom, which conditionally
      omits the 'extern' keyword:
        * If _GL_ATTRIBUTE_* expands to bracket syntax [[...]]
          in both C and C++, there are two available positions:
            - before the return type,
            - between the function name and the parameter list.
        * If _GL_ATTRIBUTE_* expands to __attribute__((...)) syntax
          in both C and C++, there are several available positions:
            - before the return type,
            - between return type and function name,
            - at the end of the declaration.
        * If _GL_ATTRIBUTE_* expands to bracket syntax [[...]] in C and to
          __attribute__((...)) syntax in C++, there is one available position:
            - before the return type.
        * If _GL_ATTRIBUTE_* expands to __attribute__((...)) syntax in C and
          to bracket syntax [[...]] in C++, there is one available position:
            - before the return type.
      The best choice is therefore to use the 'EXTERN_C_FUNC' idiom and
      put the attributes before the return type. This works regardless
      to what the _GL_ATTRIBUTE_* macros expand.
 */

/* Attributes in bracket syntax [[...]] vs. attributes in __attribute__((...))
   syntax, in static/inline function definitions.

   There are similar constraints as for function declarations.  However, here,
   we cannot omit the storage-class specifier.  Therefore, the following rule
   applies:
     * The macros
         _GL_ATTRIBUTE_CONST
         _GL_ATTRIBUTE_DEPRECATED
         _GL_ATTRIBUTE_MAYBE_UNUSED
         _GL_ATTRIBUTE_NODISCARD
         _GL_ATTRIBUTE_PURE
         _GL_ATTRIBUTE_REPRODUCIBLE
         _GL_ATTRIBUTE_UNSEQUENCED
       which may expand to bracket syntax [[...]], must come first, before the
       storage-class specifier.
     * Other _GL_ATTRIBUTE_* macros, that expand to __attribute__((...)) syntax,
       are better placed between the storage-class specifier and the return
       type.
 */

/* Attributes in bracket syntax [[...]] vs. attributes in __attribute__((...))
   syntax, in variable declarations.

   At which position can they be placed?
   (Last tested with gcc/g++ 14 and clang/clang++ 18.)

      =========================== foo.c = foo.cc ===========================
      #ifdef __cplusplus
      # define CC "C"
      #else
      # define CC
      #endif

      #define BD   [[__deprecated__]]
      #define AD   __attribute__ ((__deprecated__))

                              // gcc   clang  g++    clang++

      BD extern CC int var;   //              error  error
      extern CC BD int var;   // error error
      extern CC int BD var;   // warn  error  warn   error
      extern CC int var BD;

      AD extern CC int var;   //              warn
      extern CC AD int var;
      extern CC int AD var;
      extern CC int var AD;

      BD extern CC int z[];   //              error  error
      extern CC BD int z[];   // error error
      extern CC int BD z[];   // warn  error  warn   error
      extern CC int z1 BD [];
      extern CC int z[] BD;   // warn  error         error

      AD extern CC int z[];   //              warn
      extern CC AD int z[];
      extern CC int AD z[];
      extern CC int z2 AD []; // error error  error  error
      extern CC int z[] AD;
      ======================================================================

   * For non-array variables, the only good position is after the variable name,
     that is, at the end of the declaration.
   * For array variables, you will need to distinguish C and C++:
       - In C, before the 'extern' keyword.
       - In C++, between the 'extern "C"' and the variable's type.
 */

/* _GL_ATTRIBUTE_ALLOC_SIZE ((N)) declares that the Nth argument of the function
   is the size of the returned memory block.
   _GL_ATTRIBUTE_ALLOC_SIZE ((M, N)) declares that the Mth argument multiplied
   by the Nth argument of the function is the size of the returned memory block.
 */
/* Applies to: functions, pointer to functions, function types.  */
#ifndef _GL_ATTRIBUTE_ALLOC_SIZE
# if _GL_HAS_ATTRIBUTE (alloc_size)
#  define _GL_ATTRIBUTE_ALLOC_SIZE(args) __attribute__ ((__alloc_size__ args))
# else
#  define _GL_ATTRIBUTE_ALLOC_SIZE(args)
# endif
#endif

/* _GL_ATTRIBUTE_ALWAYS_INLINE tells that the compiler should always inline the
   function and report an error if it cannot do so.  */
/* Applies to: functions.  */
#ifndef _GL_ATTRIBUTE_ALWAYS_INLINE
# if _GL_HAS_ATTRIBUTE (always_inline)
#  define _GL_ATTRIBUTE_ALWAYS_INLINE __attribute__ ((__always_inline__))
# else
#  define _GL_ATTRIBUTE_ALWAYS_INLINE
# endif
#endif

/* _GL_ATTRIBUTE_ARTIFICIAL declares that the function is not important to show
    in stack traces when debugging.  The compiler should omit the function from
    stack traces.  */
/* Applies to: functions.  */
#ifndef _GL_ATTRIBUTE_ARTIFICIAL
# if _GL_HAS_ATTRIBUTE (artificial)
#  define _GL_ATTRIBUTE_ARTIFICIAL __attribute__ ((__artificial__))
# else
#  define _GL_ATTRIBUTE_ARTIFICIAL
# endif
#endif

/* _GL_ATTRIBUTE_COLD declares that the function is rarely executed.  */
/* Applies to: functions.  */
/* Avoid __attribute__ ((cold)) on MinGW; see thread starting at
   <https://lists.gnu.org/r/emacs-devel/2019-04/msg01152.html>.
   Also, Oracle Studio 12.6 requires 'cold' not '__cold__'.  */
#ifndef _GL_ATTRIBUTE_COLD
# if _GL_HAS_ATTRIBUTE (cold) && !defined __MINGW32__
#  ifndef __SUNPRO_C
#   define _GL_ATTRIBUTE_COLD __attribute__((cold))
#  else
#   define _GL_ATTRIBUTE_COLD __attribute__((cold))
#  endif
# else
#  define _GL_ATTRIBUTE_COLD __attribute__((cold))
# endif
#endif

/* _GL_ATTRIBUTE_CONST declares:
   It is OK for a compiler to move calls to the function and to omit
   calls to the function if another call has the same arguments or the
   result is not used.
   This attribute is safe for a function that neither depends on
   nor affects state, and always returns exactly once -
   e.g., does not raise an exception, call longjmp, or loop forever.
   (This attribute is stricter than _GL_ATTRIBUTE_PURE because the
   function cannot observe state.  It is stricter than
   _GL_ATTRIBUTE_UNSEQUENCED because the function must return exactly
   once and cannot depend on state addressed by its arguments.)  */
/* Applies to: functions.  */
#ifndef _GL_ATTRIBUTE_CONST
# if _GL_HAS_ATTRIBUTE (const)
#  define _GL_ATTRIBUTE_CONST __attribute__ ((__const__))
# else
#  define _GL_ATTRIBUTE_CONST _GL_ATTRIBUTE_UNSEQUENCED
# endif
#endif

/* _GL_ATTRIBUTE_DEALLOC (F, I) declares that the function returns pointers
   that can be freed by passing them as the Ith argument to the
   function F.
   _GL_ATTRIBUTE_DEALLOC_FREE declares that the function returns pointers that
   can be freed via 'free'; it can be used only after declaring 'free'.  */
/* Applies to: functions.  Cannot be used on inline functions.  */
#ifndef _GL_ATTRIBUTE_DEALLOC
# if _GL_GNUC_PREREQ (11, 0)
#  define _GL_ATTRIBUTE_DEALLOC(f, i) /**/
# else
#  define _GL_ATTRIBUTE_DEALLOC(f, i) /**/
# endif
#endif
/* If gnulib's <string.h> or <wchar.h> has already defined this macro, continue
   to use this earlier definition, since <stdlib.h> may not have been included
   yet.  */
#ifndef _GL_ATTRIBUTE_DEALLOC_FREE
# if defined __cplusplus && defined __GNUC__ && !defined __clang__
/* Work around GCC bug <https://gcc.gnu.org/bugzilla/show_bug.cgi?id=108231> */
#  define _GL_ATTRIBUTE_DEALLOC_FREE \
     _GL_ATTRIBUTE_DEALLOC ((void (*) (void *)) free, 1)
# else
#  define _GL_ATTRIBUTE_DEALLOC_FREE \
     _GL_ATTRIBUTE_DEALLOC (free, 1)
# endif
#endif

/* _GL_ATTRIBUTE_DEPRECATED: Declares that an entity is deprecated.
   The compiler may warn if the entity is used.  */
/* Applies to:
     - function, variable,
     - struct, union, struct/union member,
     - enumeration, enumeration item,
     - typedef,
   in C++ also: namespace, class, template specialization.  */
#ifndef _GL_ATTRIBUTE_DEPRECATED
# ifndef _GL_BRACKET_BEFORE_ATTRIBUTE
#  if _GL_HAVE___HAS_C_ATTRIBUTE
#   if __has_c_attribute (__deprecated__)
#    define _GL_ATTRIBUTE_DEPRECATED [[__deprecated__]]
#   endif
#  endif
# endif
# if !defined _GL_ATTRIBUTE_DEPRECATED && _GL_HAS_ATTRIBUTE (deprecated)
#  define _GL_ATTRIBUTE_DEPRECATED __attribute__ ((__deprecated__))
# endif
# ifndef _GL_ATTRIBUTE_DEPRECATED
#  define _GL_ATTRIBUTE_DEPRECATED
# endif
#endif

/* _GL_ATTRIBUTE_ERROR(msg) requests an error if a function is called and
   the function call is not optimized away.
   _GL_ATTRIBUTE_WARNING(msg) requests a warning if a function is called and
   the function call is not optimized away.  */
/* Applies to: functions.  */
#if !(defined _GL_ATTRIBUTE_ERROR && defined _GL_ATTRIBUTE_WARNING)
# if _GL_HAS_ATTRIBUTE (error)
#  define _GL_ATTRIBUTE_ERROR(msg) __attribute__ ((__error__ (msg)))
#  define _GL_ATTRIBUTE_WARNING(msg) __attribute__ ((__warning__ (msg)))
# elif _GL_HAS_ATTRIBUTE (diagnose_if)
#  define _GL_ATTRIBUTE_ERROR(msg) __attribute__ ((__diagnose_if__ (1, msg, "error")))
#  define _GL_ATTRIBUTE_WARNING(msg) __attribute__ ((__diagnose_if__ (1, msg, "warning")))
# else
#  define _GL_ATTRIBUTE_ERROR(msg)
#  define _GL_ATTRIBUTE_WARNING(msg)
# endif
#endif

/* _GL_ATTRIBUTE_EXTERNALLY_VISIBLE declares that the entity should remain
   visible to debuggers etc., even with '-fwhole-program'.  */
/* Applies to: functions, variables.  */
#ifndef _GL_ATTRIBUTE_EXTERNALLY_VISIBLE
# if _GL_HAS_ATTRIBUTE (externally_visible)
#  define _GL_ATTRIBUTE_EXTERNALLY_VISIBLE __attribute__ ((externally_visible))
# else
#  define _GL_ATTRIBUTE_EXTERNALLY_VISIBLE
# endif
#endif

/* _GL_ATTRIBUTE_FALLTHROUGH declares that it is not a programming mistake if
   the control flow falls through to the immediately following 'case' or
   'default' label.  The compiler should not warn in this case.  */
/* Applies to: Empty statement (;), inside a 'switch' statement.  */
/* Always expands to something.  */
#ifndef _GL_ATTRIBUTE_FALLTHROUGH
# if _GL_HAVE___HAS_C_ATTRIBUTE
#  if __has_c_attribute (__fallthrough__)
#   define _GL_ATTRIBUTE_FALLTHROUGH [[__fallthrough__]]
#  endif
# endif
# if !defined _GL_ATTRIBUTE_FALLTHROUGH && _GL_HAS_ATTRIBUTE (fallthrough)
#  define _GL_ATTRIBUTE_FALLTHROUGH __attribute__ ((__fallthrough__))
# endif
# ifndef _GL_ATTRIBUTE_FALLTHROUGH
#  define _GL_ATTRIBUTE_FALLTHROUGH ((void) 0)
# endif
#endif

/* _GL_ATTRIBUTE_FORMAT ((ARCHETYPE, STRING-INDEX, FIRST-TO-CHECK))
   declares that the STRING-INDEXth function argument is a format string of
   style ARCHETYPE, which is one of:
     printf, gnu_printf
     scanf, gnu_scanf,
     strftime, gnu_strftime,
     strfmon,
   or the same thing prefixed and suffixed with '__'.
   If FIRST-TO-CHECK is not 0, arguments starting at FIRST-TO_CHECK
   are suitable for the format string.  */
/* Applies to: functions.  */
#ifndef _GL_ATTRIBUTE_FORMAT
# if _GL_HAS_ATTRIBUTE (format)
#  define _GL_ATTRIBUTE_FORMAT _GL_ATTRIBUTE_SPEC_PRINTF_ERROR
# else
#  define _GL_ATTRIBUTE_FORMAT _GL_ATTRIBUTE_SPEC_PRINTF_ERROR
# endif
#endif

/* _GL_ATTRIBUTE_LEAF declares that if the function is called from some other
   compilation unit, it executes code from that unit only by return or by
   exception handling.  This declaration lets the compiler optimize that unit
   more aggressively.  */
/* Applies to: functions.  */
#ifndef _GL_ATTRIBUTE_LEAF
# if _GL_HAS_ATTRIBUTE (leaf)
#  define _GL_ATTRIBUTE_LEAF __attribute__ ((__leaf__))
# else
#  define _GL_ATTRIBUTE_LEAF
# endif
#endif

/* _GL_ATTRIBUTE_MALLOC declares that the function returns a pointer to freshly
   allocated memory.  */
/* Applies to: functions.  */
#ifndef _GL_ATTRIBUTE_MALLOC
# if _GL_HAS_ATTRIBUTE (malloc)
#  define _GL_ATTRIBUTE_MALLOC /**/
# else
#  define _GL_ATTRIBUTE_MALLOC /**/
# endif
#endif

/* _GL_ATTRIBUTE_MAY_ALIAS declares that pointers to the type may point to the
   same storage as pointers to other types.  Thus this declaration disables
   strict aliasing optimization.  */
/* Applies to: types.  */
/* Oracle Studio 12.6 mishandles may_alias despite __has_attribute OK.  */
#ifndef _GL_ATTRIBUTE_MAY_ALIAS
# if _GL_HAS_ATTRIBUTE (may_alias) && !defined __SUNPRO_C
#  define _GL_ATTRIBUTE_MAY_ALIAS __attribute__ ((__may_alias__))
# else
#  define _GL_ATTRIBUTE_MAY_ALIAS
# endif
#endif

/* _GL_ATTRIBUTE_MAYBE_UNUSED declares that it is not a programming mistake if
   the entity is not used.  The compiler should not warn if the entity is not
   used.  */
/* Applies to:
     - function, variable,
     - struct, union, struct/union member,
     - enumeration, enumeration item,
     - typedef,
   in C++ also: class.  */
/* In C++ and C23, this is spelled [[__maybe_unused__]].
   GCC's syntax is __attribute__ ((__unused__)).
   clang supports both syntaxes.  Except that with clang ≥ 6, < 10, in C++ mode,
   __has_c_attribute (__maybe_unused__) yields true but the use of
   [[__maybe_unused__]] nevertheless produces a warning.  */
#ifndef _GL_ATTRIBUTE_MAYBE_UNUSED
# ifndef _GL_BRACKET_BEFORE_ATTRIBUTE
#  if defined __clang__ && defined __cplusplus
#   if !defined __apple_build_version__ && __clang_major__ >= 10
#    define _GL_ATTRIBUTE_MAYBE_UNUSED __attribute__((unused))
#   endif
#  elif _GL_HAVE___HAS_C_ATTRIBUTE
#   if __has_c_attribute (__maybe_unused__)
#    define _GL_ATTRIBUTE_MAYBE_UNUSED __attribute__((unused))
#   endif
#  endif
# endif
# ifndef _GL_ATTRIBUTE_MAYBE_UNUSED
#  define _GL_ATTRIBUTE_MAYBE_UNUSED __attribute__((unused))
# endif
#endif
/* Alternative spelling of this macro, for convenience and for
   compatibility with glibc/include/libc-symbols.h.  */
#ifndef LIBTEXTSTYLE__GL_UNUSED
#define LIBTEXTSTYLE__GL_UNUSED _GL_ATTRIBUTE_MAYBE_UNUSED
#endif
/* Earlier spellings of this macro.  */
#ifndef LIBTEXTSTYLE__UNUSED_PARAMETER_
#define LIBTEXTSTYLE__UNUSED_PARAMETER_ _GL_ATTRIBUTE_MAYBE_UNUSED
#endif

/* _GL_ATTRIBUTE_NODISCARD declares that the caller of the function should not
   discard the return value.  The compiler may warn if the caller does not use
   the return value, unless the caller uses something like ignore_value.  */
/* Applies to: function, enumeration, class.  */
#ifndef _GL_ATTRIBUTE_NODISCARD
# ifndef _GL_BRACKET_BEFORE_ATTRIBUTE
#  if defined __clang__ && defined __cplusplus
  /* With clang up to 15.0.6 (at least), in C++ mode, [[__nodiscard__]] produces
     a warning.
     The 1000 below means a yet unknown threshold.  When clang++ version X
     starts supporting [[__nodiscard__]] without warning about it, you can
     replace the 1000 with X.  */
#   if __clang_major__ >= 1000
#    define _GL_ATTRIBUTE_NODISCARD [[__nodiscard__]]
#   endif
#  elif _GL_HAVE___HAS_C_ATTRIBUTE
#   if __has_c_attribute (__nodiscard__)
#    define _GL_ATTRIBUTE_NODISCARD [[__nodiscard__]]
#   endif
#  endif
# endif
# if !defined _GL_ATTRIBUTE_NODISCARD && _GL_HAS_ATTRIBUTE (warn_unused_result)
#  define _GL_ATTRIBUTE_NODISCARD __attribute__ ((__warn_unused_result__))
# endif
# ifndef _GL_ATTRIBUTE_NODISCARD
#  define _GL_ATTRIBUTE_NODISCARD
# endif
#endif

/* _GL_ATTRIBUTE_NOINLINE tells that the compiler should not inline the
   function.  */
/* Applies to: functions.  */
#ifndef _GL_ATTRIBUTE_NOINLINE
# if _GL_HAS_ATTRIBUTE (noinline)
#  define _GL_ATTRIBUTE_NOINLINE __attribute__ ((__noinline__))
# else
#  define _GL_ATTRIBUTE_NOINLINE
# endif
#endif

/* _GL_ATTRIBUTE_NONNULL ((N1, N2,...)) declares that the arguments N1, N2,...
   must not be NULL.
   _GL_ATTRIBUTE_NONNULL () declares that all pointer arguments must not be
   null.  */
/* Applies to: functions.  */
#ifndef _GL_ATTRIBUTE_NONNULL
# if _GL_HAS_ATTRIBUTE (nonnull)
#  define _GL_ATTRIBUTE_NONNULL(args) __attribute__ ((__nonnull__ args))
# else
#  define _GL_ATTRIBUTE_NONNULL(args)
# endif
#endif

/* _GL_ATTRIBUTE_NONSTRING declares that the contents of a character array is
   not meant to be NUL-terminated.  */
/* Applies to: struct/union members and variables that are arrays of element
   type '[[un]signed] char'.  */
#ifndef _GL_ATTRIBUTE_NONSTRING
# if _GL_HAS_ATTRIBUTE (nonstring)
#  define _GL_ATTRIBUTE_NONSTRING __attribute__ ((__nonstring__))
# else
#  define _GL_ATTRIBUTE_NONSTRING
# endif
#endif

/* There is no _GL_ATTRIBUTE_NORETURN; use _Noreturn instead.  */

/* _GL_ATTRIBUTE_NOTHROW declares that the function does not throw exceptions.
 */
/* Applies to: functions.  */
/* After a function's parameter list, this attribute must come first, before
   other attributes.  */
#ifndef _GL_ATTRIBUTE_NOTHROW
# if defined __cplusplus
#  if _GL_GNUC_PREREQ (2, 8) || __clang_major__ >= 4
#   if __cplusplus >= 201103L
#    define _GL_ATTRIBUTE_NOTHROW noexcept (true)
#   else
#    define _GL_ATTRIBUTE_NOTHROW throw ()
#   endif
#  else
#   define _GL_ATTRIBUTE_NOTHROW
#  endif
# else
#  if _GL_HAS_ATTRIBUTE (nothrow)
#   define _GL_ATTRIBUTE_NOTHROW __attribute__ ((__nothrow__))
#  else
#   define _GL_ATTRIBUTE_NOTHROW
#  endif
# endif
#endif

/* _GL_ATTRIBUTE_PACKED declares:
   For struct members: The member has the smallest possible alignment.
   For struct, union, class: All members have the smallest possible alignment,
   minimizing the memory required.  */
/* Applies to: struct members, struct, union,
   in C++ also: class.  */
#ifndef _GL_ATTRIBUTE_PACKED
/* Oracle Studio 12.6 miscompiles code with __attribute__ ((__packed__)) despite
   __has_attribute OK.  */
# if _GL_HAS_ATTRIBUTE (packed) && !defined __SUNPRO_C
#  define _GL_ATTRIBUTE_PACKED __attribute__ ((__packed__))
# else
#  define _GL_ATTRIBUTE_PACKED
# endif
#endif

/* _GL_ATTRIBUTE_PURE declares:
   It is OK for a compiler to move calls to the function and to omit
   calls to the function if another call has the same arguments or the
   result is not used, and if observable state is the same.
   This attribute is safe for a function that does not affect observable state
   and always returns exactly once.
   (This attribute is looser than _GL_ATTRIBUTE_CONST because the function
   can depend on observable state.  It is stricter than
   _GL_ATTRIBUTE_REPRODUCIBLE because the function must return exactly
   once and cannot affect state addressed by its arguments.)  */
/* Applies to: functions.  */
#ifndef _GL_ATTRIBUTE_PURE
# if _GL_HAS_ATTRIBUTE (pure)
#  define _GL_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define _GL_ATTRIBUTE_PURE _GL_ATTRIBUTE_REPRODUCIBLE
# endif
#endif

/* _GL_ATTRIBUTE_REPRODUCIBLE declares:
   It is OK for a compiler to move calls to the function and to omit duplicate
   calls to the function with the same arguments, so long as the state
   addressed by its arguments is the same and is updated in time for
   the rest of the program.
   This attribute is safe for a function that is effectless and idempotent; see
   ISO C 23 § 6.7.12.7 for a definition of these terms.
   (This attribute is looser than _GL_ATTRIBUTE_UNSEQUENCED because
   the function need not be stateless and idempotent.  It is looser
   than _GL_ATTRIBUTE_PURE because the function need not return
   exactly once and can affect state addressed by its arguments.)
   See also <https://www.open-std.org/jtc1/sc22/wg14/www/docs/n2956.htm> and
   <https://stackoverflow.com/questions/76847905/>.  */
/* Applies to: functions, pointer to functions, function types.  */
#ifndef _GL_ATTRIBUTE_REPRODUCIBLE
/* This may be revisited when gcc and clang support [[reproducible]] or possibly
   __attribute__ ((__reproducible__)).  */
# ifndef _GL_BRACKET_BEFORE_ATTRIBUTE
#  if _GL_HAS_ATTRIBUTE (reproducible)
#   define _GL_ATTRIBUTE_REPRODUCIBLE [[reproducible]]
#  endif
# endif
# ifndef _GL_ATTRIBUTE_REPRODUCIBLE
#  define _GL_ATTRIBUTE_REPRODUCIBLE
# endif
#endif

/* _GL_ATTRIBUTE_RETURNS_NONNULL declares that the function's return value is
   a non-NULL pointer.  */
/* Applies to: functions.  */
#ifndef _GL_ATTRIBUTE_RETURNS_NONNULL
# if _GL_HAS_ATTRIBUTE (returns_nonnull)
#  define _GL_ATTRIBUTE_RETURNS_NONNULL __attribute__ ((__returns_nonnull__))
# else
#  define _GL_ATTRIBUTE_RETURNS_NONNULL
# endif
#endif

/* _GL_ATTRIBUTE_SENTINEL(pos) declares that the variadic function expects a
   trailing NULL argument.
   _GL_ATTRIBUTE_SENTINEL () - The last argument is NULL (requires C99).
   _GL_ATTRIBUTE_SENTINEL ((N)) - The (N+1)st argument from the end is NULL.  */
/* Applies to: functions.  */
#ifndef _GL_ATTRIBUTE_SENTINEL
# if _GL_HAS_ATTRIBUTE (sentinel)
#  define _GL_ATTRIBUTE_SENTINEL(pos) __attribute__ ((__sentinel__ pos))
# else
#  define _GL_ATTRIBUTE_SENTINEL(pos)
# endif
#endif

/* _GL_ATTRIBUTE_UNSEQUENCED declares:
   It is OK for a compiler to move calls to the function and to omit duplicate
   calls to the function with the same arguments, so long as the state
   addressed by its arguments is the same.
   This attribute is safe for a function that is effectless, idempotent,
   stateless, and independent; see ISO C 23 § 6.7.12.7 for a definition of
   these terms.
   (This attribute is stricter than _GL_ATTRIBUTE_REPRODUCIBLE because
   the function must be stateless and independent.  It is looser than
   _GL_ATTRIBUTE_CONST because the function need not return exactly
   once and can depend on state addressed by its arguments.)
   See also <https://www.open-std.org/jtc1/sc22/wg14/www/docs/n2956.htm> and
   <https://stackoverflow.com/questions/76847905/>.  */
/* Applies to: functions, pointer to functions, function types.  */
#ifndef _GL_ATTRIBUTE_UNSEQUENCED
/* This may be revisited when gcc and clang support [[unsequenced]] or possibly
   __attribute__ ((__unsequenced__)).  */
# ifndef _GL_BRACKET_BEFORE_ATTRIBUTE
#  if _GL_HAS_ATTRIBUTE (unsequenced)
#   define _GL_ATTRIBUTE_UNSEQUENCED [[unsequenced]]
#  endif
# endif
# ifndef _GL_ATTRIBUTE_UNSEQUENCED
#  define _GL_ATTRIBUTE_UNSEQUENCED
# endif
#endif

/* A helper macro.  Don't use it directly.  */
#ifndef _GL_ATTRIBUTE_UNUSED
# if _GL_HAS_ATTRIBUTE (unused)
#  define _GL_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define _GL_ATTRIBUTE_UNUSED
# endif
#endif


/* _GL_UNUSED_LABEL; declares that it is not a programming mistake if the
   immediately preceding label is not used.  The compiler should not warn
   if the label is not used.  */
/* Applies to: label (both in C and C++).  */
/* Note that g++ < 4.5 does not support the '__attribute__ ((__unused__)) ;'
   syntax.  But clang does.  */
#ifndef _GL_UNUSED_LABEL
# if !(defined __cplusplus && !_GL_GNUC_PREREQ (4, 5)) || defined __clang__
#  define _GL_UNUSED_LABEL _GL_ATTRIBUTE_UNUSED
# else
#  define _GL_UNUSED_LABEL
# endif
#endif

/* The following attributes enable detection of multithread-safety problems
   and resource leaks at compile-time, by clang ≥ 15, when the warning option
   -Wthread-safety is enabled.  For usage, see
   <https://clang.llvm.org/docs/ThreadSafetyAnalysis.html>.  */
#ifndef _GL_ATTRIBUTE_CAPABILITY_TYPE
# if __clang_major__ >= 15
#  define _GL_ATTRIBUTE_CAPABILITY_TYPE(concept) \
     __attribute__ ((__capability__ (concept)))
#else
#  define _GL_ATTRIBUTE_CAPABILITY_TYPE(concept)
# endif
#endif
#ifndef _GL_ATTRIBUTE_ACQUIRE_CAPABILITY
# if __clang_major__ >= 15
#  define _GL_ATTRIBUTE_ACQUIRE_CAPABILITY(resource) \
     __attribute__ ((__acquire_capability__ (resource)))
# else
#  define _GL_ATTRIBUTE_ACQUIRE_CAPABILITY(resource)
# endif
#endif
#ifndef _GL_ATTRIBUTE_RELEASE_CAPABILITY
# if __clang_major__ >= 15
#  define _GL_ATTRIBUTE_RELEASE_CAPABILITY(resource) \
     __attribute__ ((__release_capability__ (resource)))
# else
#  define _GL_ATTRIBUTE_RELEASE_CAPABILITY(resource)
# endif
#endif


/* In C++, there is the concept of "language linkage", that encompasses
    name mangling and function calling conventions.
    The following macros start and end a block of "C" linkage.  */
#ifdef __cplusplus
# define _GL_BEGIN_C_LINKAGE extern "C" {
# define _GL_END_C_LINKAGE }
#else
# define _GL_BEGIN_C_LINKAGE
# define _GL_END_C_LINKAGE
#endif


/* Define to a type to use for 'error_t' if it is not otherwise available. */
#ifndef _libtextstyle_error_t
#define _libtextstyle_error_t int
#endif

/* Work around a bug in Apple GCC 4.0.1 build 5465: In C99 mode, it supports
   the ISO C 99 semantics of 'extern inline' (unlike the GNU C semantics of
   earlier versions), but does not display it by setting __GNUC_STDC_INLINE__.
   __APPLE__ && __MACH__ test for Mac OS X.
   __APPLE_CC__ tests for the Apple compiler and its version.
   __STDC_VERSION__ tests for the C99 mode.  */
#if defined __APPLE__ && defined __MACH__ && __APPLE_CC__ >= 5465 && !defined __cplusplus && __STDC_VERSION__ >= 199901L && !defined __GNUC_STDC_INLINE__
# define __GNUC_STDC_INLINE__ 1
#endif

/* _GL_CMP (n1, n2) performs a three-valued comparison on n1 vs. n2, where
   n1 and n2 are expressions without side effects, that evaluate to real
   numbers (excluding NaN).
   It returns
     1  if n1 > n2
     0  if n1 == n2
     -1 if n1 < n2
   The naïve code   (n1 > n2 ? 1 : n1 < n2 ? -1 : 0)  produces a conditional
   jump with nearly all GCC versions up to GCC 10.
   This variant     (n1 < n2 ? -1 : n1 > n2)  produces a conditional with many
   GCC versions up to GCC 9.
   The better code  (n1 > n2) - (n1 < n2)  from Hacker's Delight § 2-9
   avoids conditional jumps in all GCC versions >= 3.4.  */
#ifndef LIBTEXTSTYLE__GL_CMP
#define LIBTEXTSTYLE__GL_CMP(n1, n2) (((n1) > (n2)) - ((n1) < (n2)))
#endif


/* Define to 'int' if <sys/types.h> does not define. */
/* #undef mode_t */

/* Define to the type of st_nlink in struct stat, or a supertype. */
#ifndef _libtextstyle_nlink_t
#define _libtextstyle_nlink_t int
#endif

/* Define as a signed integer type capable of holding a process identifier. */
/* #undef pid_t */

/* Define to the equivalent of the C99 'restrict' keyword, or to
   nothing if this is not supported.  Do not define if restrict is
   supported only directly.  */
#ifndef _libtextstyle_restrict
#define _libtextstyle_restrict __restrict__
#endif
/* Work around a bug in older versions of Sun C++, which did not
   #define __restrict__ or support _Restrict or __restrict__
   even though the corresponding Sun C compiler ended up with
   "#define restrict _Restrict" or "#define restrict __restrict__"
   in the previous line.  This workaround can be removed once
   we assume Oracle Developer Studio 12.5 (2016) or later.  */
#if defined __SUNPRO_CC && !defined __RESTRICT && !defined __restrict__
# define _Restrict
# define __restrict__
#endif

/* Define as 'unsigned int' if <stddef.h> doesn't define. */
/* #undef size_t */

/* Define as a signed type of the same size as size_t. */
/* #undef ssize_t */

#ifndef HAVE_C_BOOL
# if !defined __cplusplus && !defined __bool_true_false_are_defined
#  if HAVE_STDBOOL_H
#   include <stdbool.h>
#  else
#   if defined __SUNPRO_C
#    error "<stdbool.h> is not usable with this configuration. To make it usable, add -D_STDC_C99= to $CC."
#   else
#    error "<stdbool.h> does not exist on this platform. Use gnulib module 'stdbool-c99' instead of gnulib module 'stdbool'."
#   endif
#  endif
# endif
# if !true
#  define true (!false)
# endif
#endif

#if (!defined HAVE_C_STATIC_ASSERT && !defined assert \
     && (!defined __cplusplus \
         || (__cpp_static_assert < 201411 \
             && __GNUG__ < 6 && __clang_major__ < 6)))
 #include <assert.h>
 #undef/**/assert
 #ifdef __sgi
  #undef/**/__ASSERT_H__
 #endif
 /* Solaris 11.4 <assert.h> defines static_assert as a macro with 2 arguments.
    We need it also to be invocable with a single argument.  */
 #if defined __sun && (__STDC_VERSION__ - 0 >= 201112L) && !defined __cplusplus
  #undef/**/static_assert
  #define static_assert _Static_assert
 #endif
#endif
 
/* once: _LIBTEXTSTYLE_CONFIG_H */
#endif
