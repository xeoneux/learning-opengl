#include "./include/glfw_app.hpp"

using namespace user;

struct MyApp : App {
  MyApp() : App() {}

  void onDraw() override {}

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
