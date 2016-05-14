#include <wiringPi.h>
#include <iostream>
#include "IRSensor.h"


#define SensorRight 4 //右循迹红外传感器(P3.2 OUT1)
#define SensorLeft 5 //左循迹红外传感器(P3.3 OUT2)

int main(void)
{
    int SL; //左循迹红外传感器状态
    int SR; //右循迹红外传感器状态
    wiringPiSetup();
    setup();
    keysacn();
    while(1)
    {
        // 有信号为LOW 没有信号为HIGH
        SR = digitalRead(SensorRight);      // 有信号表明在白色区域，车子底板上L3亮；没信号表明压在黑
        线上，车子底板上L3灭
        SL = digitalRead(SensorLeft);       // 有信号表明在白色区域，车子底板上L2亮；没信号表明压在黑线
        上，车子底板上L2灭
        if (SL == LOW&&SR==LOW)
            run();                          // 调用前进函数
        else if (SL == HIGH & SR == LOW)    // 左循迹红外传感器,检测到信号，车子向右偏离轨道，向左
            转
            left();
        else if (SR == HIGH & SL == LOW)    // 右循迹红外传感器,检测到信号，车子向左偏离轨道，向右
            转
            right();
        else                                // 都是白色, 停止
            brake();
    }
    return 0;
}
