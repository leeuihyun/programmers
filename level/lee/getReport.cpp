#include <string>
#include <vector>
#include <unordered_map>
#include <set>
#include <sstream>

using namespace std;
unordered_map <string,set<string>> report_map;
unordered_map <string,int> cnt_map;

vector<int> solution(vector<string> id_list, vector<string> report, int k) {
    vector<int> answer(id_list.size(),0);
    for(string s : report){
        string first,second;
        istringstream sst(s);
        sst >> first >> second;
        report_map[second].insert(first);
    }    
    for(int i=0;i<id_list.size();i++){
        cnt_map[id_list[i]]=i;
    }
    for(auto it : report_map){
        if(it.second.size() >= k){
            for(auto second_it : it.second){
                int num = cnt_map[second_it];
                answer[num]++;
            }
        }
    }
    return answer;
}