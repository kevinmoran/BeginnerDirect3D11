# Beginner Direct3D11 Programming

This is my starter code for Direct3D11 graphics programming on Windows in a simple, procedural (C-like) style.

Released into the public domain under the Unlicense, see LICENSE.txt. No warranty is implied.

## Code style and ethos

This repository is provided as the resource I wish I had for learning Direct3D11. While tutorials and other samples exist, they are often overcomplicated for simply illustrating basic usage of the API to a beginner. In particular I've seen the simplest code for drawing a triangle split up into several classes and files which make the code flow very hard to follow.

My goal is to provide a straightforward, linear series of API calls that you can follow along with; everything is written in a procedural (C-like) style rather than abstracting code away into container classes. As a result this 

This is *not* intended to be a tutorial. If you are using this as a learning resource you will have to look up the documentation for the Win32 and Direct3D structs/functions being used to get a good understanding of what is being done and why. I think it's much more valuable to provide working code as a reference that you can explore and play around with rather than writing pages explaining what each line of code does. 

To any beginners reading this: Learning a 3D graphics API is tricky. You invariably have to learn 10 new concepts at once at all times. Rather than learning from the bottom up (i.e. understanding *every* line of code before moving on) I advise you to try and get the general idea for most things as you go, play around and slowly build up your knowledge. You will probably feel a bit overwhelmed at times, but with patience and persistence you will eventually have 'Eureka' moments where things click into place. If you have any questions I'll be happy to answer them.

To any non-beginners reading this: If you notice and mistakes/areas for improvement please let me know.

## Building the source code

Compilation is handled using simple batch (`.bat`) files. You will have to install [Visual Studio](https://visualstudio.microsoft.com/) to use the MSVC compiler if you haven't already (the Community version is free).

To call the Microsoft compiler from the command-line or in a batch file you need to call a special script call `vcvarsall`. In each `build.bat` script I've included a list of paths to this file for each version of Visual Studio. Uncomment only the one you have installed in each batch file and you should be good to go.

Once you have all that done, compiling should be as easy as opening a command line window, navigating to a directory containing a `build.bat` script and running it like so:

```
build.bat
```

This will create a build directory containing an executable `main.exe` that you can run.

Additionally I have included configuration files for building/running the code using [VSCode](https://code.visualstudio.com/), my editor of choice. If you open one of the project folders in VSCode you should be able to build and run using the `Run Build Task` and `Start Debugging` commands.

## Resources
These are online resources I found helpful when learning the basics of Direct3D11/Win32 programming.

* [Handmade Hero by Casey Muratori](http://www.handmadehero.org)
* [Minimal D3D11 Reference by d7samurai](https://gist.github.com/d7samurai/261c69490cce0620d0bfc93003cd1052)
* [Introduction to DirectX 11 by Jeremiah van Oosten](https://www.3dgep.com/introduction-to-directx-11/)
* [DirectXTutorial.com by Chris Hanson](http://www.directxtutorial.com/LessonList.aspx?listid=11)
