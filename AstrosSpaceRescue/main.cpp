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
// Calculates LCS and also reconstructs the matching letters.
int calculateLCS(string secret, string player, string &matched) {

    int n = secret.length();
    int m = player.length();

    int dp[101][101] = {};

    // Build the dynamic programming table.
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {

            if (secret[i - 1] == player[j - 1]) {

                dp[i][j] = dp[i - 1][j - 1] + 1;

            } else {

                dp[i][j] = max(dp[i - 1][j],
                               dp[i][j - 1]);
            }
        }
    }

    // Reconstruct the matching subsequence.
    int i = n;
    int j = m;

    matched = "";

    while (i > 0 && j > 0) {

        if (secret[i - 1] == player[j - 1]) {

            matched += secret[i - 1];

            i--;
            j--;

        } else if (dp[i - 1][j] >= dp[i][j - 1]) {

            i--;

        } else {

            j--;
        }
    }

    // Reverse because reconstruction happens backwards.
    reverse(matched.begin(), matched.end());

    return dp[n][m];
}

int level2() {

    ifstream file("sample_world.txt");

    if (!file) {

        cout << "Error: Could not open sample_world.txt\n";
        return 0;
    }

    string line;
    string secret = "";
    bool inDoor = false;

    // Find the DOOR section and read its secret code.
    while (getline(file, line)) {

        if (line.find("[DOOR]") != string::npos) {

            inDoor = true;
            continue;
        }

        if (inDoor) {

            stringstream ss(line);
            string key;

            if (!(ss >> key))
                continue;

            if (key == "CODE") {

                ss >> secret;
                break;
            }

            // Stop if another section starts.
            if (line.find('[') != string::npos)
                break;
        }
    }

    file.close();

    if (secret.empty()) {

        cout << "Error: Door code not found!\n";
        return 0;
    }

    // Convert secret code to uppercase.
    for (char &ch : secret) {
        ch = toupper(static_cast<unsigned char>(ch));
    }

    int required = (secret.length() + 1) / 2;

    int points = 0;
    bool doorOpened = false;

    cout << "LEVEL 2\n";
    cout << "MISSION: OPEN THE DOOR\n";

    cout << "The secret code contains "
         << secret.length() << " letters.\n";

    cout << "You need at least "
         << required << " matching letters.\n";

    cout << "You have 3 attempts.\n\n";


    // Give the player three attempts.
    for (int attempt = 1; attempt <= 3; attempt++) {

        string player;
        string matched;

        cout << "Attempt " << attempt << "/3\n";
        cout << "Enter your code: ";

        cin >> player;

        // Convert player's code to uppercase.
        for (char &ch : player) {
            ch = toupper(static_cast<unsigned char>(ch));
        }

        // Calculate the LCS score.
        int score = calculateLCS(secret, player, matched);

        cout << "Matching letters: " << score << "\n";

        cout << "Matched subsequence: ";

        if (matched.empty())
            cout << "None";
        else
            cout << matched;

        cout << "\n";

        // Check whether the door opens.
        if (score >= required) {

            doorOpened = true;

            points = 10 * score;

            cout << "\n*** DOOR OPENED! ***\n";

            cout << "Congratulations, Astro!\n";

            cout << "Points earned = "
                 << points << "\n";

            break;

        } else {

            cout << "Door stays shut!\n";

            // Extra feature: Door hint.
            int needed = required - score;

            cout << "Hint: You need "
                 << needed
                 << " more matching letters.\n";

            if (attempt < 3) {
                cout << "Try again!\n\n";
            }
        }
    }

    // If all attempts fail.
    if (!doorOpened) {

        cout << "\nMISSION FAILED!\n";
        cout << "The door remains locked.\n";
        cout << "Points earned = 0\n";

        points = 0;
    }

    cout << "=============================\n";

    return points;
}

//level 3 (BFS)

// Direction arrays for Up, Down, Left and Right.
int rowMove[4] = {-1, 1, 0, 0};
int colMove[4] = {0, 0, -1, 1};


