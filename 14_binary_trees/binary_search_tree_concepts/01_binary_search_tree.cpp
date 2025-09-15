#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* left;
    Node* right;

    Node(int d){
        this->data = d;
        this->left = NULL;
        this->right = NULL;
    }
};

Node* insertIntoTree(Node* root, int val){
    Node* newNode = new Node(val);
    if (root == NULL)
    {
        return newNode;
    }

    if(val >= root->data){
        root->right = insertIntoTree(root->right, val);
    }
    else{
        root->left = insertIntoTree(root->left, val);
    }
    return root;
}

Node* takeInput(Node* root){
    int val;
    
    cout << "enter data: ";
    cin >> val;
    while(val != -1){
        root = insertIntoTree(root, val);
        cout << "Enter data (-1 to stop): ";
        cin >> val;
    }
    return root;
}

bool searchNode(Node* root, int x){
    if(root == NULL) return false;
    Node* temp = root;
    while(temp != NULL){
        if(temp->data == x){
            return true;
        }
        else if(temp->data < x){
            temp = temp->right;
        }
        else{
            temp = temp->left;
        }
    }
}

void minNode(Node* root){
    if(root == NULL){
        cout << "The tree is empty!" << endl;
        return;
    }

    Node* temp = root;
    while(temp->left!= NULL){
        temp = temp->left;
    }
    cout << temp->data << " is the min node of the tree" << endl;
}

void maxNode(Node* root){
    if(root == NULL){
        cout << "The tree is empty!" << endl;
        return;
    }

    Node* temp = root;
    while(temp->right!= NULL){
        temp = temp->right;
    }
    cout << temp->data << " is the max node of the tree" << endl;
}

void inorderTraversal(Node* root){
    if(root == NULL){
        return;
    }

    inorderTraversal(root->left);
    cout << root->data << " ";
    inorderTraversal(root->right);
}

Node *deleteNode(Node *root, int key)
{
    if (root == NULL)
        return NULL;

    Node *temp = root;
    Node *prev = NULL;

    // Search for the node
    while (temp != NULL && temp->data != key)
    {
        prev = temp;
        if (temp->data < key)
            temp = temp->right;
        else
            temp = temp->left;
    }

    if (temp == NULL)
        return root; // Key not found

    // Case 1: Node with 0 or 1 child
    if (temp->left == NULL || temp->right == NULL)
    {
        Node *newNode = (temp->left) ? temp->left : temp->right;

        if (prev == NULL)
        { // Deleting root
            delete temp;
            return newNode;
        }

        if (temp == prev->left)
            prev->left = newNode;
        else
            prev->right = newNode;

        delete temp;
    }
    // Case 2: Node with 2 children
    else
    {
        Node *p = NULL;
        Node *temp2 = temp->left;

        // Find inorder predecessor (max in left subtree)
        while (temp2->right != NULL)
        {
            p = temp2;
            temp2 = temp2->right;
        }

        temp->data = temp2->data; // Replace value

        // Fix links
        if (p != NULL)
        {
            p->right = temp2->left;
        }
        else
        {
            temp->left = temp2->left;
        }

        delete temp2;
    }

    return root;
}

Node *delNodeRec(Node *root, int key)
{
    if (root == NULL)
    {
        return root; // Base case: empty tree
    }

    if (root->data < key)
    {
        // Search in right subtree if key is greater
        root->right = delNodeRec(root->right, key);
    }
    else if (root->data > key)
    {
        // Search in left subtree if key is smaller
        root->left = delNodeRec(root->left, key);
    }
    else
    {
        // Node found: handle 3 cases (0, 1, or 2 children)

        if (root->left == NULL)
        {
            // Case: only right child (or none)
            Node *temp = root->right;
            delete root;
            return temp;
        }

        if (root->right == NULL)
        {
            // Case: only left child
            Node *temp = root->left;
            delete root;
            return temp;
        }

        // Case: 2 children → replace with inorder predecessor
        Node *temp = root->left;
        while (temp->right != NULL)
        {
            temp = temp->right; // Find max in left subtree
        }

        root->data = temp->data;                         // Copy predecessor value
        root->left = delNodeRec(root->left, temp->data); // Delete predecessor
    }
    return root; // Return (possibly updated) root
}

int main(){
    Node* root = NULL;
    cout << "Enter data to create a BST: " << endl;
    root = takeInput(root);

    inorderTraversal(root);
    cout << endl;
    cout << searchNode(root, 12) << endl;
    minNode(root);
}