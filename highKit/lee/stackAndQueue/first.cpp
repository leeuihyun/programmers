#include <string>
#include <vector>
#include <queue>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    queue <int> q;
    int number;
    for(int i=0;i<speeds.size();i++){
        number = 100-progresses[i];
        if(number%speeds[i]>0){
            number = number/speeds[i]+1;
        }
        else if(number%speeds[i]==0){
            number = number/speeds[i];
        }
        q.push(number);
    }
    int res = 0;
    int fn = q.front();
    while(!q.empty()){
        if(fn >= q.front()){
            q.pop();
            res+=1;
        }
        else{
            answer.push_back(res);
            fn = q.front();
            res = 0;
        }
    }
    answer.push_back(res);
    return answer;
}