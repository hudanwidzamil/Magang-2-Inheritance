#include "Bergerak.h"
#include <cmath>
#include <iostream>
using namespace std;

//Setter vMaju, vSudut
void Bergerak::setVMaju(double _vM)
{
    vMaju = _vM;
}

void Bergerak::setVPutar(double _vP)
{
    vPutar = _vP;
}

//Getter x, y, arah
double Bergerak::getX()
{
    return x;
}
double Bergerak::getY()
{
    return y;
}
double Bergerak::getArah()
{
    return arah;
}

//Bergerak dengan kecepatan maju vMaju dan kecepatan putar vPutar selama t detik
void Bergerak::go(double t)
{
    double dt = 0.001;
    while (t > dt)
    {
        arah += vPutar * dt;
        x += dt * vMaju * cos((arah / 360) * M_PI * 2);
        y += dt * vMaju * sin((arah / 360) * M_PI * 2);
        t -= dt;
    }
}

//Berhenti, semua kecepatan jadi 0
void Bergerak::stop()
{
    vMaju = 0;
    vPutar = 0;
    cout << "Stopped" << endl;
}

//Mencetak status (posisi x,y, arah, kecepatan)
void Bergerak::printStatusBergerak()
{
    cout << "X : " << x << endl;
    cout << "Y : " << y << endl;
    cout << "Arah : " << arah << endl;
}