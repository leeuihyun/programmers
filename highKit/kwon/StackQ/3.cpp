#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> priorities, int location) {
    int answer = 1, max = 0;
    
    queue<pair<int, int>> q;
    
    for(int i = 0; i < priorities.size(); i++) {
        q.push({priorities[i], i});
        if(max < priorities[i])
            max = priorities[i];
    }
    
    while(!q.empty()) {
        int p = q.front().first;
        int idx = q.front().second;
        q.pop();
        
        if(p == max) {
            if(idx == location) break;
            max = 0;
            queue<pair<int, int>> tmp = q;
            while(!tmp.empty()) {
                if(tmp.front().first > max)
                    max = tmp.front().first;
                tmp.pop();
            }
            answer++;
        }
        else
            q.push({p, idx});
    }
    
    return answer;
}