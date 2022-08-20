#include <bits/stdc++.h>
using namespace std;

/*
Algo:
Start traversing from 1st elemnt
Keep the left array sorted and right unsorted, how?
Move the i-th elemnt at its correct position
Compare i and (i-1) index elements, if (i-1) > i, then swap and compare i-2 amd i-1
Proceed similarly you are swaping, stop if i > i-1
*/

void insertion_sort(vector<int>& vec) {
    for(auto itr1= vec.begin(); itr1!=vec.end(); ++itr1) {
        for(auto itr2 = itr1+1; itr2!=vec.begin(); --itr2) {
            if(*(itr2) < *(itr2-1)) {
                swap(*itr2, *(itr2-1));
            }
            else {
                break;
            }
        }
    }
}

int main () {
    vector<int> vec{1, 4, -1, 3, -10, 2, 19, 6, 84, -67};
    insertion_sort(vec);
    for(const auto& x : vec) {
        cout<<x<<" ";
    }cout<<endl;
    return 0;
}