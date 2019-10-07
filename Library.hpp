/*******************************************************************************
** Program name: Storm Area 51
** Author:       Elaine Kim
** Date:         August 9, 2019
** Description:  Header file for the Library class. Inherits from Space.
*******************************************************************************/
#ifndef LIBRARY_HPP
#define LIBRARY_HPP

#include "Space.hpp"

class Library : public Space
{
private:
    Space *up,
          *down,
          *left,
          *right;
    int spaceNum;
    
public:
    Library();
    virtual void spaceInfo();
    virtual Space* spaceMenu(Player *);
    virtual  int getSpace();
    virtual void setUp(Space*);
    virtual void setDown(Space*);
    virtual void setLeft(Space*);
    virtual void setRight(Space*);
};
#endif
