/*******************************************************************************
** Program name: Final Project - Storm Area 51 (text based game)
** Author:       Elaine Kim
** Date:         August 9, 2019
** Description:  Source file for the Library class
*******************************************************************************/
#include <iostream>
#include "Library.hpp"

using std::cin;
using std::cout;
using std::endl;

// Default Constructor
Library::Library()
{
    up = NULL;
    down = NULL;
    left = NULL;
    right = NULL;
    spaceNum = 4;
}

/*******************************************************************************
** Function Name: spaceInfo
** Description: Displays the room's name and information
*******************************************************************************/
void Library::spaceInfo()
{
    cout << "LIBRARY" << endl;
    cout << "There are rows and rows of books reaching as high as the ceiling! ";
    cout << "You take a book off the shelf." << endl;
    cout << "You flip through some pages and put it back down. ";
    cout << "Something shiny on the shelf catches your eye.." << endl;
}

/*******************************************************************************
** Function Name: spaceMenu
** Description: Provides the player with the current room options and actions.
** Returns a pointer to the next room the player chooses.
*******************************************************************************/
Space* Library::spaceMenu(Player* player)
{
    do
    { 
        cout << "==========================" << endl;
        cout << "What will you do?" << endl;
        cout << "1. Go Up" << endl;
        cout << "2. Go Down" << endl;
        cout << "3. Go Left" << endl;
        cout << "4. Go Right" << endl;
        cout << "5. Take a Closer Look" << endl;
        int choice = intValidation(5);
        
        switch (choice)
        {
        case 1:
            // up, the next room is the Observatory
            return up;
            break;

        case 2:
            // down
            cout << "Oof! There's a wall there. Take another look at the map." << endl;
            break;

        case 3:
            // left, the next room is the Cafeteria
            return left;
            break;

        case 4:
            // right
            cout << "Oof! There's a wall there. Take another look at the map." << endl;
            break;

        case 5: 
            // Special action: Unlock the cabinet with a key
            // Check if player has key and does not already have the movie item
            if (!(player->searchInventory("key")))
            {
            cout << "It's a key! You put it in your pocket. It may be useful later." << endl;
            player->addItem(new Item("key"));
            }
            else 
            {
            cout << "There was nothing there." << endl;
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
int Library::getSpace()
{
    return spaceNum;
}

void Library::setUp(Space* room)
{
    up = room;
}

void Library::setDown(Space* room)
{
    down = room;
}

void Library::setLeft(Space* room)
{
    left = room;
}

void Library::setRight(Space* room)
{
    right = room;
}

