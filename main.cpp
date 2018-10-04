#include "./include/glfw_app.hpp"
#include <math.h>

using namespace user;

struct MyApp : App {
  MyApp() : App() {}

  void drawTriangle() {
    glBegin(GL_TRIANGLES);
    glColor3f(1, 0, 0);
    glVertex3f(-1, 0, 0);
    glColor3f(0, 1, 0);
    glVertex3f(0, 1, 0);
    glColor3f(0, 0, 1);
    glVertex3f(1, 0, 0);
    glEnd();
  }

  void onDraw() override {
    static float counter = 0.0;
    counter += .01;

    int width = MyApp::mWindow.mWidth;
    int height = MyApp::mWindow.mHeight;

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-(float)width / height, (float)width / height, -1.f, 1.f, 1.f,
            -1.f);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    for (int i = 0; i < 10; i++) {
      float t = (float)i / 10;
      glPushMatrix();

      glTranslatef(t * sin(counter), 0, 0);
      glRotatef(360 * t * counter, 0, 0, 1);
      glScalef(1 - t, 1 - t, 1 - t);

      drawTriangle();

      glPopMatrix();
    }
  }

  void onMouseMove(int x, int y) override { cout << x << " " << y << endl; }

  void onMouseDown(int button, int action) override {
    if (action == GLFW_PRESS)
      cout << "mouse pressed" << endl;
    if (action == GLFW_RELEASE)
      cout << "mouse released" << endl;
  }

  void onKeyDown(int key, int action) override {
    cout << (unsigned char)key << endl;
  }
};

int main() {
  MyApp app;
  app.start();
}
