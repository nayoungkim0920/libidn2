#ifndef _OSTREAM_H
#define _OSTREAM_H

#include <stdarg.h>
#include <stddef.h>
#include <string.h>

#include "moo.h"
#include "term_ostream.priv.h" // term_style_control_data, hyperlink_t, attributes_t
//#include "textstyle.h"         // ostream_flush_scope_t
// typedef FILE * ostream_t;
// #if IS_CPLUSPLUS
// typedef ostream_t term_ostream_t;
// #else
// typedef struct any_ostream_representation * term_ostream_t;
// #endif 
//#include "term-ostream.h"      // term_ostream_t
// typedef struct term_ostream_representation* ostream_t;
// #if IS_CPLUSPLUS
// typedef ostream_t term_ostream_t;
// #else
// typedef struct any_ostream_representation * term_ostream_t;
// #endif 

#if defined(__cplusplus)
extern "C" {
#endif

#if IS_CPLUSPLUS

struct ostream_t {
private:
  struct term_ostream_representation *_pointer;
public:
  ostream_t() : _pointer(nullptr) {}
  ostream_t(struct term_ostream_representation *pointer) : _pointer(pointer) {}
  struct term_ostream_representation* operator->() { return _pointer; }
  operator struct term_ostream_representation*() { return _pointer; }
  operator void*() { return _pointer; }
  bool operator==(const void *p) { return _pointer == p; }
  bool operator!=(const void *p) { return _pointer != p; }
};

#else
typedef struct term_ostream_representation* ostream_t;
#endif

#if defined(__cplusplus)
}
#endif

/* Function declarations */
#ifdef __cplusplus
extern "C" {
#endif

extern void ostream_write_mem(ostream_t first_arg, const void *data, size_t len);
extern void ostream_flush(ostream_t first_arg, ostream_flush_scope_t scope);
extern void ostream_free(ostream_t first_arg);

#ifdef __cplusplus
}
#endif

/* Type representing an implementation of ostream_t. */
struct ostream_implementation
{
  const typeinfo_t * const *superclasses;
  size_t superclasses_length;
  size_t instance_size;
#define THIS_ARG ostream_t first_arg
#include "ostream.vt.h"
#undef THIS_ARG
};

/* Public portion of the object pointed to by an ostream_t. */
struct ostream_representation_header
{
  const struct ostream_implementation *vtable;
};

#if HAVE_INLINE

/* Define the functions that invoke the methods as inline accesses to
   the ostream_implementation.  */

# define ostream_write_mem ostream_write_mem_inline
static inline void
ostream_write_mem(ostream_t first_arg, const void *data, size_t len)
{
  const struct ostream_implementation *vtable =
    ((struct ostream_representation_header *) (struct term_ostream_representation *) first_arg)->vtable;
  vtable->write_mem(first_arg, data, len);
}

# define ostream_flush ostream_flush_inline
static inline void
ostream_flush(ostream_t first_arg, ostream_flush_scope_t scope)
{
  const struct ostream_implementation *vtable =
    ((struct ostream_representation_header *) (struct term_ostream_representation *) first_arg)->vtable;
  vtable->flush(first_arg, scope);
}

# define ostream_free ostream_free_inline
static inline void
ostream_free(ostream_t first_arg)
{
  const struct ostream_implementation *vtable =
    ((struct ostream_representation_header *) (struct term_ostream_representation *) first_arg)->vtable;
  vtable->free(first_arg);
}

#endif

extern const typeinfo_t ostream_typeinfo;
#define ostream_SUPERCLASSES &ostream_typeinfo, NULL
#define ostream_SUPERCLASSES_LENGTH (1 + 1)

extern const struct ostream_implementation ostream_vtable;

#ifdef __cplusplus
extern "C" {
#endif

/* Write a string's contents to a stream. */
extern void ostream_write_str(ostream_t stream, const char *string);

/* Writes formatted output to a stream.
   Returns the size of formatted output, or a negative value in case of an
   error. */
extern ptrdiff_t ostream_printf(ostream_t stream, const char *format, ...)
#if (__GNUC__ == 3 && __GNUC_MINOR__ >= 1) || __GNUC__ > 3
  __attribute__ ((__format__ (__printf__, 2, 3)))
#endif
  ;
extern ptrdiff_t ostream_vprintf(ostream_t stream,
                                  const char *format, va_list args)
#if (__GNUC__ == 3 && __GNUC_MINOR__ >= 1) || __GNUC__ > 3
  __attribute__ ((__format__ (__printf__, 2, 0)))
#endif
  ;

#if HAVE_INLINE

#define ostream_write_str ostream_write_str_inline
static inline void
ostream_write_str(ostream_t stream, const char *string)
{
  ostream_write_mem(stream, string, strlen(string));
}

#endif

#ifdef __cplusplus
}
#endif

#endif /* _OSTREAM_H */
