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

void preInPostTraversal(Node* root){
    stack<pair<Node*, int>> st;
    st.push({root, 1});
    vector<int> pre, in, post;
    if(root == NULL) return;
    while(!st.empty()){
        auto it = st.top();
        st.pop();

        if(it.second == 1){
            pre.push_back(it.first->data);
            it.second++;
            st.push(it);

            if(it.first->left != NULL){
                st.push({it.first->left, 1});
            }
        }
        else if(it.second == 2){
            in.push_back(it.first->data);
            it.second++;
            st.push(it);

            if(it.first->right != NULL){
                st.push({it.first->right, 1});
            }
        }
        else{
            post.push_back(it.first->data);
        }
    }
    cout << "Preorder: ";
    for (int x : pre)
        cout << x << " ";
    cout << endl;

    cout << "Inorder: ";
    for (int x : in)
        cout << x << " ";
    cout << endl;

    cout << "Postorder: ";
    for (int x : post)
        cout << x << " ";
    cout << endl;
}

int main()
{
    Node *root = NULL;

    root = buildTree(root);

    // 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1

    preInPostTraversal(root);
}