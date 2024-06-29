struct Node{
    Node * links[2];
    bool containskey(int bit){
        return links[bit]!=NULL;
    }
    void put(int bit){
        links[bit]=new Node();
    }
    Node * next(int bit){
        return links[bit];
    }
};
class Trie{
    private: 
    Node * root;
    public:
    Trie(){
        root=new Node();
    }
    void Insert(int num){
        Node * node=root;
        for(int i=31;i>=0;--i){
            int bit=(num>>i)&1;
            if(!node->containskey(bit)){
                node->put(bit);
            }
            node=node->next(bit);
        }
    }
    int getMax(int num){
        Node * node=root;
        int mxxor=0;
        for(int i=31;i>=0;--i){
            int bit=(num>>i)&1;
            if(node->containskey(1-bit)){
                mxxor|=(1<<i);
                node=node->next(1-bit);
            }else{
                node=node->next(bit);
            }
        }
        return mxxor;
    }
};
class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        Trie trie;
        for(int i=0;i<nums.size();++i){
            trie.Insert(nums[i]);
        }
        int ans=0;
        for(auto x:nums){
            ans=max(ans,trie.getMax(x));
        }
        return ans;
    }
};
