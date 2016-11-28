
CXXFLAGS=-Wall -Wextra -std=c++11 -Wno-unused-parameter
SFML_FLAGS= -lsfml-graphics -lsfml-window -lsfml-system
OBJECTS =  game.o Object.o Non_movables.o Match.o Texture_handler.o Player.o Movable.o Character.o
OBJECTS2 = game_menu.o Menu.o Play_Button.o Menu_Texture_handler.o Object.o
#MATCH = Match
#RIP = ../
CCC = g++
#CPPFLAGS += -I$(MATCH)
#CPPFLAGS2 += -I$(RIP)

game: $(OBJECTS) Makefile
	$(CCC) $(CPPFLAGS) $(CXXFLAGS) $(LDFLAGS) -o game $(OBJECTS) $(SFML_FLAGS)

menu: $(OBJECTS2) Makefile
	$(CCC) $(CPPFLAGS) $(CXXFLAGS) $(LDFLAGS) -o menu $(OBJECTS2) $(SFML_FLAGS)

Menu.o: Menu/Menu.h Menu/Menu.cc
	$(CCC) $(CPPFLAGS) $(CXXFLAGS) -c Menu/Menu.cc

Play_Button.o: Menu/Play_Button.h Menu/Play_Button.cc
	$(CCC) $(CPPFLAGS) $(CXXFLAGS) -c Menu/Play_Button.cc

Menu_Texture_handler.o: Menu_Texture_handler.h Menu_Texture_handler.cc
	$(CCC) $(CPPFLAGS) $(CXXFLAGS) -c Menu_Texture_handler.cc
game_menu.o: game_menu.cc
	$(CCC) $(CPPFLAGS) $(CXXFLAGS) -c game_menu.cc

game.o: game.cc
	$(CCC) $(CPPFLAGS) $(CXXFLAGS) -c game.cc

Object.o: Object.h Object.cc
	$(CCC) $(CPPFLAGS) $(CXXFLAGS) -c Object.cc

Non_movables.o: Match/Non_movables.h Match/Non_movables.cc
	$(CCC) $(CPPFLAGS) $(CXXFLAGS) -c Match/Non_movables.cc

Texture_handler.o: Texture_handler.h Texture_handler.cc
	$(CCC) $(CPPFLAGS) $(CXXFLAGS) -c Texture_handler.cc

Player.o: Match/Player.h Match/Player.cc
	$(CCC) $(CPPFLAGS) $(CXXFLAGS) -c Match/Player.cc

Movable.o: Match/Movable.h Match/Movable.cc
	$(CCC) $(CPPFLAGS) $(CXXFLAGS) -c Match/Movable.cc

Character.o: Match/Character.h Match/Character.cc
	$(CCC) $(CPPFLAGS) $(CXXFLAGS) Match/Character.cc

Match.o: Match/Match.h Match/Match.cc
	$(CCC) $(CPPFLAGS) $(CXXFLAGS) -c Match/Match.cc

clean:
	@ \rm -rf *.o *.gch core
#.PHONY clean:
#	rm -f match
