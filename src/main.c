/**
 * Hello World Example
 * Created With Genesis-Code extension for Visual Studio Code
 * Use "Genesis Code: Compile" command to compile this program.
 **/
#include "incs.h"

enum GAME_STATE
{
    STATE_LOGO_PHASE1,
    STATE_LOGO_PHASE2,
    STATE_MENU,
    STATE_PLAY
};

enum GAME_STATE currentState;


void basicInit(){
    JOY_init();
    SPR_init(0, 0, 0);
    VDP_setTextPlane(BG_A);
    animationStuntTimer = 250;
    spritemylogoPosY = 50;
    spritemylogohandPosY = 50;
    generalPurposeCounter = 0;
    doIncrease = FALSE;
    doneLoadingVRAM = FALSE;
    generalPurposeX1 = 148;
    generalPurposeY1 = 140;
    generalPurposeX2 = 148;
    generalPurposeY2 = 140;
    generalPurposeX3 = 168;
    generalPurposeY3 = 140;
    generalPurposeX4 = 168;
    generalPurposeY4 = 140;
    deadelineMovementSpeed = 8;
    currentState = STATE_LOGO_PHASE1;
}


void prepareResForLogoAnimation(){
    VDP_loadTileSet(bgtile.tileset, 1, DMA);
    VDP_loadTileSet(blanktile.tileset, 2, DMA);
    VDP_setPalette(PAL0, bgtile.palette->data);
    VDP_setPalette(PAL1, spritemylogohand.palette->data);
    VDP_setPalette(PAL2, spritemylogo.palette->data);

    XGM_setLoopNumber(-1);
    XGM_startPlay(testmusic);

    mylogohand = SPR_addSprite(&spritemylogohand, 130, 50, TILE_ATTR(PAL1, 0, FALSE, FALSE));
    mylogo = SPR_addSprite(&spritemylogo, 90, 50, TILE_ATTR(PAL2, 0, FALSE, FALSE));

    //VDP_fillTileMapRect(BG_B, TILE_ATTR_FULL(PAL0, 0, FALSE, FALSE, 1), 0, 0, 40, 30);
}

void logoAnimationPhase1(){
    if(animationStuntTimer >= -150){
        if(animationStuntTimer < 0){
            SPR_setPosition(mylogohand, 130, spritemylogohandPosY);
            spritemylogohandPosY = spritemylogohandPosY - 2;

            SPR_setPosition(mylogo, 90, spritemylogoPosY);
            spritemylogoPosY = spritemylogoPosY + 2;
        }
    }

    if(animationStuntTimer == -151){
        SPR_reset();
        VDP_setPalette(PAL1, sprite_deadeline_idle1.palette->data);
        VDP_setPalette(PAL0, blanktile.palette->data);
        
        currentState = STATE_LOGO_PHASE2;
    }   
    animationStuntTimer = animationStuntTimer - 1;
}


