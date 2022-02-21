#include <string>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int getMax(int max, int num) {
    if(max < num)
        return num;
    return max;
}

int solution(int n, vector<vector<int>> edge) {
    int answer = 0, max = 1;
    
    vector<bool> visited(n + 1, false);
    vector<int> dist(n + 1, 0);
    vector<vector<int>> graph(n + 1);
    queue<int> q;
    
    for(auto i : edge) {
        graph[i[0]].push_back(i[1]);
        graph[i[1]].push_back(i[0]);
    }
    
    q.push(1);
    visited[1] = true;
    
    while(!q.empty()) {
        int point = q.front();
        q.pop();

        visited[point] = true;
        
        for(auto i : graph[point]) {
            if(visited[i])
                continue;
            visited[i] = true;
            dist[i] = dist[point] + 1;
            max = getMax(max, dist[i]);
            q.push(i);
        }
    }
    
    for(int i = 1; i <= n; i++)
        if(max == dist[i])
            answer++;
    
    return answer;
}