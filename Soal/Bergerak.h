#ifndef BERGERAK_H
#define BERGERAK_H

class Bergerak
{
  protected:
    double x = 0, y = 0;
    double arah = 0; //0 = timur, 90 = utara, 180 = barat, 270 = selatan
    double vMaju = 0;
    double vPutar = 0;

  public:
    //Setter vMaju, vSudut
    void setVMaju(double _vM);
    void setVPutar(double _vP);

    //Getter x, y, arah
    double getX();
    double getY();
    double getArah();

    //Bergerak dengan kecepatan maju vMaju dan kecepatan putar vPutar selama t detik
    void go(double t);

    //Berhenti, semua kecepatan jadi 0
    void stop();

    //Mencetak status (posisi x,y, arah, kecepatan)
    void printStatusBergerak();
};

#endif