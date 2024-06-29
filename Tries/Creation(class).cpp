/*
    Your Trie object will be instantiated and called as such:
    Trie* obj = new Trie();
    obj->insert(word);
    bool check2 = obj->search(word);
    bool check3 = obj->startsWith(prefix);
 */

class Node{
    private:
    Node ** links;
    bool flag;
    public:
    Node(){
        links=new Node*[26];
        flag=false;
    }
    bool containsKey(char c){
        return links[c-'a']!=nullptr;
    }
    void put(char c,Node * node){
        links[c-'a']=node;
    }
    Node * next(char c){
        return links[c-'a'];
    }
    void setEnd(){
        flag=true;
    }
    bool isEnd(){
        return flag;
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
        node->setEnd();
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
