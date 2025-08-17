#include <iostream>
#include <vector>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }

        bool possible = true;
        for (int i = 0; i < n - 1; ++i) {
            if (a[i] > a[i + 1]) {
                possible = false;
                break;
            }
            else{
                int temp = min(a[i], a[i + 1]);
                a[i] -= temp;
                a[i + 1] -= temp;
            }
        }

        if (possible) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }

    return 0;
}
