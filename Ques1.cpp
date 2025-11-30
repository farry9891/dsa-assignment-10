#include <iostream>
#include <unordered_map>
using namespace std;

int main() {
    int arr[] = {1, 2, 2, 4, 1};
    int n = sizeof(arr) / sizeof(arr[0]);

    unordered_map<int, int> freq;

    for (int i = 0; i < n; i++) {
        freq[arr[i]]++;
    }

    int ans = -1;
    int bestFreq = 0;

    for (auto p : freq) {
        int value = p.first;
        int count = p.second;

        if (count > bestFreq || 
           (count == bestFreq && value > ans)) {
            bestFreq = count;
            ans = value;
        }
    }

    cout << "Most frequent element: " << ans << endl;
    return 0;
}
