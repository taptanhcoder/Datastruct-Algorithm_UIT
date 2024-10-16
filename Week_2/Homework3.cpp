#include <iostream>
#include <vector>
#include <stack>
using namespace std;

vector<int> Problem (const vector<int>& heights) {
    int n = heights.size();
    vector<int> answer(n, 0);  
    stack<int> s;               

 
    for (int i = n - 1; i >= 0; --i) {

        while (!s.empty() && heights[s.top()] < heights[i]) {
            s.pop(); 
        }
        answer[i] = s.size();

        s.push(i);
    }

    return answer;
}

int main() {
    int n;
    cout << "Enter n: ";
    cin >> n;  
    vector<int> heights(n);  
    cout << "Input: ";
    for (int i = 0; i < n; i++) {
        cin >> heights[i];  
    }

    vector<int> result = Problem(heights); 
    cout << "Output: ";
    for (size_t i = 0; i < result.size(); ++i) {
        cout << result[i];
        if (i < result.size() - 1) cout << ", ";
    }
    return 0;
}