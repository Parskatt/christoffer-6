
CXXFLAGS=-Wall -Wextra -std=c++11 -Wno-unused-parameter
SFML_FLAGS= -lsfml-graphics -lsfml-window -lsfml-system
OBJECTS =  game.o Object.o Non_movables.o Match.o Texture_handler.o
MATCH = Match
RIP = ../
CCC = g++
#CPPFLAGS += -I$(MATCH)
#CPPFLAGS2 += -I$(RIP)

game: $(OBJECTS) Makefile
	$(CCC) $(CPPFLAGS) $(CXXFLAGS) $(LDFLAGS) -o game $(OBJECTS) $(SFML_FLAGS)

game.o: game.cc
	$(CCC) $(CPPFLAGS) $(CXXFLAGS) -c game.cc

Object.o: Object.h Object.cc
	$(CCC) $(CPPFLAGS) $(CXXFLAGS) -c Object.cc

Non_movables.o: Non_movables.h Non_movables.cc
	$(CCC) $(CPPFLAGS) $(CXXFLAGS) -c Non_movables.cc

Match.o: Match.h Match.cc
	$(CCC) $(CPPFLAGS) $(CXXFLAGS) -c Match.cc

Texture_handler.o: Texture_handler.h Texture_handler.cc
	$(CCC) $(CPPFLAGS) $(CXXFLAGS) -c Texture_handler.cc



clean:
	@ \rm -rf *.o *.gch core
#.PHONY clean:
#	rm -f match
