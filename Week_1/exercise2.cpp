#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    
    Node(int value) : data(value), next(NULL) {}
};

bool hasCycle(Node* head) {
    if (head == NULL || head->next == NULL) {
        return false; 
    }

    Node* slow = head;  
    Node* fast = head;  
    
    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;             
        fast = fast->next->next;       
        if (slow == fast) {
            return true;
        }
    }

    return false;
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

int main() {
    Node* head = NULL;

    appendNode(head, 1);
    appendNode(head, 2);
    appendNode(head, 3);
    appendNode(head, 4);
    appendNode(head, 5);

    head->next->next->next->next->next = head->next->next;

    if (hasCycle(head)) {
        cout << "Danh sách liên kết có chu trình." << endl;
    } else {
        cout << "Danh sách liên kết không có chu trình." << endl;
    }

    return 0;
}
