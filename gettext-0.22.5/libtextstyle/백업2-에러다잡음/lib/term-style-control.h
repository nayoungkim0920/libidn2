#ifndef _TERM_STYLE_CONTROL_H
#define _TERM_STYLE_CONTROL_H

#include <stdbool.h>  /* bool type for boolean values */
#include <signal.h>
#include "term_ostream.priv.h" //struct term_ostream_representation
#include "term-ostream.h" //term_ostream_t
//#include "ostream.h"  //typedef struct term_ostream_representation* ostream_t;
//#include "textstyle.h" //typedef term_ostream_representation any_ostream_representation;

#if !_GL_CONFIG_H_INCLUDED
 #error "Please include config.h first."
#endif

#ifdef _WIN32 // window는 posix를 완벽히지원하지 않음. Windows API SetConsoleCtrlHandler 콘솔신호유사기능 구현
typedef unsigned int sigset_t;

#ifndef sigemptyset
extern int sigemptyset(sigset_t *set) {
    if (set) {
        *set = 0;
        return 0;
    }
    return -1;
}
#endif

#ifndef sigaddset
extern int sigaddset(sigset_t *set, int signal) {
    if (set && signal > 0 && signal < 32) {
        *set |= (1U << signal);
        return 0;
    }
    return -1;
}
#endif

#ifndef sigprocmask
extern int sigprocmask(int how, const sigset_t *set, sigset_t *oldset) {
	(void)how;  // 사용하지 않음을 명시
	(void)set; // 사용하지 않음을 명시
	(void)oldset; // 사용하지 않음을 명시
    return 0;
}
#endif

#endif /* _WIN32 */




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

/* Struct containing function pointers for terminal style control */
// struct term_style_controller {
//     term_style_control_data *(*get_control_data)(term_style_user_data *);  /* Function to get control data */
//     void (*restore)(term_style_user_data *);  /* Restore terminal to default state */
//     _GL_ASYNC_SAFE void (*async_restore)(term_style_user_data *);  /* Async-safe restore function */
//     _GL_ASYNC_SAFE void (*async_set_attributes_from_default)(term_style_user_data *);  /* Set attributes from default */
// };

struct term_style_controller {
    term_style_control_data *(*get_control_data)(term_style_user_data *);  /* Function to get control data */
    void (*restore)(struct term_ostream_representation *);  /* Restore terminal to default state */
    //void (*restore)(struct term_style_user_data *);
	_GL_ASYNC_SAFE void (*async_restore)(struct term_ostream_representation *);  /* Async-safe restore function */
    _GL_ASYNC_SAFE void (*async_set_attributes_from_default)(struct term_ostream_representation *);  /* Set attributes from default */
};

#ifdef __cplusplus
extern "C" {
#endif

extern void activate_term_style_controller(const struct term_style_controller *controller,
                                           term_style_user_data *user_data,
                                           int fd, ttyctl_t tty_control);

extern void activate_term_non_default_mode(const struct term_style_controller *controller,
											struct term_ostream_representation *user_data);
                                           //term_style_user_data *user_data);

extern void deactivate_term_non_default_mode(const struct term_style_controller *controller,
											 struct term_ostream_representation *user_data);
                                             //term_style_user_data *user_data);

extern void deactivate_term_style_controller(const struct term_style_controller *controller,
                                             struct term_ostream_representation *user_data);
											 //term_style_user_data *user_data);

#ifdef __cplusplus
}
#endif

#endif /* _TERM_STYLE_CONTROL_H */