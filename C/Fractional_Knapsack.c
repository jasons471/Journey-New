#include <stdio.h> 

//all sortings are in descending order except for weight which is in ascending order


// Helper function: swaps two items located at index i and index j across all 3 arrays
void swap(float weight[], float value[], float ratio[], int i, int j) {
    float temp; // Temporary variable used as intermediate storage for swapping

    // Step 1: Swap weights between position i and position j
    temp = weight[i];      // Save item i's weight in temp
    weight[i] = weight[j]; // Overwrite item i's weight with item j's weight
    weight[j] = temp;      // Put the saved weight into item j's position

    // Step 2: Swap values between position i and position j
    temp = value[i];       // Save item i's value in temp
    value[i] = value[j];   // Overwrite item i's value with item j's value
    value[j] = temp;       // Put the saved value into item j's position

    // Step 3: Swap ratios between position i and position j
    temp = ratio[i];       // Save item i's ratio in temp
    ratio[i] = ratio[j];   // Overwrite item i's ratio with item j's ratio
    ratio[j] = temp;       // Put the saved ratio into item j's position
}

// Helper function: copies original values into working arrays so inputs remain untouched
void clone(float orig_w[], float orig_v[], float orig_r[], 
           float work_w[], float work_v[], float work_r[], int n) {
    // Loop through each element up to total item count n
    for (int i = 0; i < n; i++) {
        work_w[i] = orig_w[i]; // Copy original weight to working weight array
        work_v[i] = orig_v[i]; // Copy original value to working value array
        work_r[i] = orig_r[i]; // Copy original ratio to working ratio array
    }
}

// Condition 1: Sort by value (highest profit first)
void by_value(float weight[], float value[], float ratio[], int n) {
    // Outer loop controls current target index to place the largest available value
    for (int i = 0; i < n - 1; i++) {
        // Inner loop checks every element that comes after target index i
        for (int j = i + 1; j < n; j++) {
            // If the subsequent item has a strictly higher value, swap them
            if (value[i] < value[j]) {
                swap(weight, value, ratio, i, j); // Bring the larger value item forward
            }
        }
    }
}



// Condition 2: Sort by weight (lightest weight first)
void by_weight(float weight[], float value[], float ratio[], int n) {
    // Outer loop controls current target index to place the smallest weight
    for (int i = 0; i < n - 1; i++) {
        // Inner loop checks every element that comes after target index i
        for (int j = i + 1; j < n; j++) {
            // If current item is heavier than the next item, swap them
            if (weight[i] > weight[j]) {
                swap(weight, value, ratio, i, j); // Bring the lighter weight item forward
            }
        }
    }
}



// Condition 3: Sort by ratio (highest density/best rate first)
void by_ratio(float weight[], float value[], float ratio[], int n) {
    // Outer loop controls current target index to place the highest ratio
    for (int i = 0; i < n - 1; i++) {
        // Inner loop checks every element that comes after target index i
        for (int j = i + 1; j < n; j++) {
            // If subsequent item has a higher value-to-weight ratio, swap them
            if (ratio[i] < ratio[j]) {
                swap(weight, value, ratio, i, j); // Bring the higher ratio item forward
            }
        }
    }
}



// Core solver: packs knapsack in greedy order, taking whole items or a fraction
float knapsack(float weight[], float value[], int n, float capacity) {
    float track_weight = 0.0; // Tracks total weight accumulated in the knapsack 
    float total_profit = 0.0;   // Tracks total profit accumulated in the knapsack 

    // Iterate through items in their pre-sorted greedy order
    for (int i = 0; i < n; i++) {
        float remaining = capacity - track_weight; // Compute how much empty space is left

        // Case A: The entire item fits within the remaining space
        if (weight[i] <= remaining) {
            track_weight += weight[i]; // Add full item weight to the knapsack
            total_profit += value[i];    // Add full item value to the total profit
        } 
        // Case B: The item is too heavy to fit whole, so take a fractional cut
        else {
            float fraction = remaining / weight[i]; // Compute the exact fraction needed to fill knapsack
            total_profit += (value[i] * fraction);  // Add only the fractional profit earned
            break; // Bag is now 100% full to capacity; stop packing and exit loop
        }
    }

    return total_profit;  
}

int main() {
    int n;          
    float capacity; 

    printf("Enter number of items: ");
    scanf("%d", &n);

    // Arrays to store original values entered by the user
    float weight[50]; 
    float value[50];  
    float ratio[50]; 

    // Temporary working arrays used so sorting doesn't destroy original input
    float work_w[50]; 
    float work_v[50]; 
    float work_r[50]; 

    for (int i = 0; i < n; i++) {
        printf("Enter weight and value for item %d: ", i); 
        scanf("%f %f", &weight[i], &value[i]);                 
        ratio[i] = value[i] / weight[i];       
    }

    //  Get the knapsack's maximum weight limit
    printf("Enter knapsack capacity: ");
    scanf("%f", &capacity); 

    
    // 1 highest value item first
    clone(weight, value, ratio, work_w, work_v, work_r, n); // Load a fresh copy of original items
    by_value(work_w, work_v, work_r, n);  // Sort items from highest value to lowest
    printf("\n1. Max Value First   -> Total Profit: %.2f\n", knapsack(work_w, work_v, n, capacity));          

   
    // 2 lightest weight item first
    clone(weight, value, ratio, work_w, work_v, work_r, n); // Reset working arrays to original input
    by_weight(work_w, work_v, work_r, n);  // Sort items from lightest weight to heaviest
    printf("2. Min Weight First  -> Total Profit: %.2f\n", knapsack(work_w, work_v, n, capacity));          

    
    // 3 highest value/weight ratio 
    clone(weight, value, ratio, work_w, work_v, work_r, n); 
    by_ratio(work_w, work_v, work_r, n);  // Sort items from highest value-to-weight ratio to lowest
    printf("3. Max Ratio First   -> Total Profit: %.2f \n", knapsack(work_w, work_v, n, capacity));          

    return 0; 
}