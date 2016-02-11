#Blocks

##Description:
Blocks is a 2D puzzle game where the objective is to rearrange the blocks (horizontally or vertically) so that you can push the red block out of the board. The blocks can only move in the direction of their orientation. Blocks positioned vertically can only move vertically, likewise, blocks positioned horizontally can only move horizontally. To slide a block, simply click on the block to select it and move the mouse, release the mouse to position the block. The number of moves and amount of time taken are displayed when the level is successfully completed.
<p align="center">
	<img src="http://i1379.photobucket.com/albums/ah129/SalinderSid/screenshot1_zpsiq71k6xv.png" alt="Main Menu"/>
	<img src="http://i1379.photobucket.com/albums/ah129/SalinderSid/screenshot2_zpswnvgdof9.png" alt="Level 1"/>
    <img src="http://i1379.photobucket.com/albums/ah129/SalinderSid/screenshot3_zpsakgqddvu.png" alt="Level 5"/>
	<img src="http://i1379.photobucket.com/albums/ah129/SalinderSid/screenshot4_zpsgdpgwkk1.png" alt="Level 5 Results"/>
</p>

##Supports:
- Microsoft Windows 7, 8, 8.1 and 10
- Linux based distributions
- Mac OS X

##Dependencies:
- `g++` or `Microsoft Visual Studio 2015` [(Community Edition)](https://www.visualstudio.com/en-us/downloads/download-visual-studio-vs.aspx)
- `SFML 32-bit` [(Build 2.3.2)](http://www.sfml-dev.org/download.php)
- `OpenSSL 32-bit` [(Build 1.0.2f)](https://slproweb.com/products/Win32OpenSSL.html)
- `PhysicsFS` [(Build 2.0.3)](http://www.sfml-dev.org/download/sfml/2.3.2/) **You will need to compile this from source**
- `CocoaDialog` [(Build 2.1.1)](https://mstratman.github.io/cocoadialog/#download) **Only for Mac OS X**

##Build Instructions:

###Windows:
####Preperation:
1. Download and install `Microsoft Visual Studio 2015`
2. Download and install [CMake](https://cmake.org/download/) Windows 32-bit installer
3. Download and install `OpenSSL` [(1.0.2f)](https://slproweb.com/products/Win32OpenSSL.html) Windows 32-bit installer
4. Download and extract the `PhysicsFS` [(2.0.3)](https://icculus.org/physfs/) source code
5. Download `SFML` [(2.3.2)](http://www.sfml-dev.org/download/sfml/2.3.2/) Visual C++ 14 (2015) 32-bit and extract it to `C:\`

####Compiling PhysicsFS:
1. Create a new folder named `bin` in the same location as the extracted `physfs-2.0.3` folder
2. Open `CMAKE (cmake-gui)`
3. Set the `Where is the source code:` to point to the extracted `physfs-2.0.3` folder
4. Set the `Where to build the binaries:` to point to the `bin` folder you've created
5. Click `Generate` and select `Visual Studio 14 2015` as the generator for this project then click `Finish`
6. Click `Configure` and then close `CMAKE`
7. Navigate to the `bin` folder and open `PhysicsFS.sln` with `Microsoft Visual Studio 2015`
8. Set the `Solutions Configurations` to `Release` and set the `Solutions Platform` to `Win32`
9. Right click  `ALL_BUILD` in the `Solution Explorer` pane and select `Build`
10. Create a new folder called `PHYSFS-2.0.3` at `C:\` and create the following folders inside of it: `bin`, `include` and `lib`
11. Navigate to your `bin\release` folder, copy `physfs.dll` and `test_physfs.exe` to `C:\PHYSFS-2.0.3\bin`
12. Copy the remaining files `physfs.exp`, `physfs.lib`, `test_physfs.exp` and `test_physfs.lib` to `C:\PHYSFS-2.0.3\lib`
13. Navigate to the extracted `PhysicsFS` source code folder `physfs-2.0.3` and copy all the folders, `.h` and `.c` files to `C:\PHYSFS-2.0.3\include`
14. Delete the extracted `PhysicsFS` source code folder `physfs-2.0.3` and the `bin` folder

####Compiling Blocks:
1. Git clone this repo
2. Open the project solution, `Blocks.sln` in `Microsoft Visual Studio 2015`
3. Set the `Solutions Configurations` to `Release` and set the `Solutions Platform` to `x86`
4. Right click the `Blocks` project in the `Solution Explorer` pane and select `Build`
5. If successful, `Blocks.exe` will build in the `Release` folder in your repo's root folder
6. Copy both `Data.7z` and `openal32.dll` files from `Blocks\Resources` to the `Release` folder where `Blocks.exe` is located
7. Execute `Blocks.exe` to start the game

###Linux:
####Preperation:
1. Download and install `CMake` by opening the terminal as root and typing `sudo apt-get install cmake`
2. Download and install `SFML` by opening the terminal as root and typing `sudo apt-get install libsfml-dev`
3. Download and install `OpenSSL` by opening the terminal as root and typing `sudo apt-get install libssl-ocaml-dev`
4. Download and extract the `PhysicsFS` [(2.0.3)](https://icculus.org/physfs/) source code

####Compiling PhysicsFS:
1. Use the terminal to navigate to the extracted `PhysicsFS` source code folder `physfs-2.0.3`
2. Create a new folder called `bin` and navigate to it by typing `mkdir bin && cd bin` into the terminal
3. Generate the Makefiles by typing `cmake ..` into the terminal
4. Type `make` into the terminal to build `PhysicsFS`
5. Type `sudo make install` to install the `PhysicsFS` library
6. Type `sudo ldconfig` to configure the shared library cache with the `PhysicsFS` library
7. Delete the extracted `PhysicsFS` source code folder `physfs-2.0.3` and the `bin` folder

####Compiling Blocks:
1. Git clone this repo
2. Open terminal and navigate to the repo, then navigate to the source code by typing `cd Blocks`
3. Type `make` into the terminal to compile the project
4. Launch the game by typing `./Blocks` in the terminal

###Mac OS X:
####Preperation:
1. Download and install [CMake](https://cmake.org/download/) Mac OSX 10.6+
2. Download and extract `SFML` [(2.3.2)](http://www.sfml-dev.org/download/sfml/2.3.2/) OS X 10.7+
3. Open terminal and navigate to the extracted `SFML` folder called `SFML-2.3.2-osx-clang-universal`
4. Install the `SFML` frameworks by typing `cd Frameworks && sudo cp -a * /Library/Frameworks && cd ..`
5. Install the dependency libraries for `SFML` by typing `cd extlibs && sudo cp -a * /Library/Frameworks`
6. Download and extract `PhysicsFS` [(2.0.3)](https://icculus.org/physfs/) source code
7. Download `CocoaDialog` [(2.1.1)](https://mstratman.github.io/cocoadialog/#download) and mount the `CocoaDialog-2.1.1.dmg` file
8. Copy `CocoaDialog.app` to your home directory and eject the mounted `CocoaDialog-2.1.1.dmg` file

####Compiling PhysicsFS:
1. Open terminal and navigate to the extracted `physfs-2.0.3` folder, then type `mkdir bin && cd bin`
2. Open `CMake` from Launchpad
3. Set the `Where is the source code:` to point to the extracted `physfs-2.0.3` folder
4. Set the `Where to build the binaries:` to point to the `bin` folder you've created
5. Click `Generate` and select `Use default native compilers` as the generator for this project then click `Finish`
6. Click `Configure` and then close `CMAKE`
7. Switch back to the terminal and type `make` to build `PhysicsFS`
8. Type `sudo make install` to install the `PhysicsFS` library
9. Delete the extracted `PhysicsFS` source code folder `physfs-2.0.3` and the `bin` folder

####Compiling Blocks:
1. Git clone this repo
2. Open terminal and navigate to the repo, then navigate to the source code by typing `cd Blocks`
3. Type `make` into the terminal to compile the project
4. Launch the game by typing `./Blocks` in the terminal

##Credits:
- `PhysicsFS` developed by [Ryan C. Gordon](https://icculus.org/physfs/)
- `CocoaDialog` developed by [Mark A. Stratman](https://github.com/mstratman)
- `OpenSSL` windows binary distribution created by [Shinning Light Productions](https://slproweb.com/index.html)
- `Game Audio` files obtained from [RPG Make VX Ace](http://www.rpgmakerweb.com/products/programs/rpg-maker-vx-ace)
- `Game Graphics` created exclusively using Photoshop
	- `Ribbon` inspired from Photoshop [Ribbon Tutorial](http://www.photoshopstar.com/web-design/cartoon-ribbon/)

##License:
Copyright (c) 2016 Salinder Sidhu

Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the "Software"), to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
