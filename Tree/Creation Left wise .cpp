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
Node * BinaryTree(){
    int x;cin>>x;
    if(x==-1)return NULL;
    Node * temp= new Node(x);
    cout<<"Enter Left Child of "<<x<<'\n';
    temp->left = BinaryTree();
    cout<<"Enter Right Child of "<<x<<'\n';
    temp->right = BinaryTree();
    return temp;
}
int32_t main() {
    //sieve();
    // SPF();
    sped
    int t;
    t=1;
    while(t--) {
        cout<<"Enter the root element:\n";
        Node * root = BinaryTree();
    }
    return 0;
}
