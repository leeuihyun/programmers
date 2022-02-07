#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> answers) {
    vector<int> answer;
    
    int max = 0;
    vector<vector<int>> v;
    v.push_back({1, 2, 3, 4, 5});
    v.push_back({2, 1, 2, 3, 2, 4, 2, 5});
    v.push_back({3, 3, 1, 1, 2, 2, 4, 4, 5, 5});
    vector<int> cnt = {0, 0, 0};
    vector<int> index = {0, 0, 0};
    
    for(int i = 0; i < answers.size(); i++) {
        for(int j = 0; j < v.size(); j++) {
            if(index[j] >= v[j].size())
                index[j] = 0;
            if(answers[i] == v[j][index[j]++])
                cnt[j]++;
            if(cnt[max] < cnt[j])
                max = j;
        }
    }
    
    for(int i = 0; i < cnt.size(); i++) {
        if(cnt[i] >= cnt[max])
            answer.push_back(i + 1);
    }
    
    return answer;
}