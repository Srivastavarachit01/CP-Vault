#include<iostream>
using namespace std;
 
int main(){
    long long n, k;
    cin >> n >> k;
    
    long long oddCount = (n + 1) / 2; // total odd numbers from 1 to n
    
    if (k <= oddCount) {
        cout << 2*k - 1 << endl; // k-th odd number
    } else {
        long long pos = k - oddCount; // position in even part
        cout << 2*pos << endl;
    }
    
    return 0;
}
