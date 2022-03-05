#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;
bool visited[46];

vector<int> solution(vector<int> lottos, vector<int> win_nums) {
    vector<int> answer;
    int high= 1;
    int low = 6;
    int number = 0;
    vector <int> new_arr;
    sort(lottos.begin(),lottos.end());
    sort(win_nums.begin(),win_nums.end());
    for(int i=0;i<lottos.size();i++){
        if(lottos[i]!=0){
            number+=1;
            for(int j=0;j<win_nums.size();j++){
                if(lottos[i]==win_nums[j]){
                    visited[lottos[i]] = true;
                    new_arr.push_back(lottos[i]);
                    break;
                }
            }
        }
    }
    int cnt = 0;
    for(int i=0;i<lottos.size();i++){
        if(visited[lottos[i]])cnt++;
    }
    if(cnt == 6){
        low = 1;
    }
    else if(cnt == 5){
        low = 2;
    }
    else if(cnt==4){
        low = 3;
    }
    else if(cnt==3){
        low = 4;
    }
    else if(cnt==2){
        low = 5;
    }
    else {
        low = 6;
    }
    int zero = 6-number;
    if(zero>0){
        for(int i=0;i<win_nums.size();i++){
            if(zero==0) break;
            if(!visited[win_nums[i]] && zero>0){
                visited[win_nums[i]] = true;
                zero-=1;
            }
        }
    }
    cnt = 0;
    for(int i=0;i<win_nums.size();i++){
        if(visited[win_nums[i]])cnt++;
    }
    if(cnt == 6){
        high = 1;
    }
    else if(cnt == 5){
        high = 2;
    }
    else if(cnt==4){
        high = 3;
    }
    else if(cnt==3){
        high = 4;
    }
    else if(cnt==2){
        high = 5;
    }
    else {
        high = 6;
    }
    answer.push_back(high);
    answer.push_back(low);
    return answer;
}