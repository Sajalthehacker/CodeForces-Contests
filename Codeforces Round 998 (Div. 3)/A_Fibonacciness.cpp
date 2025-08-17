#include<bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin>>t;

    while(t--){
        int a1, a2, a4, a5;
        cin >> a1 >> a2 >> a4 >> a5;

        vector<int> b(3);
        b[0] = a1 + a2;
        b[1] = a4 - a2;
        b[2] = a5 - a4;

        sort(b.begin(), b.end());
        if(b[0] == b[2]){
            cout << 3 << "\n";
        }
        else if(b[0] == b[1] || b[1] == b[2]){
            cout << 2 << "\n";
        }
        else{
            cout << 1 << "\n";
        }
    }
    return 0;
}