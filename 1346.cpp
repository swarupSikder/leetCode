//author:   Swarup Sikder
//judge:    ...
//problem:  ...
#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
        bool checkIfExist(vector<int>& a) {
            //check array
            bool isExists= false;
            for(int i=0; i<a.size() ;i++){
                for(int j=0; j<a.size() ;j++){
                    if(i!=j && a[i]==2*a[j]){
                        //cout<< a[i] <<" "<< a[j] <<endl;
                        isExists = true;
                        break;
                    }
                }

                if(isExists){
                    break;
                }
            }

            //return (true/false)
            return isExists;
        }
};

int main(){
    vector<int> a(10000);
    int len=0;
    while(cin>> a[len]){
        len++;
    }


    Solution solution;
    (solution.checkIfExist(a))? std::cout<< "true" <<endl : std::cout<< "false" <<endl;
    
    return 0;
}