#include<bits/stdc++.h>
using namespace std;
struct Route {
    int from;
    int to;
    int fuel;
};

int level1(){
    ifstream file("sample_world_2.txt");
    if (!file) {
        cout << "Error: Could not open sample_world_2.txt\n";
        return -1;
    }
    string line, word;
    int startFuel = 0, numPlaces = 0, numRoutes = 0;
    string placeNames[105];
    Route routes[1005];

    // Read the file line by line
    while (getline(cin, line)) {
        if (line.empty() ||line.substr(0, 2) == "//") {
            continue;
        }
        if (line == "[FLIGHT]") {
            break;
        }
    }
    file>>word>>startFuel;
    file>>word>>numPlaces;
    file>>word>>numRoutes;
    for (int i = 0; i < numPlaces; i++) {
    // Read the station name
        string name;
        int id;
    // temporary variable to hold station number
        file>>id>>name;
        placeNames[i] = name;
    }
    for (int i = 0; i < numRoutes; i++) {
        file >> routes[i].from >> routes[i].to >> routes[i].fuel;
    }
    file.close();
}

void menu() {
    int button;

    while (true) {
        cout << "       ASTRO'S SPACE RESCUE        \n";
        cout << "----------------------------------\n";
        cout << " 1. Play full game                |\n";
        cout << " 2. Play one level                |\n";
        cout << " 3. Show Hall of Fame             |\n";
        cout << " 4. Extra features                |\n";
        cout << " 0. Exit                          |\n";

        cout << "Press a button: ";
        cin >> button;

        switch (button) {
            case 1:
                playFullGame();
                break;
            case 2:
                playOneLevel();
                break;
            case 3:
                showHallOfFame();
                break;
            case 4:
                showExtraFeatures();
                break;
            case 0:
                cout << "Bye bye!\n";
                return;
            default:
                cout << "Oops! Pick 0 to 4.\n";
        }
    }
}
void playFullGame() {
    string playerName;

    cout << "\n--- STARTING FULL GAME ---\n";
    cout << "Enter pilot name: ";
    cin >> playerName;                 
    cout << "Welcome, Pilot " << playerName << "! Preparing Level 1...\n";

    // Level 1 call will go right here next
}