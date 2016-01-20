#Blocks

**<p style='color:red'>NOTICE: This project is currently being updated, for a working version please check the `Legacy` branch.</p>**

##Description:
Blocks is a 2D puzzle game where the objective is to rearrange the blocks (horizontally or vertically) so that you can push the red block out of the board. The blocks can only move in the direction of their orientation. Blocks positioned vertically can only move vertically, likewise, blocks positioned horizontally can only move horizontally. To slide a block, simply click on the block to select it and move the mouse, release the mouse to position the block. The number of moves and amount of time taken are displayed when the level is successfully completed.

##Supports:
- Microsoft Windows 7, 8, 8.1 and 10
- Linux based distributions

##Dependencies:
- `G++` or `Microsoft Visual Studio 2015` [(Community Edition)](https://www.visualstudio.com/en-us/downloads/download-visual-studio-vs.aspx)
- `SFML 32-bit` [(Build 2.3.2)](http://www.sfml-dev.org/download.php)
- `PhysicsFS` [(Build 2.0.3)](https://icculus.org/physfs/) **You will need to compile this from source**

##Build Instructions:

###Windows:
####Compiling PhysicsFS:
1. First download and install `Microsoft Visual Studio 2015`
2. Download and install [CMake](https://cmake.org/download/) Windows 32-bit installer
3. Download and extract the `PhysicsFS` [(2.0.3)](https://icculus.org/physfs/) source code
4. Create a new folder named `bin` in the same location as the extracted source code folder
5. Open `CMAKE (cmake-gui)`
6. Set the `Where is the source code:` to point to the extracted `physfs-2.0.3` folder
7. Set the `Where to build the binaries:` to point to the `bin` folder you've created
8. Click `Generate` and select `Visual Studio 14 2015` as the generator for this project then click `Finish`
9. Click `Configure` and then close `CMAKE`
10. Navigate to the `bin` folder and open `PhysicsFS.sln` with `Microsoft Visual Studio 2015`
11. Set the `Solutions Configurations` to `Release` and set the `Solutions Platform` to `Win32`
12. Right click  `ALL_BUILD` in the `Class View` pane and select `Build`
13. Create a new folder called `PHYSFS-2.0.3` at `C:\` and create the following folders inside of it: `bin`, `include` and `lib`
14. Navigate to your `bin\release` folder, copy `physfs.dll` and `test_physfs.exe` to `C:\PHYSFS-2.0.3\bin`
15. Copy the remaining files `physfs.exp`, `physfs.lib`, `test_physfs.exp` and `test_physfs.lib` to `C:\PHYSFS-2.0.3\lib`
16. Navigate to the extracted PhysicsFS source code folder `physfs-2.0.3` and copy all the folders, `.h` and `.c` files to `C:\PHYSFS-2.0.3\include`
17. Delete the extracted PhysicsFS source code folder `physfs-2.0.3` and the `bin` folder

####Compiling Blocks:
1. Clone the repo to obtain the project and source code
2. Download `SFML` Visual C++ 14 32-bit version build 2.3.2 and extract it to `C:\`
3. Open the project solution, `Blocks.sln` in `Microsoft Visual Studio 2015`
4. Set the `Solutions Configurations` to `Release` and set the `Solutions Platform` to `x86`
5. Right click the `Blocks` project in the `Class View` pane and select `Build`
6. If successful, `Blocks.exe` will build in the `Release` folder in your repo's root folder
7. Copy the `Data.7z` resource file from `Blocks\Resources` to the `Release` folder where `Blocks.exe` is located
8. Execute `Blocks.exe` to launch the application

###Linux:
####Compiling PhysicsFS:
1. Download and extract `PhysicsFS` [(2.0.3)](https://icculus.org/physfs/) source code
2. Open terminal as root and type `sudo apt-get install cmake` to install CMake
3. Use the terminal to navigate to the extracted `PhysicsFS` source code folder `physfs-2.0.3`
4. Create a new folder called `bin` and navigate to it by typing `mkdir bin && cd bin` into the terminal
5. Generate the Makefiles by typing `cmake ..` into the terminal
6. Type `make` into the terminal to build `PhysicsFS`
7. Type `sudo make install` to install the `PhysicsFS` library
8. Type `sudo ldconfig` to configure the shared library cache with the `PhysicsFS` library
9. Delete the extracted PhysicsFS source code folder `physfs-2.0.3` and the `bin` folder

####Compiling Blocks:
1. Clone the repo to obtain the project and source code
2. Open terminal as root and type `sudo apt-get install libsfml-dev` to install the latest official release of SFML
3. From the cloned repo, navigate to the source code by typing `cd Blocks` in the terminal
4. Type `make` into the terminal to compile the project
5. Copy the `Data.7z` resource file from `/Resources` by typing `cp Resources/Data.7z .` in the terminal
6. Launch the app by typing `./Blocks &` in the terminal

##License:
Copyright (c) 2016 Salinder Sidhu

Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the "Software"), to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
