class Solution {
public:
    struct Node{
        int count=0;
    };
    vector<Node> seg;
    vector<int> arr;
    int n;
    bool isPeak(int i){
        if(i==0 || i==n-1) return false;
        return arr[i+1]<arr[i] && arr[i-1]<arr[i];
    }
    void build(int index,int lo,int hi){
        if(lo==hi){
            seg[index].count=(isPeak(lo)?1:0);
            return;
        }
        int mid=lo+(hi-lo)/2;
        build(2*index+1,lo,mid);
        build(2*index+2,mid+1,hi);
        seg[index].count=seg[2*index+1].count+seg[2*index+2].count;
    }
    int query(int index,int lo,int hi,int l,int r){
        if(hi<l || r<lo) return 0;
        if(l<=lo && hi<=r) return seg[index].count;
        int mid=lo+(hi-lo)/2;
        int left=query(2*index+1,lo,mid,l,r);
        int right=query(2*index+2,mid+1,hi,l,r);
        return left+right;
    }
    void updateAtIndex(int index,int lo,int hi,int i,int val){
        if(lo==hi){
            seg[index].count=(isPeak(i)?1:0);
            return;
        }
        int mid=lo+(hi-lo)/2;
        if(i<=mid) updateAtIndex(2*index+1,lo,mid,i,val);
        else updateAtIndex(2*index+2,mid+1,hi,i,val);
        seg[index].count=seg[2*index+1].count+seg[2*index+2].count;
    }
    void update(int i,int val){
        arr[i]=val;
        updateAtIndex(0,0,n-1,i,val);
        if(i>0) updateAtIndex(0,0,n-1,i-1,arr[i-1]);
        if(i<n-1) updateAtIndex(0,0,n-1,i+1,arr[i+1]);
    }
    vector<int> countOfPeaks(vector<int>& nums, vector<vector<int>>& queries) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
        n=nums.size();
        arr=nums;
        seg.resize(4*n+1);
        build(0,0,n-1);
        int q=queries.size();
        vector<int> ans;
        for(auto q:queries){
            int type=q[0];
            if(type==1){
                int l=q[1],r=q[2];
                ans.push_back(query(0,0,n-1,l+1,r-1));
            }else{
                int index=q[1],val=q[2];
                update(index,val);
            }
        }
        return ans;
    }
};
