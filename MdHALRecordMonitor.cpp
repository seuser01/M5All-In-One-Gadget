#include "MdHALRecordMonitor.h"

void MdHALRecordMonitor::startbattle(String data, String time)
{
    m_win_cnt = 0;

    battle_record[15].startdate = battle[15].startdate;
    battle_record[15].starttime = battle[15].starttime;
    battle_record[15].win_cnt = battle[15].win_cnt;
    battle[15].startdate = battle[14].startdate;
    battle[15].starttime = battle[14].starttime;
    battle[15].win_cnt = battle[14].win_cnt;
    battle[14].startdate = battle_record[14].startdate;
    battle[14].starttime = battle_record[14].starttime;
    battle[14].win_cnt = battle_record[14].win_cnt;

    battle_record[14].startdate = battle[14].startdate;
    battle_record[14].starttime = battle[14].starttime;
    battle_record[14].win_cnt = battle[14].win_cnt;
    battle[14].startdate = battle[13].startdate;
    battle[14].starttime = battle[13].starttime;
    battle[14].win_cnt = battle[13].win_cnt;
    battle[13].startdate = battle_record[13].startdate;
    battle[13].starttime = battle_record[13].starttime;
    battle[13].win_cnt = battle_record[13].win_cnt;

    battle_record[13].startdate = battle[13].startdate;
    battle_record[13].starttime = battle[13].starttime;
    battle_record[13].win_cnt = battle[13].win_cnt;
    battle[13].startdate = battle[12].startdate;
    battle[13].starttime = battle[12].starttime;
    battle[13].win_cnt = battle[12].win_cnt;
    battle[12].startdate = battle_record[12].startdate;
    battle[12].starttime = battle_record[12].starttime;
    battle[12].win_cnt = battle_record[12].win_cnt;

    battle_record[12].startdate = battle[12].startdate;
    battle_record[12].starttime = battle[12].starttime;
    battle_record[12].win_cnt = battle[12].win_cnt;
    battle[12].startdate = battle[11].startdate;
    battle[12].starttime = battle[11].starttime;
    battle[12].win_cnt = battle[11].win_cnt;
    battle[11].startdate = battle_record[11].startdate;
    battle[11].starttime = battle_record[11].starttime;
    battle[11].win_cnt = battle_record[11].win_cnt;

    battle_record[11].startdate = battle[11].startdate;
    battle_record[11].starttime = battle[11].starttime;
    battle_record[11].win_cnt = battle[11].win_cnt;
    battle[11].startdate = battle[10].startdate;
    battle[11].starttime = battle[10].starttime;
    battle[11].win_cnt = battle[10].win_cnt;
    battle[10].startdate = battle_record[10].startdate;
    battle[10].starttime = battle_record[10].starttime;
    battle[10].win_cnt = battle_record[10].win_cnt;

    battle_record[10].startdate = battle[10].startdate;
    battle_record[10].starttime = battle[10].starttime;
    battle_record[10].win_cnt = battle[10].win_cnt;
    battle[10].startdate = battle[9].startdate;
    battle[10].starttime = battle[9].starttime;
    battle[10].win_cnt = battle[9].win_cnt;
    battle[9].startdate = battle_record[9].startdate;
    battle[9].starttime = battle_record[9].starttime;
    battle[9].win_cnt = battle_record[9].win_cnt;

    battle_record[9].startdate = battle[9].startdate;
    battle_record[9].starttime = battle[9].starttime;
    battle_record[9].win_cnt = battle[9].win_cnt;
    battle[9].startdate = battle[8].startdate;
    battle[9].starttime = battle[8].starttime;
    battle[9].win_cnt = battle[8].win_cnt;
    battle[8].startdate = battle_record[8].startdate;
    battle[8].starttime = battle_record[8].starttime;
    battle[8].win_cnt = battle_record[8].win_cnt;

    battle_record[8].startdate = battle[8].startdate;
    battle_record[8].starttime = battle[8].starttime;
    battle_record[8].win_cnt = battle[8].win_cnt;
    battle[8].startdate = battle[7].startdate;
    battle[8].starttime = battle[7].starttime;
    battle[8].win_cnt = battle[7].win_cnt;
    battle[7].startdate = battle_record[7].startdate;
    battle[7].starttime = battle_record[7].starttime;
    battle[7].win_cnt = battle_record[7].win_cnt;

    battle_record[7].startdate = battle[7].startdate;
    battle_record[7].starttime = battle[7].starttime;
    battle_record[7].win_cnt = battle[7].win_cnt;
    battle[7].startdate = battle[6].startdate;
    battle[7].starttime = battle[6].starttime;
    battle[7].win_cnt = battle[6].win_cnt;
    battle[6].startdate = battle_record[6].startdate;
    battle[6].starttime = battle_record[6].starttime;
    battle[6].win_cnt = battle_record[6].win_cnt;

    battle_record[6].startdate = battle[6].startdate;
    battle_record[6].starttime = battle[6].starttime;
    battle_record[6].win_cnt = battle[6].win_cnt;
    battle[6].startdate = battle[5].startdate;
    battle[6].starttime = battle[5].starttime;
    battle[6].win_cnt = battle[5].win_cnt;
    battle[5].startdate = battle_record[5].startdate;
    battle[5].starttime = battle_record[5].starttime;
    battle[5].win_cnt = battle_record[5].win_cnt;

    battle_record[5].startdate = battle[5].startdate;
    battle_record[5].starttime = battle[5].starttime;
    battle_record[5].win_cnt = battle[5].win_cnt;
    battle[5].startdate = battle[4].startdate;
    battle[5].starttime = battle[4].starttime;
    battle[5].win_cnt = battle[4].win_cnt;
    battle[4].startdate = battle_record[4].startdate;
    battle[4].starttime = battle_record[4].starttime;
    battle[4].win_cnt = battle_record[4].win_cnt;

    battle_record[4].startdate = battle[4].startdate;
    battle_record[4].starttime = battle[4].starttime;
    battle_record[4].win_cnt = battle[4].win_cnt;
    battle[4].startdate = battle[3].startdate;
    battle[4].starttime = battle[3].starttime;
    battle[4].win_cnt = battle[3].win_cnt;
    battle[3].startdate = battle_record[3].startdate;
    battle[3].starttime = battle_record[3].starttime;
    battle[3].win_cnt = battle_record[3].win_cnt;

    battle_record[3].startdate = battle[3].startdate;
    battle_record[3].starttime = battle[3].starttime;
    battle_record[3].win_cnt = battle[3].win_cnt;
    battle[3].startdate = battle[2].startdate;
    battle[3].starttime = battle[2].starttime;
    battle[3].win_cnt = battle[2].win_cnt;
    battle[2].startdate = battle_record[2].startdate;
    battle[2].starttime = battle_record[2].starttime;
    battle[2].win_cnt = battle_record[2].win_cnt;

    battle_record[2].startdate = battle[2].startdate;
    battle_record[2].starttime = battle[2].starttime;
    battle_record[2].win_cnt = battle[2].win_cnt;
    battle[2].startdate = battle[1].startdate;
    battle[2].starttime = battle[1].starttime;
    battle[2].win_cnt = battle[1].win_cnt;
    battle[1].startdate = battle_record[1].startdate;
    battle[1].starttime = battle_record[1].starttime;
    battle[1].win_cnt = battle_record[1].win_cnt;

    battle_record[1].startdate = battle[1].startdate;
    battle_record[1].starttime = battle[1].starttime;
    battle_record[1].win_cnt = battle[1].win_cnt;
    battle[1].startdate = battle[0].startdate;
    battle[1].starttime = battle[0].starttime;
    battle[1].win_cnt = battle[0].win_cnt;
    battle[0].startdate = battle_record[0].startdate;
    battle[0].starttime = battle_record[0].starttime;
    battle[0].win_cnt = battle_record[0].win_cnt;

    /*for (int i = 0; i < m_hal_cnt; i++)
    {
        battle_record[i++].startdate = battle[i++].startdate;
        battle_record[i++].starttime = battle[i++].starttime;
        battle_record[i++].win_cnt = battle[i++].win_cnt;
        battle[i++].startdate = battle[i].startdate;
        battle[i++].starttime = battle[i].starttime;
        battle[i++].win_cnt = battle[i].win_cnt;
        battle[i].startdate = battle_record[i].startdate;
        battle[i].starttime = battle_record[i].starttime;
        battle[i].win_cnt = battle_record[i].win_cnt;
    }*/

    /*int i = 0;
    do
    {
        battle_record[i++].startdate = battle[i++].startdate;
        battle_record[i++].starttime = battle[i++].starttime;
        battle_record[i++].win_cnt = battle[i++].win_cnt;
        battle[i++].startdate = battle[i].startdate;
        battle[i++].starttime = battle[i].starttime;
        battle[i++].win_cnt = battle[i].win_cnt;
        battle[i].startdate = battle_record[i].startdate;
        battle[i].starttime = battle_record[i].starttime;
        battle[i].win_cnt = battle_record[i].win_cnt;
        i++;
    } while (i < m_hal_cnt);*/

    battle[0].startdate = data;
    battle[0].starttime = time;
    battle[0].win_cnt = 0;
}

