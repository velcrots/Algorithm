#include <stdio.h>

int main(void) {
    // SLL : Single Linked List
    // Description: These are simple functions to implement a single linked list.

    // Using Structure to define a node
    struct Mynode {
        int data;   // Data type can be changed as per requirement
        struct Mynode *nextNode;
    };

    // Using typedef to define a new data type
    typedef struct Mynode Node;

    // or like this
    typedef struct Mynode {
        int data;
        struct Mynode *nextNode;
    } Node;


    // SLL needs five operations : Create, Append, Insert, Delete, Search

    // Create a new node
    Node *SLL_createNode(int data) {
        Node *newNode = (Node *)malloc(sizeof(Node));
        newNode->data = data;
        newNode->nextNode = NULL;
        return newNode;
    }

    // Free a node
    void SLL_freeNode(Node *node) {
        free(node);
    }

    // Append a node at the end
    void SLL_appendNode(Node **head, Node *newNode) {
        if (*head == NULL) {
            *head = newNode;
        } else {
            Node *temp = *head;
            while (temp->nextNode != NULL) {
                temp = temp->nextNode;
            }
            temp->nextNode = newNode;
        }
    }

    // Insert a node
    void SLL_insertNode(Node *currentNode, Node *newNode) {
        newNode->nextNode = currentNode->nextNode;
        currentNode->nextNode = newNode;
    }

    // Delete a node
    void SLL_deleteNode(Node **head, Node *node) {
        if (*head == node) {
            *head = node->nextNode;
        } else {
            Node *temp = *head;
            while (temp->nextNode != node) {
                temp = temp->nextNode;
            }
            temp->nextNode = node->nextNode;
        }
        SLL_freeNode(node);
    }

    // Search a node
    Node *SLL_searchNode(Node *head, int data) {
        Node *temp = head;
        while (temp != NULL) {
            if (temp->data == data) {
                return temp;
            }
            temp = temp->nextNode;
        }
        return NULL;
    }

    // Special function to count the number of nodes
    int SLL_countNodes(Node *head) {
        int count = 0;
        Node *temp = head;
        while (temp != NULL) {
            count++;
            temp = temp->nextNode;
        }
        return count;
    }

    // Conclusion: Linked List if faster than Array for Insertion and Deletion but slower for Search and Access

    return 0;
}