int level3() {

    ifstream file("sample_world.txt");

    if (!file) {
        cout << "Error: Could not open sample_world.txt\n";
        return 0;
    }

    string line;
    int rows = 0, cols = 0, oxygen = 0;
    string word;

    // Find the MAZE section.
    while (getline(file, line)) {

        if (line == "[MAZE]") {
            break;
        }
    }

    if (!file) {
        cout << "Error: MAZE section not found!\n";
        return 0;
    }

    // Read maze information.
    file >> word >> rows;
    file >> word >> cols;
    file >> word >> oxygen;

    // Validate maze dimensions.
    if (rows <= 0 || rows > 50 ||
        cols <= 0 || cols > 50) {

        cout << "Error: Invalid maze dimensions!\n";
        return 0;
    }

    // Store the maze.
    vector<string> maze(rows);

    for (int i = 0; i < rows; i++) {

        file >> maze[i];

        if (maze[i].length() != cols) {
            cout << "Error: Invalid maze row!\n";
            return 0;
        }
    }

    file.close();

    // Find starting position A and destination C.
    int startRow = -1, startCol = -1;
    int endRow = -1, endCol = -1;

    for (int i = 0; i < rows; i++) {

        for (int j = 0; j < cols; j++) {

            if (maze[i][j] == 'A') {
                startRow = i;
                startCol = j;
            }

            if (maze[i][j] == 'C') {
                endRow = i;
                endCol = j;
            }
        }
    }

    if (startRow == -1 || endRow == -1) {

        cout << "Error: Starting point or crew not found!\n";
        return 0;
    }


    // BFS DATA STRUCTURES

    // Stores minimum distance from A to each cell.
    vector<vector<int>> distance(
        rows, vector<int>(cols, -1)
    );

    // Stores the previous row and column.
    vector<vector<int>> parentRow(
        rows, vector<int>(cols, -1)
    );

    vector<vector<int>> parentCol(
        rows, vector<int>(cols, -1)
    );

    // Queue stores the coordinates of cells.
    queue<pair<int, int>> q;


    // Start BFS from A.
    q.push({startRow, startCol});

    distance[startRow][startCol] = 0;


    cout << "LEVEL 3"<<endl;
    cout << "MISSION: FIND THE CREW\n";

    cout << "Starting BFS exploration...\n";


    // BREADTH-FIRST SEARCH

    while (!q.empty()) {

        // Get the front cell from the queue.
        int currentRow = q.front().first;
        int currentCol = q.front().second;

        q.pop();


        // Stop when the crew is reached.
        if (currentRow == endRow &&
            currentCol == endCol) {

            break;
        }


        // Explore all four directions.
        for (int d = 0; d < 4; d++) {

            int newRow = currentRow + rowMove[d];
            int newCol = currentCol + colMove[d];


            // Check whether the new position is inside the maze.
            if (newRow >= 0 && newRow < rows &&
                newCol >= 0 && newCol < cols) {


                // Check whether the cell is not a wall
                // and has not been visited before.
                if (maze[newRow][newCol] != '#' &&
                    distance[newRow][newCol] == -1) {


                    // Calculate distance.
                    distance[newRow][newCol] =
                        distance[currentRow][currentCol] + 1;


                    // Store the parent coordinates.
                    parentRow[newRow][newCol] = currentRow;
                    parentCol[newRow][newCol] = currentCol;


                    // Add the new cell to the queue.
                    q.push({newRow, newCol});
                }
            }
        }
    }


    // CHECK WHETHER THE CREW CAN BE REACHED.

    if (distance[endRow][endCol] == -1) {

        cout << "No path found to the crew!\n";
        cout << "GAME OVER\n";
        cout << "Points earned = 0\n";

        return 0;
    }


    // Calculate shortest distance and remaining oxygen.
    int steps = distance[endRow][endCol];

    int oxygenLeft = oxygen - steps;


    cout << "Fewest steps = " << steps << "\n";
    cout << "Oxygen available = " << oxygen << "\n";
    cout << "Oxygen left = " << oxygenLeft << "\n";


    // CHECK OXYGEN AVAILABILITY.

    if (oxygenLeft < 0) {

        cout << "\nNot enough oxygen to reach the crew!\n";
        cout << "GAME OVER\n";
        cout << "Points earned = 0\n";

        return 0;
    }


    // RECONSTRUCT THE SHORTEST PATH.

    int currentRow = endRow;
    int currentCol = endCol;

    // Mark the shortest path with *.
    while (!(currentRow == startRow &&
             currentCol == startCol)) {

        if (maze[currentRow][currentCol] == '.') {
            maze[currentRow][currentCol] = '*';
        }

        int previousRow = parentRow[currentRow][currentCol];
        int previousCol = parentCol[currentRow][currentCol];

        currentRow = previousRow;
        currentCol = previousCol;
    }


    // DISPLAY THE MAZE WITH THE SHORTEST PATH.

    cout << "\nShortest path (*):\n";

    for (int i = 0; i < rows; i++) {

        for (int j = 0; j < cols; j++) {

            cout << maze[i][j];
        }

        cout << "\n";
    }


    // CALCULATE POINTS.

    int points = oxygenLeft;

    cout << "\n*** CREW RESCUED! ***\n";

    cout << "Astro successfully reached the crew!\n";

    cout << "Points earned = " << points << "\n";

    cout << "============================\n";

    return points;
}


