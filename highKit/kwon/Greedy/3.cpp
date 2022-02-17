#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(string number, int k) {
    string answer = "";
    int cnt = 0, idx = 0;
    
    while(cnt < k && idx < number.size() - 1) {
        if(cnt == k)
            break;
        
        if(number[idx] < number[idx + 1]) {
            number.erase(idx, 1);
            cnt++;
            idx = 0;
            continue;
        }
        idx++;
    }
    while(cnt < k && idx > 0) {
        if(cnt == k)
            break;
        
        if(number[idx] < number[idx - 1]) {
            number.erase(idx, 1);
            cnt++;
            idx = number.size() - 1;
            continue;
        }
        idx--;
    }
    
    answer = number;
    
    return answer;
}