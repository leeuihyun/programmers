#include <string>
#include <vector>
#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

vector <int> list[20001];

vector<bool> visited(20001,false);
vector<int> pathSum(20001,0);

queue <int> q;

void solve(){
    while(!q.empty()){
        int front = q.front();
        q.pop();
        for(int i=0;i<list[front].size();i++){
            if(!visited[list[front][i]] && list[front][i]!=1){
                visited[list[front][i]] = true;
                pathSum[list[front][i]]=pathSum[front]+1;
                q.push(list[front][i]);
            }
        }
    }            
}

int solution(int n, vector<vector<int>> edge) {
    int answer = 0;
    for(int i=0;i<edge.size();i++){
        list[edge[i][0]].push_back(edge[i][1]);
        list[edge[i][1]].push_back(edge[i][0]);
    }
    q.push(1);
    solve();
    int max_result = *max_element(pathSum.begin(),pathSum.end());
    
    for(int i=1;i<=n;i++){
        if(pathSum[i]==max_result) answer+=1;
    }
    return answer;
}
