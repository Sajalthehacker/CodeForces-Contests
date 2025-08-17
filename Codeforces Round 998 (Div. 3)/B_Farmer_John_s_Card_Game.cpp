#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> decks(n, vector<int>(m));

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cin >> decks[i][j];
            }
            sort(decks[i].begin(), decks[i].end());
        }

        if (n == 1)
        {
            cout << 1 << "\n";
            continue;
        }

        vector<int> permutation;
        vector<int> pointers(n, 0);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

        for (int i = 0; i < n; i++)
        {
            pq.push({decks[i][pointers[i]], i});
            pointers[i]++;
        }

        int totalRounds = m;
        int topCard = -1;
        bool isPossible = true;
        int lastCowPlayed = -1;

        for (int round = 0; round < totalRounds; round++)
        {
            vector<pair<int, int>> nextCards;
            while (!pq.empty())
            {
                int card = pq.top().first;
                int cowId = pq.top().second;
                pq.pop();

                if (card != topCard + 1 || lastCowPlayed == cowId)
                {
                    isPossible = false;
                    break;
                }

                topCard = card;
                permutation.push_back(cowId);
                if (pointers[cowId] < m)
                {
                    nextCards.push_back({decks[cowId][pointers[cowId]], cowId});
                    pointers[cowId]++;
                }
                lastCowPlayed = cowId;
            }

            if (!isPossible)
            {
                break;
            }

            for (auto it : nextCards)
            {
                pq.push({it.first, it.second});
            }
        }

        if (isPossible)
        {
            for (int i = 0; i < n; i++)
            {
                cout << permutation[i] + 1 << " ";
            }
            cout << endl;
        }
        else
        {
            cout << -1 << endl;
        }
    }
    return 0;
}