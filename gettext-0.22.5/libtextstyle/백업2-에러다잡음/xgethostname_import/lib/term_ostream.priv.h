#include "config.h"

#ifdef HAVE_WINDOWS_CONSOLES  
#include <windows.h>	      // HANDLE, WORD
#endif

#include <stdbool.h>		  // bool
#include <pthread.h>          // Mutex
#include <stdint.h>           // uint32_t, uint64_t
#include "ostream.priv.h"     // Include the header where any_ostream_representation is defined

#ifndef TTYCTL_T_H
#define TTYCTL_T_H
/* The amount of control to take over the underlying tty in order to avoid
   garbled output on the screen, due to interleaved output of escape sequences
   and output from the kernel (such as when the kernel echoes user's input
   or when the kernel prints '^C' after the user pressed Ctrl-C).  */
typedef enum
{
  TTYCTL_AUTO = 0,  /* Automatic best-possible choice.  */
  TTYCTL_NONE,      /* No control.
                       Result: Garbled output can occur, and the terminal can
                       be left in any state when the program is interrupted.  */
  TTYCTL_PARTIAL,   /* Signal handling.
                       Result: Garbled output can occur, but the terminal will
                       be left in the default state when the program is
                       interrupted.  */
  TTYCTL_FULL       /* Signal handling and disabling echo and flush-upon-signal.
                       Result: No garbled output, and the the terminal will
                       be left in the default state when the program is
                       interrupted.  */
} ttyctl_t;
#endif // TTYCTL_T_H

#ifndef BITFIELD_TYPE_H
#define BITFIELD_TYPE_H
/* ANSI C and ISO C99 6.7.2.1.(4) forbid use of bit fields for types other
   than 'int' or 'unsigned int'.
   On the other hand, C++ forbids conversion between enum types and integer
   types without an explicit cast.  */
#ifdef __cplusplus
# define BITFIELD_TYPE(orig_type,integer_type) orig_type
#else
# define BITFIELD_TYPE(orig_type,integer_type) integer_type
#endif
#endif // BITFIELD_TYPE_H

#ifndef OSTREAM_FLUSH_SCOPE_T_H
#define OSTREAM_FLUSH_SCOPE_T_H
/* Describes the scope of a flush operation.  */
typedef enum
{
  /* Flushes buffers in this ostream_t.
     Use this value if you want to write to the underlying ostream_t.  */
  FLUSH_THIS_STREAM = 0,
  /* Flushes all buffers in the current process.
     Use this value if you want to write to the same target through a
     different file descriptor or a FILE stream.  */
  FLUSH_THIS_PROCESS = 1,
  /* Flushes buffers in the current process and attempts to flush the buffers
     in the kernel.
     Use this value so that some other process (or the kernel itself)
     may write to the same target.  */
  FLUSH_ALL = 2
} ostream_flush_scope_t;
#endif // OSTREAM_FLUSH_SCOPE_T_H

#ifndef COLORMODEL_H
#define COLORMODEL_H
/* ============================= Color models ============================= */
/* The color model used by the terminal.  */
typedef enum
{
    cm_monochrome,        /* No colors.  */
    cm_common8,           /* Usual terminal with at least 8 colors.  */
    cm_xterm8,            /* TERM=xterm, with 8 colors.  */
    cm_xterm16,           /* TERM=xterm-16color, with 16 colors.  */
    cm_xterm88,           /* TERM=xterm-88color, with 88 colors.  */
    cm_xterm256,          /* TERM=xterm-256color, with 256 colors.  */
    cm_xtermrgb           /* TERM=xterm-direct, with 256*256*256 colors.  */
} colormodel_t;
#endif // COLORMODEL_H

#ifndef HYPERLINK_T_H
#define HYPERLINK_T_H
typedef struct {
    char *url;
    char *ref;
    char *id;
    char *real_id;
} hyperlink_t;
#endif // HYPERLINK_T_H

