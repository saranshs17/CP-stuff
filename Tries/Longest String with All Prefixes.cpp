#include <bits/stdc++.h> 
struct Node{
    Node * links[26];
    bool flag=false;
    bool containsKey(char c){
        return links[c-'a']!=NULL;
    }
    void put(char c){
        links[c-'a']=new Node();
    }
    Node * next(char c){
        return links[c-'a'];
    }
    bool isEnd(){
        return flag;
    }
    void setEnd(){
        flag=true;
    }
};
class Trie{
    private: 
    Node * root;
    public:
    Trie(){
        root=new Node();
    }
    void Insert(string & word){
        Node * node=root;
        for(int i=0;i<word.size();++i){
            if(!node->containsKey(word[i])){
                node->put(word[i]);
            }
            node=node->next(word[i]);
        }
        node->setEnd();
    }
    bool search(string & word){
        Node * node=root;
        for(int i=0;i<word.size();++i){
            if(!node->containsKey(word[i]))return false;
            node=node->next(word[i]);
            if(node->isEnd()==false)return false;
        }
        return true;
    }
};
string completeString(int n, vector<string> &a){
    Trie obj;
    for(int i=0;i<n;++i){
        obj.Insert(a[i]);
    }
    string mx="";
    for(int i=0;i<n;++i){
        if(obj.search(a[i])){
            if(mx.size()<a[i].size()){
                mx=a[i];
            }else if(mx.size()==a[i].size() && mx>a[i]){
                mx=a[i];
            }
        }
    }
    return (mx=="")?"None":mx;
}
