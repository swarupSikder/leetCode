//author:   Swarup Sikder
//judge:    ...
//problem:  ...
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) {
        string result;
        int idx=0, n= spaces.size();

        for(int i=0; i<s.size() ;i++){
            if(idx<n && i==spaces[idx]){
                result += ' ';
                idx++;
            }
            result += s[i];
        }
        return result;
    }
};

int main(){
    string s;
    cin>> s;

    // Reading spaces dynamically until the end of input
    vector<int> spaces;
    int temp;
    while (cin >> temp) {
        spaces.push_back(temp);
    }

    // Printing the spaces vector (for debugging purposes)
    // for (int j = 0; j < spaces.size(); ++j) {
    //     cout << spaces[j] << " ";
    // }
    // cout << endl;


    Solution solution;
    cout<< solution.addSpaces(s, spaces);
    
    
    return 0;
}