CC=g++
CFLAGS=-std=c++0x -c
OS := $(shell uname)
ifeq ($(OS), Darwin)
	# Mac OS X LDFLAGS
	LDFLAGS=-framework sfml-graphics -framework sfml-audio -framework sfml-window -framework sfml-system -lphysfs
else
	# Linux LDFLAGS
	LDFLAGS=-L/usr/local/lib -lsfml-graphics -lsfml-audio -lsfml-window -lsfml-system -lphysfs
endif
OBJECTS=Logic/MinuteClock.o Logic/Block.o Logic/Grid.o Objects/GameGrid.o Objects/Button.o Objects/FadeEffect.o Objects/GameInfo.o Objects/HUD.o Objects/BGMusic.o Levels/CoreLevel.o Levels/MenuLevel.o Levels/GameLevel.o Engine/SaveObject.o Engine/LevelObject.o Engine/DialogManager.o Engine/Game.o Engine/PhysfsStream.o Engine/ResourceManager.o main.o
SOURCES=$(OBJECTS:.cpp=.0)
EXECUTABLE=Blocks

# Build the project and configure
all: $(OBJECTS) $(EXECUTABLE)

# Rules for compiling all sources, building the project and add the resource archive file
$(EXECUTABLE): $(SOURCES)
	@printf "BUILDING PROJECT..."
	@$(CC) $(SOURCES) $(LDFLAGS) -o $@
	@printf "DONE\n"
	@printf "ADDING RESOURCE..."
	@cp Resources/data.7z .
	@printf "DONE\n\nPlease type ./Blocks to start the game.\n"

.cpp.o:
	@printf "COMPILING "$@"..."
	@$(CC) $(CFLAGS) $< -o $@
	@printf "DONE\n"

# Clean all compiled files, resources and executable
clean:
	@printf "CLEANING..."
	@rm -rf *.o */*.o *.7z $(EXECUTABLE)
	@printf "DONE\n"
