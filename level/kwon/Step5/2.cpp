#include <string>
#include <vector>
#include <queue>
#include <tuple>

using namespace std;

int dr[4] = {0, 0, -1, 1};
int dc[4] = {-1, 1, 0, 0};

bool chk(int r, int c, vector<vector<bool>> v) {
    if(r >= 0 && r < 5 && c >= 0 && c < 5 && !v[r][c])
        return true;
    return false;
}

vector<int> solution(vector<vector<string>> places) {
    vector<int> answer;
    
    vector<vector<bool>> visited(5, vector<bool>(5, false));
    
    bool flag = false;
    
    queue<tuple<int, int, int>> q;
    
    for(int n = 0; n < places.size(); n++) {
        flag = true;
        for(int i = 0; i < 5; i++) {
            for(int j = 0; j < 5; j++) {
                if(places[n][i][j] == 'P') {
                    fill(visited.begin(), visited.end(), vector<bool>(5, false));
                    visited[i][j] = true;
                    for(int k = 0; k < 4; k++) {
                        int nr = i + dr[k];
                        int nc = j + dc[k];
                        
                        if(chk(nr, nc, visited))
                            q.push({nr, nc, 1});
                    }
                    
                    while(!q.empty()) {
                        int r = get<0>(q.front());
                        int c = get<1>(q.front());
                        int dis = get<2>(q.front());
                        q.pop();
                        
                        if(dis > 2)
                            continue;
                        
                        if(places[n][r][c] == 'X')
                            continue;
                        else if(places[n][r][c] == 'O') {
                            for(int k = 0; k < 4; k++) {
                                int nr = r + dr[k];
                                int nc = c + dc[k];
                                
                                if(chk(nr, nc, visited)) {
                                    q.push({nr, nc, dis + 1});
                                    visited[nr][nc] = true;
                                }
                            }
                        }
                        else {
                            if(dis <= 2)
                                flag = false;
                        }
                    }
                }
            }
        }
        if(flag)
            answer.push_back(1);
        else
            answer.push_back(0);
    }
    
    return answer;
}