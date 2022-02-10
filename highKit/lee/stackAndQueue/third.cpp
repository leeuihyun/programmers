#include <string>
#include <vector>
#include <queue>

using namespace std;

vector <int> v;
deque <pair<int,int>> q; // 무게, time

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 0;
    int sum = 0;
    int time = 1;
    int idx = 0;
    while(idx < truck_weights.size()){
        if(sum+truck_weights[idx]<=weight){
            q.push_back({truck_weights[idx],bridge_length+time});
            sum+=truck_weights[idx];
            idx+=1;
            time+=1;
        }
        else{
            sum -= q.front().first;
            if(q.front().second >= time){
                time = q.front().second;
            }
            q.pop_front();    
        }
    }
    answer = q.back().second;
    return answer;
}