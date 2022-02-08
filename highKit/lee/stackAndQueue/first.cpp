#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

queue <int> q;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    for(int i=0;i<progresses.size();i++){
        if((100-progresses[i])%speeds[i] == 0) {
            q.push((100-progresses[i])/speeds[i]);
        }
        else{
            q.push((100-progresses[i])/speeds[i] + 1);
        }
    }
    int number = -1;
    int plus = 1;
    while(!q.empty()){
        if(number==-1){
            number = q.front();
            q.pop();
        }
        else{
            if(number >= q.front()){
                plus+=1;
            }
            else{
                answer.push_back(plus);
                number = q.front();
                plus = 1;
            }
            q.pop();
        }
    }
    answer.push_back(plus);
    return answer;
}