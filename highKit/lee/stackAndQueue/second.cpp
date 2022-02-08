#include <string>
#include <vector>
#include <queue>

using namespace std;
priority_queue <int> pq;
queue <pair<int,int>> q; //idx,[idx]

int solution(vector<int> priorities, int location) {
    int answer = 0;
    for(int i=0;i<priorities.size();i++){
        pq.push(priorities[i]);
        q.push({i,priorities[i]});
    }
    while(!q.empty()){
        int first = q.front().first;
        int second = q.front().second;
        q.pop();
        if(second == pq.top()){
            pq.pop();
            answer+=1;
            if(first == location){
                break;
            }
        }
        else{
            q.push({first,second});
        }
    }
    return answer;
}