#pragma once
#include <M5Stack.h>
#include "MdDateTime.h"

typedef struct
{
    String startdate;
    String starttime;
    int win_cnt = 0;
} Getdata;

class MdHALRecordMonitor // classの定義
{
private: // privateはクラス内からしかアクセスできない
    Getdata battle[16];
    Getdata battle_record[16];
    int m_hal_cnt = 0;
    int m_win_cnt = 0;
    MdDateTime mdtime;

public: // publicはどこからでもアクセス可能
    void startbattle(String data, String time);
    void getrecord(int winorlose);
    Getdata WinCountPlus(int x);
    void recordmonitor();
};