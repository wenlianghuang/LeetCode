#include "../inc/Solution.h"
#include<vector>
#include<iostream>
#include<string>

using namespace std;

bool Solution::exist(vector<vector<char>> &board, string word){
    if (board.empty() || board[0].empty()) return false;
        int m = board.size(), n = board[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n)); //2-D vector which the previous is row and the last is column
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (search(board, word, 0, i, j, visited)) return true;
            }
        }
        return false;
}

bool Solution::search(vector<vector<char>>& board, string word, int idx, int i, int j, vector<vector<bool>>& visited) {
        if (idx == word.size()) return true;
        int m = board.size(), n = board[0].size();
        if (i < 0 || j < 0 || i >= m || j >= n || visited[i][j] || board[i][j] != word[idx]) return false;
        visited[i][j] = true;
        
        // 其實他是四個遞迴(上下左右)，每個方向都進去看一看，只要board[i][j] == word[idx]的話，就遞迴進去，不然就往下個方向看。
        // 如果中心的周圍四個方向進去以後都找不到適合的話，直接return false;
        // bool define default is "false"
        bool res; 
        res = search(board, word, idx + 1, i - 1, j, visited) 
                 || search(board, word, idx + 1, i + 1, j, visited)
                 || search(board, word, idx + 1, i, j - 1, visited)
                 || search(board, word, idx + 1, i, j + 1, visited);
        cout << "search res: " << boolalpha << res << endl;
        visited[i][j] = false;
        return res;
    }