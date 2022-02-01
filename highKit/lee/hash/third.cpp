#include <string>
#include <vector>
#include <map>

using namespace std;

int solution(vector<vector<string>> clothes) {
    int answer = 0;
    int res = 1;
    map<string,int> maps;
    for(int i=0;i<clothes.size();i++){
        maps[clothes[i][1]]+=1;
    }
    for(auto i = maps.begin();i!=maps.end();i++){
        res*=(i->second + 1);
    }
    answer = res;
    return answer-1;
}