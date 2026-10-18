#include <stdio.h>

// Define maximum capacity for static queue arrays
#define MAX 5

// ==========================================
// 1. LINEAR QUEUE IMPLEMENTATION
// ==========================================

// Global array for linear queue storage
int linear_queue[MAX];
// Front index pointer for linear queue
int l_front = -1;
// Rear index pointer for linear queue
int l_rear = -1;

// Function to insert an element into the Linear Queue
void enqueue_linear(int value) {
    // Check if the rear pointer has reached the maximum capacity boundary
    if (l_rear == MAX - 1) {
        // Linear queue cannot accept new items once rear reaches the end
        printf("Linear Queue Overflow! Cannot insert %d\n", value);
    } else {
        // If the queue was empty, set front to index 0
        if (l_front == -1) {
            l_front = 0;
        }
        // Advance rear index by 1
        l_rear++;
        // Place value at the current rear position
        linear_queue[l_rear] = value;
        // Print insertion confirmation message
        printf("Linear Queue: Enqueued %d at index %d\n", value, l_rear);
    }
}

// Function to remove an element from the Linear Queue
void dequeue_linear() {
    // Check if the linear queue contains no items
    if (l_front == -1 || l_front > l_rear) {
        // Print underflow error message
        printf("Linear Queue Underflow! Queue is empty.\n");
    } else {
        // Retrieve and print the dequeued element from the front
        printf("Linear Queue: Dequeued %d from index %d\n", linear_queue[l_front], l_front);
        // Move front pointer forward to eliminate the element logically
        l_front++;
        // If front has moved past rear, reset both pointers to -1
        if (l_front > l_rear) {
            l_front = -1;
            l_rear = -1;
        }
    }
}

// Function to display elements of the Linear Queue
void display_linear() {
    // Check if the queue is empty
    if (l_front == -1 || l_front > l_rear) {
        // Display empty status message
        printf("Linear Queue is currently empty.\n");
    } else {
        // Print header for linear queue contents
        printf("Linear Queue elements (front to rear): ");
        // Iterate through all active indices from front to rear
        for (int i = l_front; i <= l_rear; i++) {
            // Print element followed by space
            printf("%d ", linear_queue[i]);
        }
        // Print newline at end
        printf("\n");
    }
}

// ==========================================
// 2. CIRCULAR QUEUE IMPLEMENTATION
// ==========================================

// Global array for circular queue storage
int circular_queue[MAX];
// Front index pointer for circular queue
int c_front = -1;
// Rear index pointer for circular queue
int c_rear = -1;

// Function to insert an element into the Circular Queue
void enqueue_circular(int value) {
    // Check if the next position of rear wraps around and collides with front
    if ((c_rear + 1) % MAX == c_front) {
        // Circular queue is full when the circular next of rear equals front
        printf("Circular Queue Overflow! Cannot insert %d\n", value);
    } else {
        // If the circular queue is completely empty
        if (c_front == -1) {
            // Initialize front to 0
            c_front = 0;
            // Initialize rear to 0
            c_rear = 0;
        } else {
            // Advance rear cyclically using modulo arithmetic
            c_rear = (c_rear + 1) % MAX;
        }
        // Assign the new value to the updated rear index
        circular_queue[c_rear] = value;
        // Print confirmation message
        printf("Circular Queue: Enqueued %d at index %d\n", value, c_rear);
    }
}

// Function to remove an element from the Circular Queue
void dequeue_circular() {
    // Check if the circular queue is empty
    if (c_front == -1) {
        // Print underflow error message
        printf("Circular Queue Underflow! Queue is empty.\n");
    } else {
        // Retrieve and print the dequeued element from the circular front
        printf("Circular Queue: Dequeued %d from index %d\n", circular_queue[c_front], c_front);
        // Check if only one single element was present in the queue
        if (c_front == c_rear) {
            // Reset both pointers to -1 to represent an empty queue
            c_front = -1;
            c_rear = -1;
        } else {
            // Advance front cyclically using modulo arithmetic
            c_front = (c_front + 1) % MAX;
        }
    }
}

// Function to display elements of the Circular Queue
void display_circular() {
    // Check if the circular queue is empty
    if (c_front == -1) {
        // Display empty status message
        printf("Circular Queue is currently empty.\n");
    } else {
        // Print header for circular queue contents
        printf("Circular Queue elements (front to rear): ");
        // Start traversal pointer from front
        int i = c_front;
        // Loop continuously until reaching rear
        while (1) {
            // Print current element
            printf("%d ", circular_queue[i]);
            // Stop when rear element has just been printed
            if (i == c_rear) {
                break;
            }
            // Move index forward cyclically
            i = (i + 1) % MAX;
        }
        // Print newline at end
        printf("\n");
    }
}

int main() {
    printf("===========================================\n");
    printf("          LINEAR QUEUE OPERATIONS          \n");
    printf("===========================================\n");

    // Insert 3 values into linear queue
    enqueue_linear(10);
    enqueue_linear(20);
    enqueue_linear(30);

    // Display current linear queue state
    display_linear();

    // Delete one element from linear queue
    dequeue_linear();
    // Display linear queue after deletion
    display_linear();

    // Insert more elements up to MAX capacity
    enqueue_linear(40);
    enqueue_linear(50);

    // Display full linear queue state
    display_linear();

    // Attempting to enqueue when rear == MAX - 1 causes overflow
    enqueue_linear(60);

    // Display divider for circular queue demonstration
    printf("\n===========================================\n");
    printf("         CIRCULAR QUEUE OPERATIONS         \n");
    printf("===========================================\n");

    enqueue_circular(100);
    enqueue_circular(200);
    enqueue_circular(300);
    enqueue_circular(400);

    // Display circular queue state
    display_circular();

    // Delete two elements from the front
    dequeue_circular();
    dequeue_circular();
    // Display circular queue showing freed space at indices 0 and 1
    display_circular();

    // Enqueue new elements to demonstrate circular wrap-around reuse
    printf("\n-- Testing Circular Wrap-around (reusing front empty slots) --\n");
    enqueue_circular(500);
    enqueue_circular(600);
    // Display wrapped-around circular queue
    display_circular();

    // Attempt to insert when circular capacity is full to test overflow
    enqueue_circular(700);

    return 0;
}