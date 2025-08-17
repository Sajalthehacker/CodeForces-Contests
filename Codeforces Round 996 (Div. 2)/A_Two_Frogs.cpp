#include <bits/stdc++.h>
using namespace std;

bool solve(vector<int> &pads, int n, int a, int b, int player) {
    if (a == b) {
        return false;  // If Alice and Bob occupy the same position, Alice loses
    }

    if (player == 1) {  // Alice's turn
        bool ans1 = false, ans2 = false;
        // Check move to the left
        if (a - 1 >= 1 && pads[a - 1] == 0) {
            pads[a - 1] = 1;  // Alice moves here
            pads[a] = 0;
            ans1 = solve(pads, n, a - 1, b, 2);  // Now it's Bob's turn
            pads[a] = 1;  // Reset Alice's position
            pads[a - 1] = 0;
        }
        // Check move to the right
        if (a + 1 <= n && pads[a + 1] == 0) {
            pads[a + 1] = 1;  // Alice moves here
            pads[a] = 0;
            ans2 = solve(pads, n, a + 1, b, 2);  // Now it's Bob's turn
            pads[a] = 1;  // Reset Alice's position
            pads[a + 1] = 0;
        }

        return ans1 || ans2;  // If any move results in a win, return true
    } else {  // Bob's turn
        bool ans1 = false, ans2 = false;
        // Check move to the left
        if (b - 1 >= 1 && pads[b - 1] == 0) {
            pads[b - 1] = 2;  // Bob moves here
            pads[b] = 0;
            ans1 = solve(pads, n, a, b - 1, 1);  // Now it's Alice's turn
            pads[b] = 2;  // Reset Bob's position
            pads[b - 1] = 0;
        }
        // Check move to the right
        if (b + 1 <= n && pads[b + 1] == 0) {
            pads[b + 1] = 2;  // Bob moves here
            pads[b] = 0;
            ans2 = solve(pads, n, a, b + 1, 1);  // Now it's Alice's turn
            pads[b] = 2;  // Reset Bob's position
            pads[b + 1] = 0;
        }

        return ans1 || ans2;  // If any move results in a win, return true
    }
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n, a, b;
        cin >> n >> a >> b;

        vector<int> pads(n + 1, 0);  // Initialize all lilypads as empty (0)
        pads[a] = pads[b] = 1;  // Mark Alice's and Bob's initial positions

        if (solve(pads, n, a, b, 1)) {
            cout << "YES" << endl;  // Alice can guarantee a win
        } else {
            cout << "NO" << endl;  // Alice cannot guarantee a win
        }
    }

    return 0;
}
