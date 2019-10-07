/*******************************************************************************
** Program name: Final Project - Storm Area 51 (text based game)
** Author:       Elaine Kim
** Date:         August 9, 2019
** Description:  Source file for the TrainingRoom class
*******************************************************************************/
#include "TrainingRoom.hpp"

using std::cin;
using std::cout;
using std::endl;

/*******************************************************************************
** Function Name: Default Constructor
*******************************************************************************/
TrainingRoom::TrainingRoom()
{
  up = NULL;
  down = NULL;
  left = NULL;
  right = NULL;
  spaceNum = 2;
}

/*******************************************************************************
** Function Name: spaceInfo
** Description: Displays the room's name and information 
*******************************************************************************/
void TrainingRoom::spaceInfo()
{
  cout << "TRAINING ROOM" << endl;
  cout << "Weird. There's nothing in this room. It's completely empty." << endl;
}

/*******************************************************************************
** Function Name: spaceMenu
** Description: Provides the player with the current room options and actions.
** Returns a pointer to the next room the player chooses.
*******************************************************************************/
Space* TrainingRoom::spaceMenu(Player* player)
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
        // up, next room is the Research Lab
        return up;
        break;
      case 2:
        // down
        cout << "Oof! There's a wall there. Take another look at the map." << endl;
        break;
      case 3:
        // left
        cout << "Oof! There's a wall there. Take another look at the map." << endl;
        break;
      case 4:
        // right, next room is the Cafeteria
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
void TrainingRoom::setUp(Space* room)
{
  up = room;
}

void TrainingRoom::setDown(Space* room)
{
  down = room;
}

void TrainingRoom::setLeft(Space* room)
{
  left = room;
}

void TrainingRoom::setRight(Space* room)
{
  right = room;
}

int TrainingRoom::getSpace()
{
  return spaceNum;
}