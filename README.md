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
This project is compiled with Visual Studio Community 2015 default settings, the only thing to change is the SubSystem from Console to Windows in order to hide the console window when running.


###### This project is licensed under the MIT Open Source License
