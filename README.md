# Blocks

[![Contributors](https://img.shields.io/github/contributors/salindersidhu/Blocks?style=for-the-badge)](https://github.com/salindersidhu/Blocks/graphs/contributors) [![Visitors](https://api.visitorbadge.io/api/visitors?path=https%3A%2F%2Fgithub.com%2Fsalindersidhu%Blocks&countColor=%23263759)](https://visitorbadge.io/status?path=https%3A%2F%2Fgithub.com%2Fsalindersidhu%Blocks) [![License: MIT](https://img.shields.io/badge/license-MIT-brightgreen.svg?style=for-the-badge)](/LICENSE.md)

## Overview

Blocks is a 2D puzzle game where the goal is to manipulate blocks horizontally or vertically to guide the red block off the board. Each block moves only along its orientation: vertical blocks move up or down, while horizontal blocks move left or right. To slide a block, click to select it, then move your mouse; release to place the block. Successful completion of each level reveals the number of moves and time taken.

<p align="center">
	<img src="https://user-images.githubusercontent.com/12175684/40275888-726a1f1c-5bca-11e8-856d-d0793b536ae0.png" alt="Main Menu"/>
	<img src="https://user-images.githubusercontent.com/12175684/40275889-74058b90-5bca-11e8-9100-8f62c97c08a0.png" alt="Level 1"/>
    <img src="https://user-images.githubusercontent.com/12175684/40275890-75054fa8-5bca-11e8-85cc-1f9166718b48.png" alt="Level 5"/>
	<img src="https://user-images.githubusercontent.com/12175684/40275891-75fa10ce-5bca-11e8-8987-7bfe8794f32c.png" alt="Level 5 Complete"/>
</p>

## Prerequisite Software

| Software      | Version |
|:--------------|:--------|
| Git           | 2.20.1+ |
| Visual Studio | 2017+   |
| SFML          | 2.3.2   |
| CocoaDialog   | 2.1.1   |
| PhysicsFS     | 3.2.0   |

## Getting Started

### Windows

1. Download and install Microsoft Visual Studio.

2. Download and install [CMake](https://cmake.org/download/) Windows 32-bit installer.

3. Download [SFML](https://www.sfml-dev.org/download/sfml/2.3.2/) Visual C++ 14 (2015) 32-bit and extract it to `C:\`.

4. Download and extract the [PhysicsFS](https://icculus.org/physfs/) source.

5. Create a new folder called `bin` in the same location as the extracted `physfs-release-3.2.0` folder.

6. Open CMake and configure the following settings:
	
	- Set `Where is the source code:` to the path of the extracted `physfs-release-3.2.0` folder.

	- Set `Where to build the binaries:` to the path of the bin folder.

7. Click `Generate` and select `Visual Studio 14 2015` as the generator, then click `Finish`.

8. Click `Configure` and close CMake.

9. Navigate to `bin` and open `PhysicsFS.sln`.

10. Change `Solutions Configurations` to `Release` and change `Solutions Platform` to `Win32`.

11. Right click `ALL_BUILD` in the Solution Explorer and select `Build`.

12. Create the following folders at `C:\`.

	- C:\PHYSFS-3.2.0\bin

	- C:\PHYSFS-3.2.0\include

	- C:\PHYSFS-3.2.0\lib

13. Navigate to the `bin\release` and copy the following files to `C:\PHYSFS-3.2.0\bin`:

	- physfs.dll

	- test_physfs.exe

14. Copy the following files to `C:\PHYSFS-3.2.0\lib`:

	- physfs.exp

	- physfs.lib

	- test_physfs.exp

	- test_physfs.lib

15. Navigate back to `physfs-release-3.2.0` and copy the following to `C:\PHYSFS-3.2.0\include`:

	- all folders

	- all `.h` header files

	- all `.c` source files

7. Delete the `physfs-release-3.2.0` folder.

### Linux

1. Install the required dependencies:

```bash
sudo apt-get install cmake
sudo apt-get install libsfml-dev
```

2. Download and extract the [PhysicsFS](https://icculus.org/physfs/) source.

3. Navigate to the extracted `physfs-release-3.2.0` folder and create a new folder called `bin`:

```bash
cd physfs-release-3.2.0
mkdir bin
```

4. Navigate to bin and generate the Makefiles:

```bash
cd bin
cmake ..
```

5. Compile and install the PhysicsFS library:

```bash
make
sudo make install
```

6. Configure the shared library cache for PhysicsFS:

```bash
sudo ldconfig
```

7. Delete the `physfs-release-3.2.0` folder.

## Running

### Windows

1. Open `Blocks.sln`.

2. Change `Solutions Configurations` to `Release` and change `Solutions Platform` to `x86`.

3. Right click `Blocks` in the Solution Explorer and select `Build` to build `Blocks.exe`.

4. Double click `Blocks.exe` compiled in the `Release` folder to start the game.

### Linux

1. Run the make command to compile the game:

```bash
cd Blocks
make
```

2. Start the game after it has compiled successfully:

```bash
./Blocks
```

## Contributing

Please see our [Contributing Guide](/CONTRIBUTING.md) for more details.

## Acknowledgements
- **Graphics**
	- Ribbon inspired from a Photoshop [Ribbon Tutorial](http://www.photoshopstar.com/web-design/cartoon-ribbon/)
	- Blocks, Grid and Background created exclusively using Photoshop
