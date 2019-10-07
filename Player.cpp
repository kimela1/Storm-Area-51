/*******************************************************************************
** Program name: Final Project - Storm Area 51 (text based game)
** Author:       Elaine Kim
** Date:         August 9, 2019
** Description:  Source file for the Player class
*******************************************************************************/
#include "Player.hpp"

// Default constructor
Player::Player()
{
  health = 75;
}

// Destructor
Player::~Player()
{
  for (int i = 0; i < inventory.size(); i++)
  {
    if (inventory[i] != NULL)
    {
      delete inventory[i];
      inventory[i] = NULL;
    }
  }
}

/*******************************************************************************
** Getters and Setters
*******************************************************************************/
int Player::getHealth()
{
  return health;
}

void Player::getInventory()
{
  for (int i = 0; i < inventory.size(); i++)
  {
    std::cout << inventory[i]->getName() << ", ";
  }
}

/*******************************************************************************
** Function Name: addHealth
** Description: Adds amount to the player's health
*******************************************************************************/

void Player::addHealth(int amount)
{
  health += amount;
}

/*******************************************************************************
** Function Name: subHealth
** Description: Subtract amount from the player's health
*******************************************************************************/
void Player::subHealth(int amount)
{
  health -= amount;
}

/*******************************************************************************
** Function Name: addItem
** Description: Adds an item to the inventory
*******************************************************************************/
void Player::addItem(Item* newItem)
{
  inventory.push_back(newItem);
}

/*******************************************************************************
** Function Name: searchInventory
** Description: Searches the inventory for an item (by name). If the item is in
** the inventory, returns true. Otherwise, returns false.
*******************************************************************************/
bool Player::searchInventory(std::string name)
{
  for (int i = 0; i < inventory.size(); i++)
  {
    // Check if item is in inventory
    if (inventory[i]->getName() == name)
    {
      // Item in inventory
      return true;
    }
  }
  // Item not in inventory
  return false;
}