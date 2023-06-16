#include "AppControl.h"
#include <Arduino.h>
#include <M5Stack.h>

MdLcd mlcd;
MdWBGTMonitor mwbgt;
MdMusicPlayer mmplay;
MdMeasureDistance mmdist;
MdDateTime mdtime;

const char* g_str_orange[] = {
    COMMON_ORANGE0_IMG_PATH,
    COMMON_ORANGE1_IMG_PATH,
    COMMON_ORANGE2_IMG_PATH,
    COMMON_ORANGE3_IMG_PATH,
    COMMON_ORANGE4_IMG_PATH,
    COMMON_ORANGE5_IMG_PATH,
    COMMON_ORANGE6_IMG_PATH,
    COMMON_ORANGE7_IMG_PATH,
    COMMON_ORANGE8_IMG_PATH,
    COMMON_ORANGE9_IMG_PATH,
};

const char* g_str_blue[] = {
    COMMON_BLUE0_IMG_PATH,
    COMMON_BLUE1_IMG_PATH,
    COMMON_BLUE2_IMG_PATH,
    COMMON_BLUE3_IMG_PATH,
    COMMON_BLUE4_IMG_PATH,
    COMMON_BLUE5_IMG_PATH,
    COMMON_BLUE6_IMG_PATH,
    COMMON_BLUE7_IMG_PATH,
    COMMON_BLUE8_IMG_PATH,
    COMMON_BLUE9_IMG_PATH,
};

void AppControl::setBtnAFlg(bool flg)
{
    m_flag_btnA_is_pressed = flg;
}

void AppControl::setBtnBFlg(bool flg)
{
    m_flag_btnB_is_pressed = flg;
}

void AppControl::setBtnCFlg(bool flg)
{
    m_flag_btnC_is_pressed = flg;
}

void AppControl::setBtnAllFlgFalse()
{
    m_flag_btnA_is_pressed = false;
    m_flag_btnB_is_pressed = false;
    m_flag_btnC_is_pressed = false;
}

State AppControl::getState()
{
    return m_state;
}

void AppControl::setState(State state)
{
    m_state = state;
}

Action AppControl::getAction()
{
    return m_action;
}

void AppControl::setAction(Action action)
{
    m_action = action;
}

void AppControl::setStateMachine(State state, Action action)
{
    setState(state);
    setAction(action);
}

FocusState AppControl::getFocusState()
{
    return m_focus_state;
}

void AppControl::setFocusState(FocusState fs)
{
    m_focus_state = fs;
}

void AppControl::displayTitleInit()
{
    mlcd.displayJpgImageCoordinate(TITLE_IMG_PATH,TITEL_X_CRD,TITEL_Y_CRD);
}

void AppControl::displayMenuInit()
{   
    mlcd.displayJpgImageCoordinate(MENU_WBGT_FOCUS_IMG_PATH, MENU_WBGT_X_CRD,MENU_WBGT_Y_CRD);
    mlcd.displayJpgImageCoordinate(MENU_MUSIC_IMG_PATH,MENU_MUSIC_X_CRD,MENU_MUSIC_Y_CRD);
    mlcd.displayJpgImageCoordinate(MENU_MEASURE_IMG_PATH,MENU_MEASURE_X_CRD,MENU_MEASURE_Y_CRD);
    mlcd.displayJpgImageCoordinate(MENU_DATE_IMG_PATH,MENU_DATE_X_CRD,MENU_DATE_Y_CRD);
    mlcd.displayJpgImageCoordinate(COMMON_BUTTON_UP_IMG_PATH,COMMON_BUTTON_UP_X_CRD,COMMON_BUTTON_UP_Y_CRD);
    mlcd.displayJpgImageCoordinate(COMMON_BUTTON_DECIDE_IMG_PATH,COMMON_BUTTON_DECIDE_X_CRD,COMMON_BUTTON_DECIDE_Y_CRD);   
    mlcd.displayJpgImageCoordinate(COMMON_BUTTON_DOWN_IMG_PATH,COMMON_BUTTON_DOWN_X_CRD,COMMON_BUTTON_DOWN_Y_CRD);
}
void AppControl::focusChangeImg(FocusState current_state, FocusState next_state)
{ 
   switch (current_state) {
        case MENU_WBGT:
            mlcd.displayJpgImageCoordinate(MENU_WBGT_IMG_PATH, MENU_WBGT_X_CRD,MENU_WBGT_Y_CRD);
            break;
        case MENU_MUSIC:
            mlcd.displayJpgImageCoordinate(MENU_MUSIC_IMG_PATH,MENU_MUSIC_X_CRD,MENU_MUSIC_Y_CRD);
            break;
        case MENU_MEASURE:
            mlcd.displayJpgImageCoordinate(MENU_MEASURE_IMG_PATH,MENU_MEASURE_X_CRD,MENU_MEASURE_Y_CRD);
            break;
        case MENU_DATE:
           mlcd.displayJpgImageCoordinate(MENU_DATE_IMG_PATH,MENU_DATE_X_CRD,MENU_DATE_Y_CRD);
            break;
    }

   switch (next_state) {
        case MENU_WBGT:
            mlcd.displayJpgImageCoordinate(MENU_WBGT_FOCUS_IMG_PATH, MENU_WBGT_X_CRD,MENU_WBGT_Y_CRD);
            break;
        case MENU_MUSIC:
            mlcd.displayJpgImageCoordinate(MENU_MUSIC_FOCUS_IMG_PATH,MENU_MUSIC_X_CRD,MENU_MUSIC_Y_CRD);
            break;
        case MENU_MEASURE:
            mlcd.displayJpgImageCoordinate(MENU_MEASURE_FOCUS_IMG_PATH,MENU_MEASURE_X_CRD,MENU_MEASURE_Y_CRD);
            break;
        case MENU_DATE:
           mlcd.displayJpgImageCoordinate(MENU_DATE_FOCUS_IMG_PATH,MENU_DATE_X_CRD,MENU_DATE_Y_CRD);
            break;
    }

}


