#include <iostream>

using namespace std;
/*
Set prjector
On DVD
Set Sound
Select Movie
Play
*/

class Projector {
    public:
        void setProject() {
            cout << "Setting Projector" << endl;
        }
};

class DVDPlayer {
    public:
        void on() {
            cout << "Turned On DVD" << endl;
        }

        void setConfig() {
            cout << "Setup config complete" << endl;
        }
};

class SoundSystem {
    public:
        void on() {
            cout << "Turned on Sound sytem" << endl;
        }

        void setVolume() {
            cout << "Set the volume" << endl;
        }
};

class HomeTheater {
    protected:
        DVDPlayer dvdp;
        Projector p;
        SoundSystem sys;
    
    public:
        void watchMovie() {
            dvdp.on();
            dvdp.setConfig();

            p.setProject();

            sys.on();
            sys.setVolume();
        }
};

int main() {
    HomeTheater ht;
    ht.watchMovie();
    return 0;
}