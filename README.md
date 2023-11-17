# Boid Simulation

An OpenGL boid simulation. Features include:

* Boid simulation following the pseudocode outlined here: https://vergenet.net/~conrad/boids/pseudocode.html
* Vector3, Vector4, Matrix3, Matrix4, Quaternion, and Transform implementations for the scope of the project.
* Window, Camera, Model, and Shader classes to encapsulate most of the raw OpenGL functions.
* Google Test unit testing all of the math classes.

![Simulation GIF](https://github.com/JoeZlonicky/opengl-demo/blob/master/Simulation.gif)

## Running from CLI

1. `cmake -B build`
2. `cmake --build build --target boid-sim`
3. `cd build`
4. `./boid-sim`

## Testing from CLI

1. `cmake -B build`
2. `cmake --build build --target math-tests`
3. `cd build`
4. `./math-tests`
