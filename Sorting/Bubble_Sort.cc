#include <bits/stdc++.h>
using namespace std;

/*
Algorithm:
2 loops from 0th index to last
swap elements if left is greater than right
it always runs in O(n^2)

To optimize it,
if the inner loop doesn't cause any swaps, then stop there only
*/

void bubble_sort (vector<int>& vec) {
    for(auto itr = vec.begin(); itr!=vec.end(); ++itr) {
        for(auto itr2 = vec.begin(); itr2!=vec.end()-1; ++itr2) {
            if(*itr2 > *(itr2+1)) {
                swap(*itr2, *(itr2+1));
            }
        }
    }
}

int main () {

    vector<int> vec{1, 4, -1, 3, -10, 2, 19, 6, 84, -67};
    bubble_sort(vec);
    for(const auto& x : vec) {
        cout<<x<<" ";
    }cout<<endl;
    return 0;
}