void MdHALRecordMonitor::getrecord(int winorlose)
{
    if (winorlose == 1)
    {
        m_win_cnt++;
        WinCountPlus(m_win_cnt);
    }
    else if (winorlose == 2)
    {
        if (m_hal_cnt < 15)
        {
            m_hal_cnt++;
        }
    }
    else
    {
        startbattle(mdtime.readDate(), mdtime.readTime());
        if (m_hal_cnt < 15)
        {
            m_hal_cnt++;
        }
    }
}

Getdata MdHALRecordMonitor::WinCountPlus(int x)
{
    battle[0].win_cnt = x;
    return (battle[0]);
}

void MdHALRecordMonitor::recordmonitor()
{
    M5.Lcd.setTextColor(0x0000, 0xFFFF);
    M5.Lcd.setTextSize(1);
    if (m_hal_cnt == 0)
    {
        M5.Lcd.setCursor(10, 10);
        M5.Lcd.print("There is no record");
    }
    else
    {
        for (int i = 0; i < m_hal_cnt; i++)
        {
            M5.Lcd.setCursor(10, i * 12 + 10);
            M5.Lcd.print(battle[i].startdate);
            M5.Lcd.print(" ");
            M5.Lcd.print(battle[i].starttime);
            M5.Lcd.print(" ");
            M5.Lcd.print(battle[i].win_cnt);
            M5.Lcd.print(" ");
            M5.Lcd.println("straight wins");
        }
    }
}