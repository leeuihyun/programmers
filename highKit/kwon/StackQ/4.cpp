#include <string>
#include <vector>
#include <stack>

using namespace std;

vector<int> solution(vector<int> prices) {
    int n = prices.size();
    vector<int> answer(n);
    
    stack<int> s;
    s.push(0);
    
    for(int i = 1; i < n; i++) {
        while(!s.empty() && prices[s.top()] > prices[i]) {
            answer[s.top()] = i - s.top();
            s.pop();
        }
        
        s.push(i);
    }
    
    while(!s.empty()) {
        answer[s.top()] = n - s.top() - 1;
        s.pop();
    }
    
    return answer;
}