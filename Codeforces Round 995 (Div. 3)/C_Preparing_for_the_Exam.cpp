#include<bits/stdc++.h>
using namespace std;

void print(vector<int> ans){
    for(auto i: ans){
        cout<<i;
    }
    cout<<endl;
}

int main() {
    int t;
    cin >> t;

    while(t--){
        int n, m, k;
        cin >> n >> m >> k;

        vector<int> am(m);
        for(int i = 0; i < m; i++){
            cin>>am[i];
        }

        vector<int> qk(k);
        for(int i = 0; i < k; i++){
            cin>>qk[i];
        }

        unordered_set<int> st;
        for(int i = 1; i <= n; i++){
            st.insert(i);
        }

        for(auto i: qk){
            if(st.find(i) != st.end()){
                st.erase(i);
            }
        }

        vector<int> ans(m, 0);

        if(st.size() >= 2){
            print(ans);
        }

        else if(st.size() == 0){
            fill(ans.begin(), ans.end(), 1);
            print(ans);
        }

        else{
            for(int i = 0; i < m; i++){
                if(st.find(am[i]) != st.end()){
                    ans[i] = 1;
                }
            }
            print(ans);
        }
    }
    return 0;
}