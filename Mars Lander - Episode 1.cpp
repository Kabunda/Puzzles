#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int N; // the number of points used to draw the surface of Mars.
    cin >> N; cin.ignore();
    for (int i = 0; i < N; i++) {
        int LAND_X; // X coordinate of a surface point. (0 to 6999)
        int LAND_Y; // Y coordinate of a surface point. By linking all the points together in a sequential fashion, you form the surface of Mars.
        cin >> LAND_X >> LAND_Y; cin.ignore();
    }

    int rot=0;
    int pow=0;
    float grav = 3.711;
    float at = 4-grav;
    float a;
    float time=0;
    float Vk=40;
    float x1,x2,D;
    float Smin,Smax;
    // game loop
    while (1) {
        int X;
        int Y;
        int HS; // the horizontal speed (in m/s), can be negative.
        int VS; // the vertical speed (in m/s), can be negative.
        int F; // the quantity of remaining fuel in liters.
        int R; // the rotation angle in degrees (-90 to 90).
        int P; // the thrust power (0 to 4).
        cin >> X >> Y >> HS >> VS >> F >> R >> P; cin.ignore();
        VS=-VS;
        // Write an action using cout. DON'T FORGET THE "<< endl"
        // To debug: cerr << "Debug messages..." << endl;
        a = grav-P; // ускорение мкорабля       

        VS=VS+a*(4-pow);
        Smin=VS*(VS-Vk)/at+at/2*((VS-Vk)/at)*((VS-Vk)/at);

        if (Smin>Y){
            pow++;
            if (pow>4) pow=4;
            
        }
        cout << rot<<' '<<pow << endl; // R P. R is the desired rotation angle. P is the desired thrust power.
    }
}