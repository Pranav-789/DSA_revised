#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int val;
    Node *next;

    Node(int x)
    {
        this->val = x;
        this->next = NULL;
    }
};


class Queue{
    int length;
    Node* front;
    Node* rare;
    int maxsize;

    public:

    Queue(int maxlim){
        maxsize = maxlim;
        front = NULL;
        rare = NULL;
        length = 0;
    }

    void Push(int x){
        if(length == maxsize){
            cout << "Queue is already full! can't push more elements." << endl;
            return;
        }
        Node* newNode = new Node(x);
        if(front == NULL){
            front = newNode;
            rare = newNode;
        }
        else{
            rare->next = newNode;
            rare = rare->next;
        }
        length++;
    }

    int pop(){
        if(length == 0){
            cout << "The queue is empty, can't pop." << endl;
            return -1;
        }
        int val = front->val;
        Node* temp = front;
        if(length == 1 || front == rare){
            front = NULL;
            rare = NULL;
        }
        else{
            front = front->next;
        }
        length--;
        delete temp;
        return val;
    }

    int Peek(){
        if(length == 0){
            cout << "Queue is empty"<<endl;
            return -1;
        }
        return front->val;
    }

    int size(){
        return length;
    }

    bool isEmpty(){
        return (length == 0);
    }

    void Display()
    {
        if (length == 0)
        {
            cout << "Queue is empty!" << endl;
            return;
        }
        Node *temp = front;
        cout << "Queue elements: ";
        while (temp)
        {
            cout << temp->val << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main()
{
    Queue q(3);

    q.Push(5);
    q.Push(10);
    q.Push(15);
    q.Push(20); // Should show queue full message

    q.Display();

    cout << "Front: " << q.Peek() << endl;

    cout << "Popped: " << q.pop() << endl;
    cout << "Popped: " << q.pop() << endl;

    q.Display();

    cout << "Is Empty: " << (q.isEmpty() ? "Yes" : "No") << endl;
    cout << "Current size: " << q.size() << endl;

    cout << "Popped: " << q.pop() << endl;
    cout << "Popped: " << q.pop() << endl; // Should say empty

    return 0;
}
