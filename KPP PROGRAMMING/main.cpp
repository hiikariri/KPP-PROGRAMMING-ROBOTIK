// NAMA		: Nehemy Davis Suryanto
// NRP		: 5023221004
// Jurusan	: Teknik Biomedik

#include <iostream>
#include <cmath>

#define GRAVITASI 10 //10 m/s^2
#define START_PENGUKURAN 1 //pengukuran dimulai dari 1 meter
#define SUDUT 45 //sudut elevasi tembakan
using namespace std;
int loss, v_roller, speed;
float jarak_max, vtangensial;
float x = SUDUT*M_PI/180;
float sudut = sin(2*x);

int mencari_V0(int v_roller, int loss) {
    speed = v_roller - loss;
    return speed;
}

int speed_loss (int v_roller){
        if(v_roller>=1 && v_roller<=10){
        loss = 1;
    }
    else if (v_roller>=11 && v_roller<=20){
        loss = 3;
    }
    else if (v_roller>=21 && v_roller<=30){
        loss = 5;
    }
    return loss;
}

int main() {
    cin >> v_roller;
    jarak_max = (mencari_V0(v_roller, speed_loss(v_roller))*mencari_V0(v_roller, speed_loss(v_roller))*sudut/GRAVITASI) - START_PENGUKURAN;
    float jarak = round(jarak_max);
    vtangensial = sqrt(jarak*GRAVITASI/sudut) + speed_loss(v_roller);
    cout << jarak << " " << vtangensial << endl;
    return 0;
}
