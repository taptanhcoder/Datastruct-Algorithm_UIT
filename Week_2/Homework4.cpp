#include <iostream>
#include <vector>
using namespace std;

int minCoins(const vector<int>& prices) {
    int totalCost = 0; 
    int n = prices.size();
    for (int i = 0; i < n; ) {

        totalCost += prices[i];

        i += 2; 
        while (i < n && prices[i] <= prices[i - 1]) {
            i++; 
        }
    }
    return totalCost;
}

int main() {
    int n;
    cout<<"Enter n: ";
    cin>>n;
    vector<int> prices (n);
    cout<<"Input : ";
    for (int i=0;i<n;i++){
        cin>>prices[i];
    }
    cout << "Output: " << minCoins(prices) << endl;
    return 0;
}
