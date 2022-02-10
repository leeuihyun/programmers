#include <string>
#include <vector>
#include <queue>
#include <tuple>

using namespace std;

vector<bool> visited(10000);

vector<string> solution(vector<vector<string>> tickets) {
    vector<string> answer;
    int n = tickets.size();
    
    queue<tuple<int, vector<string>, vector<bool>>> q;
    answer.push_back("ICN");
    
    for(int i = 0; i < n; i++)
        if(tickets[i][0] == "ICN")
            q.push({i, answer, visited});
    
    while(!q.empty()) {
        int idx = get<0>(q.front());
        string s = tickets[idx][1];
        vector<string> res = get<1>(q.front());
        res.push_back(s);
        vector<bool> v = get<2>(q.front());
        v[idx] = true;
        q.pop();
            
        if(res.size() == n + 1) {
            if(answer.size() < n + 1)
                answer = res;
            else if(answer > res)
                answer = res;
        }
        
        for(int i = 0; i < n; i++)
            if(s == tickets[i][0] && !v[i])
                q.push({i, res, v});
    }
    
    return answer;
}