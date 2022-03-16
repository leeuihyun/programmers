#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <tuple>

using namespace std;

int solution(vector<int> numbers, int target) {
    int answer = 0, num_sum = 0;
    
    for(auto i : numbers)
        num_sum += i;
    
    queue<tuple<int, int, int, int>> q;
    
    q.push({0, 1, 0, num_sum});
    q.push({0, -1, 0, num_sum});
    
    while(!q.empty()) {
        int idx = get<0>(q.front());
        int pm = get<1>(q.front());
        int cur = get<2>(q.front()) + numbers[idx] * pm;
        int sum = get<3>(q.front()) - numbers[idx];
        q.pop();
        
        if(cur == target && idx == numbers.size() - 1) {
            answer++;
            continue;
        }
        else if(idx + 1 >= numbers.size())
            continue;
        
        if(cur < target)
            if(cur + sum < target)
                continue;
        else
            if(cur - sum > target)
                continue;
        
        q.push({idx + 1, pm, cur, sum});
        q.push({idx + 1, -pm, cur, sum});
    }
    
    return answer;
}