#ifndef GAME_H
#define GAME_H

#include <Arduino.h>
#include "globals.h"
#include "inputs.h"
#include "player.h"
#include "enemies.h"
#include "elements.h"
#include "levels.h"

void stateGamePrepareLevel()
{
  //level = 0;
  scorePlayer = 0;
  setKid();
  cam.pos = vec2(0, 0);
  cam.offset = vec2(0, 0);
  //gameState = STATE_GAME_NEXT_LEVEL;
  gameState = STATE_GAME_PLAYING;
  levelLoad(level);
};

void stateGameNextLevel()
{
  level++;
  //gameState = STATE_GAME_PLAYING;
  gameState = STATE_GAME_PREPARE_LEVEL;
};

void stateGamePlaying()
{
  checkInputs();
  checkKid();
  updateCamera();

  drawGrid();
  drawKid();
  
  checkCollisions();
}


void stateGamePause()
{
  if (arduboy.justPressed(A_BUTTON | B_BUTTON))
  {
    gameState = STATE_MENU_MAIN;
  }
}


void stateGameOver()
{
  if (arduboy.justPressed(A_BUTTON | B_BUTTON))
  {
    gameState = STATE_GAME_PLAYING;
  }
}

#endif
