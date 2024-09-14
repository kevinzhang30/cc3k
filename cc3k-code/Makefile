CXX = g++
CXXFLAGS = -std=c++14 -Wall -Werror -MMD -g
EXEC = cc3k

# Object files
MAIN_OBJ = main.o game.o character.o player.o enemy.o item.o gold.o potion.o direction.o
GOLD_OBJ = gold_types/dragonhoard.o gold_types/merchanthoard.o gold_types/normalpile.o gold_types/smallpile.o gold_types/humanpile.o
ENEMY_OBJ = enemy_races/dragon.o enemy_races/dwarf.o enemy_races/elf.o enemy_races/halfling.o enemy_races/human.o enemy_races/merchant.o enemy_races/orc.o
PLAYER_OBJ = player_races/drow.o player_races/goblin.o player_races/shade.o player_races/troll.o player_races/vampire.o
POTION_OBJ = potion_types/boostatk.o potion_types/boostdef.o potion_types/poisonhealth.o potion_types/restorehealth.o potion_types/woundatk.o potion_types/wounddef.o
DECORATOR_OBJ = potion_decorator/atkpotion.o potion_decorator/consumed.o potion_decorator/defpotion.o potion_decorator/nopotion.o potion_decorator/potiondecorator.o

OBJECTS = $(MAIN_OBJ) $(GOLD_OBJ) $(ENEMY_OBJ) $(PLAYER_OBJ) $(POTION_OBJ) $(DECORATOR_OBJ)
DEPENDS = ${OBJECTS:.o=.d}

# Link object files to create the executable
${EXEC}: ${OBJECTS}
	${CXX} ${CXXFLAGS} ${OBJECTS} -o ${EXEC}

# Include dependency files
-include ${DEPENDS}

# Clean up build artifacts
clean:
	rm -f ${OBJECTS} ${EXEC} ${DEPENDS}

# Compile object files
%.o: %.cc
	$(CXX) $(CXXFLAGS) -c $< -o $@

.PHONY: clean