#include "AppControl.h"
#include <Arduino.h>
#include <M5Stack.h>

MdLcd mlcd;
MdWBGTMonitor mwbgt;
MdMusicPlayer mmplay;
MdMeasureDistance mmdist;
MdDateTime mdtime;

const char *g_str_orange[] = {
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

const char *g_str_blue[] = {
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
    mlcd.displayJpgImageCoordinate(TITLE_IMG_PATH, TITLE_X_CRD, TITLE_Y_CRD);
}

void AppControl::displayMenuInit()
{
    mlcd.fillBackgroundWhite();
    mlcd.displayJpgImageCoordinate(MENU_WBGT_IMG_PATH, MENU_WBGT_X_CRD, MENU_WBGT_Y_CRD);
    mlcd.displayJpgImageCoordinate(MENU_MUSIC_IMG_PATH, MENU_MUSIC_X_CRD, MENU_MUSIC_Y_CRD);
    mlcd.displayJpgImageCoordinate(MENU_MEASURE_IMG_PATH, MENU_MEASURE_X_CRD, MENU_MEASURE_Y_CRD);
    mlcd.displayJpgImageCoordinate(MENU_DATE_IMG_PATH, MENU_DATE_X_CRD, MENU_DATE_Y_CRD);
    mlcd.displayJpgImageCoordinate(COMMON_BUTTON_UP_IMG_PATH, MENU_UP_X_CRD, MENU_UP_Y_CRD);
    mlcd.displayJpgImageCoordinate(COMMON_BUTTON_DECIDE_IMG_PATH, MENU_DECIDE_X_CRD, MENU_DECIDE_Y_CRD);
    mlcd.displayJpgImageCoordinate(COMMON_BUTTON_DOWN_IMG_PATH, MENU_DOWN_X_CRD, MENU_DOWN_Y_CRD);
    switch (m_focus_state)
    {
    case MENU_WBGT:
        mlcd.displayJpgImageCoordinate(MENU_WBGT_FOCUS_IMG_PATH, MENU_WBGT_X_CRD, MENU_WBGT_Y_CRD);
        break;
    case MENU_MUSIC:
        mlcd.displayJpgImageCoordinate(MENU_MUSIC_FOCUS_IMG_PATH, MENU_MUSIC_X_CRD, MENU_MUSIC_Y_CRD);
        break;
    case MENU_MEASURE:
        mlcd.displayJpgImageCoordinate(MENU_MEASURE_FOCUS_IMG_PATH, MENU_MEASURE_X_CRD, MENU_MEASURE_Y_CRD);
        break;
    case MENU_DATE:
        mlcd.displayJpgImageCoordinate(MENU_DATE_FOCUS_IMG_PATH, MENU_DATE_X_CRD, MENU_DATE_Y_CRD);
        break;
    default:
        break;
    }
}

void AppControl::focusChangeImg(FocusState current_state, FocusState next_state)
{
    switch (current_state)
    {
    case MENU_WBGT:
        mlcd.displayJpgImageCoordinate(MENU_WBGT_IMG_PATH, MENU_WBGT_X_CRD, MENU_WBGT_Y_CRD);
        break;
    case MENU_MUSIC:
        mlcd.displayJpgImageCoordinate(MENU_MUSIC_IMG_PATH, MENU_MUSIC_X_CRD, MENU_MUSIC_Y_CRD);
        break;
    case MENU_MEASURE:
        mlcd.displayJpgImageCoordinate(MENU_MEASURE_IMG_PATH, MENU_MEASURE_X_CRD, MENU_MEASURE_Y_CRD);
        break;
    case MENU_DATE:
        mlcd.displayJpgImageCoordinate(MENU_DATE_IMG_PATH, MENU_DATE_X_CRD, MENU_DATE_Y_CRD);
        break;
    default:
        break;
    }

    switch (next_state)
    {
    case MENU_WBGT:
        mlcd.displayJpgImageCoordinate(MENU_WBGT_FOCUS_IMG_PATH, MENU_WBGT_X_CRD, MENU_WBGT_Y_CRD);
        break;
    case MENU_MUSIC:
        mlcd.displayJpgImageCoordinate(MENU_MUSIC_FOCUS_IMG_PATH, MENU_MUSIC_X_CRD, MENU_MUSIC_Y_CRD);
        break;
    case MENU_MEASURE:
        mlcd.displayJpgImageCoordinate(MENU_MEASURE_FOCUS_IMG_PATH, MENU_MEASURE_X_CRD, MENU_MEASURE_Y_CRD);
        break;
    case MENU_DATE:
        mlcd.displayJpgImageCoordinate(MENU_DATE_FOCUS_IMG_PATH, MENU_DATE_X_CRD, MENU_DATE_Y_CRD);
        break;
    default:
        break;
    }
}

void AppControl::displayWBGTInit()
{
    mwbgt.init();
    mlcd.fillBackgroundWhite();
    mlcd.displayJpgImageCoordinate(WBGT_TEMPERATURE_IMG_PATH, WBGT_TEMPERATURE_X_CRD, WBGT_TEMPERATURE_Y_CRD);
    mlcd.displayJpgImageCoordinate(WBGT_HUMIDITY_IMG_PATH, WBGT_HUMIDITY_X_CRD, WBGT_HUMIDITY_Y_CRD);
    mlcd.displayJpgImageCoordinate(COMMON_ORANGEDOT_IMG_PATH, WBGT_TDOT_X_CRD, WBGT_TDOT_Y_CRD);
    mlcd.displayJpgImageCoordinate(COMMON_BLUEDOT_IMG_PATH, WBGT_HDOT_X_CRD, WBGT_HDOT_Y_CRD);
    mlcd.displayJpgImageCoordinate(WBGT_DEGREE_IMG_PATH, WBGT_DEGREE_X_CRD, WBGT_DEGREE_Y_CRD);
    mlcd.displayJpgImageCoordinate(WBGT_PERCENT_IMG_PATH, WBGT_PERCENT_X_CRD, WBGT_PERCENT_Y_CRD);
    mlcd.displayJpgImageCoordinate(COMMON_BUTTON_BACK_IMG_PATH, WBGT_BACK_X_CRD, WBGT_BACK_Y_CRD);
}

void AppControl::displayTempHumiIndex()
{
    static double temperature;
    static double humidity;
    static WbgtIndex index;
    mwbgt.getWBGT(&temperature, &humidity, &index);

    int num = temperature * 10;
    mlcd.displayJpgImageCoordinate(g_str_orange[num / 100], WBGT_T2DIGIT_X_CRD, WBGT_T2DIGIT_Y_CRD);
    mlcd.displayJpgImageCoordinate(g_str_orange[num / 10 % 10], WBGT_T1DIGIT_X_CRD, WBGT_T1DIGIT_Y_CRD);
    mlcd.displayJpgImageCoordinate(g_str_orange[(num % 100) % 10], WBGT_T1DECIMAL_X_CRD, WBGT_T1DECIMAL_Y_CRD);

    num = humidity * 10;
    mlcd.displayJpgImageCoordinate(g_str_blue[num / 100], WBGT_H2DIGIT_X_CRD, WBGT_H2DIGIT_Y_CRD);
    mlcd.displayJpgImageCoordinate(g_str_blue[num / 10 % 10], WBGT_H1DIGIT_X_CRD, WBGT_H1DIGIT_Y_CRD);
    mlcd.displayJpgImageCoordinate(g_str_blue[(num % 100) % 10], WBGT_H1DECIMAL_X_CRD, WBGT_H1DECIMAL_Y_CRD);

    if (index == SAFE)
    {
        mlcd.displayJpgImageCoordinate(WBGT_SAFE_IMG_PATH, WBGT_NOTICE_X_CRD, WBGT_NOTICE_Y_CRD);
    }
    else if (index == ATTENTION)
    {
        mlcd.displayJpgImageCoordinate(WBGT_ATTENTION_IMG_PATH, WBGT_NOTICE_X_CRD, WBGT_NOTICE_Y_CRD);
    }
    else if (index == ALERT)
    {
        mlcd.displayJpgImageCoordinate(WBGT_ALERT_IMG_PATH, WBGT_NOTICE_X_CRD, WBGT_NOTICE_Y_CRD);
    }
    else if (index == HIGH_ALERT)
    {
        mlcd.displayJpgImageCoordinate(WBGT_HIGH_ALERT_IMG_PATH, WBGT_NOTICE_X_CRD, WBGT_NOTICE_Y_CRD);
    }
    else
    {
        mlcd.displayJpgImageCoordinate(WBGT_DANGER_IMG_PATH, WBGT_NOTICE_X_CRD, WBGT_NOTICE_Y_CRD);
    }
}

void AppControl::displayMusicInit()
{
    mlcd.fillBackgroundWhite();
    displayMusicStop();
}

void AppControl::displayMusicStop()
{
    mlcd.displayJpgImageCoordinate(MUSIC_NOWSTOPPING_IMG_PATH, MUSIC_NOTICE_X_CRD, MUSIC_NOTICE_Y_CRD);
    displayMusicTitle();
    mlcd.displayJpgImageCoordinate(COMMON_BUTTON_PLAY_IMG_PATH, MUSIC_PLAY_X_CRD, MUSIC_PLAY_Y_CRD);
    mlcd.displayJpgImageCoordinate(COMMON_BUTTON_BACK_IMG_PATH, MUSIC_BACK_X_CRD, MUSIC_BACK_Y_CRD);
    mlcd.displayJpgImageCoordinate(COMMON_BUTTON_NEXT_IMG_PATH, MUSIC_NEXT_X_CRD, MUSIC_NEXT_Y_CRD);
}

void AppControl::displayMusicTitle()
{
    mlcd.displayText("                  ", MUSIC_TITLE_X_CRD, MUSIC_TITLE_Y_CRD);
    mlcd.displayText(mmplay.getTitle(), MUSIC_TITLE_X_CRD, MUSIC_TITLE_Y_CRD);
}

void AppControl::displayNextMusic()
{
    mmplay.selectNextMusic();
    displayMusicTitle();
}

void AppControl::displayMusicPlay()
{
    mmplay.prepareMP3();
    mlcd.displayJpgImageCoordinate(MUSIC_NOWPLAYING_IMG_PATH, MUSIC_NOTICE_X_CRD, MUSIC_NOTICE_Y_CRD);
    mlcd.displayJpgImageCoordinate(COMMON_BUTTON_STOP_IMG_PATH, MUSIC_STOP_X_CRD, MUSIC_STOP_Y_CRD);
    mlcd.displayJpgImageCoordinate(COMMON_BUTTON_FILLWHITE_IMG_PATH, MUSIC_BACK_X_CRD, MUSIC_BACK_Y_CRD);
    mlcd.displayJpgImageCoordinate(COMMON_BUTTON_FILLWHITE_IMG_PATH, MUSIC_NEXT_X_CRD, MUSIC_NEXT_Y_CRD);
}

void AppControl::displayMeasureInit()
{
    mlcd.fillBackgroundWhite();
    mlcd.displayJpgImageCoordinate(MEASURE_NOTICE_IMG_PATH, MEASURE_NOTICE_X_CRD, MEASURE_NOTICE_Y_CRD);
    mlcd.displayJpgImageCoordinate(COMMON_BLUEDOT_IMG_PATH, MEASURE_DOT_X_CRD, MEASURE_DOT_Y_CRD);
    mlcd.displayJpgImageCoordinate(MEASURE_CM_IMG_PATH, MEASURE_CM_X_CRD, MEASURE_CM_Y_CRD);
    mlcd.displayJpgImageCoordinate(COMMON_BUTTON_BACK_IMG_PATH, MEASURE_BACK_X_CRD, MEASURE_BACK_Y_CRD);
}

void AppControl::displayMeasureDistance()
{
    int measure = mmdist.getDistance() * 10;
    if (measure < 4500 && measure > 20)
    {
        if (measure < 1000)
        {
            mlcd.displayJpgImageCoordinate(COMMON_BLUEFILLWHITE_IMG_PATH, MEASURE_DIGIT3_X_CRD, MEASURE_DIGIT3_Y_CRD);
        }
        else
        {
            mlcd.displayJpgImageCoordinate(g_str_blue[measure / 1000], MEASURE_DIGIT3_X_CRD, MEASURE_DIGIT3_Y_CRD);
        }
        if (measure < 100)
        {
            mlcd.displayJpgImageCoordinate(COMMON_BLUEFILLWHITE_IMG_PATH, MEASURE_DIGIT2_X_CRD, MEASURE_DIGIT2_Y_CRD);
        }
        else
        {
            mlcd.displayJpgImageCoordinate(g_str_blue[(measure / 100) % 10], MEASURE_DIGIT2_X_CRD, MEASURE_DIGIT2_Y_CRD);
        }
        mlcd.displayJpgImageCoordinate(g_str_blue[((measure / 10) % 100) % 10], MEASURE_DIGIT1_X_CRD, MEASURE_DIGIT1_Y_CRD);
        mlcd.displayJpgImageCoordinate(g_str_blue[(((measure % 1000) % 100) % 10)], MEASURE_DECIMAL_X_CRD, MEASURE_DECIMAL_Y_CRD);
    }
}

void AppControl::displayDateInit()
{
    mlcd.fillBackgroundWhite();
    mlcd.displayJpgImageCoordinate(DATE_NOTICE_IMG_PATH, DATE_NOTICE_X_CRD, DATE_NOTICE_Y_CRD);
    mlcd.displayJpgImageCoordinate(COMMON_BUTTON_BACK_IMG_PATH, DATE_BACK_X_CRD, DATE_BACK_Y_CRD);
}

void AppControl::displayDateUpdate()
{
    mlcd.displayDateText(mdtime.readDate(), DATE_YYYYMMDD_X_CRD, DATE_YYYYMMDD_Y_CRD);
    mlcd.displayDateText(mdtime.readTime(), DATE_HHmmSS_X_CRD, DATE_HHmmSS_Y_CRD);
}

void AppControl::controlApplication()
{
    mmplay.init();

    while (1)
    {

        switch (getState())
        {
        case TITLE:
            switch (getAction())
            {
            case ENTRY:
                /*
                ** まずはここにタイトル画面の表示処理を呼び出してみよう。
                ** タイトル画面表示の関数はdisplayTitleInit()である。
                ** この関数の中身はまだ何もないので、この関数にタイトル画面表示処理を書いてみよう。
                */
                displayTitleInit();
                setStateMachine(TITLE, DO);
                break;

            case DO:

                if (m_flag_btnA_is_pressed || m_flag_btnB_is_pressed || m_flag_btnC_is_pressed)
                {
                    delay(200); // チャタリング防止
                    setBtnAllFlgFalse();
                    setStateMachine(TITLE, EXIT);
                }

                break;

            case EXIT:
                setStateMachine(MENU, ENTRY);
                break;

            default:
                break;
            }

            break;

        case MENU:

            switch (getAction())
            {
            case ENTRY:
                displayMenuInit();
                setStateMachine(MENU, DO);
                break;

            case DO:
                if (m_flag_btnA_is_pressed)
                {
                    switch (m_focus_state)
                    {
                    case MENU_WBGT:
                        focusChangeImg(m_focus_state, MENU_DATE);
                        m_focus_state = MENU_DATE;
                        break;
                    case MENU_MUSIC:
                        focusChangeImg(m_focus_state, MENU_WBGT);
                        m_focus_state = MENU_WBGT;
                        break;
                    case MENU_MEASURE:
                        focusChangeImg(m_focus_state, MENU_MUSIC);
                        m_focus_state = MENU_MUSIC;
                        break;
                    case MENU_DATE:
                        focusChangeImg(m_focus_state, MENU_MEASURE);
                        m_focus_state = MENU_MEASURE;
                        break;
                    default:
                        break;
                    }
                    setBtnAllFlgFalse();
                    delay(100); // チャタリング防止
                }
                else if (m_flag_btnB_is_pressed)
                {
                    delay(100); // チャタリング防止
                    setBtnAllFlgFalse();
                    setStateMachine(MENU, EXIT);
                }
                else if (m_flag_btnC_is_pressed)
                {
                    switch (m_focus_state)
                    {
                    case MENU_WBGT:
                        focusChangeImg(m_focus_state, MENU_MUSIC);
                        m_focus_state = MENU_MUSIC;
                        break;
                    case MENU_MUSIC:
                        focusChangeImg(m_focus_state, MENU_MEASURE);
                        m_focus_state = MENU_MEASURE;
                        break;
                    case MENU_MEASURE:
                        focusChangeImg(m_focus_state, MENU_DATE);
                        m_focus_state = MENU_DATE;
                        break;
                    case MENU_DATE:
                        focusChangeImg(m_focus_state, MENU_WBGT);
                        m_focus_state = MENU_WBGT;
                        break;
                    default:
                        break;
                    }
                    setBtnAllFlgFalse();
                    delay(100); // チャタリング防止
                }
                else
                {
                    setStateMachine(MENU, DO);
                }
                break;

            case EXIT:
                switch (m_focus_state)
                {
                case MENU_WBGT:
                    setStateMachine(WBGT, ENTRY);
                    break;
                case MENU_MUSIC:
                    setStateMachine(MUSIC_STOP, ENTRY);
                    break;
                case MENU_MEASURE:
                    setStateMachine(MEASURE, ENTRY);
                    break;
                case MENU_DATE:
                    setStateMachine(DATE, ENTRY);
                    break;
                default:
                    break;
                }
            default:
                break;
            }

            break;

        case WBGT:

            switch (getAction())
            {
            case ENTRY:
                displayWBGTInit();
                setStateMachine(WBGT, DO);
                break;

            case DO:
                displayTempHumiIndex();
                delay(100);
                if (m_flag_btnB_is_pressed)
                {
                    delay(100); // チャタリング防止
                    setBtnAllFlgFalse();
                    setStateMachine(WBGT, EXIT);
                }
                else
                {
                    setStateMachine(WBGT, DO);
                }
                break;

            case EXIT:
                setStateMachine(MENU, ENTRY);
                break;

            default:
                break;
            }

            break;

        case MUSIC_STOP:
            switch (getAction())
            {
            case ENTRY:
                displayMusicInit();
                setStateMachine(MUSIC_STOP, DO);
                break;

            case DO:
                if (m_flag_btnA_is_pressed)
                {
                    delay(100); // チャタリング防止
                    setStateMachine(MUSIC_STOP, EXIT);
                }
                else if (m_flag_btnB_is_pressed)
                {
                    delay(100); // チャタリング防止
                    setBtnAllFlgFalse();
                    setStateMachine(MUSIC_STOP, EXIT);
                }
                else if (m_flag_btnC_is_pressed)
                {
                    displayNextMusic();
                    delay(100); // チャタリング防止
                    setBtnAllFlgFalse();
                }
                else
                {
                    setStateMachine(MUSIC_STOP, DO);
                }
                break;

            case EXIT:
                if (m_flag_btnA_is_pressed)
                {
                    setBtnAllFlgFalse();
                    setStateMachine(MUSIC_PLAY, ENTRY);
                }
                else
                {
                    setStateMachine(MENU, ENTRY);
                }
                break;

            default:
                break;
            }

            break;

        case MUSIC_PLAY:

            switch (getAction())
            {
            case ENTRY:
                displayMusicPlay();
                setStateMachine(MUSIC_PLAY, DO);
                break;

            case DO:
                if (m_flag_btnA_is_pressed)
                {
                    delay(100); // チャタリング防止
                    setBtnAllFlgFalse();
                    setStateMachine(MUSIC_PLAY, EXIT);
                }
                else if (!mmplay.isRunningMP3())
                {
                    mmplay.stopMP3();
                    setStateMachine(MUSIC_PLAY, EXIT);
                }
                else
                {
                    mmplay.playMP3();
                    setStateMachine(MUSIC_PLAY, DO);
                }
                break;

            case EXIT:
                mmplay.stopMP3();
                setStateMachine(MUSIC_STOP, ENTRY);
                break;

            default:
                break;
            }

            break;

        case MEASURE:

            switch (getAction())
            {
            case ENTRY:
                displayMeasureInit();
                setStateMachine(MEASURE, DO);
                break;

            case DO:
                displayMeasureDistance();
                delay(250);
                if (m_flag_btnB_is_pressed)
                {
                    delay(100); // チャタリング防止
                    setBtnAllFlgFalse();
                    setStateMachine(MEASURE, EXIT);
                }
                else
                {
                    setStateMachine(MEASURE, DO);
                }
                break;

            case EXIT:
                setStateMachine(MENU, ENTRY);
                break;

            default:
                break;
            }

            break;

        case DATE:

            switch (getAction())
            {
            case ENTRY:
                displayDateInit();
                setStateMachine(DATE, DO);
                break;

            case DO:
                displayDateUpdate();
                delay(100);
                if (m_flag_btnB_is_pressed)
                {
                    delay(100); // チャタリング防止
                    setBtnAllFlgFalse();
                    setStateMachine(DATE, EXIT);
                }
                else
                {
                    setStateMachine(DATE, DO);
                }
                break;

            case EXIT:
                setStateMachine(MENU, ENTRY);
                break;

            default:
                break;
            }

        default:
            break;
        }
    }
}
