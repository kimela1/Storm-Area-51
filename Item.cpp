/*******************************************************************************
** Program name: Storm Area 51
** Author:       Elaine Kim
** Date:         August 9, 2019
** Description:  Source file for the Item class
*******************************************************************************/
#include "Item.hpp"

// Default constructor
Item::Item()
{
  name = "";
}

// Overload constructor
Item::Item(std::string name)
{
  this->name = name;
}

// Destructor
Item::~Item(){}

/*******************************************************************************
** Getter
*******************************************************************************/
std::string Item::getName()
{
  return name;
}
