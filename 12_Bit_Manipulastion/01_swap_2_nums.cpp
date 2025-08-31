#include<iostream>
using namespace std;

int main(){
    int a = 5;
    int b = 6;

    //swapping numbers without external(temp) variable

    //the swapping occurs with basic concept of bit manipulation

    // 5 ^ 5 = 0, XOR same numbers you get 0
    // in terms of bits manipulation, even number of 1 => 0 and odd number of 1 => 1, refer example below.
    // x = 13^7 = 10
    // 1 1 0 1
    //^0 1 1 1
    //--------
    // 1 0 1 0

    a = a ^ b; // here we are setting a as (a^b)
    b = a ^ b; // step 2. b = (a^b) ^ b; as from above equation we put modified value of a;
    // as we know b^b = 0, leeaving only b = a
    a = a ^ b; // step 3. substitute b as a^b, you have the answer

    cout << "a: " << a << " b: " << b <<  endl;
}