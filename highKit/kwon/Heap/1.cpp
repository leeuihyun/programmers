#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> scoville, int K) {
    int answer = 0, s1 = 0, s2 = 0;
    
    priority_queue<int, vector<int>, greater<int>> pq;
    
    for(int i = 0; i < scoville.size(); i++)
        pq.push(scoville[i]);
    
    s1 = pq.top();
    pq.pop();
    while(!pq.empty()) {
        s2 = pq.top();
        pq.pop();
        
        pq.push(s1 + s2 * 2);
        answer++;
        
        s1 = pq.top();
        if(s1 >= K)
            break;
        
        pq.pop();
    }
    
    if(pq.empty()) answer = -1;
    
    return answer;
}