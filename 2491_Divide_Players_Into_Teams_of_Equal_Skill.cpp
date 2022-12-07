// https://leetcode.com/problems/divide-players-into-teams-of-equal-skill/description/

// https://leetcode.com/problems/divide-players-into-teams-of-equal-skill/solutions/2885860/c-sort-2-pointers-approach-discussed/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

long long dividePlayers(vector<int> &skill)
{
    sort(skill.begin(), skill.end());

    long long chemistry = 0;
    int n = skill.size();
    int i = 0, j = n - 1;
    int sum = 0;

    while (i < j)
    {
        int localSum = skill[i] + skill[j];
        if (sum == 0)
        {
            sum = localSum;
            chemistry += (skill[i] * skill[j]);
        }
        else if (localSum != sum)
        {
            return -1;
        }
        else if (localSum == sum)
        {
            chemistry += (skill[i] * skill[j]);
        }
        ++i, --j;
    }

    return chemistry;
}

int main()
{
    vector<int> skill = {3, 2, 5, 1, 3, 4};

    cout << dividePlayers(skill) << "\n";

    return 0;
}