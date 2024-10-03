#include<iostream>
using namespace std;

struct Node {
    int data;
    Node* next;

    Node(int value): data(value), next(NULL) {}
};

class Stack {

private:
    Node* head;
    int size;
    int capacity;

public:

    Stack(int cap): head(NULL), size(0), capacity(cap) {}

    void push(int n) {
        if (size >= capacity) {
            cout << "Stack is full\n";
            return;
        }
        Node* newnode = new Node(n);
        newnode->next = head;
        head = newnode;
        size++;
    }

 
    bool isEmpty() {
        return head == NULL;  
    }


    void pop() {
        if (isEmpty()) {
            cout << "Stack is empty\n";
            return;
        }
        Node* temp = head;
        head = head->next;
        delete temp;
        size--;
    }

    void display() {
        if (isEmpty()) {
            cout << "Stack is empty\n";
            return;
        }
        Node* temp = head;
        while (temp != NULL) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    void check_empty() {
        if (isEmpty()) {
            cout << "true\n";
        } else {
            cout << "false\n";
        }
    }

    void check_isfull() {
        if (size >= capacity) {
            cout << "true\n";
        } else {
            cout << "false\n";
        }
    }

    void printhead(){
        cout<<endl;
        cout<<head->data;
        cout<<endl;
    }
};

int main() {

    int cap;
    cout << "Enter the capacity: ";
    cin >> cap;

    Stack stack(cap); 

    stack.push(10);  
    stack.push(20);
    stack.push(30);

    int choice, value;
    do {

        cout << "1. check empty\n";
        cout << "2. check full\n";
        cout << "3. push \n";
        cout << "4. pop \n";
        cout << "5. print head\n";

        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1: // Enqueue
            stack.check_empty();
            break;
        case 2:
            stack.check_isfull();
            break;
        case 3:
            int x;
            cout<<"enter x: ";
            cin>>x;
            stack.push(x);
            stack.display();
            break;
        case 4: 
            stack.pop();
            stack.display();
            break;
        case 5: 
            stack.printhead();
            break;
        default:
            cout << "Invalid choice!\n";
        }
    } while (true);  

    return 0;
}
