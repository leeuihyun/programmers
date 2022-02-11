#include <string>
#include <vector>
#include <queue>

using namespace std;

vector<int> solution(vector<string> operations) {
    vector<int> answer;
    int data;
    
    answer.push_back(0);
    answer.push_back(0);
    
    priority_queue<int> desc_pq;
    priority_queue<int, vector<int>, greater<int>> asc_pq;
    
    for(int i = 0; i < operations.size(); i++) {
        if(operations[i][0] == 'I') {
            string s;
            for(int j = 2; j < operations[i].size(); j++)
                s += operations[i][j];
            data = stoi(s);
            desc_pq.push(data);
            asc_pq.push(data);
            answer[0] = desc_pq.top();
            answer[1] = asc_pq.top();
        }
        else if(operations[i][0] == 'D' && !desc_pq.empty() && !asc_pq.empty()) {
            if(operations[i][2] == '1') {
                desc_pq.pop();
                if(!desc_pq.empty())
                    answer[0] = desc_pq.top();
            }
            else {
                asc_pq.pop();
                if(!asc_pq.empty())
                    answer[1] = asc_pq.top();
            }
            if(desc_pq.empty() || asc_pq.empty() || answer[0] < answer[1]) {
                while(!desc_pq.empty())
                    desc_pq.pop();
                while(!asc_pq.empty())
                    asc_pq.pop();
                answer[0] = 0;
                answer[1] = 0;
                continue;
            }
        }
    }
    
    return answer;
}