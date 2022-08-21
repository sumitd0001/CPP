#include <bits/stdc++.h>
using namespace std;

void max_heapify(vector<int>& vec, int size, int i) {
    int current = i;
    int leftchild = 2*i+1;
    int rightchild = 2*i+2;

    if(leftchild < size && vec[current] < vec[leftchild]) {
        current = leftchild;
    }
    if(rightchild < size && vec[current] < vec[rightchild]) {
        current = rightchild;
    }
    if(current!=i) {
        swap(vec[current], vec[i]);
        max_heapify(vec, size, current);
    }
}

void HeapSort(vector<int>& vec) {
    int size = vec.size();
    while(size > 0) {
        size--;
        swap(vec[0], vec[size]);
        max_heapify(vec, size, 0);
    }
}

int main () {

    vector<int> vec{5,8,3,7,1};
    
    for(int i = (5/2)-1; i>=0; --i) {
        max_heapify(vec, 5, i);
    }

    HeapSort(vec);

    for(const auto& x : vec) {
        cout<<x<<" ";
    }cout<<endl;

    return 0;
}