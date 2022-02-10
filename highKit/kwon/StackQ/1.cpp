#include <string>
#include <vector>
#include <stack>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    vector<int> release;
    int n = progresses.size();
    stack<int> s;
    
    for(int i = 0; i < n; i++) {
        int a = (100 - progresses[i]) / speeds[i];
        if((100 - progresses[i]) % speeds[i] != 0)
            a += 1;
        release.push_back(a);
    }
    
    int idx = 0;
    s.push(idx);
    
    while(idx < n) {
        int i = s.top();
        s.pop();
        for(i = i + 1; i < n; i++) {
            if(release[i] > release[idx])
                break;
            s.push(i);
        }
        
        answer.push_back(s.size() + 1);
        idx = idx + s.size() + 1;
        while(!s.empty()) s.pop();
        s.push(idx);
    }
    
    return answer;
}