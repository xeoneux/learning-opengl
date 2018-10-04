#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include <stdlib.h>

using namespace std;

int main() {
  GLFWwindow *window;

  if (!glfwInit())
    exit(EXIT_FAILURE);

  window = glfwCreateWindow(1024, 768, "glfw", nullptr, nullptr);

  if (!window) {
    glfwTerminate();
    exit(EXIT_FAILURE);
  }

  glfwMakeContextCurrent(window);

  // Get Version String
  const GLubyte *p = glGetString(GL_VERSION);
  cout << "OpenGL Version: " << p << endl;
  return 0;
}
