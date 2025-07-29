#include<bits/stdc++.h>
using namespace std;

class Queue{
    public:
    stack<int> mainStack, supportStack;

    void Push(int data){
        while(!mainStack.empty()){
            supportStack.push(mainStack.top());
            mainStack.pop();
        }

        cout << "The element pushed is " << data << endl;
        mainStack.push(data);

        while (!supportStack.empty())
        {
            mainStack.push(supportStack.top());
            supportStack.pop();
        }
    }

    int pop(){
        if(mainStack.empty()){
            cout << "Stack is empty!" << endl;
            exit(0);
        }
        int val = mainStack.top();
        mainStack.pop();
        return val;
    }

    int Top(){
        if (mainStack.empty())
        {
            cout << "Stack is empty!" << endl;
            exit(0);
        }
        return mainStack.top();
    }

    int size(){
        return mainStack.size();
    }
};

int main(){
    Queue q;
    q.Push(3);
    q.Push(4);
    cout << "The element poped is " << q.pop() << endl;
    q.Push(5);
    cout << "The top of the queue is " << q.Top() << endl;
    cout << "The size of the queue is " << q.size() << endl;
}