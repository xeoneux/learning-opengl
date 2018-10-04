#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include <stdlib.h>

using namespace std;

int main() {
  GLFWwindow *window;
  int w = 1024, h = 768;

  if (!glfwInit())
    exit(EXIT_FAILURE);

  window = glfwCreateWindow(w, h, "glfw", nullptr, nullptr);

  if (!window) {
    glfwTerminate();
    exit(EXIT_FAILURE);
  }

  glfwMakeContextCurrent(window);

  while (!glfwWindowShouldClose(window)) {
    glViewport(0, 0, w, h);
    glClearColor(1, 0, 0, 1);
    glClear(GL_COLOR_BUFFER_BIT);

    // Draw Code

    glfwSwapBuffers(window);
    glfwPollEvents();
  }

  glfwDestroyWindow(window);
  glfwTerminate();

  // Get Version String
  const GLubyte *p = glGetString(GL_VERSION);
  cout << "OpenGL Version: " << p << endl;
  return 0;
}
