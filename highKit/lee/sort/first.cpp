#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
    for(int i=0;i<commands.size();i++){
        vector <int> v;
        int first = commands[i][0]-1;
        int second = commands[i][1]-1;
        int third = commands[i][2]-1;
        for(int j=first;j<=second;j++){
            v.push_back(array[j]);
        }
        sort(v.begin(),v.end());
        answer.push_back(v[third]);
    }
    return answer;
}