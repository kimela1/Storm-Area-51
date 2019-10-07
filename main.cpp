/*******************************************************************************
** Program name: Final Project - Storm Area 51 (text based game)
** Author:       Elaine Kim
** Date:         August 9, 2019
** Description:  This is a text based game named "Storm Area 51" that gives the
** player the chance to go on an adventure through Area 51 and try to befriend
** an alien. The player is able to move through the map by entering different 
** rooms and can also interact with certain rooms. The win conditions is becoming
** friends with the alien. The player must accomplish their goal before losing 
** all their health.  
*******************************************************************************/
#include <iostream>

#include "Game.hpp"

int main()
{
  Game g;
  
  g.playGame();
  
  return 0;
}