void logoAnimationPhase2(){
    animationStuntTimer = animationStuntTimer + 1;

    if(!doneLoadingVRAM){
        SPR_clear();
        SPR_reset();
        gravestone = SPR_addSprite(&sprite_gravestone, 150, 140, TILE_ATTR(PAL2, 0, FALSE, FALSE));
        floor_piece = SPR_addSprite(&sprite_floor_piece, 100, 160, TILE_ATTR(PAL1, 0, FALSE, FALSE));
        //deadeline_idle1 = SPR_addSprite(&sprite_deadeline_idle1, 10, 10, TILE_ATTR(PAL1, 0, FALSE, FALSE));
        doneLoadingVRAM = !doneLoadingVRAM;
    }  

    if(animationStuntTimer == -57){
        VDP_fillTileMapRect(BG_B, TILE_ATTR_FULL(PAL0, 0, FALSE, FALSE, 2), 0, 0, 40, 30);
    } 
    if(animationStuntTimer == -47){
        VDP_fillTileMapRect(BG_B, TILE_ATTR_FULL(PAL0, 0, FALSE, FALSE, 1), 0, 0, 40, 30);
    }

    if(animationStuntTimer == -25){
        VDP_fillTileMapRect(BG_B, TILE_ATTR_FULL(PAL0, 0, FALSE, FALSE, 2), 0, 0, 40, 30);
    }
    if(animationStuntTimer == -15){
        VDP_fillTileMapRect(BG_B, TILE_ATTR_FULL(PAL0, 0, FALSE, FALSE, 1), 0, 0, 40, 30);
    }

    if(animationStuntTimer == 30){
        VDP_fillTileMapRect(BG_B, TILE_ATTR_FULL(PAL0, 0, FALSE, FALSE, 2), 0, 0, 40, 30);
    }
    if(animationStuntTimer == 40){
        VDP_fillTileMapRect(BG_B, TILE_ATTR_FULL(PAL0, 0, FALSE, FALSE, 1), 0, 0, 40, 30);
    }

    if(animationStuntTimer == 60){
        SPR_setPosition(gravestone, 152, 140);
    }
    if(animationStuntTimer == 70){
        SPR_setPosition(gravestone, 148, 140);
    }
    if(animationStuntTimer == 80){
        SPR_setPosition(gravestone, 152, 140);
    }
    if(animationStuntTimer == 90){
        SPR_setPosition(gravestone, 148, 140);
    }
    if(animationStuntTimer == 100){
        SPR_setPosition(gravestone, 152, 140);
    }
    if(animationStuntTimer == 110){
        SPR_setPosition(gravestone, 148, 140);
    }
    if(animationStuntTimer == 120){
        SPR_setPosition(gravestone, 152, 140);
    }
    if(animationStuntTimer == 130){
        SPR_setPosition(gravestone, 148, 140);
    }
    if(animationStuntTimer == 140){
        SPR_setPosition(gravestone, 152, 140);
    }
    if(animationStuntTimer == 150){
        SPR_setPosition(gravestone, 148, 140);
    }
    if(animationStuntTimer == 160){
        SPR_setPosition(gravestone, 152, 140);
    }
    if(animationStuntTimer == 170){
        SPR_setPosition(gravestone, 148, 140);
    }

    if(animationStuntTimer == 200){
        SPR_releaseSprite(gravestone);
        SPR_releaseSprite(floor_piece);
        SPR_reset();
        VDP_setPalette(PAL2, sprite_title_part1.palette->data);
        floor_piece = SPR_addSprite(&sprite_floor_piece, 100, 160, TILE_ATTR(PAL1, 0, FALSE, FALSE));
        gravestone_piece1 = SPR_addSprite(&sprite_gravestone_piece1, -32, -32, TILE_ATTR(PAL2, 0, FALSE, FALSE));
        gravestone_piece2 = SPR_addSprite(&sprite_gravestone_piece2, -32, -32, TILE_ATTR(PAL2, 0, FALSE, FALSE));
        gravestone_piece3 = SPR_addSprite(&sprite_gravestone_piece3, -32, -32, TILE_ATTR(PAL2, 0, FALSE, FALSE));
        gravestone_piece4 = SPR_addSprite(&sprite_gravestone_piece4, -32, -32, TILE_ATTR(PAL2, 0, FALSE, FALSE));
        deadelinePosX = 150;
        deadelinePosY = 150;
        deadeline_falling = SPR_addSprite(&sprite_deadeline_falling, deadelinePosX, deadelinePosY, TILE_ATTR(PAL1, 0, FALSE, FALSE));
        SPR_setPosition(gravestone_piece1, 148, 140);
        SPR_setPosition(gravestone_piece2, 148, 140);
        SPR_setPosition(gravestone_piece3, 168, 140);
        SPR_setPosition(gravestone_piece4, 168, 140);
    }

    if(animationStuntTimer == 200){
        VDP_fillTileMapRect(BG_B, TILE_ATTR_FULL(PAL0, 0, FALSE, FALSE, 2), 0, 0, 40, 30);
    } 
    if(animationStuntTimer == 210){
        VDP_fillTileMapRect(BG_B, TILE_ATTR_FULL(PAL0, 0, FALSE, FALSE, 1), 0, 0, 40, 30);
    }
    if(animationStuntTimer > 200 && animationStuntTimer < 235){
        SPR_setPosition(deadeline_falling, deadelinePosX, deadelinePosY);
        deadelinePosY = deadelinePosY - (1 + deadelineMovementSpeed);
    }
    if(animationStuntTimer > 210 && animationStuntTimer < 235){
        deadelineMovementSpeed = deadelineMovementSpeed - 1;
    }
    if(animationStuntTimer > 200 && animationStuntTimer < 255){
        SPR_setPosition(gravestone_piece1, generalPurposeX1, generalPurposeY1);
        SPR_setPosition(gravestone_piece2, generalPurposeX2, generalPurposeY2);
        SPR_setPosition(gravestone_piece3, generalPurposeX3, generalPurposeY3);
        SPR_setPosition(gravestone_piece4, generalPurposeX4, generalPurposeY4);
        generalPurposeX1 = generalPurposeX1 - 6;
        generalPurposeY1 = generalPurposeY1 - 6;
        generalPurposeX2 = generalPurposeX2 - 4;
        generalPurposeY2 = generalPurposeY2 - 4;
        generalPurposeX3 = generalPurposeX3 + 6;
        generalPurposeY3 = generalPurposeY3 - 6;
        generalPurposeX4 = generalPurposeX4 + 4;
        generalPurposeY4 = generalPurposeY4 - 4;
    }
    if(animationStuntTimer == 255){
        SPR_releaseSprite(gravestone_piece1);
        SPR_releaseSprite(gravestone_piece2);
        SPR_releaseSprite(gravestone_piece3);
        SPR_releaseSprite(gravestone_piece4);
        generalPurposeY1 = -128;
        deadelineMovementSpeed = 8;
        genericBool1 = TRUE;
        title_part1 = SPR_addSprite(&sprite_title_part1, 30, -128, TILE_ATTR(PAL2, 0, FALSE, FALSE));
        title_part2 = SPR_addSprite(&sprite_title_part2, 158, -128, TILE_ATTR(PAL2, 0, FALSE, FALSE));
    }
    if(animationStuntTimer == 235){
        SPR_releaseSprite(deadeline_falling);
        SPR_releaseSprite(floor_piece);
        deadeline_idle1 = SPR_addSprite(&sprite_deadeline_idle1, deadelinePosX, 125, TILE_ATTR(PAL1, 0, FALSE, FALSE));
        floor_piece = SPR_addSprite(&sprite_floor_piece, 100, 160, TILE_ATTR(PAL1, 0, FALSE, FALSE));
    }

    if(animationStuntTimer > 255 && genericBool2){
        SPR_setPosition(title_part1, 30, generalPurposeY1);
        SPR_setPosition(title_part2, 158, generalPurposeY1);
        if(genericBool1){
            generalPurposeY1 = generalPurposeY1 + (1 + deadelineMovementSpeed);
            if(generalPurposeY1 > 20){
                deadelineMovementSpeed = deadelineMovementSpeed / 2;
                generalPurposeY1 = 20;
                genericBool1 = !genericBool1;
            }
        }
        if(!genericBool1){
            generalPurposeY1 = generalPurposeY1 - (1 + deadelineMovementSpeed);
            if(generalPurposeY1 < 5){
                generalPurposeY1 = 5;
                genericBool1 = !genericBool1;
            }
        }
        if(deadelineMovementSpeed == 1){
            genericBool2 = !genericBool2;
        }
    }
    if(animationStuntTimer > 255 && !genericBool2){
        VDP_drawText("PRESS...", 2, 20);
    }
}

int main(){
    basicInit();
    prepareResForLogoAnimation();

    while(1)
    {
        switch(currentState){
            case STATE_LOGO_PHASE1:{
                logoAnimationPhase1();
                break;
            }
            case STATE_LOGO_PHASE2:{
                logoAnimationPhase2();     
                break;
            }
            case STATE_MENU:{
                SPR_reset();
                break;
            }
            case STATE_PLAY:{
                
                break;
            }
        }
        SPR_update();
        SYS_doVBlankProcess();
        /*
        sprintf(srt_animationStuntTimer, "%d", animationStuntTimer);
        VDP_clearText(0, 0, 6);
        VDP_drawText(srt_animationStuntTimer, 0, 0);
        */
    }
    return (0);
}
