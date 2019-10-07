/*******************************************************************************
** Program name: Final Project - Storm Area 51 (text based game)
** Author:       Elaine Kim
** Date:         August 9, 2019
** Description:  Header file for the Space abstract class. 
*******************************************************************************/
#ifndef SPACE_HPP
#define SPACE_HPP

#include <iostream>

#include "InputValidation.hpp"
#include "Player.hpp"

class Space
{
  private:
    Space *up,
          *down,
          *left,
          *right;
    int spaceNum;
    
  public:
    Space();
    virtual ~Space();
    virtual void spaceInfo() = 0;
    virtual Space* spaceMenu(Player*) = 0;
    virtual int getSpace() = 0;
    virtual void setUp(Space*) = 0;
    virtual void setDown(Space*) = 0;
    virtual void setLeft(Space*) = 0;
    virtual void setRight(Space*) = 0; 
};
#endif