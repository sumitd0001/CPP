#include <bits/stdc++.h>
using namespace std;

/*
Algo:
Given an unsorted array, needs to sort it
Start from the 0th index, and find the minimum in the array and swap it with the 0the index
Then, on to 1st index, find the minimum of the elemnts left, and swap it with the 1st index 
||ly proceed till last
*/

void selection_sort(vector<int>& vec) {
    for(auto itr = vec.begin(); itr!=vec.end(); ++itr) {
        auto itr3 = itr;
        for(auto itr2 = itr+1; itr2!=vec.end(); ++itr2) {
            if(*itr3 > *itr2) {
                itr3 = itr2;
            }
        }
        swap(*itr, *itr3);
    }
}

int main () {

    vector<int> vec{1, 4, -1, 3, -10, 2, 19, 6, 84, -67};
    selection_sort(vec);
    for(const auto& x : vec) {
        cout<<x<<" ";
    }cout<<endl;
    return 0;
}