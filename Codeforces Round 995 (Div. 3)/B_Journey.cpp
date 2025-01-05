#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin>>t;

    while(t--){
        int n, a, b, c;
        cin>>n>>a>>b>>c;

        int total = a + b + c;

        int cycles = n / total;
        int cnt = cycles * total;
        int day = cycles * 3;

        while (cnt < n) {
            if (day % 3 == 0) {
                cnt += a;
            } else if (day % 3 == 1) {
                cnt += b;
            } else {
                cnt += c;
            }
            day++;
        }

        cout << day << endl;
    }

    return 0;
}
