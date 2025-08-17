#include<bits/stdc++.h>
#include<unordered_set>
using namespace std;

int main() {
    int t;
    cin>>t;

    while(t--){
        int n, k;
        cin >> n >> k;

        vector<int> nums(n);
        for(int i = 0; i < n; i++){
            cin >> nums[i];
        }

        sort(nums.begin(), nums.end());
        int cnt = 0;

        int low = 0, high = n - 1;
        
        while(low < high){
            if(nums[low] + nums[high] == k){
                cnt++;
                low++;
                high--;
            }
            else if(nums[low] + nums[high] < k){
                low++;
            }
            else{
                high--;
            }
        }

        cout << cnt << "\n";
    }
    return 0;
}