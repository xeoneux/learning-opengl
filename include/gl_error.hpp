#ifndef gl_error_INC
#define gl_error_INC

#include "gl_lib.hpp"

namespace GL {

inline void error(std::string tmsg) {

  GLenum err = glGetError();

  const char *msg = tmsg.c_str();

  switch (err) {
  case GL_INVALID_ENUM:
    printf("%s:\n %s\n", msg,
           "An unacceptable value is specified for an enumerated argument. The "
           "offending command is ignored and has no other side effect than to "
           "set the error flag.");
    break;

  case GL_INVALID_VALUE:
    printf("%s:\n %s\n", msg,
           "A numeric argument is out of range. The offending command is "
           "ignored and has no other side effect than to set the error flag.");
    break;

  case GL_INVALID_OPERATION:
    printf("%s:\n %s\n", msg,
           "The specified operation is not allowed in the current state. The "
           "offending command is ignored and has no other side effect than to "
           "set the error flag.");
    break;

  case GL_INVALID_FRAMEBUFFER_OPERATION:
    printf("%s:\n %s\n", msg, "Framebuffer is Incomplete");
    break;

  case GL_STACK_OVERFLOW:
    printf(
        "%s:\n %s\n", msg,
        "This command would cause a stack overflow. The offending command is "
        "ignored and has no other side effect than to set the error flag.");
    break;

  case GL_STACK_UNDERFLOW:
    printf(
        "%s:\n %s\n", msg,
        "This command would cause a stack underflow. The offending command is "
        "ignored and has no other side effect than to set the error flag.");
    break;

  case GL_OUT_OF_MEMORY:
    printf("%s:\n %s\n", msg,
           "There is not enough memory left to execute the command.  The state "
           "of the GL is undefined, except for the state of the error flags, "
           "after this error is recorded.");
    break;

  case GL_NO_ERROR:
    break;

  default:
    break;
  }
}
} // namespace GL

#endif
