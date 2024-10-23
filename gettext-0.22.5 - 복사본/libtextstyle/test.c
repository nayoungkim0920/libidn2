#define _GL_EXTERN_C_FUNC extern

#define _GL_FUNCDECL_RPL(func, rettype, parameters, ...) \
  _GL_FUNCDECL_RPL_1(rpl_##func, rettype, parameters, ##__VA_ARGS__)

#define _GL_FUNCDECL_RPL_1(rpl_func, rettype, parameters, ...) \
  _GL_EXTERN_C_FUNC rettype rpl_func parameters

_GL_FUNCDECL_RPL(free, void, (void *ptr));