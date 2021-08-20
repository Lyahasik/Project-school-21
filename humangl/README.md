# humangl

The project allows you to load 3D models in various formats, display them on the screen and play the animation.
Implemented using OpenGL, Assimp. Allows you to change the size of the mesh in real time.

<img src="https://s6.gifyu.com/images/Untitled-_online-video-cutter.com_.md.gif">

Models are stored in Resources/Models.
To change the model, replace the file name on line 20 in Resources/Scenes/Main.yaml.

## Installation

You need CMake. Then you do :

```
./Tools/InstallLibraries.sh
./Tools/BuildProject.sh
```

## Controls

* w/a/s/d/space - movement
* left mouse button dragging - camera rotation
* command + left/right arrow - select mesh
* +/- resize mesh (when a mesh is selected)

## Resources

* [Matrix Algebra and Game Programming](https://www.gameludere.com/2019/12/21/matrix-algebra-and-game-programming/#Rotation_matrices)
* [Mouse Picking with Ray Casting](https://antongerdelan.net/opengl/raycasting.html)
