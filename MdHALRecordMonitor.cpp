#include "MdHALRecordMonitor.h"

void MdHALRecordMonitor::startbattle(String data, String time)
{
    m_win_cnt = 0;

    for (int i = 14; i >= 0; i--)
    {
        battle[i + 1].startdate = battle[i].startdate;
        battle[i + 1].starttime = battle[i].starttime;
        battle[i + 1].win_cnt = battle[i].win_cnt;
    }

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