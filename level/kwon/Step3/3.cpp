#include <stdio.h>
#include <vector>
#include <queue>

using namespace std;

bool chk(int x, int y, int m, int n) {
    if(x >= 0 && y >= 0 && x < m && y < n)
        return true;
    return false;
}

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
vector<int> solution(int m, int n, vector<vector<int>> picture) {
    int number_of_area = 0;
    int max_size_of_one_area = 0, size_of_one_area = 0, color = 0;
    
    int dx[4] = {0, 0, -1, 1};
    int dy[4] = {-1, 1, 0, 0};
    vector<vector<bool>> visited(m, vector<bool>(n, false));
    queue<pair<int, int>> q;
    
    for(int i = 0; i < m; i++)
        for(int j = 0; j < n; j++)
            if(chk(i, j, m, n) && !visited[i][j] && picture[i][j] != 0) {
                q.push({i, j});
                visited[i][j] = true;
                size_of_one_area = 0;
                color = picture[i][j];
                
                while(!q.empty()) {
                    int qx = q.front().first;
                    int qy = q.front().second;
                    q.pop();
                    
                    size_of_one_area++;
                    
                    for(int i = 0; i < 4; i++) {
                        int nx = qx + dx[i];
                        int ny = qy + dy[i];
                        
                        if(chk(nx, ny, m, n) && !visited[nx][ny] && picture[nx][ny] == color) {
                            q.push({nx, ny});
                            visited[nx][ny] = true;
                        }
                    }
                }
                
                if(size_of_one_area > max_size_of_one_area)
                    max_size_of_one_area = size_of_one_area;
                
                number_of_area++;
            }
    
    vector<int> answer(2);
    answer[0] = number_of_area;
    answer[1] = max_size_of_one_area;
        
    return answer;
}