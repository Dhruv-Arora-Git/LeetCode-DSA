// https://leetcode.com/problems/search-suggestions-system/

// https://leetcode.com/problems/search-suggestions-system/discuss/2171348/Simple-Brute-Force-or-Without-Trie-or-Sort-C%2B%2B

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<string>> suggestedProducts(vector<string> &products, string searchWord)
{

    vector<vector<string>> search;

    sort(products.begin(), products.end());

    string temp = "";

    for (int i = 0; i < searchWord.length(); ++i)
    {
        temp.push_back(searchWord[i]); // adding character one by one, to search

        vector<string> v;
        int cnt = 0;

        for (const string &a : products)
        {
            if (cnt == 3) // we need 3 words at max
                break;

            if (a.find(temp) == 0) // if string `starts with` temp
            {
                ++cnt;
                v.push_back(a);
            }
        }

        search.push_back(v);
    }

    return search;
}

int main()
{
    vector<string> products = {"mobile", "mouse", "moneypot", "monitor", "mousepad"};
    string searchWord = "mouse";

    vector<vector<string>> search = suggestedProducts(products, searchWord);

    for (vector<string> &v : search)
    {
        for (string &a : v)
            cout << a << " ";

        cout << "\n";
    }

    return 0;
}