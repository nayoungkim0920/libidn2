#ifndef COLOR_H
#define COLOR_H

/* 다른 헤더 파일 포함 */
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>

#include "term-ostream.h"

// #ifdef LIBTEXTSTYLE_DLL_EXPORTS
// #define LIBTEXTSTYLE_DLL_VARIABLE __declspec(dllexport)
// #else
// #define LIBTEXTSTYLE_DLL_VARIABLE __declspec(dllimport)
// #endif

typedef enum {
    color_no,
    color_tty,
    color_yes,
    color_html
} color_option;

#ifdef _WIN32
  #ifdef BUILDING_DLL
    #define DLLIMPORT __declspec(dllexport)
  #else
    #define DLLIMPORT __declspec(dllimport)
  #endif
#else
  #define DLLIMPORT
#endif

#ifdef __cplusplus
extern "C" {
#endif

// extern LIBTEXTSTYLE_DLL_VARIABLE bool color_test_mode;
// extern LIBTEXTSTYLE_DLL_VARIABLE enum color_option color_mode;
// extern LIBTEXTSTYLE_DLL_VARIABLE const char *style_file_name;

extern bool handle_color_option(const char *option);
extern void handle_style_option(const char *option);
extern void print_color_test(void);
extern void style_file_prepare(const char *style_file_envvar, const char *default_style_file_name);

#ifdef __cplusplus
}
#endif

#endif /* COLOR_H */