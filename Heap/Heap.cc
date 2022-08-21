#include <bits/stdc++.h>
using namespace std;

class Heap {
    vector<int> maxheap;
    vector<int> minheap;
    //int size;

public: 

    Heap () {
        maxheap.push_back(INT_MIN);
        minheap.push_back(INT_MAX);
    }

    int getmaxheapsize() {
        return maxheap.size();
    }

    int getminheapsize() {
        return minheap.size();
    }

    void insert_maxheap(int val) {
        maxheap.push_back(val);
        int index = getmaxheapsize()-1;
        //index is the index of child, only parent can be at 1 index, 
        //so for 'index', we don't need to check for index > 0
        while(index > 1) {
            int parent = index/2;
            if(maxheap[index] > maxheap[parent]) {
                swap(maxheap[index], maxheap[parent]);
                index = parent;
            }
            else return;  
        }    
    }

    void insert_minheap(int val) {
        minheap.push_back(val);
        int index = getminheapsize()-1;
        //index is the index of child, only parent can be at 1 index, 
        //so for 'index', we don't need to check for index > 0
        while(index > 1) {
            int parent = index/2;
            if(minheap[index] < minheap[parent]) {
                swap(minheap[index], minheap[parent]);
                index = parent;
            }
            else return;    
        }    
    }

    void delete_maxheap() {
        if((getmaxheapsize()-1)==0) {
            return;
        }
        int index = getmaxheapsize()-1;
        swap(maxheap[index], maxheap[1]);
        auto itr = maxheap.end();
        maxheap.erase(--itr);
        index = 1;
        while(index <= getmaxheapsize()-1) {
            int leftindex = 2*index;
            int rightindex = 2*index+1;
            if(leftindex <= getmaxheapsize()-1 && rightindex <= getmaxheapsize()-1) {
                if(maxheap[leftindex] < maxheap[rightindex]) {
                    swap(maxheap[index], maxheap[rightindex]);
                    index = rightindex;
                }
                else {
                    swap(maxheap[index], maxheap[leftindex]);
                    index = leftindex;
                }
            
            }
            else return;
        }
    }

    void delete_minheap() {
        if((getminheapsize()-1)==0) {
            return;
        }
        int index = getminheapsize()-1;
        swap(minheap[index], minheap[1]);
        auto itr = minheap.end();
        minheap.erase(--itr);
        index = 1;
        while(index <= getminheapsize()-1) {
            int leftindex = 2*index;
            int rightindex = 2*index+1;
            if(leftindex <= getminheapsize()-1 && rightindex <= getminheapsize()-1) {
                if(minheap[leftindex] > minheap[rightindex]) {
                    swap(minheap[index], minheap[rightindex]);
                    index = rightindex;
                }
                else {
                    swap(minheap[index], minheap[leftindex]);
                    index = leftindex;
                }
            }
            else return;
        }
    }

    void print_maxheap() {
        for(auto itr = (maxheap.begin())+1; itr!=maxheap.end(); ++itr) {
            cout<<*itr<<" ";
        }cout<<endl;
    }

    void print_minheap() {
        for(auto itr = minheap.begin()+1; itr!=minheap.end(); ++itr) {
            cout<<*itr<<" ";
        }cout<<endl;
    }

};

void max_heapify (vector<int>& vec, int size, int i) {
        int current = i;
        int leftchild = 2*i+1;
        int rightchild = 2*i+2;

        if(leftchild < size && vec[leftchild] > vec[current]) {
            current = leftchild;
        }
        if(rightchild < size && vec[rightchild] > vec[current]) {
            current = rightchild;
        }
        if(current != i) {
            swap(vec[current], vec[i]);
            max_heapify(vec, size, current);
        }
}

void HeapSort (vector<int>& vec, int size) {
    while(size>0) {
        --size;
        swap(vec[0],vec[size]);
        max_heapify(vec, size, 0);
    }
}

int main () {

    Heap h;
    cout<<"Max Heap"<<endl;
    h.insert_maxheap(50);
    h.insert_maxheap(55);
    h.insert_maxheap(54);
    h.insert_maxheap(52);
    h.insert_maxheap(53);
    h.print_maxheap();

    cout<<"Min Heap"<<endl;
    h.insert_minheap(54);
    h.insert_minheap(52);
    h.insert_minheap(53);
    h.insert_minheap(55);
    h.insert_minheap(50);
    h.print_minheap();

    cout<<"After deleting from Max Heap"<<endl;
    h.delete_maxheap();
    h.print_maxheap();

    cout<<"After deleting from Min Heap"<<endl;
    h.delete_minheap();
    h.print_minheap();

    cout<<"Max Heapify"<<endl;
    
    vector<int> v{54, 55, 53, 52, 50};
    for(int i = (5/2)-1; i >= 0; --i) {
        max_heapify(v, 5, i);
    }
    for(auto i = v.begin(); i!=v.end(); ++i) {
        cout<<*i<<" ";
    }cout<<endl;

    cout<<"Heap Sort"<<endl;
    vector<int> v2{5, 4 ,3, 2, 1};
    //Heap Creation
    for(int i = (5/2)-1; i >= 0; --i) {
        max_heapify(v2, 5, i);
    }
    HeapSort(v2, 5);
    for(int i = 0; i<5; ++i) {
        cout<<v2[i]<<" ";
    }cout<<endl;

    return 0;
}