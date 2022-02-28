#include <string>
#include <vector>
#include <unordered_map>
#include <sstream>

using namespace std;

vector<string> solution(vector<string> record) {
    vector<string> answer;
    
    unordered_map<string, string> uid_map;
    
    for(auto rec : record) {
        stringstream ss(rec);
        string op, uid, name;
        
        ss >> op;
        ss >> uid;
        ss >> name;
        if(op == "Enter")
            uid_map[uid] = name;
        else if(op == "Change")
            uid_map[uid] = name;
    }
    
    for(auto rec : record) {
        stringstream ss(rec);
        string op, uid, name, res;
        
        ss >> op;
        ss >> uid;
        ss >> name;
        if(op == "Enter" || op == "Leave") {
            auto iter = uid_map.find(uid);
            res = iter->second + "님이 ";
            if(op == "Enter")
                res += "들어왔습니다.";
            else if(op == "Leave")
                res += "나갔습니다.";
        
            answer.push_back(res);
        }
    }
    
    return answer;
}