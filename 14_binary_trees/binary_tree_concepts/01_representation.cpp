#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* left;
    Node* right;

    Node(int val){
        this->data = val;
        this->left = NULL;
        this->right = NULL;
    }
};

Node* buildTree(Node* root){
    cout << "Enter the data: " << endl;
    int data;
    cin >> data;

    if(data == -1){
        return NULL;
    }

    root = new Node(data);

    cout << "Enter data for inserting in left: " << endl;
    root-> left = buildTree(root->left);
    cout << "Enter data for inserting in right: " << endl;
    root-> right = buildTree(root->right);

    return root;
}

void levelOrderTraversal(Node* root){
    queue<Node*> q; //BFS

    q.push(root);
    q.push(NULL);
    while(!q.empty()){
        Node* temp = q.front();
        q.pop();
        
        if(temp == NULL){
            cout << endl;
            if(!q.empty()){
                q.push(NULL);
            }
        }
        else{
            cout << temp->data << " ";
            if (temp->left)
            {
                q.push(temp->left);
            }
            if (temp->right)
            {
                q.push(temp->right);
            }
        }
    }

}

void inorderTraversal(Node* root){
    if(root == NULL){
        return;
    }
    inorderTraversal(root->left);
    cout << root->data << " ";
    inorderTraversal(root->right);
}

void inorderIterative(Node* root){
    if(root == NULL) return;

    stack<Node*> st;
    Node* temp = root;
    while(temp != NULL || !st.empty()){
        while(temp != nullptr){
            st.push(temp);
            temp= temp->left;
        }

        temp = st.top();
        st.pop();

        cout << temp->data << " ";
        temp = temp->right;
    }

}

void preOrderTraversal(Node* root){
    if(root == NULL) return;

    cout << root->data << " ";
    preOrderTraversal(root->left);
    preOrderTraversal(root->right);
}

void postorderTraversal(Node* root){
    if(root == NULL) return;

    postorderTraversal(root->left);
    postorderTraversal(root->right);
    cout << root-> data << " ";
}

void preOrderIterative(Node* root){
    if(root == NULL) return;
    Node* temp = root;

    stack<Node*> st;

    st.push(root);
    while(!st.empty()){
        Node* temp = st.top();
        st.pop();
        if(temp->right != NULL){
            st.push(temp->right);
        }
        if(temp->left != NULL){
            st.push(temp->left);
        }
        cout << temp->data << " ";
    }
}

int main(){
    Node* root = NULL;
    
    root = buildTree(root);

    // 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1

    levelOrderTraversal(root);
    inorderTraversal(root);
    cout << endl;
    preOrderTraversal(root);
    cout << endl;
    postorderTraversal(root);
    cout << endl;
    preOrderIterative(root);
    cout << endl;
    inorderIterative(root);
}