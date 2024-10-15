# ft_FdF

<br>
<img align="left" height="250" src="https://github.com/42kmira/ft_FdF/blob/master/resources/Untitled.png" />
<br>

This is the first of the graphics projects in the graphics branch. This project involves reading a map, some example maps
are in the [maps folder](https://github.com/42kmira/ft_FdF/tree/master/maps), and converting that map into a 3D wireframe.
It uses a basic graphics library, one that interacts with the kernel to announce key events, make a window, and draw raw pixels on said window,
called minilibx.

The library does not have powerful drawing functions, the purpose was for the programmer to write their own [draw line functions](https://github.com/42kmira/ft_FdF/blob/9992fffc91638176aeee362450b50f96bef038b2/srcs/rendering.c#L64), [matrix/projection functions](https://github.com/42kmira/ft_FdF/blob/master/srcs/transformations.c), and other key functions. 

This project was entirely done in C. Rotations, translation and zoom were implemented from scratch. How keys presses are handled
was up to the programmer. These keys are non blocking i.e. multiple keys can be pressed at the same time. The controls are:

Rotation:

```
Numpad 8
Numpad 2
Numpad 4
Numpad 6
```

Translation:
```
Arrow Left
Arrow Right
Arrow Up
Arrow Down
```

Zoom:
```
Z
X
```

Change Map Height:
```
<
>
```

<br>
<img align="top" height="450" src="https://github.com/42kmira/ft_FdF/blob/master/resources/elem_col.gif" />
<br>

Also supports RGB maps!

<br>
<img align="bottom" height="450" src="https://github.com/42kmira/ft_FdF/blob/master/resources/t1.gif" />
<br>

