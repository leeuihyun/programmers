#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 1, cnt = 1, sum = 0, idx = 0;
    
    queue<pair<int, int>> q;
    
    q.push({truck_weights[idx++], cnt++});
    sum += q.front().first;
    while(!q.empty()) {
        if(cnt == q.front().second + bridge_length) {
            sum -= q.front().first;
            printf("pop : %d %d %d\n", q.front().first, q.front().second, cnt);
            q.pop();
        }
        if(sum + truck_weights[idx] <= weight && idx < truck_weights.size()) {
            sum += truck_weights[idx];
            printf("push : %d %d %d\n", sum, truck_weights[idx], cnt);
            q.push({truck_weights[idx++], cnt});
        }
        cnt ++;
    }
    
    answer = cnt - 1;
    
    return answer;
}
