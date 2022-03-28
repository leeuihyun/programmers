#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool chk(char c) {
    if((c >= 65 && c <= 90) || (c >= 97 && c <= 122))
        return true;
    return false;
}

int solution(string str1, string str2) {
    int answer = 0;
    
    vector<string> v1, v2;
    
    for(int i = 0; i < str1.size() - 1; i++) {
        if(!chk(str1[i]) || !chk(str1[i + 1]))
            continue;
        if(str1[i] >= 97)
            str1[i] -= 32;
        if(str1[i + 1] >= 97)
            str1[i + 1] -= 32;
        
        string tmp = "";
        tmp += str1[i];
        tmp += str1[i + 1];
        v1.push_back(tmp);
    }
    
    for(int i = 0; i < str2.size() - 1; i++) {
        if(!chk(str2[i]) || !chk(str2[i + 1]))
            continue;
        if(str2[i] >= 97)
            str2[i] -= 32;
        if(str2[i + 1] >= 97)
            str2[i + 1] -= 32;
        
        string tmp = "";
        tmp += str2[i];
        tmp += str2[i + 1];
        v2.push_back(tmp);
    }
    
    sort(v1.begin(), v1.end());
    sort(v2.begin(), v2.end());
    
    vector<string> union_v(v1.size() + v2.size()), inter_v(v1.size() + v2.size());
    auto iter = set_union(v1.begin(), v1.end(), v2.begin(), v2.end(), union_v.begin());
    union_v.erase(iter, union_v.end());
    iter = set_intersection(v1.begin(), v1.end(), v2.begin(), v2.end(), inter_v.begin());
    inter_v.erase(iter, inter_v.end());
    
    if(v1.empty() && v2.empty())
        return 65536;
    
    double res = 0;
    res = (double)inter_v.size() / (double)union_v.size();
    answer = 65536 * res;
    
    return answer;
}