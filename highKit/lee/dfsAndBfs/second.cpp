#include <string>
#include <vector>

using namespace std;

bool visited[201] = {false,};

void sol(int start,vector<vector<int>> computers){
    visited[start] = true;
    for(int i=0;i<computers[start].size();i++){
        if(visited[i]==true) continue;
        else{
            if(computers[start][i] && start!=i){
                sol(i,computers);
            }
        }
    }
}
int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    for(int i=0;i<computers.size();i++){
        if(!visited[i]){
            sol(i, computers);
            answer+=1;
        }
    }
    return answer;
}