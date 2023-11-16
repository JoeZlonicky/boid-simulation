# OpenGL Boid Simulation

An OpenGL boid simulation. Features include:

* Vector3, Vector4, Matrix3, Matrix4, Quaternion, and Transform implementations for the scope of the project.
* Window, Camera, Model, and Shader classes to encapsulate most of the raw OpenGL functions.
* Google Test library for unit testing all of the math classes.
* A demo showing off all the transform math/logic.

![Demo GIF](https://github.com/JoeZlonicky/opengl-demo/blob/master/Demo.gif)

## Running from CLI

1. `cmake -B build`
2. `cmake --build build --target opengl-demo`
3. `cd build`
4. `./opengl-demo`

## Testing from CLI

1. `cmake -B build`
2. `cmake --build build --target opengl-demo-tests`
3. `cd build`
4. `./opengl-demo-tests`
