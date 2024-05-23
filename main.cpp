#include <iostream>
#include <Windows.h>
#include <algorithm>

using namespace std;

// Node structure for doubly linked list
struct SongNode {
    string name;
    SongNode* next;
    SongNode* prev;
};

class MusicPlayer {
private:
    SongNode* playlist; // Head of the playlist doubly linked list
    SongNode* currentSong; // Currently playing song

public:
    MusicPlayer() {
        playlist = nullptr;
        currentSong = nullptr;
    }

    // Function to add a song to the playlist
    void addSong(const string& songName) {
        SongNode* newNode = new SongNode;
        newNode->name = songName;
        newNode->next = nullptr;
        newNode->prev = nullptr;

        if (playlist == nullptr) {
            playlist = newNode;
        } else {
            SongNode* temp = playlist;
            while (temp->next != nullptr) {
                temp = temp->next;
            }
            temp->next = newNode;
            newNode->prev = temp;
        }
    }

    // Function to play a song
    void playSong(const string& songName) {
        string fullPath = "C:\\Users\\OC\\CLionProjects\\music-player-dsa-project\\songs\\" + songName + ".wav";
        PlaySound(fullPath.c_str(), NULL, SND_FILENAME | SND_ASYNC);
        cout << "Now playing: " << songName << endl;
    }

    // Function to stop the currently playing song
    void stopSong() {
        PlaySound(NULL, NULL, 0);
        cout << "Audio stopped." << endl;
    }

    // Function to start playing the next song in the playlist
    void playNextSong() {
        if (currentSong != nullptr && currentSong->next != nullptr) {
            currentSong = currentSong->next;
            stopSong();
            playSong(currentSong->name);
        } else {
            cout << "No more songs in the playlist." << endl;
        }
    }

    // Function to start playing the previous song in the playlist
    void playPreviousSong() {
        if (currentSong != nullptr && currentSong->prev != nullptr) {
            currentSong = currentSong->prev;
            stopSong();
            playSong(currentSong->name);
        } else {
            cout << "No previous song in the playlist." << endl;
        }
    }

    // Function to search for a song by name
    bool searchSong(const string& songName) {
        SongNode* temp = playlist;
        while (temp != nullptr) {
            if (temp->name == songName) {
                cout << "Song found: " << songName << endl;
                return true;
            }
            temp = temp->next;
        }
        cout << "Song not found." << endl;
        return false;
    }

    // Function to start playing the playlist from the beginning
    void playPlaylist() {
        if (playlist != nullptr) {
            currentSong = playlist;
            playSong(currentSong->name);
        } else {
            cout << "Playlist is empty." << endl;
        }
    }

    // Destructor to release memory allocated for the playlist
    ~MusicPlayer() {
        SongNode* temp = playlist;
        while (temp != nullptr) {
            SongNode* next = temp->next;
            delete temp;
            temp = next;
        }
    }
};

// Function to clear the console screen
void clearScreen() {
    system("cls");
}

int main() {
    MusicPlayer player;

    // Adding songs to the playlist
    player.addSong("aadat");
    player.addSong("cheap-thrills");
    player.addSong("o-yara");
    player.addSong("shape-of-you");
    player.addSong("unstop");

    // Command loop
    while (true) {
        cout << "Music Player" << endl;
        cout << "1. Play Playlist" << endl;
        cout << "2. Stop" << endl;
        cout << "3. Next" << endl;
        cout << "4. Previous" << endl;
        cout << "5. Search Song" << endl;
        cout << "6. Quit" << endl;
        cout << "Enter your choice: ";

        int choice;
        cin >> choice;

        switch (choice) {
            case 1:
                clearScreen();
                player.playPlaylist();
                break;
            case 2:
                player.stopSong();
                break;
            case 3:
                player.playNextSong();
                break;
            case 4:
                player.playPreviousSong();
                break;
            case 5: {
                clearScreen();
                cout << "Enter song name to search: ";
                string songName;
                cin >> songName;
                player.searchSong(songName);
                break;
            }
            case 6:
                return 0;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    }

    return 0;
}
