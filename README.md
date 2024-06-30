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
| PhysicsFS     | 3.0.2   |

## Getting Started

### Linux

1. Install the required dependencies:

```bash
sudo apt-get install cmake
sudo apt-get install libsfml-dev
```

2. Download the [PhysicsFS](https://icculus.org/physfs/) source.

3. Extract the PhysicsFS source.

4. Navigate to the extracted `physfs-release-3.2.0` folder and create a new folder called bin.

```bash
cd physfs-release-3.2.0
mkdir bin
```

5. Navigate to the newly created bin folder and generate the Makefiless.

```bash
cd bin
cmake ..
```

6. Compile and install the PhysicsFS library.

```bash
make
sudo make install
```

7. Configure the shared library cache for PhysicsFS.

```bash
sudo ldconfig
```

8. You can delete the `physfs-release-3.2.0` folder.

## Running

### Linux

1. Run the make command to compile the game.

```bash
cd Blocks
make
```

2. Start the game after it has compiled successfully.

```bash
./Blocks
```

## Contributing

Please see our [Contributing Guide](/CONTRIBUTING.md) for more details.

## Acknowledgements
- **Graphics**
	- Ribbon inspired from a Photoshop [Ribbon Tutorial](http://www.photoshopstar.com/web-design/cartoon-ribbon/)
	- Blocks, Grid and Background created exclusively using Photoshop
