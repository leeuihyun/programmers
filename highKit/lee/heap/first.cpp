#include <string>
#include <vector>
#include <queue>

using namespace std;

priority_queue <int,vector<int>,greater<int>> pq;

int solution(vector<int> scoville, int K) {
    int answer = 0;
    for(int i=0;i<scoville.size();i++){
        pq.push(scoville[i]);
    }
    while(true){
        if(pq.size()>1 && pq.top() < K){
            int tmp = pq.top();
            pq.pop();
            int second = pq.top();
            pq.pop();
            tmp+=second*2;
            pq.push(tmp);
            answer+=1;
        }
        else break;  
    }
    if(pq.top() >= K) return answer;
    else return -1;
    return answer;
}