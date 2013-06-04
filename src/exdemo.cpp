#include <cstdlib>
#include <iostream>
#include <vector>
#include <cmath>
#include <exru/exru.h>

using namespace std;

struct Pixel {
  float red;
  float green;
  float blue;
  float alpha;
};

int main(int argc, char**argv) {
  
  cout << "exdemo started...\n";

//  float f[4] = {1.0, 0.0, 1.0, 1.0};

  const int w = 1280, h = 720;
  vector<Pixel> pixels(w * h);
  for (int y = 0; y < h; ++y) {
    for (int x = 0; x < w; ++x) {
      pixels[y * w + x] = (Pixel){0.1 * sin(y * 0.1) * sin(x * 0.1), 
        sin(x * 0.06 * sin(y * 0.004)), 
            sin(0.04 * y + sin(x * 0.04)), 
            1.0};
    }
  }

  if (!write_rgba(w, h, "/tmp/externs.exr", reinterpret_cast<float*>(&pixels[0]))) {
    cout << "write_rgba failed\n";
  }

  return EXIT_SUCCESS;
}

