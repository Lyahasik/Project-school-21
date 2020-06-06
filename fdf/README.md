# Fdf

The aim of the project is to visualize a three-dimensional landscape on a height map. For implementation,
the Minilibx graphics library is provided.
The capabilities of this library allow you to get acquainted with rendering in a simplified form.

In this implementation, it is possible:
- scaling
- moving an object with a mouse inside a limited area
- object rotation
- color change
- change of height

For drawing lines, the **Xiaolin Wu's line** algorithm was used.
Rotation is done using **Euler angles**.

The [`fdf.en.pdf`](/fdf/fdf.en.pdf) file contains the technical documentation of the project.

## How to use on MACos
 
1. go to the "Realization" folder
2. run the `make` command to create the **"fdf"** binary
3. run the program with the card to read `./fdf maps/name_map.fdf`
