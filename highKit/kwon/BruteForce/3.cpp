#include <string>
#include <vector>
#include <cmath>

using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer;
    
    int w, l, sum = brown + yellow;
    
    for(int i = 3; i * i <= sum; i++) {
        if(sum % i == 0) {
            l = i, w = sum / i;
            if((w - 2) * (l - 2) == yellow)
                break;
        }
    }
    
    answer.push_back(w);
    answer.push_back(l);
    
    return answer;
}