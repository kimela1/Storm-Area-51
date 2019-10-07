/*******************************************************************************
** Program name: Final Project - Storm Area 51 (text based game)
** Author:       Elaine Kim
** Date:         August 9, 2019
** Description:  Header file for the Item class
*******************************************************************************/
#include <string>

#ifndef ITEM_HPP
#define ITEM_HPP

class Item
{
private:
    std::string name;

public:
    Item();
    Item(std::string);
    virtual ~Item();
    std::string getName();
};
#endif