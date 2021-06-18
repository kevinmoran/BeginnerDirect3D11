# Beginner Direct3D11 Programming

This is my starter code for Direct3D11 graphics programming on Windows in a simple, procedural (C-like) style.

No external dependencies, uses [stb_image](https://github.com/nothings/stb) for loading textures and minimal CRT features.

Released into the public domain under the Unlicense, see LICENSE.txt. No warranty is implied.

## Code style and ethos

This repository is provided as the resource I wish I had for learning Direct3D11. While tutorials and other samples exist, they are often overcomplicated for simply illustrating basic usage of the API to a beginner. In particular I've seen the simplest code for drawing a triangle split up into several classes and files which make the code flow very hard to follow. 

My goal is to provide a straightforward, linear series of API calls that you can follow along with; everything is written in a procedural (C-like) style rather than abstracting code away into container classes. It is a simplified starting point to get you started instead of production-ready code.

Additionally I have split this repo into smaller sub-projects that gradually introduce new concepts important for realtime graphics and game programming. Hopefully this makes approaching these topics a bit easier.

This is *not* intended to be a tutorial. If you are using this as a learning resource you will have to look up the documentation for the Win32 and Direct3D structs/functions being used to get a good understanding of what is being done and why. I think it's much more valuable to provide working code as a reference that you can explore and play around with rather than writing pages explaining what each line of code does. 

To any beginners reading this: Learning a 3D graphics API is tricky. You invariably have to learn 10 new concepts at once at all times. Rather than learning from the bottom up (i.e. understanding *every* line of code before moving on) I advise you to try and get the general idea for most things as you go, play around and slowly build up your knowledge. You will probably feel a bit overwhelmed at times, but with patience and persistence you will eventually have 'Eureka' moments where things click into place. If you have any questions I'll be happy to answer them.

To any non-beginners reading this: If you notice any mistakes/areas for improvement please let me know.

## Building the source code

Compilation for each sub-project is handled using a simple batch file called `build.bat`, you can also use the provided Visual Studio 2019 solution. 

For using the solution or batch files, you will have to install [Visual Studio](https://visualstudio.microsoft.com/) to use the MSVC compiler if you haven't already (the Community version is free). Or if you want to make your own CMake projects it should be really easy, there are very few files and fairly straightforward compiler arguments!

To call the Microsoft compiler from the command-line or in a batch file you need to set up your command line environment so it knows where to find the compiler executable (this is weird and it's a bit annoying that installing Visual Studio doesn't just handle this for you). There are two ways to do this: 
* The easiest is to use the special command prompt that Visual Studio sets up for you on installation. For VS2019 it is called "Developer Command Prompt for VS 2019". If you open the Start menu and search `vs` it should show up. 
* Alternatively you can open a regular command prompt and call a special script named `vcvarsall`. You can (hopefully) find it in one of the following locations, depending on the version of Visual Studio you're using:
```
C:\Program Files (x86)\Microsoft Visual Studio 10.0\VC\vcvarsall.bat
C:\Program Files (x86)\Microsoft Visual Studio 11.0\VC\vcvarsall.bat
C:\Program Files (x86)\Microsoft Visual Studio 12.0\VC\vcvarsall.bat
C:\Program Files (x86)\Microsoft Visual Studio 13.0\VC\vcvarsall.bat
C:\Program Files (x86)\Microsoft Visual Studio 14.0\VC\vcvarsall.bat
C:\Program Files (x86)\Microsoft Visual Studio\2017\Community\VC\Auxiliary\Build\vcvarsall.bat
C:\Program Files (x86)\Microsoft Visual Studio\2019\Community\VC\Auxiliary\Build\vcvarsall.bat
```

Once you have your command line set up in either way, you can compile each subproject by navigating with `cd` to a directory containing a `build.bat` script and running it like so:
```
build.bat
```

This will create a directory called `build` containing an executable `main.exe` that you can run.

Additionally I have included configuration files for building/running the code using [VSCode](https://code.visualstudio.com/), my editor of choice. Once you have your command line interface set up as explained above simply run the command `code` to launch VS Code. Now if you open one of the project folders in VSCode you should be able to build and run using the `Run Build Task` and `Start Debugging` commands.

If you try to build one of the subprojects and you get the following error message it means that you haven't set up your command line properly because it does not recognised the compiler executable `cl.exe`:
```
'cl' is not recognized as an internal or external command,
operable program or batch file.
```

## Resources
These are online resources I found helpful when learning the basics of Direct3D11/Win32 programming.

* [Handmade Hero by Casey Muratori](http://www.handmadehero.org)
* [Minimal D3D11 Reference by d7samurai](https://gist.github.com/d7samurai/261c69490cce0620d0bfc93003cd1052)
* [Introduction to DirectX 11 by Jeremiah van Oosten](https://www.3dgep.com/introduction-to-directx-11/)
* [DirectXTutorial.com by Chris Hanson](http://www.directxtutorial.com/LessonList.aspx?listid=11)
* [Direct3D 11 Functional Specification](https://microsoft.github.io/DirectX-Specs/d3d/archive/D3D11_3_FunctionalSpec.htm) Thanks to Github user procedural for the suggestion
* [Official Microsoft Programming Guide for Direct3D 11](https://docs.microsoft.com/en-us/windows/win32/direct3d11/dx-graphics-overviews)
* ["Properly handling keyboard input" by Stefan Reinalter](https://blog.molecular-matters.com/2011/09/05/properly-handling-keyboard-input/). Great blog post exploring the different Windows input APIs and their idiosyncracies. [[WayBack Archive]](https://web.archive.org/web/20190406180221/https://blog.molecular-matters.com/2011/09/05/properly-handling-keyboard-input/)

## Acknowledgements

* Thanks to [chanibal](https://github.com/chanibal) for setting up a Visual Studio solution.
