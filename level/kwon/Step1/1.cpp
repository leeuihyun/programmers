#include <string>
#include <vector>
#include <unordered_map>
#include <sstream>
#include <set>

using namespace std;

vector<int> solution(vector<string> id_list, vector<string> report, int k) {
    vector<int> answer(id_list.size(), 0);
    
    unordered_map<string, set<string>> report_list;
    unordered_map<string, int> report_cnt;

    string a, b;
    
    for(auto i : report) {
        stringstream ss(i);
        ss.str(i);
        
        ss >> a;
        ss >> b;
        
        report_list[a].insert(b);
    }
    
    for(auto i : report_list)
        for(auto j : i.second)
            report_cnt[j]++;
    
    for(int i = 0; i < id_list.size(); i++) {
        auto report_id = report_list.find(id_list[i]);
        if(report_id != report_list.end())
            for(auto j : report_id->second) {
                auto reported_id = report_cnt.find(j);
                if(reported_id->second >= k)
                    answer[i] += 1;
            }
    }
    
    return answer;
}