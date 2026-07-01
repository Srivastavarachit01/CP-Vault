#include<iostream>
using namespace std;

int main(){
    int n;
    cin >> n;
    double sum = 0;
    for(int i = 0; i < n; i++){
        double p;
        cin >> p;
        sum += p;
    }
    cout << fixed << setprecision(10) << sum / n << endl;
}