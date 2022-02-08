#include <string>
#include <vector>
#include <cmath>

using namespace std;

int answer = 50;
bool visited[50] = {false,};
void solve(string idx, string target, vector <string> words,int cnt){
    if(cnt >= answer){
        return;
    }
    if(idx == target){
        answer = min(answer,cnt);
        return;
    }
    for(int i=0;i<words.size();i++){
        int dif = 0;
        for(int j=0;j<words[i].size();j++){
            if(idx[j]!=words[i][j] && !visited[i]){
                
                dif+=1;
            }
        }
        if(dif==1){
            visited[i] = true;
            solve(words[i],target,words,cnt+1);
            visited[i] = false;
        }
    }
}
int solution(string begin, string target, vector<string> words) {
    solve(begin,target,words,0);
    if(answer == 50){
        answer = 0;
    }
    return answer;
}