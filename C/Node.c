#include <stdio.h>

// Define maximum capacity for static node pool to avoid stdlib.h (malloc/free)
#define MAX_NODES 100

// Define self-referential structure representing a single node in a linked list
struct Node {
    // Member integer variable to store the payload/data value of the node
    int data;
    // Member pointer variable holding the memory address of the next consecutive node
    struct Node* next;
};

// Static storage pool for nodes to eliminate the need for malloc/free
struct Node node_pool[MAX_NODES];
// Tracker for the next available slot inside the static node pool
int pool_top = 0;

// Function definition to allocate and initialize a new node from static memory
struct Node* createNode(int value) {
    // Check if the static memory pool has reached its maximum capacity
    if (pool_top >= MAX_NODES) {
        // Print an error message indicating memory pool exhaustion
        printf("Node pool overflow! Cannot allocate new node.\n");
        // Return NULL as no slot is available
        return NULL;
    }

    // Retrieve memory address of the next available node in the static array
    struct Node* newNode = &node_pool[pool_top++];
    // Assign the input parameter value into the data field of the node
    newNode->data = value;
    // Initialize the next pointer of the new node to NULL as it is unlinked
    newNode->next = NULL;
    // Return the memory address of the allocated node back to the caller
    return newNode;
}

// Function to print all elements in the linked list starting from the head node
void displayList(struct Node* head) {
    // Check if the list pointer is NULL indicating an empty list
    if (head == NULL) {
        // Output a message indicating that the list contains no nodes
        printf("List is empty.\n");
        // Exit the display function early
        return;
    }

    // Initialize a temporary pointer to point to the first node without modifying head
    struct Node* temp = head;
    // Print the starting header label for the list display
    printf("Linked List: ");
    // Loop through the list as long as the current node pointer is not NULL
    while (temp != NULL) {
        // Print the data value of the current node followed by an arrow symbol
        printf("%d -> ", temp->data);
        // Advance the temporary pointer to the next node in sequence
        temp = temp->next;
    }
    // Print NULL at the end to signify the termination of the linked list
    printf("NULL\n");
}

// Function to count and return the total number of nodes present in the list
int countNodes(struct Node* head) {
    // Initialize an integer counter variable to track the total node count
    int count = 0;
    // Initialize a temporary pointer to traverse the list starting from head
    struct Node* temp = head;
    // Iterate through each node in the chain until reaching NULL
    while (temp != NULL) {
        // Increment the node counter by one for the current visited node
        count++;
        // Advance the temporary pointer to point to the subsequent node
        temp = temp->next;
    }
    // Return the final accumulated count of nodes
    return count;
}

// Function to insert a new node at the very beginning (index 0) of the list
struct Node* insertAtBeginning(struct Node* head, int value) {
    // Call createNode to allocate and populate the new node with the given value
    struct Node* newNode = createNode(value);
    // Check if node allocation was successful
    if (newNode == NULL) {
        // Return original head if allocation failed
        return head;
    }
    // Link the new node's next pointer to the current starting head node
    newNode->next = head;
    // Update head pointer reference to make the new node the first element
    head = newNode;
    // Return the updated head pointer of the list
    return head;
}

// Function to insert a new node at the end (tail) of the list
struct Node* insertAtEnd(struct Node* head, int value) {
    // Allocate and initialize the new node to be appended
    struct Node* newNode = createNode(value);
    // Check if node allocation was successful
    if (newNode == NULL) {
        // Return original head if allocation failed
        return head;
    }
    // Check if the list is completely empty
    if (head == NULL) {
        // Return the new node directly as the head of the new list
        return newNode;
    }

    // Initialize a temporary pointer to find the current last node
    struct Node* temp = head;
    // Traverse until temp points to the last node whose next pointer is NULL
    while (temp->next != NULL) {
        // Move to the next node in the list
        temp = temp->next;
    }
    // Set the previous last node's next pointer to point to the new node
    temp->next = newNode;
    // Return the original head pointer
    return head;
}

// Function to insert a new node at a specified 0-based index position
struct Node* insertAtPosition(struct Node* head, int value, int pos) {
    // If the insertion target position is 0, delegate to beginning insertion
    if (pos == 0) {
        // Return result of inserting node at the beginning
        return insertAtBeginning(head, value);
    }

    // Create and allocate the new node
    struct Node* newNode = createNode(value);
    // Check if node allocation was successful
    if (newNode == NULL) {
        // Return original head if allocation failed
        return head;
    }

    // Initialize traversal pointer to locate the node preceding the target position
    struct Node* temp = head;

    // Loop until reaching index (pos - 1) or reaching the end of the list
    for (int i = 0; temp != NULL && i < pos - 1; i++) {
        // Advance pointer to the next node
        temp = temp->next;
    }

    // Verify if position is out of bounds (temp is NULL before reaching index)
    if (temp == NULL) {
        // Print an error message indicating position exceeds list bounds
        printf("Position %d out of bounds! Cannot insert.\n", pos);
        // Return head pointer without altering the list
        return head;
    }

    // Connect new node's next pointer to the node currently occupying the target index
    newNode->next = temp->next;
    // Update the preceding node's next pointer to point to the new node
    temp->next = newNode;
    // Return the head pointer
    return head;
}

// Function to delete the first node (head) from the list
struct Node* deleteFromBeginning(struct Node* head) {
    // Check underflow condition when list contains zero nodes
    if (head == NULL) {
        // Print underflow error message
        printf("List underflow! No nodes to delete.\n");
        // Return NULL as the list remains empty
        return NULL;
    }

