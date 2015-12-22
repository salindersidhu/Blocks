#Blocks

Description:
-------------
Blocks is a 2D puzzle game where the objective is to re-arrange the blocks (horizontally or vertically) so that you can push
the red block out of the board. The blocks can only move in the direction of their orientation (blocks positioned vertically, can only
move vertically, likewise, blocks positioned horizontally can only move horizontally). To slide a block, simply click on the block to 
select it and move the mouse, release the mouse to position the block. The number of moves and amount of time taken are displayed when the 
level is successfully completed.

<p align="center">
	<img src="http://i1379.photobucket.com/albums/ah129/SalinderSid/screenshot1_zpsoxlag9ny.png" alt="Screenshot 1"/>
	<img src="http://i1379.photobucket.com/albums/ah129/SalinderSid/screenshot2_zpsldqo5nu1.png" alt="Screenshot 2"/>
</p>

Supports:
-------------
- Microsoft Windows 7, 8, 8.1 and 10

Dependencies:
-------------
- `Microsoft Visual Studio 2015` [(Community Edition)](https://www.visualstudio.com/en-us/downloads/download-visual-studio-vs.aspx)
- `Simple and Fast Multimedia Library 32-bit` [(Build 2.3.2)](http://www.sfml-dev.org/download.php)
- `PhysicsFS` [(Build 2.0.3)](https://icculus.org/physfs/)

Build Instructions:
-------------
1. Clone the repo to obtain the project and source code
2. Download and install `Microsoft Visual Studio 2015`
3. Download `SFML` 32-bit version build 2.3.2 and extract it to `C:\`
4. Download `PhysicsFS` build 2.0.3 and extract it to `C:\`
5. Open the project solution, `Blocks.sln` in `Microsoft Visual Studio 2015`
6. Right click the `Blocks` project in the `Class View` pane and select `Clean`
7. Set the `Solutions Configurations` to `Release` and set the `Solutions Platform` to `x86`
8. Right click the `Blocks` project in the `Class View` pane and select `Build`
9. If successful, Blocks.exe will build in the `Release` folder in your repo's root folder
10. Copy the `Data.7z` resource file from `\Blocks\Resources` to the `\Release` folder where `Blocks.exe` is located
11. Execute `Blocks.exe` to launch the application
