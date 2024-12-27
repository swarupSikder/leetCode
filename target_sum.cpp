//author:   Swarup Sikder
//judge:    ...
//problem:  ...
#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>> n;

    vector<int> nums(n);
    for(int i=0; i<n ;i++){
        cin>> nums[i];
    }

    int target;
    cin>> target;

    //edge case 1: for only item
    if(nums.size()==1){
        if(nums[0]==target || nums[0]==-target){
            cout<< 1 <<endl;
        }
        else{
            cout<< 0 <<endl;
        }
        
    }

    //edge case 2: for only non-zero array
    int nonZero, count=0;
    for(int i=0; i<nums.size() ;i++){
        if(nums[i]==0){
            count++;
        }
    }
    if(count==nums.size()-1){
        cout<< pow(2, count);
        return 0;
    }


    int sum = 0;
    count = 0;
    for(int i=0; i<nums.size() ;i++){
        for(int j=0; j<nums.size() ;j++){
            for(int k=0; k<nums.size() ;k++){
                cout<< nums[k] <<" ";
                sum += nums[k];
            }
            cout<< sum <<endl;
            if(sum == target){
                count++;
            }

            sum=0;
            nums[j] = -nums[j];

            
        }
    }
    
    cout<< count <<endl;
    

    return 0;
}