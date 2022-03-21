#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

vector<string> solution(vector<string> orders, vector<int> course) {
    vector<string> answer;
    
    int tmp[20] = { 0, }, i = 0;
    
    map<string, int> m;
    vector<pair<string, int>> menu_v;
    vector<int> cnt(11, 0);
    
    for(auto order : orders) {
        for(int n = 2; n <= order.size(); n++) {
            for(i = 0; i < course.size(); i++)
                if(course[i] == n)
                    break;
            if(i == course.size())
                continue;
            vector<bool> visited(order.size() - n, false);
            visited.insert(visited.end(), n, true);
            do {
                string menu = "";
                for(int i = 0; i < order.size(); i++)
                    if(visited[i])
                        menu += order[i];
                sort(menu.begin(), menu.end());
                m[menu]++;
            } while(next_permutation(visited.begin(), visited.end()));
        }
    }
    
    for(auto i : m)
        menu_v.push_back({i.first, i.second});
    
    struct {
        bool operator()(pair<string, int> a, pair<string, int> b) {
            return a.second > b.second;
        }
    } cmp;
    
    sort(menu_v.begin(), menu_v.end(), cmp);
    
    for(auto i : menu_v) {
        if(cnt[i.first.size()] == 0 && i.second >= 2) {
            answer.push_back(i.first);
            cnt[i.first.size()] = i.second;
        }
        else if(i.second == cnt[i.first.size()])
            answer.push_back(i.first);
    }
    
    sort(answer.begin(), answer.end());
    
    return answer;
}