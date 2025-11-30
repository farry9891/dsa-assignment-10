#include <iostream>
#include <unordered_map>
using namespace std;

int main() {
    int arr[] = {2, 3, 2, 4, 3, 2};
    int n = 6;

    unordered_map<int,int> freq;

    for (int x : arr)
        freq[x]++;

    for (auto p : freq)
        cout << p.first << " → " << p.second << " times\n";

    cout << endl;
}
