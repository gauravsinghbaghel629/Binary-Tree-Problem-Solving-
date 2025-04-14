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

vector<vector<int>> zigzagTraversal(Node* root){
    vector<vector<int>> ans;
    if(root == NULL) return ans;

    queue<Node*> q;
    q.push(root);

    bool leftTRight = true;

    while(!q.empty()){
        int size = q.size();
        vector<int> row(size);

        for(int i=0;i<size;i++){
            Node* node = q.front();
            q.pop();

            int index = (leftTRight) ? (i) : (size - i - 1);
            
            row[index] = node->data;
            if(node->left != NULL) q.push(node->left);
            if(node->right != NULL) q.push(node->right);
        }
        leftTRight = !leftTRight;
        ans.push_back(row);
    }
    return ans;
}


int main(){
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);

    root->left->left = new Node(4);
    root->left->right = new Node(5);

    root->right->left = new Node(6);
    root->right->right = new Node(7);

    vector<vector<int>> arr = zigzagTraversal(root);

    for(int i=0;i<arr.size();i++){
        for(int j=0;j<arr[i].size();j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }

    return 0;
}