#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    
    int data;
    Node* left;
    Node* right;

    Node(int data){
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};


bool isLeaf(Node* root){
    return (!root->left) && (!root->right);
}

void addLeftBoundary(Node* root,vector<int>& res){
    Node* curr = root->left;

    while(curr){
        if(!isLeaf(curr)) res.push_back(curr->data);

        if(curr->left) curr = curr->left;
        else curr = curr->right;
    }
}

void addLeaves(Node* root,vector<int>& res){
    if(isLeaf(root)) res.push_back(root->data);

    if(root->left) addLeaves(root->left,res);
    if(root->right) addLeaves(root->right,res);
}


void addRightBoundary(Node* root,vector<int>& res){
    Node* curr = root->right;
    vector<int> temp;

    while(curr){
        if(!isLeaf(curr)) temp.push_back(curr->data);

        if(curr->right) curr = curr->right;
        else curr = curr->left;
    }

    for(int i=temp.size()-1;i>=0;i--){
        res.push_back(temp[i]);
    }
}


vector<int> boundaryTraversal(Node* root){
    vector<int> res;
    if(root == NULL) return res;

    if(!isLeaf(root)) res.push_back(root->data);

    addLeftBoundary(root,res);
    addLeaves(root,res);
    addRightBoundary(root,res);

    return res;
}


int main(){
    Node* root = new Node(1);
    
    root->left = new Node(2);
    root->right = new Node(3);

    root->left->left = new Node(4);
    root->left->right = new Node(5);

    root->right->left = new Node(6);
    root->right->right = new Node(7);

    vector<int> arr = boundaryTraversal(root);

    for(int i=0;i<arr.size();i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;

    return 0;
}