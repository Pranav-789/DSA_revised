#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int val;
    Node* next;

    Node(int x){
        this->val = x;
        this->next = NULL;
    }
};

class Stack
{
    Node* head;
    int length;
    int maxsize;
    public:

    Stack(int maxLimit){
        head = NULL;
        length = 0;
        maxsize = maxLimit;
    }

    void Push(int x)
    {
        Node *newNode = new Node(x);
        if(length == maxsize){
            cout << "Stack full!, can't push more elements" << endl;
            return;
        }
        newNode->next = head;
        head = newNode;
        length++;
    }

    int Pop(){
        if(length == 0){
            cout << "Stack is empty!" << endl;
            return -1;
        }
        int val = head->val;
        Node* temp = head;
        head = head->next;
        delete temp;
        length--;
        cout << "popped " << val << endl;
        return val;
    }

    int Size(){
        return length;
    }

    int Top(){
        if (length == 0)
        {
            cout << "Stack is empty!" << endl;
            return -1;
        }
        return head->val;
    }

    void Display(){
        if(length == 0){
            cout << "Stack is empty!" << endl;
            return;
        }
        Node* temp = head;
        while(temp!= NULL){
            cout << temp->val << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main()
{
    Stack st(3);
    st.Push(10);
    st.Push(20);
    st.Push(30);
    st.Push(40); // Should show stack full message

    cout << "Top element: " << st.Top() << endl;
    cout << "Size: " << st.Size() << endl;

    st.Display();

    st.Pop();
    st.Pop();
    st.Pop();
    st.Pop(); // Should show stack empty message

    return 0;
}
