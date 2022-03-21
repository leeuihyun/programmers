#include <string>
#include <vector>
#include <cmath>

using namespace std;

vector<int> solution(int rows, int columns, vector<vector<int>> queries) {
    vector<int> answer;
    
    vector<vector<int>> vv(rows, vector<int>(columns, 0));
    int cnt = 1;
    
    for(int i = 0; i < rows; i++)
        for(int j = 0; j < columns; j++)
            vv[i][j] = cnt++;
    
    int r = 0, c = 0, dir_r = 0, dir_c = 0;
    int res = 0, tmp1 = 0, tmp2 = 0;
    
    for(auto i : queries) {
        pair<int, int> start = {i[0] - 1, i[1] - 1};
        pair<int, int> end = {i[2] - 1, i[3] - 1};
        r = start.first;
        c = start.second;
        dir_r = 0;
        dir_c = 1;
        res = vv[r][c];
        
        tmp1 = vv[r][c];
        tmp2 = vv[r + dir_r][c + dir_c];
        vv[r + dir_r][c + dir_c] = tmp1;
        r += dir_r;
        c += dir_c;
        
        while(1) {
            if(r == start.first && c == start.second)
                    break;
            else if(r == start.first && c == end.second) {
                    dir_r = 1; dir_c = 0;
                }
            else if(r == end.first && c == start.second) {
                    dir_r = -1; dir_c = 0;
            }
            else if(r == end.first && c == end.second) {
                    dir_r = 0; dir_c = -1;
            }
            
            tmp1 = vv[r + dir_r][c + dir_c];
            vv[r + dir_r][c + dir_c] = tmp2;
            res = min(res, tmp2);
            tmp2 = tmp1;
            r += dir_r;
            c += dir_c;
        }
        
        answer.push_back(res);
    }
    
    return answer;
}