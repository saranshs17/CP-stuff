/*
    Your Trie object will be instantiated and called as such:
    Trie* obj = new Trie();
    obj->insert(word);
    bool check2 = obj->search(word);
    bool check3 = obj->startsWith(prefix); 
 */

struct Node{
    Node * links[26];
    bool flag=false;
    bool containsKey(char c){
        return links[c-'a']!=NULL;
    }
    void put(char c,Node * node){
        links[c-'a']=node;
    }
    Node * next(char c){
        return links[c-'a'];
    }
    bool isEnd(){
        return flag==true;
    }
};
class Trie {
private: Node * root;
public:

    /** Initialize your data structure here. */
    Trie() {
        root=new Node();
    }

    /** Inserts a word into the trie. */
    void insert(string word) {
        Node * node=root;
        for(int i=0;i<word.size();++i){
            if(!node->containsKey(word[i])){
                node->put(word[i],new Node());
            }
            node=node->next(word[i]);
        }
        node->flag=true;
    }

    /** Returns if the word is in the trie. */
    bool search(string word) {
        Node * node=root;
        for(int i=0;i<word.size();++i){
            if(!node->containsKey(word[i])) return false;
            node=node->next(word[i]);
        }
        return node->isEnd();
    }

    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        Node * node=root;
        for(int i=0;i<prefix.size();++i){
            if(!node->containsKey(prefix[i])) return false;
            node=node->next(prefix[i]);
        }
        return true;
    }
};
