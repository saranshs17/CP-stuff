#include <bits/stdc++.h> 
class MinHeap{
    int * arr;
    int size;
    int total_size;
    public:
    MinHeap(int n){
        arr=new int[n];
        size=0;
        total_size=n;
    }
    void Insert(int data){
        if(size==total_size){
            return;
        }
        arr[size]=data;
        int index=size;
        size++;
        while(index>0 && arr[index]<arr[(index-1)/2]){
            swap(arr[index],arr[(index-1)/2]);
            index=(index-1)/2;
        }
    }
    void Heapify(int index){
        int smallest = index;
        int left=2*index+1;
        int right=2*index+2;
        if(left<size && arr[smallest]>arr[left]){
            smallest=left;
        }
        if(right<size && arr[smallest]>arr[right]){
            smallest=right;
        }
        if(smallest!=index){
            swap(arr[index],arr[smallest]);
            Heapify(smallest);
        }
    }
    int Top(){
        if(size==0)return 0;
        int top=arr[0];
        arr[0]=arr[size-1];
        size--;
        Heapify(0);
        return top;
    }
};
vector<int> minHeap(int n, vector<vector<int>>& q) {
    // Write your code here.
    MinHeap h(n);
    vector<int> ans;
    for(auto x:q){
        if(x[0]==1){
            ans.push_back(h.Top());
        }else{
            int data=x[1];
            h.Insert(data);
        }
    }
    return ans;
}