void AppControl::displayWBGTInit()
{

    mlcd.clearDisplay();
    mlcd.fillBackgroundWhite();
    mlcd.displayJpgImageCoordinate(WBGT_TEMPERATURE_IMG_PATH,WBGT_TEMPERATURE_X_CRD,WBGT_TEMPERATURE_Y_CRD);
    mlcd.displayJpgImageCoordinate(WBGT_HUMIDITY_IMG_PATH,WBGT_HUMIDITY_X_CRD,WBGT_HUMIDITY_Y_CRD);
    mlcd.displayJpgImageCoordinate(WBGT_SAFE_IMG_PATH,WBGT_SAFE_X_CRD,WBGT_SAFE_Y_CRD);
    mlcd.displayJpgImageCoordinate(WBGT_DEGREE_IMG_PATH,WBGT_DEGREE_X_CRD,WBGT_DEGREE_Y_CRD);
    mlcd.displayJpgImageCoordinate(WBGT_PERCENT_IMG_PATH,WBGT_PERCENT_X_CRD,WBGT_PERCENT_Y_CRD);
    mlcd.displayJpgImageCoordinate(COMMON_BUTTON_BACK_IMG_PATH,COMMON_BUTTON_BACK_X_CRD,COMMON_BUTTON_BACK_Y_CRD);
}


void AppControl::displayTempHumiIndex()
{
}
void AppControl::displayMusicInit()
{
    mlcd.clearDisplay();
    mlcd.fillBackgroundWhite();
}

void AppControl::displayMusicStop()
{
}

void AppControl::displayMusicTitle()
{
}

void AppControl::displayNextMusic()
{
}

void AppControl::displayMusicPlay()
{
}

void AppControl::displayMeasureInit()
{
    mlcd.clearDisplay();
    mlcd.fillBackgroundWhite(); 
}

void AppControl::displayMeasureDistance()
{
}

void AppControl::displayDateInit()
{
    mlcd.clearDisplay();
    mlcd.fillBackgroundWhite(); 
}

void AppControl::displayDateUpdate()
{
}

