#include <iostream>
using namespace std;


struct Node {
    int data;
    Node* next;
    
    Node(int value) : data(value), next(NULL) {}
};


Node* findMiddleNode(Node* head) {
    if (head == NULL) {
        return NULL; 
    }

    Node* slow = head; 
    Node* fast = head; 

   
    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }

    return slow; 
}


void appendNode(Node*& head, int value) {
    Node* newNode = new Node(value);
    if (head == NULL) {
        head = newNode;
    } else {
        Node* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}


void printList(Node* head) {
    while (head != NULL) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    Node* head = NULL;

    appendNode(head, 1);
    appendNode(head, 2);
    appendNode(head, 3);
    appendNode(head, 4);
    appendNode(head, 5);

    cout << "Linked List: ";
    printList(head);


    Node* middle = findMiddleNode(head);
    if (middle != NULL) {
        cout << "Middle Node " << middle->data << endl;
    } else {
        cout << "LinkedList is empty !" << endl;
    }

    return 0;
}
