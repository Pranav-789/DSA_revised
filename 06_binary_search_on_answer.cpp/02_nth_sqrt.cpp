#include <bits/stdc++.h>
using namespace std;

long long rthPower(long long num, long long r){
    int ans = 1;
    for(int i = 0; i < r; i++){
        ans *= num;
    }
    return ans;
}

int main()
{
    long long n;
    cout << "Enter the number of to sqrt: ";
    cin >> n;
    long long r;
    cout << "Enter the root power: ";
    cin >> r;
    long long ans = INT16_MIN;

    // Naive approach:
    //  for(int i = 1; i <= n; i++){
    //      if(i*i == n){
    //          ans = i;
    //          break;
    //      }
    //      else if(i*i > n){
    //          ans = i-1;
    //          break;
    //      }
    //  }

    // Better approach, using binary search:
    long long low = 0, high = n;
    while (low <= high)
    {
        long long mid = low + (high - low) / 2;
        long long midPow = rthPower(mid, r);
        if (midPow == n)
        {
            ans = mid;
            break;
        }
        else if (midPow < n)
        {
            ans = mid;
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }

    cout << "The rth root of " << n << ": " << ans << endl;

    return 0;
}