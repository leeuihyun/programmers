#include <string>
#include <vector>
#include <cmath>

using namespace std;

int solution(string s) {
    int answer = s.size(), cnt = 0, res = 0;
    int i = 0, j = 0;
    
    for(i = 1; i <= s.size(); i++) {
        string cmp = s.substr(0, i);
        cnt = i;
        res = 0;
        for(j = i; j < s.size(); j += i) {
            if(cmp != s.substr(j, i)) {
                if(cnt <= i)
                    res += i;
                else if((cnt / i) < 10)
                    res += i + 1;
                else if((cnt / i) < 100)
                    res += i + 2;
                else if((cnt / i) < 1000)
                    res += i + 3;
                if(j + i >= s.size())
                    break;
                cnt = i;
                cmp = s.substr(j, i);
            }
            else
                cnt += i;
        }
        if(j < s.size()) {
            res += s.size() - j;
        }
        else {
            if(cnt <= i)
                res += i;
            else if((cnt / i) < 10)
                res += i + 1;
            else if((cnt / i) < 100)
                res += i + 2;
            else if((cnt / i) < 1000)
                res += i + 3;
        }
        
        answer = min(answer, res);
    }
    
    return answer;
}