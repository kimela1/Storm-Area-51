/*******************************************************************************
** Program name: Storm Area 51
** Author:       Elaine Kim
** Date:         August 9, 2019
** Description:  Source file for the Game class
*******************************************************************************/
#include "Game.hpp"

using std::cin;
using std::cout;
using std::endl;

// Default constructor
Game::Game()
{
  player = new Player();
  cafeteriaPtr = new Cafeteria();
  trainingRoomPtr = new TrainingRoom();
  researchLabPtr = new ResearchLab();
  libraryPtr = new Library();
  observatoryPtr = new Observatory();
  towerPtr = new Tower();

  // Player starts in Cafeteria
  currentSpace = cafeteriaPtr;

  // Set pointers for all to-be-instantiated spaces
  cafeteriaPtr->setLeft(trainingRoomPtr);
  cafeteriaPtr->setRight(libraryPtr);

  trainingRoomPtr->setRight(cafeteriaPtr);
  trainingRoomPtr->setUp(researchLabPtr);

  researchLabPtr->setDown(trainingRoomPtr);

  libraryPtr->setLeft(cafeteriaPtr);
  libraryPtr->setUp(observatoryPtr);

  observatoryPtr->setDown(libraryPtr);
  observatoryPtr->setRight(towerPtr);

  towerPtr->setLeft(observatoryPtr);
}

// Destructor
Game::~Game()
{
  delete cafeteriaPtr;
  delete trainingRoomPtr;
  delete researchLabPtr;
  delete libraryPtr;
  delete observatoryPtr;
  delete towerPtr;
  delete player;

  currentSpace = NULL;
  cafeteriaPtr = NULL;
  trainingRoomPtr = NULL;
  researchLabPtr = NULL;
  libraryPtr = NULL;
  observatoryPtr = NULL;
  towerPtr = NULL;
  player = NULL;
}

/*******************************************************************************
** Function Name: printMap
** Description: Prints the map with the player's current location
*******************************************************************************/
void Game::printMap(Space* room)
{
  cout << "\t MAP" << endl;
  cout << "X marks your current location" << endl;
  cout << "\n \n";

  // Get the room number
  switch (room->getSpace())
  {
    case 1:
      // room 1: Cafeteria (starting room)
      cout << R"(
      +---+         +---+  +---+
      |   |         |   +--+   |
      +-+-+         +-+-+  +---+
        |             |
      +-+-+  +---+  +-+-+
      |   +--+ X +--+   |
      +---+  +---+  +---+
      )" << '\n';
      break;

    case 2:
      // room 2: Training Room
      cout << R"(
      +---+         +---+  +---+
      |   |         |   +--+   |
      +-+-+         +-+-+  +---+
        |             |
      +-+-+  +---+  +-+-+
      | X +--+   +--+   |
      +---+  +---+  +---+
      )" << '\n';
      break;
    
    case 3:
      // room 3: Research Lab
      cout << R"(
      +---+         +---+  +---+
      | X |         |   +--+   |
      +-+-+         +-+-+  +---+
        |             |
      +-+-+  +---+  +-+-+
      |   +--+   +--+   |
      +---+  +---+  +---+
      )" << '\n';
      break;

    case 4:
      // room 4: Library
      cout << R"(
      +---+         +---+  +---+
      |   |         |   +--+   |
      +-+-+         +-+-+  +---+
        |             |
      +-+-+  +---+  +-+-+
      |   +--+   +--+ X |
      +---+  +---+  +---+
      )" << '\n';
      break;

    case 5:
      // room 5: Observatory
      cout << R"(
      +---+         +---+  +---+
      |   |         | X +--+   |
      +-+-+         +-+-+  +---+
        |             |
      +-+-+  +---+  +-+-+
      |   +--+   +--+   |
      +---+  +---+  +---+
      )" << '\n';
      break;

    case 6:
      // room 6: Tower
      cout << R"(
      +---+         +---+  +---+
      |   |         |   +--+ X |
      +-+-+         +-+-+  +---+
        |             |
      +-+-+  +---+  +-+-+
      |   +--+   +--+   |
      +---+  +---+  +---+
      )" << '\n';
      break;

    default:
      break;
  }
  cout << "\n";
}

/*******************************************************************************
** Function Name: playGame
** Description: Function to play the game. Starts by displaying the game menu and
** game rules. Asks the player to play or quit the game. 
*******************************************************************************/
void Game::playGame()
{
  // Variables
  int numTurn = 1;
  int choice = 0; 

  do
  {
    // main menu
    cout << "==================================================================" << endl;
    cout << "========================== STORM AREA 51 =========================" << endl;
    cout << "==================================================================" << endl;
    cout << "Rules:" << endl;
    cout << "Your goal is to befriend an alien hidden in Area 51." << endl;
    cout << "There are special actions/items in this map to help and hurt you." << endl;
    cout << "If you take too long, you'll lose too much health and the alien " << endl;
    cout << "will abduct you. Be careful!" << endl;
    cout << "==========================" << endl;
    cout << "What would you like to do?" << endl;
    cout << "1. Play Game" << endl;
    cout << "2. Quit Game" << endl;
    int choice = intValidation(2);
  
    if (choice == 2)
    {
      // quit game
      cout << "Thanks for playing, goodbye!" << endl;
      exit(0);
    }

    // Delete player and create new to reset health    
    delete player; 
    player = new Player();
    
    // choice == 1, play game
    cout << "\nYou've decided to storm Area 51!" << endl;
    cout << "You take a look around. You see empty tables, chairs, and a kitchen. ";
    cout << "Looks like you're in the cafeteria." << endl;
    cout << "Where are you going to go?" << endl;
    
    // Play if player health > 0
    while (player->getHealth() > 0)
    {
      cout << "----------------------------" << endl;
      // Display turn number
      cout << "Turn: " << numTurn << endl;
      // Display health
      cout << "Health: " << player->getHealth() << endl;
      // Display inventory
      cout << "Inventory: ";
      player->getInventory();
      cout << "\n";
      cout << "----------------------------" << endl;
      
      // Print map with player's current location
      printMap(currentSpace);
      
      // Print current room info
      currentSpace->spaceInfo();
      
      // Set the currentSpace to the pointer above
      // Print room menu
      currentSpace = currentSpace->spaceMenu(player);
      
      // Increment nuumber of turns
      numTurn++;
      
      // Player loses 5 health moving space to space
      player->subHealth(5);   
    }

    // Player health < 0
    // Display game over
    cout << "\nYou're tried from walking around. You sit down to rest and fall asleep." << endl;
    cout << "You wake up in an unfamiliar place. It's dark...you look around." << endl;
    cout << "You realize you're being stared at by something...aliens!" << endl;
    cout << "You've been abducted by aliens!!!" << endl;

    cout << R"(
     _____          __  __ ______    ______      ________ _____  
    / ____|   /\   |  \/  |  ____|  / __ \ \    / /  ____|  __ \ 
   | |  __   /  \  | \  / | |__    | |  | \ \  / /| |__  | |__) |
   | | |_ | / /\ \ | |\/| |  __|   | |  | |\ \/ / |  __| |  _  / 
   | |__| |/ ____ \| |  | | |____  | |__| | \  /  | |____| | \ \ 
    \_____/_/    \_\_|  |_|______|  \____/   \/   |______|_|  \_\                                                       
    )" << '\n';
    cout << "\n" << endl;

  }while(choice !=2);  // loop until player chooses to quit game
}
