/*******************************************************************************
** Program name: Final Project - Storm Area 51 (text based game)
** Author:       Elaine Kim
** Date:         August 9, 2019
** Description:  Header file for the Observatory class. Inherits from Space.
*******************************************************************************/
#ifndef OBSERVATORY_HPP
#define OBSERVATORY_HPP

#include "Space.hpp"

class Observatory : public Space
{
private:
    Space *up,
          *down,
          *left,
          *right;
    int spaceNum;
    
public:
    Observatory();
    virtual void spaceInfo();
    virtual Space* spaceMenu(Player *);
    virtual  int getSpace();
    virtual void setUp(Space*);
    virtual void setDown(Space*);
    virtual void setLeft(Space*);
    virtual void setRight(Space*);
};
#endif