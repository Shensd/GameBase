# GraphicsEngine
This is a basic graphics/game engine written in C++ with allegro

## What is this?
I had recently come across a game engine method I really like in java, and probably against better judgement this is my attempt of porting it over to C++. I don't generally use C++ so this was more or less a way to try to understand how classes work together in it. I would describe that it falls most in line with the MVC design approach.

## What are the Features?
 * Largely based off of states, which can be changed at any time in order to better organize level segments
 * Uses [Allegro 5](http://liballeg.org/) to draw graphics
 * Probably includes many don'ts of C++

## What are Future Plans for this Project?
 * Add more states to better show functionality
 * Add a basic menu state
 * Support more shapes in the graphics controller
 * Add fill shapes and not just drawn shapes to graphics controller

## How do I Compile it?
 * If compiling under Visual Studio 2015:
   * Install Allegro 5 using Nuget
   * Right click project > Allegro 5 > Add-ons
     * Change Primitives Addon and Color Addon to Yes 
   * Change SubSystem from `Console` to `Windows`
   * Build project
 * If compiling via command line:
   * https://wiki.allegro.cc/index.php?title=Compiling_Allegro_Programs


###### This project is licensed under the MIT Open Source License
