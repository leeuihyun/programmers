#include <string>
#include <vector>
#include <stack>
using namespace std;

string solution(int n) {
    string answer = "";
    long long number = n;
    stack <int> s;
    int result = 0;

    while (number >= 1) {
        result = number % 3;
        if (result == 0) {
            result = 4;
            number -= 1;
        }
        s.push(result);
        number /= 3;
    }
    
    while (!s.empty()) {
        answer += to_string(s.top());
        s.pop();
    }
    return answer;
}