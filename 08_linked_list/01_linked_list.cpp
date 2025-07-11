#include<iostream>
#include<vector>
using namespace std;

class Node{
    public:
    int data;
    Node* next;

    // construtor for Node

    Node(int d1, Node* n1){
        data = d1;
        next = n1;
    }

    Node(int d1){
        data = d1;
        next = NULL;
    }
};

Node* arrayToLL(vector<int> array){
    Node *head = NULL;
    for (int i = array.size()-1; i >= 0; i--)
    {
        Node *newNode = new Node(array[i], head);
        head = newNode;
    }
    return head;
}

void displayLL(Node* head){ // traversal
    Node* temp = head;
    while(temp != NULL){
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

int main(){
    Node* n1 = new Node(10, NULL);
    cout << n1->data << endl;

    vector<int> vec = {1, 2, 3, 4, 5};
    Node* head = arrayToLL(vec);
    displayLL(head);
    return 0;
}