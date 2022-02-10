#include <string>
#include <vector>

using namespace std;

bool visited[200];

void dfs(int index, vector<vector<int>> c) {
    if(visited[index])
        return;
    else {
        visited[index] = true;
        for(int i = 0; i < c[index].size(); i++) {
            if(c[index][i] == 1 && index != i) {
                dfs(i, c);
                visited[i] = true;
            }
        }
    }
}

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    
    for(int i = 0; i < n; i++) {
        if(!visited[i]) {
            dfs(i, computers);
            answer++;
        }
    }
    
    return answer;
}