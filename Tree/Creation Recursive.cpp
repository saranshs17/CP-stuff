class Node{
    public:
    int data;
    Node* left,*right;
    Node(int val){
        data=val;
        left=NULL;
        right=NULL;
    }
};
int32_t main() {
    //sieve();
    // SPF();
    sped
    int t;
    t=1;
    while(t--) {
        cout<<"Enter the root element:\n";
        int x;cin>>x;
        queue<Node*> q;
        Node * root = new Node(x);
        q.push(root);
        while(!q.empty()){
            Node * temp = q.front();
            q.pop();
            cout<<"Enter left child \n";
            int first;cin>>first;
            if(first!=-1){
                temp->left = new Node(first);
                q.push(temp->left);
            }
            cout<<"Enter right child \n";
            int second;cin>>second;
            if(second!=-1){
                temp->right = new Node(second);
                q.push(temp->right);
            }
        }
    }
    return 0;
}
