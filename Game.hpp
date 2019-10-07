/*******************************************************************************
** Program name: Final Project - Storm Area 51 (text based game)
** Author:       Elaine Kim
** Date:         August 9, 2019
** Description:  Header file for the Game class
*******************************************************************************/
#ifndef GAME_HPP
#define GAME_HPP

#include "Player.hpp"
#include "Cafeteria.hpp"
#include "TrainingRoom.hpp"
#include "ResearchLab.hpp"
#include "Library.hpp"
#include "Observatory.hpp"
#include "Tower.hpp"

class Game
{
  private:
    Player *player;
    Space  *currentSpace,
           *cafeteriaPtr,
           *trainingRoomPtr,
           *researchLabPtr,
           *libraryPtr,
           *observatoryPtr,
           *towerPtr;
  public:
    Game();
    ~Game();
    void playGame();
    void printMap(Space*);
};
#endif