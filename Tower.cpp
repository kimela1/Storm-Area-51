/*******************************************************************************
** Program name: Final Project - Storm Area 51 (text based game)
** Author:       Elaine Kim
** Date:         August 9, 2019
** Description:  Source file for the Tower class
*******************************************************************************/
#include <iostream>
#include "Tower.hpp"
#include "Game.hpp"

using std::cin;
using std::cout;
using std::endl;

// Default Constructor
Tower::Tower()
{
  up = NULL;
  down = NULL;
  left = NULL;
  right = NULL;
  spaceNum = 6;
}

/*******************************************************************************
** Function Name: spaceInfo
** Description: Displays the room's name and information
*******************************************************************************/
void Tower::spaceInfo()
{
  cout << "TOWER" << endl;
  cout << "There's shadowy figure by the window. ";
  cout << "You realize it's an alien!! Must be enjoying the view." << endl;
  cout << "But how do you become friends with the alien??" << endl;
}

/*******************************************************************************
** Function Name: spaceMenu
** Description: Provides the player with the current room options and actions.
** Returns a pointer to the next room the player chooses.
*******************************************************************************/
Space* Tower::spaceMenu(Player* player)
{
    do
    { 
        cout << "==========================" << endl;
        cout << "What will you do?" << endl;
        cout << "1. Go Up" << endl;
        cout << "2. Go Down" << endl;
        cout << "3. Go Left" << endl;
        cout << "4. Go Right" << endl;
        cout << "5. Approach the Alien" << endl;
        int choice = intValidation(5);
        
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
            // left, the next room is the Observatory
            return left;
            break;

        case 4:
            // right
            cout << "Oof! There's a wall there. Take another look at the map." << endl;
            break;

        case 5: 
            // Special action: approach the alien
            // Check if player has the movie
            if (player->searchInventory("movie"))
            {
                cout << "A ha! You remember you picked up a copy of E.T. earlier in the ";
                cout << "Library. You notice there's a TV in the ";
                cout << "room and decide to play the DVD for the alien..." << endl;
                cout << "You both watch until the end with tears in your eyes." << endl;
                cout << "The alien motions to you. " << endl;
                cout << R"(
                    .--.   |V|
                   /    \ _| /
                   q .. p \ /
                    \--/  //
                   __||__//
                  /.    _/
                 // \  /
                //   ||
                \\  /  \
                 )\|    |
                |/\| || |
                   \ || /
                __/ || \__
                \____/\____/

                )" << "\n";
                cout << "You accept this as a sentiment of friendship." << endl;
                cout << "You were able to befriend an alien!" << endl;
                cout << "You have reached the goal and succesfully completed the game!" << endl;
                cout << "Thanks for playing! \n" << endl;
                
                // Call function to display game menu
                Game g2;
                g2.playGame();
            }
            else
            {
                cout << "The alien does not look interested in you." << endl;
                cout << "Come back after something that'll help you gain the alien's trust." << endl;
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
int Tower::getSpace()
{
  return spaceNum;
}

void Tower::setUp(Space* room)
{
  up = room;
}

void Tower::setDown(Space* room)
{
  down = room;
}

void Tower::setLeft(Space* room)
{
  left = room;
}

void Tower::setRight(Space* room)
{
  right = room;
}

