# TETRIS

Regular old Tetris... kinda sorta. Just a project to learn some new concepts
<br> 

# Running Game
First, clone repo
<br>
```git clone https://github.com/jevon-23/tetris && cd tetris```
<br>

Next, using compile cmake
<br>
```cmake . & cmake --build . & make ```
<br>

Run executable to see some functionality. Game shuold have a block fall straight down in a couple of different spots, and eventually segfault
<br>
``` ./tetris ```
<br>

# Why
Originally, I began making this because I was interested in building some front end, and learning more about SDL/SDL2!!
<br>

I tried to make OOP because everything will be a block structure, which was a very interesting exercise. 
<br> 
I created a block struct, and I casted it to be the type of block that is associated w/ the different types of blocks in Tetris (SQUARE, LINE, SNAKE, etc.).
Embeded within that struct is the type of block we are delaing w/, and pointers to its associated functions. This allowed me to make an api that through my block struct. For example, the code is written such that:
<br>
```block *b = make_block({block_type});``` <br>
```b = move_block_down(game_board, block)```<br>
Under the hood though, simply does some checking for collision and runs <br>```block->move_block()```<br>

This means that instead of using a bunch of switch casess for functional flow, we use one switch statement to determine which init function to call, and inside the init function set the embedded function pointers to point to the functions associated w/ block_type, and call those functions directly from our higher level code.
<br>

Lastly, I finally got some time to touch sdl2/sdl. I got the chance to learn a little bit about the difference of a renderer vs a surface, (which from what I understand, renderer actually calls all of the surface functionality).

<br>
