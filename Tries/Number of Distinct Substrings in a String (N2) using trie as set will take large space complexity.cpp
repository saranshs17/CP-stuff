struct Node{
    Node * links[26];
    bool containsKey(char c){
        return links[c-'a']!=NULL;
    }
    void put(char c){
        links[c-'a']=new Node();
    }
    Node * next(char c){
        return links[c-'a'];
    }
};
class Trie{
    private: 
    Node * root;
    public:
    int ct=0;
    Trie(){
        root=new Node();
    }
    void Insert(string & word){
        Node * node=root;
        for(int i=0;i<word.size();++i){
            if(!node->containsKey(word[i])){
                node->put(word[i]);
                ct++;
            }
            node=node->next(word[i]);
        }
    }
};
int countDistinctSubstrings(string &s)
{
    Trie obj;
    for(int i=0;i<s.size();++i){
        string sub=s.substr(i,s.size()-i+1);
        obj.Insert(sub);
    }
    return obj.ct+1;   
}
