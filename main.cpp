#include <iostream>
#include <Windows.h>
#include <mmsystem.h>
#include <mciapi.h>
#include <algorithm>

using namespace std;

#pragma comment (lib,"winmm.lib")

int main() {
    mciSendString("open \"C:\\Users\\OC\\CLionProjects\\music-player-dsa-project\\songs\\o-yara.wav\" type waveaudio alias wav", NULL, 0, NULL);

    mciSendString("play wav", NULL, 0, NULL);

    while (true) {
        cout << "Enter a command (pause, play, stop): ";
        string command;
        cin >> command;

        transform(command.begin(), command.end(), command.begin(), ::tolower);

        if (command == "pause") {
            mciSendString("pause wav", NULL, 0, NULL);
            cout << "Audio paused." << endl;
        } else if (command == "play") {
            mciSendString("play wav", NULL, 0, NULL);
            cout << "Audio resumed." << endl;
        } else if (command == "stop") {
            mciSendString("stop wav", NULL, 0, NULL);
            mciSendString("seek wav to start", NULL, 0, NULL); // Rewind to the beginning
            cout << "Audio stopped." << endl;
            break;
        } else {
            cout << "Invalid command. Please enter 'pause', 'play', or 'stop'." << endl;
        }
    }

    // Close the WAV file
    mciSendString("close wav", NULL, 0, NULL);

    return 0;
}
