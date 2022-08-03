// https://leetcode.com/problems/my-calendar-i/

// https://leetcode.com/problems/my-calendar-i/discuss/2373508/C%2B%2B-Clean-Code-with-HashMap-or-Explained-with-Comments

#include <iostream>
#include <unordered_map>

using namespace std;

class MyCalendar
{
private:
    unordered_map<int, int> mp;

public:
    bool book(int start, int end)
    {
        for (auto &it : mp)
        {
            // checking for bounds
            if ((start > it.first && start < it.second) || (end > it.first && end < it.second) || (start == it.first) || (end == it.second) || (start < it.first && end > it.second))
            {
                return false;
            }
        }
        // if it's not overlapping, add it in the HashMap
        mp.insert({start, end});

        return true;
    }
};

int main()
{
    // ["MyCalendar","book","book","book","book","book","book","book","book","book","book"]
    // [ [], [ 47, 50 ], [ 33, 41 ], [ 39, 45 ], [ 33, 41 ], [ 32, 41 ], [ 26, 35 ], [ 19, 25 ], [ 3, 8 ], [ 8, 13 ], [ 18, 27 ] ] return 0;
    // true true false false false false true true true false
    MyCalendar myCalendar;

    cout << boolalpha;

    cout << myCalendar.book(47, 50) << " ";
    cout << myCalendar.book(33, 41) << " ";
    cout << myCalendar.book(39, 45) << " ";
    cout << myCalendar.book(33, 41) << " ";
    cout << myCalendar.book(32, 41) << " ";
    cout << myCalendar.book(26, 35) << " ";
    cout << myCalendar.book(19, 25) << " ";
    cout << myCalendar.book(3, 8) << " ";
    cout << myCalendar.book(8, 13) << " ";
    cout << myCalendar.book(18, 27) << "\n";
}