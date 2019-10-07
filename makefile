CXX = g++
VARNAME = value
CXXFLAGS = -std=c++0x

final: main.o Cafeteria.o Game.o InputValidation.o Item.o Library.o Observatory.o Player.o ResearchLab.o Space.o Tower.o TrainingRoom.o
	$(CXX) $(CXXFLAGS) -o final main.o Cafeteria.o Game.o InputValidation.o Item.o Library.o Observatory.o Player.o ResearchLab.o Space.o Tower.o TrainingRoom.o
Cafeteria.o: Cafeteria.cpp Cafeteria.hpp
	$(CXX) $(CXXFLAGS) -c Cafeteria.cpp
Game.o: Game.cpp Game.hpp
	$(CXX) $(CXXFLAGS) -c Game.cpp
InputValidation.o: InputValidation.cpp InputValidation.hpp
	$(CXX) $(CXXFLAGS) -c InputValidation.cpp
Item.o: Item.cpp Item.hpp
	$(CXX) $(CXXFLAGS) -c Item.cpp
Library.o: Library.cpp Library.hpp
	$(CXX) $(CXXFLAGS) -c Library.cpp
Observatory.o: Observatory.cpp Observatory.hpp
	$(CXX) $(CXXFLAGS) -c Observatory.cpp
Player.o: Player.cpp Player.hpp
	$(CXX) $(CXXFLAGS) -c Player.cpp
ResearchLab.o: ResearchLab.cpp ResearchLab.hpp
	$(CXX) $(CXXFLAGS) -c ResearchLab.cpp
Space.o: Space.cpp Space.hpp
	$(CXX) $(CXXFLAGS) -c Space.cpp
Tower.o: Tower.cpp Tower.hpp
	$(CXX) $(CXXFLAGS) -c Tower.cpp
TrainingRoom.o: TrainingRoom.cpp TrainingRoom.hpp
	$(CXX) $(CXXFLAGS) -c TrainingRoom.cpp
clean:
	rm *.o final