    // Move head pointer forward to make the second node the new head
    head = head->next;
    // Return the updated head pointer
    return head;
}

// Function to delete the last node (tail) from the list
struct Node* deleteFromEnd(struct Node* head) {
    // Check underflow condition when the list is empty
    if (head == NULL) {
        // Print underflow error message
        printf("List underflow! No nodes to delete.\n");
        // Return NULL as no deletion can take place
        return NULL;
    }

    // Check if the list contains only a single node
    if (head->next == NULL) {
        // Return NULL as list is now completely empty
        return NULL;
    }

    // Initialize traversal pointer to find the second-to-last node
    struct Node* temp = head;
    // Loop until temp points to the node whose next node points to NULL
    while (temp->next->next != NULL) {
        // Advance traversal pointer forward
        temp = temp->next;
    }

    // Set the second-to-last node's next pointer to NULL to mark it as the new end
    temp->next = NULL;
    // Return the head pointer
    return head;
}

// Function to delete a node located at a specific 0-based index position
struct Node* deleteFromPosition(struct Node* head, int pos) {
    // Check if the list is empty before attempting deletion
    if (head == NULL) {
        // Print underflow error message
        printf("List underflow! No nodes to delete.\n");
        // Return NULL
        return NULL;
    }

    // If deleting the first element, call deleteFromBeginning
    if (pos == 0) {
        // Return result of deleting the head node
        return deleteFromBeginning(head);
    }

    // Pointer to find the node directly preceding the node to be removed
    struct Node* temp = head;
    // Traverse forward up to the (pos - 1)th node
    for (int i = 0; temp != NULL && i < pos - 1; i++) {
        // Advance traversal pointer
        temp = temp->next;
    }

    // Check if target position does not exist or falls beyond current length
    if (temp == NULL || temp->next == NULL) {
        // Print out-of-bounds error message
        printf("Position %d out of bounds! Cannot delete.\n", pos);
        // Return original head pointer without modifying the list
        return head;
    }

    // Store address of the node that is to be bypassed
    struct Node* nodeToDelete = temp->next;
    // Relink preceding node's next pointer to bypass the deleted node
    temp->next = nodeToDelete->next;
    // Return the head pointer
    return head;
}

// Function to search for a value and return its 0-based index in the list
int searchNode(struct Node* head, int target) {
    // Pointer to traverse through each node
    struct Node* temp = head;
    // Integer variable to track index position
    int index = 0;

    // Traverse until reaching the end of the linked list
    while (temp != NULL) {
        // Compare the current node's stored value against the search target
        if (temp->data == target) {
            // Return current index if match is found
            return index;
        }
        // Advance traversal pointer to next node
        temp = temp->next;
        // Increment index position tracker
        index++;
    }

    // Return -1 to indicate target value does not exist in list
    return -1;
}

// Function to reverse the direction of all pointer links in place
struct Node* reverseList(struct Node* head) {
    // Pointer to store previous node reference (initialized to NULL for new tail)
    struct Node* prev = NULL;
    // Pointer to track current node being processed
    struct Node* current = head;
    // Pointer to temporarily store reference to next node in original chain
    struct Node* nextNode = NULL;

    // Loop through list adjusting pointer directions
    while (current != NULL) {
        // Store address of next node before overwriting current pointer
        nextNode = current->next;
        // Reverse current node's next pointer to point backward to previous node
        current->next = prev;
        // Advance previous pointer to current node
        prev = current;
        // Advance current pointer to next node saved earlier
        current = nextNode;
    }

    // Assign prev (which points to the last processed node) as the new head
    head = prev;
    // Return the new head pointer of the reversed list
    return head;
}

// Main execution entry point
int main() {
    // Initialize head pointer of linked list to NULL (empty list)
    struct Node* head = NULL;

    // Print section header for insertion operations
    printf("--- Insertion Operations ---\n");
    // Insert node with value 20 at beginning
    head = insertAtBeginning(head, 20);
    // Insert node with value 10 at beginning
    head = insertAtBeginning(head, 10);
    // Append node with value 40 at end
    head = insertAtEnd(head, 40);
    // Insert node with value 30 at index position 2
    head = insertAtPosition(head, 30, 2);
    // Display all active nodes in the list
    displayList(head);
    // Print the total number of nodes in list
    printf("Total nodes: %d\n\n", countNodes(head));

    // Print section header for search operation
    printf("--- Search Operation ---\n");
    // Set target search value
    int target = 30;
    // Execute search function and store resulting index
    int searchResult = searchNode(head, target);
    // Check if item was found
    if (searchResult != -1) {
        // Print index where element was found
        printf("Value %d found at node index: %d\n\n", target, searchResult);
    } else {
        // Print not found message
        printf("Value %d not found in the list.\n\n", target);
    }

    // Print section header for list reversal
    printf("--- Reversal Operation ---\n");
    // Reverse linked list pointers in place
    head = reverseList(head);
    // Display reversed list
    displayList(head);
    // Print newline for formatting
    printf("\n");

    // Print section header for deletion operations
    printf("--- Deletion Operations ---\n");
    // Delete first node from the list
    head = deleteFromBeginning(head);
    // Display remaining nodes
    displayList(head);

    // Delete last node from the list
    head = deleteFromEnd(head);
    // Display remaining nodes
    displayList(head);

    // Delete node at index position 1
    head = deleteFromPosition(head, 1);
    // Display remaining nodes
    displayList(head);

    // Return 0 indicating successful program execution
    return 0;
}