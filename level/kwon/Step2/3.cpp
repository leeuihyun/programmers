#include <string>
#include <vector>
#include <unordered_map>
#include <math.h>

using namespace std;

unordered_map<string, int> mapInit() {
    unordered_map<string, int> um;
    
    um["zero"] = 0;
    um["one"] = 1;
    um["two"] = 2;
    um["three"] = 3;
    um["four"] = 4;
    um["five"] = 5;
    um["six"] = 6;
    um["seven"] = 7;
    um["eight"] = 8;
    um["nine"] = 9;
    
    return um;
}

int solution(string s) {
    int answer = 0;
    string tmp = "";
    
    unordered_map<string, int> nm;
    
    nm = mapInit();
    
    for(int i = 0; i < s.size(); i++) {
        tmp = "";
        
        if(s[i] > 9)
            for(int j = i; j < s.size(); j++) {
                if(s[j] <= 9)
                    break;
                tmp += s[j];
                auto iter = nm.find(tmp);
                if(iter != nm.end()) {
                    s.erase(i + 1, j - i);
                    s[i] = iter->second + '0';
                }
            }
    }
    
    for(int i = 0; i < s.size(); i++)
        answer += (s[i] - '0') * pow(10, s.size() - i - 1);
        
    return answer;
}