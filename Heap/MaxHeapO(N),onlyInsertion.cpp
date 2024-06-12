#include<bits/stdc++.h>
using namespace std;
void Heapify(int index,int arr[],int size){
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
            Heapify(largest,arr,size); // as now largest is pointing to least element
        }
}
int main(){
    int arr[3]={1,2,3};
    int n=3;
    // n-1 is index of last leaf node so its parent index will be ((n-1)-1)/2 => (n-2)/2 => n/2-1
    for(int i=n/2-1;i>=0;--i){
        Heapify(i,arr,n);
    }
    for(int i=0;i<n;++i){
        cout<<arr[i]<<" ";
    }
    cout<<'\n';
    priority_queue<int> pq(arr,arr+n); // O(N) me create ho jayega if convert whole array at once , but if inserted 1/1 then take NlogN
    while(!pq.empty()){
        cout<<pq.top()<<" ";
        pq.pop();
    }
}
