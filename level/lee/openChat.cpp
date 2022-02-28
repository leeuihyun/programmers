#include <string>
#include <vector>
#include <map>
#include <sstream>

using namespace std;


vector<string> solution(vector<string> record) {
    vector<string> answer;
    vector<string> elc;
    vector<string> name;
    map<string, string> m;

    for (int i = 0; i < record.size(); i++) {      
        string s1, s2, s3;
        stringstream ss(record[i]);
        ss >> s1;
        ss >> s2;

        if (s1 == "Enter") {
            ss >> s3;
            elc.push_back("님이 들어왔습니다.");
            name.push_back(s2);
            m[s2] = s3;

        }
        else if (s1 == "Leave") {
            elc.push_back("님이 나갔습니다.");
            name.push_back(s2);

        }
        else {
            ss >> s3;
            m[s2] = s3;
        }
    }
    for (int i = 0; i < name.size(); i++) {
        string tmp = m[name[i]] + elc[i];
        answer.push_back(tmp);
    }
    return answer;
}