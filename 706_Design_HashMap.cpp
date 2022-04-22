#include <iostream>
#include <vector>

using namespace std;

class MyHashMap
{
private:
    vector<int> data = vector<int>(1000001, -1);

public:
    void put(int key, int val)
    {
        data[key] = val;
    }

    int get(int key)
    {
        return data[key];
    }

    void remove(int key)
    {
        data[key] = -1;
    }
};

int main()
{
    MyHashMap hashMap;
    hashMap.put(1, 1);
    hashMap.put(2, 2);
    cout << hashMap.get(1) << endl;
    cout << hashMap.get(2) << endl;
    hashMap.put(3, 5);
    cout << hashMap.get(3) << endl;
    hashMap.remove(2);
    cout << hashMap.get(2) << endl;

    return 0;
}