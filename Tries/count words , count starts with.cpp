#include <bits/stdc++.h> 
struct Node{
    Node * links[26];
    int ctpre=0;
    int ctendwith=0;
    void put(char c){
        links[c-'a']=new Node();
    }
    bool containsKey(char c){
        return links[c-'a']!=NULL;
    }
    Node * next(char c){
        return links[c-'a'];
    }
    int getEndct(){
        return ctendwith;
    }
    int getPrect(){
        return ctpre;
    }
    void increasePre(){
        ctpre++;
    }
    void increaseEnd(){
        ctendwith++;
    }
    void decreasePre(){
        ctpre--;
    }
    void decreaseEnd(){
        ctendwith--;
    }
};
class Trie{
    private: Node * root;
    public:

    Trie(){
        root=new Node();
    }

    void insert(string &word){
        Node * node = root;
        for(int i=0;i<word.size();++i){
            if(!node->containsKey(word[i])){
                node->put(word[i]);
            }
            node=node->next(word[i]);
            node->increasePre();
        }
        node->increaseEnd();
    }

    int countWordsEqualTo(string &word){
        Node * node=root;
        for(int i=0;i<word.size();++i){
            if(!node->containsKey(word[i])) return 0;
            node=node->next(word[i]);
        }
        return node->getEndct();
    }

    int countWordsStartingWith(string &word){
        Node * node=root;
        for(int i=0;i<word.size();++i){
            if(!node->containsKey(word[i])) return 0;
            node=node->next(word[i]);
        }
        return node->getPrect();
    }

    void erase(string &word){
        Node * node = root;
        for(int i=0;i<word.size();++i){
            node=node->next(word[i]);
            node->decreasePre();
        }
        node->decreaseEnd();
    }
};
