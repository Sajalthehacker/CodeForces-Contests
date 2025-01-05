#include<bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin>>t;

    while(t--){
        long long n, x, y;
        cin >> n >> x >> y;

        vector<long long> arr(n);
        long long sum = 0;

        for(int i = 0; i < n; i++){
            cin >> arr[i];
            sum += arr[i];
        }

        long long cnt = 0;
        long long L = sum - y, R = sum - x;
        sort(arr.begin(), arr.end());

        for(int i = 0; i < n; i++){
            long long left = lower_bound(arr.begin(), arr.end(), L - arr[i]) - arr.begin();
            long long right = upper_bound(arr.begin(), arr.end(), R - arr[i]) - arr.begin();

            cnt += max(0, right - left);
            // if i lies in the range [l, r - 1]
            if(left <= i && i < right){
                cnt--;
            }
        }

        // as each pair is counted twice
        cnt = cnt / 2;

        cout << cnt << endl;
    }
    return 0;
}
