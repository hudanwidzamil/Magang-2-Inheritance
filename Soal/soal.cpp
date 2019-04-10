#include "Bergerak.cpp"
#include <iostream>
using namespace std;

//Class robot adalah turunan dari class bergerak, gunakan konsep inheritance oop pada c++
class Robot: public Bergerak
{
  private:
    double baterai = 16.8; //Tegangan baterai, Max = 16.8, Min = 15.0
  public:
    ////////////////////////////////////////
    // Robot hanya bisa bergerak jika baterai tidak 0% (alias baterai > 15.0)
    // Jika di tengah tengah bergerak baterai <= 0% (15.0),
    //      semua fungsi gerak akan mencetak "BeepBeepBeep" ke layar lalu menghentikan robot
    // Jika baterai <= 15.15 tapi masih > 15.0,
    //      semua fungsi gerak akan menggerakkan robot dan mencetak "Beep" ke layar
    ////////////////////////////////////////
    // Sebelum mulai / Setelah selesai melakukan gerakan, robot harus stop
    // Gunakan fungsi stop, go, setVPutar, setVMaju pada class bergerakan untuk membuat fungsi gerak
    ////////////////////////////////////////
    // Baterai akan berkurang sebanyak 0.03 / detik saat bergerak
    
    //Fungsi gerak

    //Bergerak maju selama t detik, kecepatan berdasarkan baterai
    //100% = 0.2m/s, 50% = 0.1m/s, 0% = 0.0m/s
    //Jika nilai baterai diantara 3 itu, gunakan interpolasi linier untuk kecepatannya
    void maju(double t){
        cout<<"Maju selama "<<t<<" detik"<<endl;
        if (baterai=16.8){
            setVMaju(0.2);
        } else if(baterai=15.9){
            setVMaju(0.1);
        } else {
            setVMaju(0);
            cout<<"Beep"<<endl;
        }
        go(t);
        stop();
        baterai-=0.03*t;
    }

    //Berputar di tempat selama t detik, kecepatan putar berdasar baterai
    //100% = 15 degree/s, 50% = 7.5 degree/s, 0% = 0 degree/s
    //Jika nilai baterai diantara 3 itu, gunakan interpolasi linier untuk kecepatannya
    void putar(double t){
        cout<<"Berputar selama "<<t<<" detik"<<endl;
        if (baterai=16.8){
            setVPutar(15);
        } else if(baterai=15.9){
            setVPutar(7.5);
        } else {
            setVPutar(0);
            cout<<"Beep"<<endl;
        }
        go(t);
        stop();
        baterai-=0.03*t;
    }

    ////////////////////Fungsi gerak end/////////////////////////////////

    //Mencetak status robot, panggil printStatusBergerak lalu cetak nilai baterai robot ke layar
    void printStatusRobot(){
        printStatusBergerak();
        cout<<"Baterai : "<< baterai <<endl;
    }

    
};

int main()
{
    Robot eins, zwei;

    cout<<"Status Eins : "<<endl;
    eins.printStatusRobot();
    cout<<"Status Zwei : "<<endl;
    zwei.printStatusRobot();

    cout<<"---------------------"<<endl;

    cout<<"Eins :"<<endl;
    eins.maju(10);
    eins.stop();

    cout<<"Zwei :"<<endl;
    zwei.putar(5);
    zwei.stop();

    cout<<"Status Eins : "<<endl;
    eins.printStatusRobot();
    cout<<"Status Zwei : "<<endl;
    zwei.printStatusRobot();

    cout<<"---------------------"<<endl;

    cout<<"Eins :"<<endl;
    eins.putar(30);
    eins.stop();

    cout<<"Zwei :"<<endl;
    zwei.maju(30);
    zwei.stop();

    cout<<"Status Eins : "<<endl;
    eins.printStatusRobot();
    cout<<"Status Zwei : "<<endl;
    zwei.printStatusRobot();

    cout<<"---------------------"<<endl;

    cout<<"Eins :"<<endl;
    eins.maju(30);
    //beep beep
    eins.stop();

    cout<<"Zwei :"<<endl;
    zwei.putar(25);
    //beep beep
    zwei.stop();

    cout<<"Status Eins : "<<endl;
    eins.printStatusRobot();
    cout<<"Status Zwei : "<<endl;
    zwei.printStatusRobot();


    //Expected Output:
    /*
        Status Eins : 
        X : 0
        Y : 0
        Arah : 0
        Baterai : 16.8
        Status Zwei : 
        X : 0
        Y : 0
        Arah : 0
        Baterai : 16.8
        ---------------------
        Eins : 
        Maju selama 10 detik
        Stopped
        Stopped
        Zwei : 
        Berputar selama 5 detik
        Stopped
        Stopped
        Status Eins : 
        X : 1.65165
        Y : 0
        Arah : 0
        Baterai : 16.4997
        Status Zwei : 
        X : 0
        Y : 0
        Arah : 64.8169
        Baterai : 16.6497
        ---------------------
        Eins : 
        Berputar selama 30 detik
        Stopped
        Stopped
        Zwei : 
        Maju selama 30 detik
        Stopped
        Stopped
        Status Eins : 
        X : 1.65165
        Y : 0
        Arah : 236.216
        Baterai : 15.5997
        Status Zwei : 
        X : 1.53165
        Y : 3.25742
        Arah : 64.8169
        Baterai : 15.7497
        ---------------------
        Eins : 
        Maju selama 30 detik
        Stopped
        Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep BeepBeepBeep
        Stopped
        Zwei : 
        Berputar selama 25 detik
        Stopped
        Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep Beep BeepBeepBeep
        Stopped
        Status Eins : 
        X : 1.31818
        Y : -0.498436
        Arah : 236.216
        Baterai : 14.9997
        Status Zwei : 
        X : 1.53165
        Y : 3.25742
        Arah : 135.101
        Baterai : 14.9997
    */
}