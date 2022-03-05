#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fr(i, a, b) for(int i = a; i < b; i++)
#define g(a,b) __gcd(a,b)
#define lcm(a,b) (a*b)/g(a,b)
#define lb(v,key) lower_bound(v.begin(), v.end(), key)
#define ub(v,key) upper_bound(v.begin(), v.end(), key)
#define srt(v) sort(v.begin(), v.end())
#define mem(arr,key) memset(arr, key, sizeof(arr))


const int N = 1000000;
bool isPrime[N];
set<int> s;


void preCalculatorPrime(){
    fill(isPrime+2, isPrime+N, true);
    for(int i = 2; i*i < N; i++){
        for(int j = i*i; j < N; j=j+i)
            isPrime[j] = false;
    }
    for(int i = 2; i < N; i++){
        if(isPrime[i])
            s.insert(i);
    }
}


int max3(int a, int b, int c){
    if(a > b)
        return (a > c) ? a : c;
    else
        return (b > c) ? b : c;
}


int min3(int a, int b, int c){
    if(a < b)
        return (a < c) ? a : c;
    else
        return (b < c) ? b : c;
}

struct Node{
    int data;
    Node *left;
    Node *right;

    Node(int val){
        data = val;
        left = NULL;
        right = NULL;
    }
};

Node * createNode(int val){
    Node *ptr = new Node(val);
    return ptr;
}

Node * insertNode(Node * root, int val){
    if(root==NULL){
        Node *root = createNode(val);
        return root;
    }
    Node *temp;
    queue<Node*> q;
    q.push(root);
    while(!q.empty()){
        temp = q.front();
        q.pop();
        if(temp->left != NULL)  q.push(temp->left);
        else{
            temp->left = createNode(val);
            return root;
        }
        if(temp->right != NULL)  q.push(temp->right);
        else{
            temp->right = createNode(val);
            return root;
        }
    }
    return root;
}

Node * deleteNode(Node *root, int key){
    Node *temp;
    Node *deletedNode;
    queue<Node*> q;
    q.push(root);
    while(!q.empty()){
        temp = q.front();
        q.pop();
        if(temp->data == key){
            deletedNode = temp;
        }
        if(temp->left)  q.push(temp->left);
        if(temp->right) q.push(temp->right);
    }
    deletedNode->data = temp->data;
    delete(temp);
    return root;
}

bool treeContinuous(Node *root){
    if(root == NULL)    return true;
    if(!root->left && !root->right) return true;
    if(!root->left){
        return ((abs(root->data - root->right->data) == 1) && treeContinuous(root->right));
    }
    if(!root->right){
        return ((abs(root->data - root->left->data) == 1) && treeContinuous(root->left));
    }
    return ((abs(root->data - root->left->data) == 1) && treeContinuous(root->left) && (abs(root->data - root->right->data) == 1) && treeContinuous(root->right));
}

void printTree(Node *root){
    if(root == NULL)    return;
    cout<<root->data<<endl;
    printTree(root->left);
    printTree(root->right);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    struct Node *root = new Node(1);
    root = insertNode(root, 2);
    root = insertNode(root, 2);
    root = insertNode(root, 3);
    root = insertNode(root, 1);
    //printTree(root);
    //cout<<"After Deletion of keyNode: 2"<<endl;
    //root = deleteNode(root, 2);
    if(treeContinuous(root))    cout<<"YES";
    else    cout<<"NO";
    return 0;
}