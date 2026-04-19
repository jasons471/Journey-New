#include <stdio.h>

// --- STACK DEFINITIONS ---
#define Max 10
int top = -1;
int arr[Max];

// --- QUEUE DEFINITIONS ---
#define size 5
int queue[size];
int front = -1;
int rear = -1;

// --- STACK FUNCTIONS ---

void push(int ele) {
    if (top == Max - 1) {
        printf("Stack full\n");
    } else {
        top++;
        arr[top] = ele;
        printf("Pushed %d to stack\n", ele);
    }
}

void pop() {
    int ele;
    if (top == -1) {
        printf("Stack Empty\n");
    } else {
        ele = arr[top];
        top--;
        printf("Popped %d from stack\n", ele);
    }
}

// --- QUEUE FUNCTIONS ---

void enqueue(int n) {
    if (rear == size - 1) {
        printf("Queue full\n");
    } else {
        rear++;
        if (front == -1) {
            front = 0; // Initialize front on first enqueue
        }
        queue[rear] = n;
        printf("Enqueued %d to queue\n", n);
    }
}

void dequeue() {
    int value;
    if (front == rear) {
        printf("Queue empty\n");
    } else {
        front++;
        value = queue[front];
        printf("Dequeued %d from queue\n", value);
    }
}

// --- MAIN FUNCTION TO TEST ---

int main() {
    printf("--- Testing Stack ---\n");
    push(10);
    push(20);
    pop();
    pop();
    pop(); // Should show empty

    printf("\n--- Testing Queue ---\n");
    enqueue(100);
    enqueue(200);
    dequeue();
    dequeue();
    dequeue(); // Should show empty

    return 0;
}