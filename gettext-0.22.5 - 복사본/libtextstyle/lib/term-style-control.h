#ifndef _TERM_STYLE_CONTROL_H
#define _TERM_STYLE_CONTROL_H

#include <stdbool.h>  /* bool type for boolean values */

#include "term_ostream.priv.h" //struct term_ostream_representation
//#include "ostream.h"  //typedef struct term_ostream_representation* ostream_t;
//#include "textstyle.h" //typedef term_ostream_representation any_ostream_representation;

#if !_GL_CONFIG_H_INCLUDED
 #error "Please include config.h first."
#endif

// term_ostream.priv.h 로 이동
// typedef struct term_style_control_data {
//     int volatile fd;
//     ttyctl_t volatile tty_control;     /* Terminal control */
//     #if HAVE_TCGETATTR
//     bool volatile same_as_stderr;
//     #endif
//     bool non_default_active;           /* Non-default mode status */
// } term_style_control_data;

typedef struct term_style_user_data {
    term_style_control_data *control_data;  /* Control data for terminal style */
    int some_terminal_setting;  /* Additional terminal settings */
    void (*custom_style_function)(void);  /* Function pointer for custom styling */
    bool is_active;  /* Status flag */
} term_style_user_data;

typedef term_style_control_data *(*get_control_data_func)(term_style_user_data *);

/* Struct containing function pointers for terminal style control */
struct term_style_controller {
    term_style_control_data *(*get_control_data)(term_style_user_data *);  /* Function to get control data */
    void (*restore)(term_style_user_data *);  /* Restore terminal to default state */
    _GL_ASYNC_SAFE void (*async_restore)(term_style_user_data *);  /* Async-safe restore function */
    _GL_ASYNC_SAFE void (*async_set_attributes_from_default)(term_style_user_data *);  /* Set attributes from default */
};

#ifdef __cplusplus
extern "C" {
#endif

extern void activate_term_style_controller(const struct term_style_controller *controller,
                                           term_style_user_data *user_data,
                                           int fd, ttyctl_t tty_control);

extern void activate_term_non_default_mode(const struct term_style_controller *controller,
                                           term_style_user_data *user_data);

extern void deactivate_term_non_default_mode(const struct term_style_controller *controller,
                                             term_style_user_data *user_data);

extern void deactivate_term_style_controller(const struct term_style_controller *controller,
                                             term_style_user_data *user_data);

#ifdef __cplusplus
}
#endif

#endif /* _TERM_STYLE_CONTROL_H */
