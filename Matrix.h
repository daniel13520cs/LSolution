#pragma once
#include<vector>
using namespace std;
class Matrix
{
public:
    vector<vector<int>> matrixMulti(vector<vector<int>> A, vector<vector<int>> B)
    {
        int x = A.size();
        int y = A[0].size();
        int z = B[0].size();
        vector<int> row(z, { 0 });
        vector<vector<int>> C(x, row);
        for (int i = 0; i < x; i++)
        {
            for (int j = 0; j < z; j++)
            {
                C[i][j] = 0;
                for (int k = 0; k < y; k++)
                {
                    C[i][j] += A[i][k] * B[k][j];
                }
            }
        }
        return C;
    }
    void print(vector<vector<int>> m)
    {
        for (int i = 0; i < m.size(); i++)
        {
            for (int j = 0; j < m[i].size(); j++)
            {
                if (j == 0) { cout << "["; }
                cout << m[i][j];
                string append = (j == m[i].size() - 1) ? "]" : ",";
                cout << append; 
            }
            cout << "\n";
        }
    }
};