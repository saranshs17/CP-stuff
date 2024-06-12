#include<bits/stdc++.h>
using namespace std;
class MaxHeap{
    int * arr;
    int size; // current size i.e. number of elements
    int total_size; // total space occupied 
    public:
    MaxHeap(int n){
        arr=new int[n];
        size = 0;
        total_size=n;
    }
    void insert(int data){
        if(size==total_size){
            cout<<"Heap Overflow\n";
            return;
        }
        arr[size]=data; // insert at last 
        // Now Heapify last element by comparing with its parent i.e. Bottom-up
        int index=size;
        size++;
        while(index>0 && arr[index]>arr[(index-1)/2]){
            swap(arr[index],arr[(index-1)/2]);
            index=(index-1)/2;
        }
        cout<<arr[index]<<" inserted into the heap\n";
    }
    void Delete(){
        // always delete the root
        if(size==0){
            cout<<"Heap Underflow\n";
            return;
        }
        cout<<arr[0]<<" deleted from heap\n";
        arr[0]=arr[size-1];
        size--;
        // now heapify the root by comparing with child , Top-Down
        Heapify(0);
        
    }
    void Heapify(int index){
        int largest=index; // store the largest among curr,left, right child
        int left=2*index+1;
        int right=2*index+2;
        if(left<size && arr[largest]<arr[left]){
            largest=left;
        }
        if(right<size && arr[largest]<arr[right]){
            largest=right;
        }
        if(largest!=index){
            swap(arr[index],arr[largest]);
            Heapify(largest); // as now largest is pointing to least element
        }
    }
    void print(){
        for(int i=0;i<size;++i){
            cout<<arr[i]<<" ";
        }
        cout<<'\n';
    }
};
int main(){
    MaxHeap h1(6);
    h1.insert(1);
    h1.insert(2);
    h1.insert(3);
    h1.print();
    h1.Delete();
    h1.print();
}
