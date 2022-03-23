#include <string>
#include <vector>

using namespace std;

bool ok(string s) {
    int count = 0;
    for (int i = 0;i<s.size();i++) {
        char cs = s[i];
        if (cs == '(') count++;
        else count--;
        if (count < 0) return false;
    }
    if (count == 0) {
        return true;
    }
}
string solution(string p) {
    string answer;
    int a = 0;
    if (p == "") return p;
    string u = "", v = "";
    for (int i = 0; i < p.size(); i++) {
        if (p[i] == '(') {
            a++;
            u += '(';
        }
        else if (p[i] == ')') {
            a--;
            u += ')';
        }
        if (a == 0) {
            for (int j = i+1; j < p.size(); j++) {
                v += p[j];
            }
            break;
        }
    }
    if (ok(u)) {
     string return_v = solution(v);
        string return_res = u+return_v;
        return return_res;   
    }
        answer = "("+solution(v) +")";
        for (int i = 1; i < u.size()-1; i++) {
            
            if (u[i] == '(') answer += ")";
            else answer += "(";
        }
        return answer;
}