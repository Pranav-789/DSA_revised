#include<bits/stdc++.h>
using namespace std;

void print(string name, int times){
    if(times <= 0) return;
    cout << name << endl;
    print(name, times-1);
}

void println(int i){
    if(i <= 0) return;
    println(i-1);
    cout << i << endl;
}

void printlnr(int i){
    if (i <= 0)
        return;
    cout << i << endl;
    printlnr(i - 1);
}

int main(){
    print("Pranav", 5);
    printlnr(10);
}