//level 4  0/1 Knapsack

 int getMax(int firstVal, int secondVal) {
    if (firstVal > secondVal) {
        return firstVal;
    } else {
        return secondVal;
    }
}
int knapsack01(int capacity,string itemName[],int Weight[],int Value[],int itemCount ){
    int DPTable[105][105];
    for (int currentCap = 0; currentCap <= capacity; currentCap++) {
        DPTable[0][currentCap] = 0;
    }
    for (int item = 1; item <= itemCount; item++) {
       DPTable [item][0] = 0;
    }
    for (int item = 1; item <= itemCount; item++) {
        for (int currentCap = 1; currentCap <= capacity; currentCap++) {
            // Check if the current item fits inside currentCap (using 0-indexed weights/values)
            if (Weight[item - 1] <= currentCap) {
                int takeItem = Value[item - 1] + DPTable[item - 1][currentCap - Weight[item - 1]];
                int skipItem = DPTable[item - 1][currentCap];
                DPTable[item][currentCap] = getMax(takeItem, skipItem);
            } else {
                // Too heavy to fit, so copy the value from above
                DPTable[item][currentCap] = DPTable[item - 1][currentCap];
            }
        }
    }
    // Backtrack to find which items were chosen
    string chosenNames[105]; // Stores the names of packed items
    int chosenCount = 0;     // Counts how many items were packed
    int totalWeight = 0;     // Tracks total weight used
    int remainingCap = capacity;
    for (int item = itemCount; item > 0 && remainingCap > 0; item--) {
        if (DPTable[item][remainingCap] != DPTable[item - 1][remainingCap]) {
            chosenNames[chosenCount] = itemName[item - 1];
            chosenCount++;
            totalWeight = totalWeight + Weight[item - 1];
            remainingCap = remainingCap - Weight[item - 1];
        }
    }
    // Print the max items that Astro selected to pack in his spaceship
    cout << "Packed cargo: ";
    if (chosenCount == 0) {
        cout << "None";
    }
    else {
/* Loop backward so the selected items print in the same order
as the map file*/
        for (int i = chosenCount - 1; i >= 0; i--) {
            cout << chosenNames[i];
            if (i > 0) cout << ", ";
        }
    }
    cout << "\n";
    cout << "Total weight = " << totalWeight << "/" << capacity << endl;
    return DPTable[itemCount][capacity];
    // Return the max value that can be packed
}
int level4(){
    ifstream file("sample_world.txt");
    if (!file) {
        cout << "Error: Could not open sample_world.txt"<< endl;
        return -1;
    }
   string line,word;
   // Holds one full line of text while scanning for [CARGO]
    // Temporary bucket to catch label words like "CAPACITY" and "ITEMS"
    int capacity = 0, itemCount = 0;
    // Stores the maximum weight the spaceship can carry (15)
    // Stores how many items are available to choose from (5)
    string itemNames[105];
    // Array storing each item's text name (e.g., "Moon_Dust")
    int weights[105];
    // Array storing each item's weight
    int values[105];
     // Array storing each item's point value

     while (getline(file, line)) {
        if (line.empty() || line.substr(0, 2) == "//") {
            continue;
        }
        // Stop scanning as soon as our finger lands on the exact [CARGO] section header.
        if (line == "[CARGO]") {
            break;
        }
    }
    file >> word >> capacity; // Read the spaceship's cargo capacity
    file >> word >> itemCount;
    // Read how many items are available to choose from

    // Loop 'itemCount' times to read each item's 3 pieces of data into our arrays
    for (int i = 0; i < itemCount; i++) {
        file >> itemNames[i] >> weights[i] >> values[i];
    }
    file.close();

    cout << "LEVEL 4"<< endl;
    cout << "MISSION: PACK THE CARGO"<< endl;

    // Run the 0/1 Knapsack algorithm to find the best items and capture the total score
    int points = knapsack01(capacity, itemNames, weights, values, itemCount);

    cout << "Points earned = " << points << endl;
    return points;

}

// level 5

// level 6

// level 7


//Menu table
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


}