void AppControl::controlApplication()
{
    mmplay.init();
    
    while (1) {

        switch (getState()) {
        case TITLE:
            switch (getAction()) {
            case ENTRY:
                /*
                ** まずはここにタイトル画面の表示処理を呼び出してみよう。
                ** タイトル画面表示の関数はdisplayTitleInit()である。
                ** この関数の中身はまだ何もないので、この関数にタイトル画面表示処理を書いてみよう。
                */
                
                displayTitleInit(); 
                setStateMachine(TITLE,DO);  
                break;

            case DO:  
                if((m_flag_btnA_is_pressed || m_flag_btnB_is_pressed || m_flag_btnC_is_pressed) == true){
                   setBtnAllFlgFalse();
                   displayMenuInit(); 
                setStateMachine(TITLE,EXIT);
                }
                
                break;

            case EXIT:
                setStateMachine(MENU,ENTRY);
                break;

            default:
                break;
            }

            break;

        case MENU:
           
            switch (getAction()) {  
                case ENTRY:
                    displayMenuInit();
                    setStateMachine(MENU,DO);
                    
                case DO:
                    if( m_flag_btnC_is_pressed == true){
                        setBtnAllFlgFalse();
                        switch (getFocusState()){
                            case MENU_WBGT:
                                focusChangeImg(MENU_WBGT,MENU_MUSIC); 
                                setFocusState(MENU_MUSIC);
                                break;
                            case MENU_MUSIC:
                                focusChangeImg(MENU_MUSIC,MENU_MEASURE); 
                                setFocusState(MENU_MEASURE);
                                break;
                            case MENU_MEASURE:
                                focusChangeImg(MENU_MEASURE,MENU_DATE);
                                setFocusState(MENU_DATE);
                                break;
                            case MENU_DATE:
                                focusChangeImg(MENU_DATE,MENU_WBGT);
                                setFocusState(MENU_WBGT);
                                break;
                        }        
                    }else if( m_flag_btnA_is_pressed == true){
                        setBtnAllFlgFalse();
                        switch (getFocusState()){
                            case MENU_WBGT:
                                focusChangeImg(MENU_WBGT,MENU_DATE); 
                                setFocusState(MENU_DATE);
                                break;
                            case MENU_DATE:
                                focusChangeImg(MENU_DATE,MENU_MEASURE); 
                                setFocusState(MENU_MEASURE);
                                break;
                            case MENU_MEASURE:
                                focusChangeImg(MENU_MEASURE,MENU_MUSIC);
                                setFocusState(MENU_MUSIC);
                                break;
                            case MENU_MUSIC:
                                focusChangeImg(MENU_MUSIC,MENU_WBGT);
                                setFocusState(MENU_WBGT);
                                break;
                        }        
                    }else if( m_flag_btnB_is_pressed == true){
                        setBtnAllFlgFalse();
                        switch (getFocusState()){
                            case MENU_WBGT:
                                 setStateMachine(MENU,EXIT);
                                break;
                            case MENU_MUSIC:
                                setStateMachine(MENU,EXIT);
                                break;
                            case MENU_MEASURE:
                                setStateMachine(MENU,EXIT);
                                break;
                            case MENU_DATE:
                                setStateMachine(MENU,EXIT);
                                break;
                        }        
                    }
                    break;

                case EXIT:
                     switch (getFocusState()){
                            case MENU_WBGT:
                                 setStateMachine(WBGT,ENTRY);
                                break;
                            case MENU_MUSIC:
                                setStateMachine(MUSIC_STOP,ENTRY);
                                break;
                            case MENU_MEASURE:
                                setStateMachine(MEASURE,ENTRY);
                                break;
                            case MENU_DATE:
                                setStateMachine(DATE,ENTRY);
                                break;
                        }                 
            default:
                break;
            }

            break;
 
        case WBGT:

            switch (getAction()) {
            case ENTRY:
                displayWBGTInit();
                
                setStateMachine(WBGT,DO);
                break;

            case DO:
                break;

            case EXIT:
                break;

            default:
                break;
            }

            break;

        case MUSIC_STOP:
            switch (getAction()) {
            case ENTRY:
                displayMusicInit();
                setStateMachine(MUSIC_STOP,DO);
                break;

            case DO:
                break;

            case EXIT:
                break;

            default:
                break;
            }

            break;

        case MUSIC_PLAY:

            switch (getAction()) {
            case ENTRY:
                break;

            case DO:
                break;

            case EXIT:
                break;

            default:
                break;
            }

            break;

        case MEASURE:

            switch (getAction()) {
            case ENTRY:
                displayMeasureInit();
                setStateMachine(MEASURE,DO);
                break;

            case DO:
                break;

            case EXIT:
                break;

            default:
                break;
            }

            break;

        case DATE:

            switch (getAction()) {
            case ENTRY:
                displayDateInit();
                setStateMachine(DATE,DO);
                break;

            case DO:
                break;

            case EXIT:
                break;

            default:
                break;
            }

        default:
            break;
        }
    }
}
