#include <string>
#include <vector>

using namespace std;

string solution(int n) {
    string answer = "";
    
    int q = n, r = 0;
    
    while(q) {
        r = q % 3;
        q = q / 3;
        
        if(r == 0) {
            answer = '4' + answer;
            q -= 1;
        }
        else if(r == 1)
            answer = '1' + answer;
        else
            answer = '2' + answer;
    }
    
    return answer;
}