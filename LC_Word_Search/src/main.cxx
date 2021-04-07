#include<iostream>
#include<vector>
#include<string>
#include "../inc/Solution.h"
using namespace std;

int main(int argc, char *argv[]){
    
    vector<vector<char>> board  
    {
        {'A','B','C','E'},
        {'S','F','C','S'},
        {'A','D','E','E'}
    };
    string word = "ABCCED";
    Solution sul;
    bool res = sul.exist(board,word);
    cout << "res: " << boolalpha << res << endl;
}