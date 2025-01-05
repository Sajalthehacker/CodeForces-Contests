#include<bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin>>t;

    while(t--){
        int n;
        cin>>n;

        vector<int> a(n, 0); 
        vector<int> b(n, 0);

        for(int i = 0; i < n; i++){
            cin>>a[i];
        }

        for(int i = 0; i < n; i++){
            cin>>b[i];
        }

        int ans = 0;

        for(int i = 0; i < n; i++){
            int curr = 0;
            if(i + 1 < n){
                curr = a[i] - b[i + 1];
            }
            else{
                curr = a[i];
            }

            if(curr > 0){
                ans += curr;
            }
        }

        cout<<ans<<endl;
    }
    return 0;
}