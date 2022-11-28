// https://leetcode.com/problems/find-players-with-zero-or-one-losses/

// https://leetcode.com/problems/find-players-with-zero-or-one-losses/discuss/2856999/C%2B%2B-Simple-Map-oror-Explained-with-Comments

#include <iostream>
#include <vector>
#include <map>

using namespace std;

vector<vector<int>> findWinners(vector<vector<int>> &matches)
{
    vector<vector<int>> winners;

    // team -> wins, loses
    map<int, pair<int, int>> standings;

    for (const auto &match : matches)
    {
        // winner - increase no. of wins
        ++standings[match[0]].first;

        // loser - increase no. of losses
        ++standings[match[1]].second;
    }

    vector<int> lostZeroMatches, lostOneMatch;

    for (const auto &scores : standings)
    {
        if (scores.second.second == 0)
            lostZeroMatches.push_back(scores.first);

        if (scores.second.second == 1)
            lostOneMatch.push_back(scores.first);
    }

    winners.push_back(lostZeroMatches);
    winners.push_back(lostOneMatch);

    return winners;
}

int main()
{
    vector<vector<int>> matches = {{1, 3}, {2, 3}, {3, 6}, {5, 6}, {5, 7}, {4, 5}, {4, 8}, {4, 9}, {10, 4}, {10, 9}};

    vector<vector<int>>
        winners = findWinners(matches);

    for (const auto &winner : winners)
    {
        for (const auto &team : winner)
            cout << team << " ";

        cout << "\n";
    }

    return 0;
}