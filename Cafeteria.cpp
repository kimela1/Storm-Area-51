/*******************************************************************************
** Program name: Final Project - Storm Area 51 (text based game)
** Author:       Elaine Kim
** Date:         August 9, 2019
** Description:  Source file for the Cafeteria class
*******************************************************************************/
#include "Cafeteria.hpp"

using std::cin;
using std::cout;
using std::endl;

// Default Constructor
Cafeteria::Cafeteria()
{
  up = NULL;
  down = NULL;
  left = NULL;
  right = NULL;
  spaceNum = 1;
}

/*******************************************************************************
** Function Name: spaceInfo
** Description: Displays the room's name and information
*******************************************************************************/
void Cafeteria::spaceInfo()
{
  cout << "CAFETERIA" << endl;
  cout << "There are empty tables, chairs, and trays stacked on a counter. " << endl;
  cout << "Not much to do here." << endl;
}

/*******************************************************************************
** Function Name: spaceMenu
** Description: Provides the player with the current room options and actions.
** Returns a pointer to the next room the player chooses.
*******************************************************************************/
Space* Cafeteria::spaceMenu(Player* player)
{
  do
  { 
    cout << "==========================" << endl;
    cout << "What will you do?" << endl;
    cout << "1. Go Up" << endl;
    cout << "2. Go Down" << endl;
    cout << "3. Go Left" << endl;
    cout << "4. Go Right" << endl;
    int choice = intValidation(4);
    
    switch (choice)
    {
      case 1:
        // up
        cout << "Oof! There's a wall there. Take another look at the map." << endl;
        break;
      case 2:
        // down
        cout << "Oof! There's a wall there. Take another look at the map." << endl;
        break;
      case 3:
        // left, next room is the Training Room
        return left;
        break;
      case 4:
        // right, next room is the Library
        return right;
        break;
      default:
        break;
    }
  } while(true);
}

/*******************************************************************************
** Getters and Setters
*******************************************************************************/
int Cafeteria::getSpace()
{
  return spaceNum;
}

void Cafeteria::setUp(Space* room)
{
  up = room;
}

void Cafeteria::setDown(Space* room)
{
  down = room;
}

void Cafeteria::setLeft(Space* room)
{
  left = room;
}

void Cafeteria::setRight(Space* room)
{
  right = room;
}


