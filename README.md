The aim of this project if to implement the Practical Byzantine Fault Tolerance algorithm in C++, but with threads simulating the nodes.

For trying it you just have to clone the repo, go to the Make folder, create the build folder and compile using the CMakeLists.txt.

Commands for linux:
```bash
  git clone <>
  cd <>/Make
  mkdir build
  cd build
  cmake ../
  cmake --build .
```

From my little experience with CMake in Windows, the process is just the same but when configuring the build folder you will need to specify a compiler like MSVC.

The output is generated in the Bin folder. 
