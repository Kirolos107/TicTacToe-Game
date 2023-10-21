#ifndef G_FILE_H
#define G_FILE_H

#include "STD_TYPES.h"

uint8 Exit;
uint8 Mode;
uint8 Pos_P1;
uint8 Pos_P2;

void Game_Modes(uint8 Arr[][7]);

void DiplayGame(uint8 Arr[][7]);

void GameInst(void);

uint8 FirstPlayer_Moving(uint8 Arr[][7]);

uint8 SecondPlayer_Moving(uint8 Arr[][7]);

uint8 PC_Player_Moving(uint8 Arr[][7]);

uint8 GetCol (uint8 Base, uint8 Input);

uint8 WinCondition(uint8 Arr[][7]);

uint8 DrawCondition(uint8 Arr[][7]);

void SingleMode_Game(uint8 Arr[][7]);

void MultiMode_Game (uint8 Arr[][7]);

void RepeatGame(uint8 Arr[][7]);

#endif // G_FILE_H

