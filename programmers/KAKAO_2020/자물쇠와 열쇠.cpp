#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> board;
int key_size, lock_size;

vector<vector<int>> rotation(vector<vector<int>>& arr) {
    vector<vector<int>> answer(arr.size(), vector<int>(arr.size()));
    for (int r = 0; r < arr.size(); r++)
        for (int i = 0; i < arr.size(); i++)
            answer[i][arr.size() - 1 - r] = arr[r][i];

    return answer;
}

bool SumCheckMinus(int r, int c, vector<vector<int>>& key) {
    bool flag = true;
    for (int i = 0; i < key_size; i++)
        for (int j = 0; j < key_size; j++)
            board[r + i][c + j] += key[i][j];


    for (int i = key_size - 1; i < key_size - 1 + lock_size; i++)
        for (int j = key_size - 1; j < key_size - 1 + lock_size; j++)
            if (board[i][j] == 2 || board[i][j] == 0)
                flag = false;

    for (int i = 0; i < key_size; i++)
        for (int j = 0; j < key_size; j++)
            board[r + i][c + j] -= key[i][j];

    return flag;
}

bool solution(vector<vector<int>> key, vector<vector<int>> lock) {
    key_size = key.size();
    lock_size = lock.size();

    board.assign(lock_size + (key_size * 2) - 2, vector<int>(lock_size + (key_size * 2) - 2, 0));

    for (int i = 0; i < lock_size; i++)
        for (int j = 0; j < lock_size; j++)
            board[key_size - 1 + i][key_size - 1 + j] = lock[i][j];

    for (int i = 0; i < 4; i++) {
        if (i)
            key = rotation(key);

        for (int r = 0; r < key_size + lock_size - 1; r++)
            for (int c = 0; c < key_size + lock_size - 1; c++)
                if(SumCheckMinus(r, c, key))
                    return true;
    }
    return false;
}