#include <iostream>
#include <stack>

using namespace std;


void print(stack<int> tower, const string& towerName) {
    stack<int> temp = tower;
    cout << "Tower " << towerName << ": ";
    stack<int> reversed;
    
    while (!temp.empty()) {
        reversed.push(temp.top());
        temp.pop();
    }
    
    while (!reversed.empty()) {
        cout << reversed.top() << " ";
        reversed.pop();
    }
    cout << endl;
}


void towerHanoi(int n, stack<int> towers[], int from, int to, int aux, int& step) {
    if (n == 0) return; 
    towerHanoi(n - 1, towers, from, aux, to, step);

    towers[to].push(towers[from].top());
    towers[from].pop();
    step++;
    cout << step << " : " << (char)('A' + from) << " -> " << (char)('A' + to) << endl;
    towerHanoi(n - 1, towers, aux, to, from, step);
}

int main() {
    int N; 
    cout << "Enter the number of disks: ";
    cin >> N;

    stack<int> towers[3];

    for (int i = N; i >= 1; i--) {
        towers[0].push(i);
    }
    print(towers[0], "A");
    int moveCount = 0;
    towerHanoi(N, towers, 0, 2, 1, moveCount); 
    print(towers[2], "C");

    return 0;
}
