#ifndef SOLUTION_H
#define SOLUTION_H
#include<string>
#include<iostream>
#include<vector>
using namespace std;
class Solution{
public:
    Solution(){};
    ~Solution(){};
    bool exist(vector<vector<char>> &board,string word);
    bool search(vector<vector<char>> &board,string word, int idx, int i,int j,vector<vector<bool>>& visited);
};

#endif