#include "dai.h"

Dai::Dai(QObject *parent) : QObject(parent)
{
    Shang = 100;
    Gong = 530;
}

int Dai::Get_Shang()
{
    return Shang;
}

int Dai::Get_Gong()
{
    return Gong;
}
