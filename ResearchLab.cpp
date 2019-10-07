/*******************************************************************************
** Program name: Final Project - Storm Area 51 (text based game)
** Author:       Elaine Kim
** Date:         August 9, 2019
** Description:  Source file for the ResearchLab class
*******************************************************************************/
#include <iostream>
#include "ResearchLab.hpp"

using std::cin;
using std::cout;
using std::endl;

// Default Constructor
ResearchLab::ResearchLab()
{
  up = NULL;
  down = NULL;
  left = NULL;
  right = NULL;
  spaceNum = 3;
}

/*******************************************************************************
** Function Name: spaceInfo
** Description: Displays the room's name and information
*******************************************************************************/
void ResearchLab::spaceInfo()
{
  cout << "RESEARCH LAB" << endl;
  cout << "There's a cabinet labeled 'CONFIDENTIAL' on the left side of the room." << endl;
  cout << "You try to open the cabinet. Ugh, it's locked! You need a key to open it." << endl;
}

/*******************************************************************************
** Function Name: spaceMenu
** Description: Provides the player with the current room options and actions.
** Returns a pointer to the next room the player chooses.
*******************************************************************************/
Space* ResearchLab::spaceMenu(Player* player)
{
  do
  { 
    cout << "==========================" << endl;
    cout << "What will you do?" << endl;
    cout << "1. Go Up" << endl;
    cout << "2. Go Down" << endl;
    cout << "3. Go Left" << endl;
    cout << "4. Go Right" << endl;
    cout << "5. Unlock the Cabinet" << endl;
    int choice = intValidation(5);
    
    switch (choice)
    {
      case 1:
        // up
        cout << "Oof! There's a wall there. Take another look at the map." << endl;
        break;

      case 2:
        // down, next room is Training Room
        return down;
        break;

      case 3:
        // left
        cout << "Oof! There's a wall there. Take another look at the map." << endl;
        break;

      case 4:
        // right
        cout << "Oof! There's a wall there. Take another look at the map." << endl;
        break;

      case 5: 
        // Special action: Unlock the cabinet with a key
        // Check if player has key and does not already have the movie item
        if (player->searchInventory("key") && !(player->searchInventory("movie")))
        {
          cout << "Click! The cabinet unlocked. The only thing inside is a ";
          cout << "DVD. It's a copy of E.T.! You put it in your backpack." << endl;
          player->addItem(new Item("movie"));
        }
        else if (!player->searchInventory("key"))
        {
          // Player does not have key 
          cout << "It won't budge! Looks like you need a key." << endl;
        }
        else 
        {
          cout << "Hmm..nothing useful inside." << endl;
        }
        break;

      default:
        break;
        }
    } while(true);
}

/*******************************************************************************
** Getters and Setters
*******************************************************************************/
int ResearchLab::getSpace()
{
  return spaceNum;
}

void ResearchLab::setUp(Space* room)
{
  up = room;
}

void ResearchLab::setDown(Space* room)
{
  down = room;
}

void ResearchLab::setLeft(Space* room)
{
  left = room;
}

void ResearchLab::setRight(Space* room)
{
  right = room;
}

