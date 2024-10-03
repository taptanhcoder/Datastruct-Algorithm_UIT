#include <iostream>
using namespace std;


struct Node {
    int data;
    Node* next;
    Node* prev; 
    Node(int value) : data(value),prev(NULL), next(NULL) {}
};

void makeNode(Node*& head, int value) {
    Node* newNode = new Node(value);
    if (head == NULL) {
        head = newNode;
        return;
    } else {
        Node* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->prev=temp;
    }
}

void display(Node* head) {
        Node* current = head;
        while (current) {  
            cout << current->data << " <-> ";
            current = current->next;
        }
        cout << "nullptr" << std::endl;
}



void printNode(Node* head) {
    Node* temp = head;
    string choice;
    int count=0;
    do {
        int x;
        cout << "Enter index: ";
        cin >> x;

        temp = head;
        if (!temp) {
            cout << "not found" << endl;
        }
        if (count<x){
            while (temp) {
            if (count == x) {
                cout << "Node at index " << x << ": " << temp->data << endl;
                break; 
            }
            temp = temp->next;
            count++;
            }
        }
        if (count >x){
            while (temp) {
            if (count == x) {
                cout << "Node at index " << x << ": " << temp->data << endl;
                break; 
            }
            temp = temp->prev;
            count--;
            }
        }
       
        
        
        cout << "Do you want to continue? (yes/no): ";
        cin >> choice;

    } while (choice == "yes");

}

void deleteNode(Node* head) {
        int k;
        cout<<"enter index: ";
        cin>>k;
        if (k < 0 || !head) {
            cout << "Invalid position or empty list!" << endl;
            return;
        }

        Node* temp = head;
        int count = 0;

        if (k == 0) {
            head = head->next; 
            if (head) {
                head->prev = NULL;  
            }
            delete temp; 
            return;
        }
        while (temp!=NULL && count < k) {
            temp = temp->next;
            count++;
        }

        if (!temp) {
            cout << "Position out of bounds!" << endl;
            return;
        }

        if (temp->prev!=NULL) {
            temp->prev->next = temp->next;
        }
        if (temp->next!=NULL) {
            temp->next->prev = temp->prev;
        }

        delete temp;  
        cout << "Node at position " << k << " deleted." << endl;
}


int main ()
{
    Node* head = NULL;
    makeNode(head,1);
    makeNode(head,3);
    makeNode(head,9);
    makeNode(head,7);
    makeNode(head,5);
    makeNode(head,8);

    display(head);
    printNode(head);
    deleteNode(head);
    display(head);
    return 0;
}
