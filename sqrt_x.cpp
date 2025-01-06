//author:   Swarup Sikder
//judge:    ...
//problem:  ...
#include <bits/stdc++.h>
using namespace std;

int main(){
    int x;
    cin>> x;

    //edge case
    if (x == 0 || x == 1) return x;

    int tmp = x;

    for(int i=1; i<=tmp ;i++){
        tmp = x/i;
    }

    cout<< tmp <<endl;
    
    return 0;
}