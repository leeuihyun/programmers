#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

vector<int> solution(string s) {
    vector<int> answer;
    vector<vector<int>> num_array;
    unordered_map<int, bool> visited;
    
    s.erase(0, 1);
    s.erase(s.size() - 1, 1);
    for(int i = 0; i < s.size(); i++) {
        if(s[i] == '{') {
            vector<int> tmp;
            int num_start = i + 1, num_end = 0;
            for(int j = i + 1; j < s.size(); j++) {
                if(s[j] == ',' || s[j] == '}') {
                    num_end = j - 1;
                    int num = stoi(s.substr(num_start, num_end - num_start + 1));
                    tmp.push_back(num);
                    visited[num] = false;
                    if(s[j] == '}')
                        break;
                    else
                        num_start = j + 1;
                }
            }
            num_array.push_back(tmp);
        }
    }
    
    struct {
        bool operator()(vector<int> a, vector<int> b) {
            return a.size() < b.size();
        }
    } cmp;
    
    sort(num_array.begin(), num_array.end(), cmp);
    
    for(auto array : num_array) {
        for(auto num : array) {
            auto iter = visited.find(num);
            if(!iter->second) {
                answer.push_back(iter->first);
                visited.at(num) = true;
            }
        }
    }
    
    return answer;
}