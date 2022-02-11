#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

struct cmp {
    bool operator()(vector<int> a, vector<int> b) {
        return a[1] > b[1];
    }
};

int solution(vector<vector<int>> jobs) {
    int answer = 0, time = 0, idx = 0;
    vector<int> task;
    
    sort(jobs.begin(), jobs.end());
    
    priority_queue<vector<int>, vector<vector<int>>, cmp> pq;
    
    pq.push(jobs[idx++]);
    time += pq.top()[0];
    
    while(!pq.empty()) {
        task = pq.top();
        pq.pop();
        time += task[1];
        answer += time - task[0];
        
        for(idx; idx < jobs.size(); idx++) {
            if(jobs[idx][0] > time) break;
            pq.push(jobs[idx]);
        }
        if(pq.empty() && idx < jobs.size()) {
            time = jobs[idx][0];
            pq.push(jobs[idx++]);
        }
    }
    
    answer /= jobs.size();
    
    return answer;
}