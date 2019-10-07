/*******************************************************************************
** Program name: Storm Area 51
** Author:       Elaine Kim
** Date:         August 9, 2019
** Description:  Header file for the Player class
*******************************************************************************/
#ifndef PLAYER_HPP
#define PLAYER_HPP

#include "Item.hpp"
#include <vector>
#include <iostream>

class Player
{
  private:
    std::vector<Item*> inventory;
    int health;
    
  public:
    Player();
    ~Player();
    int getHealth();
    void getInventory();
    void addItem(Item*);
    void subHealth(int);
    void addHealth(int);
    bool searchInventory(std::string);
};
#endif
