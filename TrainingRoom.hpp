/*******************************************************************************
** Program name: Storm Area 51
** Author:       Elaine Kim
** Date:         August 9, 2019
** Description:  Header file for the TrainingRoom class. Inherits from space.
*******************************************************************************/
#ifndef TRAININGROOM_HPP
#define TRAININGROOM_HPP

#include "Space.hpp"

class TrainingRoom : public Space
{
private:
    Space *up,
          *down,
          *left,
          *right;
    int spaceNum;
    
public:
    TrainingRoom();
    virtual void spaceInfo();
    virtual Space* spaceMenu(Player *);
    virtual void setUp(Space*);
    virtual void setDown(Space*);
    virtual void setLeft(Space*);
    virtual void setRight(Space*);
    virtual int getSpace();
};
#endif
