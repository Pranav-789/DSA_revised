#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int val)
    {
        this->data = val;
        this->left = NULL;
        this->right = NULL;
    }
};

Node *buildTree(Node *root)
{
    cout << "Enter the data: " << endl;
    int data;
    cin >> data;

    if (data == -1)
    {
        return NULL;
    }

    root = new Node(data);

    cout << "Enter data for inserting in left: " << endl;
    root->left = buildTree(root->left);
    cout << "Enter data for inserting in right: " << endl;
    root->right = buildTree(root->right);

    return root;
}

void iterativePostOrder(Node* root){
    if(root == NULL){
        return;
    }

    stack<Node*> st1, st2;

    st1.push(root);
    while(!st1.empty()){
        Node* temp = st1.top();
        st1.pop();
        if(temp->left){
            st1.push(temp->left);
        }
        if(temp->right){
            st1.push(temp->right);
        }
        st2.push(temp);
    }

    while(!st2.empty()){
        cout << st2.top()->data << " ";
        st2.pop();
    }
}

void iterativePostOrderUniStack(Node* root){
    if(root == NULL) return;

    Node* curr = root;
    stack<Node*> st;
    while(curr != NULL || !st.empty()){
        if(curr != NULL){
            st.push(curr);
            curr = curr->left;
        }
        else{
            Node* temp = st.top()->right;
            if(temp == NULL){
                temp = st.top();
                st.pop();

                cout << temp->data << " ";
                while(!st.empty() && temp == st.top()->right){
                    temp = st.top();
                    st.pop();
                    cout << temp->data << " ";
                }
            }
            else{
                curr = temp;
            }
        }
    }

}

int main(){
    Node *root = NULL;

    root = buildTree(root);

    // 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1
    iterativePostOrder(root);
    cout << endl;
    iterativePostOrderUniStack(root);
}