#ifndef ATTRIBUTES_T_H
#define ATTRIBUTES_T_H
typedef struct {
    BITFIELD_TYPE(term_color_t, signed int) color : 25;
    BITFIELD_TYPE(term_color_t, signed int) bgcolor : 25;
    BITFIELD_TYPE(term_weight_t, unsigned int) weight : 1;
    BITFIELD_TYPE(term_posture_t, unsigned int) posture : 1;
    BITFIELD_TYPE(term_underline_t, unsigned int) underline : 1;
    hyperlink_t *hyperlink;
} attributes_t;
#endif // ATTRIBUTES_T_H


#ifndef TERM_COLOR_T_H
#define TERM_COLOR_T_H
typedef int term_color_t;
#endif // TERM_COLOR_T_H


#ifndef COLOR_DEFAULT_H
#define COLOR_DEFAULT_H
enum
{
	COLOR_DEFAULT = -1  /* unknown */
};
#endif // COLOR_DEFAULT_H

#ifndef TERM_WEIGHT_T_H
#define TERM_WEIGHT_T_H
typedef enum
{
	WEIGHT_NORMAL = 0,
	WEIGHT_BOLD,
	WEIGHT_DEFAULT = WEIGHT_NORMAL
} term_weight_t;
#endif // TERM_WEIGHT_T_H

#ifndef TERM_POSTURE_T_H
#define TERM_POSTURE_T_H
typedef enum
{
	POSTURE_NORMAL = 0,
	POSTURE_ITALIC, /* same as oblique */
	POSTURE_DEFAULT = POSTURE_NORMAL
} term_posture_t;
#endif // TERM_POSTURE_T_H

#ifndef TERM_UNDERLINE_T_H
#define TERM_UNDERLINE_T_H
typedef enum
{
	UNDERLINE_OFF = 0,
	UNDERLINE_ON,
	UNDERLINE_DEFAULT = UNDERLINE_OFF
} term_underline_t;
#endif // TERM_UNDERLINE_T_H

#ifndef TERM_STYLE_CONTROL_H
#define TERM_STYLE_CONTROL_H
typedef struct term_style_control_data {
    int volatile fd;
    ttyctl_t volatile tty_control;     /* Terminal control */
    #if HAVE_TCGETATTR
    bool volatile same_as_stderr;
    #endif
    bool non_default_active;           /* Non-default mode status */
} term_style_control_data;
#endif // TERM_STYLE_CONTROL_H

#ifndef TERM_OSTREAM_REPRESENTATION_H
#define TERM_OSTREAM_REPRESENTATION_H

struct term_ostream_representation {
    struct ostream_representation base;
    int fd;
    #if HAVE_WINDOWS_CONSOLES
    HANDLE handle;
    bool is_windows_console;
    #endif
    char *filename;
    ttyctl_t tty_control;
    int max_colors;
    int no_color_video;
    char *set_a_foreground;
    char *set_foreground;
    char *set_a_background;
    char *set_background;
    char *orig_pair;
    char *enter_bold_mode;
    char *enter_italics_mode;
    char *exit_italics_mode;
    char *enter_underline_mode;
    char *exit_underline_mode;
    char *exit_attribute_mode;
    bool supports_foreground;
    bool supports_background;
    colormodel_t colormodel;
    bool supports_weight;
    bool supports_posture;
    bool supports_underline;
    bool supports_hyperlink;
    const char *restore_colors;
    const char *restore_weight;
    const char *restore_posture;
    const char *restore_underline;
    const char *restore_hyperlink;
    term_style_control_data control_data;
    uint32_t hostname_hash;
    uint64_t start_time;
    uint32_t id_serial;
    hyperlink_t **hyperlinks_array;
    size_t hyperlinks_count;
    size_t hyperlinks_allocated;
    #if HAVE_WINDOWS_CONSOLES
    WORD default_console_attributes;
    WORD current_console_attributes;
    #endif
    attributes_t default_attr;
    attributes_t active_attr;
    term_color_t active_attr_color;
    term_color_t active_attr_bgcolor;
    hyperlink_t *active_attr_hyperlink;
    char *buffer;
    attributes_t *attrbuffer;
    size_t buflen;
    size_t allocated;
    attributes_t curr_attr;
    attributes_t simp_attr;
    pthread_mutex_t mutex; // Mutex for thread safety
};

typedef struct term_ostream_representation any_ostream_representation;

#endif // TERM_OSTREAM_REPRESENTATION_H
