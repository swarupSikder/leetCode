//author:   Swarup Sikder
//judge:    ...
//problem:  ...
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int isPrefixOfWord(string sentence, string searchWord) {
        stringstream ss(sentence);
        string word;
        int i=0;
        bool foundPrefix = false;

        while(ss >> word){
            int searchWordLength = searchWord.size();
            int wordLength = word.size();
            bool isMatched = true;

            for(int j=0; j<searchWordLength ;j++){
                //cout<< word[j] <<" "<< searchWord[j]<<endl;

                if(word[j]!=searchWord[j]){
                    isMatched = false;
                    break;
                }
            }

            if(isMatched){
                return i+1;
                foundPrefix= true;
            }

            i++;
        }

        return (!foundPrefix)? -1 : i ;
    }
};

int main(){
    string sentence, searchWord;
    getline(cin, sentence);
    cin>> searchWord;

    Solution solution;
    cout<< solution.isPrefixOfWord(sentence, searchWord);
    
    return 0;
}