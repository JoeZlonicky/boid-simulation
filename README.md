# Sim Engine

## GLFW Set-up (For Linux)
1. Download GLFW source (https://www.glfw.org/download)
2. Extract zip file and `cd` into folder
3. `cmake -S . -B build`
4. `cd build`
5. `make`
6. `sudo make install`

## Running
1. `mkdir build`
2. `cmake -B build`
3. `cmake --build build --target sim_engine`
4. `cd build`
5. `./sim_engine`