/*******************************************************************************
** Program name: Final Project - Storm Area 51 (text based game)
** Author:       Elaine Kim
** Date:         August 9, 2019
** Description:  Source file for the Obervatory class
*******************************************************************************/
#include <iostream>
#include "Observatory.hpp"

using std::cin;
using std::cout;
using std::endl;

// Default Constructor
Observatory::Observatory()
{
  up = NULL;
  down = NULL;
  left = NULL;
  right = NULL;
  spaceNum = 5;
}

/*******************************************************************************
** Function Name: spaceInfo
** Description: Displays the room's name and information
*******************************************************************************/
void Observatory::spaceInfo()
{
  cout << "OBSERVATORY" << endl;
  cout << "AH! It's dark. There's a giant telescope in the center of the room." << endl;
}

/*******************************************************************************
** Function Name: spaceMenu
** Description: Provides the player with the current room options and actions.
** Returns a pointer to the next room the player chooses.
*******************************************************************************/
Space* Observatory::spaceMenu(Player* player)
{
  do
  { 
    cout << "==========================" << endl;
    cout << "What will you do?" << endl;
    cout << "1. Go Up" << endl;
    cout << "2. Go Down" << endl;
    cout << "3. Go Left" << endl;
    cout << "4. Go Right" << endl;
    cout << "5. Look through the Telescope" << endl;
    int choice = intValidation(5);
    
    switch (choice)
    {
      case 1:
        // up
        cout << "Oof! There's a wall there. Take another look at the map." << endl;
        break;

      case 2:
        // down, the next room is the Library
        return down;
        break;

      case 3:
        // left
        cout << "Oof! There's a wall there. Take another look at the map." << endl;
        break;

      case 4:
        // right, the next room is the Tower
        return right;
        break;

      case 5: 
        // Special action: look through the telescope
        cout << R"(
  ----------------------------------------------------------------
  ||            +             +                  +              ||
  ||   |                *           o     +                .    ||
  ||  -O-    o               .               .          +       ||
  ||   |                    _,.-----.,_         o    |          ||
  ||           +    *    .-'.         .'-.          -O-         ||
  ||      *            .'.-'   .---.   `'.'.         |     *    ||
  || .                /_.-'   /     \   .'-.\                   ||
  ||         ' -=*<  |-._.-  |   @   |   '-._|  >*=-    .     + ||
  || -- )--           \`-.    \     /    .-'/                   ||
  ||       *     +     `.'.    '---'    .'.'    +       o       ||
  ||                  .  '-._         _.-'  .                   ||
  ||         |               `~~~~~~~`       - --===            ||
  ||   o    -O-      *   .                  *        +          ||
  ||         |                      +         .            +    ||
  ||           .           o                        *           ||
  ||       o                          *          o           .  ||
  ---------------------------------------------------------------
        )" << '\n';
        break;

      default:
        break;
    }    
  } while(true);
}

/*******************************************************************************
** Getters and Setters
*******************************************************************************/
int Observatory::getSpace()
{
  return spaceNum;
}

void Observatory::setUp(Space* room)
{
  up = room;
}

void Observatory::setDown(Space* room)
{
  down = room;
}

void Observatory::setLeft(Space* room)
{
  left = room;
}

void Observatory::setRight(Space* room)
{
  right = room;
}

