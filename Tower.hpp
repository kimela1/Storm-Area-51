/*******************************************************************************
** Program name: Storm Area 51
** Author:       Elaine Kim
** Date:         August 9, 2019
** Description:  Header file for the Tower class. Inherits from Space.
*******************************************************************************/
#ifndef TOWER_HPP
#define TOWER_HPP

#include "Space.hpp"

class Tower : public Space
{
private:
    Space *up,
          *down,
          *left,
          *right;
    int spaceNum;
    
public:
    Tower();
    virtual void spaceInfo();
    virtual Space* spaceMenu(Player*);
    virtual int getSpace();
    virtual void setUp(Space*);
    virtual void setDown(Space*);
    virtual void setLeft(Space*);
    virtual void setRight(Space*);
};
#endif
