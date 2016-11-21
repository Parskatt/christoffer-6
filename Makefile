CXXFLAGS=-Wall -Wextra -std=c++11 -Wno-unused-parameter
SFML_FLAGS= -lsfml-graphics -lsfml-window -lsfml-system
OBJECTS =  Object.o Non_Movables.o Match.o
MATCH = /Match
SRC_DIR=src
CCC = g++


game: $(SRC_DIR)/game.cc
	g++ $(CXXFLAGS)$(LDFLAGS) $(MATCH)/Match.h $(MATCH)/Match.cc -o game $(OBJECTS) $(SFML_FLAGS)

Object.o: $(SRC_DIR)/Object.h $(SRC_DIR)/Object.cc
		$(CCC) $(CPPFLAGS) $(CXXFLAGS) -c Object.cc

Non_Movables.o: $(MATCH)/Non_Movables.h $(MATCH)/Non_Movables.cc
		$(CCC) $(CPPFLAGS) $(CXXFLAGS) -c Non_Movables.cc

Match.o: $(MATCH)/Match.h $(MATCH)/Match.cc
	$(CCC) $(CPPFLAGS) $(CXXFLAGS) -c Match.cc





.PHONY clean:
	rm -f match
