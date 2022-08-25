// https://leetcode.com/problems/time-needed-to-inform-all-employees/

// https://leetcode.com/problems/time-needed-to-inform-all-employees/discuss/2476609/The-Strange-Test-Case-Explained!-oror-BFS-with-Contextual-Variable-Names-C%2B%2B

#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>

using namespace std;

class Employee
{
public:
    int id;
    int time;

    Employee() {}

    Employee(int id, int time)
    {
        this->id = id;
        this->time = time;
    }
};

class Solution
{
public:
    int numOfMinutes(int n, int headID, vector<int> &manager, vector<int> &informTime)
    {
        if (n == 1)
            return informTime[0];

        unordered_map<int, vector<Employee>> employeeTree;

        for (int i = 0; i < n; ++i)
        {
            employeeTree[manager[i]].push_back(Employee(i, informTime[i]));
        }

        int totalTime = 0;

        queue<Employee> q;

        q.push(Employee(headID, informTime[headID]));

        while (!q.empty())
        {
            int size = q.size();
            Employee currEmployee;

            int maxTime = 0;

            while (size--)
            {
                currEmployee = q.front();
                q.pop();

                for (Employee &junior : employeeTree[currEmployee.id])
                {
                    junior.time += currEmployee.time;

                    maxTime = max(maxTime, junior.time);
                    q.push(junior);
                }
            }
            totalTime = max(totalTime, maxTime);
        }

        return totalTime;
    }
};

int main()
{
    /*
        n = 11
        headID = 4
        manager = [5,9,6,10,-1,8,9,1,9,3,4]
        informTime = [0,213,0,253,686,170,975,0,261,309,337]


                4     686
               /
              10     337
              /
             3     253
             /
             9      309
            /|\
           8 6 1    261     975     231
          /  |  \
          5  2   7  170      0      0
         /
        0              0

        After seeing the Tree, you will realise that there is no need to add 170 at last,
        as each employee has it's own time, and will not wait for all other Employees( of same level),
        as soon as his time is complete, he will send the message down to his respective juniors (level -1)
    */
    int n = 11,
        headID = 4;

    vector<int> informTime = {0, 213, 0, 253, 686, 170, 975, 0, 261, 309, 337},
                manager = {5, 9, 6, 10, -1, 8, 9, 1, 9, 3, 4};

    Solution obj;
    cout << obj.numOfMinutes(n, headID, manager, informTime) << "\n";

    return 0;
}