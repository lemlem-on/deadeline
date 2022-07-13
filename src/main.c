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
    currentState = STATE_LOGO_PHASE1;
}


void prepareResForLogoAnimation(){
    VDP_loadTileSet(bgtile.tileset, 1, DMA);
    VDP_setPalette(PAL0, bgtile.palette->data);
    VDP_setPalette(PAL1, spritemylogohand.palette->data);
    VDP_setPalette(PAL2, spritemylogo.palette->data);

    XGM_setLoopNumber(-1);
    XGM_startPlay(&testmusic);

    mylogohand = SPR_addSprite(&spritemylogohand, 130, 50, TILE_ATTR(PAL1, 0, FALSE, FALSE));
    mylogo = SPR_addSprite(&spritemylogo, 90, 50, TILE_ATTR(PAL2, 0, FALSE, FALSE));

    VDP_fillTileMapRect(BG_B, TILE_ATTR_FULL(PAL0, 0, FALSE, FALSE, 1), 0, 0, 40, 30);
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
        
        
        currentState = STATE_LOGO_PHASE2;
    }   
    animationStuntTimer = animationStuntTimer - 1;
}


void logoAnimationPhase2(){

    
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
    }
    return (0);
}
