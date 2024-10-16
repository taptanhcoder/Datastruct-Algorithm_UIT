#include <iostream>
#include <stack>
#include <string>

using namespace std;

class Browser {
private:
    stack<string> backStack;   
    stack<string> forwardStack; 
    string currentPage;     

public:

    void visit(const string& url) {
        if (!currentPage.empty()) {
            backStack.push(currentPage); 
        }
        currentPage = url;             
        while (!forwardStack.empty()) {  
            forwardStack.pop();
        }
        cout << "Visited: " << currentPage << endl;
    }


    string back() {
        if (backStack.empty()) {
            cout << "No more back history!" << endl;
            return currentPage;
        }
        forwardStack.push(currentPage);    
        currentPage = backStack.top();     
        backStack.pop();
        cout << "Back to: " << currentPage << endl;
        return currentPage;
    }

    string forward() {
        if (forwardStack.empty()) {
            cout << "No more forward history!" << endl;
            return currentPage;
        }
        backStack.push(currentPage);     
        currentPage = forwardStack.top();
        forwardStack.pop();
        cout << "Forward to: " << currentPage << endl;
        return currentPage;
    }
};

int main() {
    Browser browser;

    browser.visit("httt.uit.edu.vn");
    browser.visit("uit.edu.vn");
    browser.back();      
    browser.forward();    
    browser.visit("daa.uit.edu.vn");
    browser.back();       

    return 0;
}
