#include<bits/stdc++.h>
using namespace std;
const int INF = 1e9; // Globally define a large value for infinity
/* Custom structure to bundle 
a single one-way flight route's details together*/
struct Route {
    int from;
    int to;
    int fuel;
};
/* u = station id(source) 
 v = station id(destination)
weight = fuel cost
dist[] = distance array
parent[] = parent array  */
bool relax(int u, int v, int weight, int dist[], int parent[]) {
    if (dist[u] != INF && dist[u] + weight < dist[v]) {
        dist[v] = dist[u] + weight;
        parent[v] = u;
        return true;
    }
    return false;
}
//level 1 (Bellman-Ford)

int level1(){
    ifstream file("sample_world.txt");
    if (!file) {
        cout << "Error: Could not open sample_world.txt\n";
        return -1;
    }
    string line, word;
    int startFuel = 0, numPlaces = 0, numRoutes = 0;
    string placeNames[105];
    Route routes[1005];

    // Read the file line by line
    while (getline(file, line)) {
        if (line.empty() ||line.substr(0, 2) == "//") {
            continue;
        }
        if (line == "[FLIGHT]") {
            break;
        }
    }
    /*Read FUEL, PLACES, and 
    ROUTES data from the [FLIGHT] section*/
    file>>word>>startFuel;
    file>>word>>numPlaces;
    for (int i = 0; i < numPlaces; i++) {
    // Read the station name in a temporary variable
        string name;
        int id;
    // temporary variable to hold station number
        file>>id>>name;
        placeNames[id] = name;
    }
    file>>word>>numRoutes;
    for (int i = 0; i < numRoutes; i++) {
        file >> routes[i].from >> routes[i].to >> routes[i].fuel;
    }
    file.close();

    //Core: Bellman-Ford algorithm
    int min_fuel[105], parent[105];
    int src = 0;
     // Assuming the source station is the first one (index 0)
    for(int v = 0; v < numPlaces; v++) {
        min_fuel[v] = INF;
        parent[v] = -1;
//there is no parent for the vertex v initially
    }
    min_fuel[src] = 0; // Distance from source to itself is 0
    for(int pass = 1;pass<=numPlaces;pass++){
        for(int i=0;i<numRoutes;i++){
            bool updated = relax(routes[i].from,routes[i].to,routes[i].fuel,min_fuel,parent);
            if(updated && pass == numPlaces){
                cout<<"BROKEN MAP\n";
                return -1;
            }
        }
    }
//condition check for destination unreachable or fuel is not enough
 int destination = numPlaces - 1;
 /* numPlaces -1 gives the exact ID number
  of the final desination*/
    if (min_fuel[destination] == INF || min_fuel[destination] > startFuel) {
        cout << "GAME OVER\n";
        return -1;
    }
    /*Reconstruct the winning route by walking backward 
    through parent[] breadcrumbs*/
    int routeStops[105];       
     // Empty list to store the station numbers
    int totalStops = 0;      
    // Counter starting at 0 items

    int currentStation = destination; 
    // Start standing at the last station (Station_Omega)

    while (currentStation != -1) {    
// Keep walking backward until we pass Earth_Base (-1)
        routeStops[totalStops] = currentStation; 
// Save the station we are standing on
        totalStops++; 
        currentStation = parent[currentStation];  
         // Jump backward to the previous station
    }
// Print the route in forward order (from the end of path[] down to index 0)
    cout << "Best route: ";
    for (int i = totalStops - 1; i >= 0; i--) {
        cout << placeNames[routeStops[i]]; // Look up and print the station's text name
        if (i > 0) cout << " -> ";   // Print an arrow between stations (skip after the last one)
    }
    cout << "\n";
/* Calculate fuel statistics and 
return remaining fuel as Level 1's score*/
    int fuelUsed = min_fuel[destination]; 
    // Total fuel spent on the cheapest route
    int fuelLeft = startFuel - fuelUsed; 
    // Remaining fuel in Astro's tank
    int points = fuelLeft; 
// Level 1 awards 1 point for each unit of remaining fuel
    cout << "Fuel used = " << fuelUsed << ", ";  
    cout << "Fuel left = " << fuelLeft << ", "; 
    cout << "Points = " << points << endl;  
    return points;
}  

//level 2 (LCS)

//level 3 (BFS)

//level 4  0/1 Knapsack

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