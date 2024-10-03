#include<iostream>
using namespace std;

struct Node {
    int data;
    Node* next;

    Node(int value): data(value),next(NULL){}
};

class Queue{

    private:
    Node* head;
    Node* tail;
    int size;
    int capacity;

    public:
    Queue (int cap): head(NULL),tail(NULL),size(0),capacity(cap){}

    bool isEmpty() {
        return head == NULL;
    }


    void enqueue (int n){
        if (size>=capacity) {  
            cout << "Queue is full "; 
            return ;
        }
        Node* newnode = new Node(n);
        if(isEmpty()){
            head=tail=newnode;

        }else{
            tail->next=newnode;
            tail=newnode;
            size++;
        }
        
    }


    void dequeue(){
        if(isEmpty()){
            cout<<"Stact is empty";
        }
        
        Node* temp=head;
        head=head->next;
        size--;
        delete temp;

    }

    void display() {
        if (isEmpty()) {
            cout << "Stack is empty";
            return; 
        }
    
        Node* temp = head;
        while (temp != NULL) {
            cout << temp->data << " ";
            temp = temp->next;
        }
    }


    void check_empty() {
        if (isEmpty()) {
            cout << "true";
        } else {
            cout << "false";
        }
    }

    void check_isfull (){
        if (size<capacity){
            cout<<"false";
        }else {
            cout<<"true";
        }
    }

    void printFront() {
        if (isEmpty()) {
            cout << "Queue is empty\n";
        } else {
            cout << "Front element: " << head->data << endl;
        }
    }
    
    void printRear() {
        if (isEmpty()) {
            cout << "Queue is empty\n";
        } else {
            cout << "Rear element: " << tail->data << endl;
        }
    }
};


int main() {
    int cap;
    cout << "Enter the capacity: ";
    cin >> cap;

    Queue myQueue(cap);
    myQueue.enqueue(10);
    myQueue.enqueue(20);
    myQueue.enqueue(30); 

    int choice, value;
    do {
        cout<<endl;
        cout << "1. Enqueue\n";
        cout << "2. Dequeue\n";
        cout << "3. Display Queue\n";
        cout << "4. Print Front Element\n";
        cout << "5. Print Rear Element\n";
        cout << "6. Check if Queue is Empty\n";
        cout << "7. Check if Queue is Full\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1: 
            cout << "Enter the value to enqueue: ";
            cin >> value;
            myQueue.enqueue(value);
            myQueue.display();
            break;
        case 2:
            myQueue.dequeue();

            break;
        case 3:
            myQueue.display();
            break;
        case 4: 
            myQueue.printFront();
            break;
        case 5: 
            myQueue.printRear();
            break;
        case 6: 
            myQueue.check_empty();
            break;
        case 7:
            myQueue.check_isfull();
            break;
        case 8:
            cout << "Exit\n";
            break;
        default:
            cout << "Invalid choice!\n";
        }
    } while (true);  

    return 0;
}

