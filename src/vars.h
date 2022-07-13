#ifndef VARS_H
#define VARS_H

#include "incs.h"

char srt_animationStuntTimer[6] = "250";

Sprite* mylogo;
Sprite* ball;
Sprite* mylogohand;
Sprite* title;
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
Sprite* floor_piece;
Sprite* gravestone;

int animationStuntTimer = 250;


int spritemylogoPosY = 50;

int spritemylogohandPosY = 50;

int spritelifeCharPosX = 0;
int spritelifeCharPosY = 0;

int generalPurposeCounter = 0;

bool doIncrease = FALSE;
bool doneLoadingVRAM = FALSE;

#endif // VARS_H