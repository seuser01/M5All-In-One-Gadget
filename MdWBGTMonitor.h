/* インクルードガード */
#pragma once

#include "DrTHSensor.h"

typedef enum
{
    SAFE,
    ATTENTION,
    ALERT,
    HIGH_ALERT,
    DANGER
} WbgtIndex;

class MdWBGTMonitor // classの定義
{
private: // privateはクラス内からしかアクセスできない
public:  // publicはどこからでもアクセス可能
    void init();
    void getWBGT(double *temperature, double *humidity, WbgtIndex *index);
};
