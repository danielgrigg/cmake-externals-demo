#include <cstdlib>
#include <iostream>
#include <exru/exru.h>

using namespace std;

int main(int argc, char**argv) {
  
  cout << "exdemo started...\n";

  float f[4] = {1.0, 0.0, 1.0, 1.0};

  if (!write_rgba(1, 1, "/tmp/externs.exr", f)) {
    cout << "write_rgba failed\n";
  }

  return EXIT_SUCCESS;
}

