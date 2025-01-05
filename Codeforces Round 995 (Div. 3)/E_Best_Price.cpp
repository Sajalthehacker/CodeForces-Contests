/*
earnings = number of trees selled * price per tree 

*/

#include<bits/stdc++.h>
using namespace std;

int solve(int n, int k, vector<int> &a, vector<int> &b, int neg, int price, int index){

    int noNeg = 0;
    if(price <= a[index]){
        noNeg = 1 + solve(n, k, a, b, neg, price, index + 1);
    }

    int neg = 0;
    else if(price <= b[index]){
        
    }
}

int main() {
    int t;
    cin>>t;

    while(t--){
        int n, k;
        cin >> n >> k;

        vector<int> a(n);
        vector<int> b(n);

        int maxPrice = INT_MIN;

        for(int i = 0; i < n; i++){
            cin >> a[i];
        }

        for(int i = 0; i < n; i++){
            cin>> b[i];
            maxPrice = max(maxPrice, b[i]);
        }

        int maxProfit = 0;

        for(int i = 1; i <= maxPrice; i++){
            maxProfit = max(maxProfit, solve(n, k, a, b, 0, i, 0) * i);
        }

        return maxProfit;
    }
    return 0;
}