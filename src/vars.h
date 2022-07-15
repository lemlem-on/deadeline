#ifndef VARS_H
#define VARS_H

#include "incs.h"

char srt_animationStuntTimer[6] = "250";

Sprite* mylogo;
Sprite* ball;
Sprite* mylogohand;
Sprite* title_part1;
Sprite* title_part2;
Sprite* deadeline_idle1;
Sprite* deadeline_idle2;
Sprite* deadeline_idle3;
Sprite* deadeline_idle4;
Sprite* deadeline_idle5;
Sprite* deadeline_idle6;
Sprite* deadeline_idle7;
Sprite* deadeline_idle8;
Sprite* deadeline_idle9;
Sprite* deadeline_idle10;
Sprite* deadeline_falling;
Sprite* floor_piece;

Sprite* gravestone;
Sprite* gravestone_piece1;
Sprite* gravestone_piece2;
Sprite* gravestone_piece3;
Sprite* gravestone_piece4;

//general game core related

int animationStuntTimer = 250;


int spritemylogoPosY = 50;

int spritemylogohandPosY = 50;

int spritelifeCharPosX = 0;
int spritelifeCharPosY = 0;

int generalPurposeCounter = 0;

int generalPurposeX1 = 148;
int generalPurposeY1 = 140;
int generalPurposeX2 = 148;
int generalPurposeY2 = 140;
int generalPurposeX3 = 168;
int generalPurposeY3 = 140;
int generalPurposeX4 = 168;
int generalPurposeY4 = 140;

//deadeline related
int deadelinePosX = 0;
int deadelinePosY = 0;
int deadelineMovementSpeed = 8;

bool doIncrease = FALSE;
bool doneLoadingVRAM = FALSE;
bool genericBool1 = FALSE;
bool genericBool2 = TRUE;

#endif // VARS_H