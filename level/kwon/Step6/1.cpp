#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

long long calculation(int n1, int n2, char opcode) {
    if(opcode == '+')
        return n1 + n2;
    else if(opcode == '-')
        return n1 - n2;
    else
        return n1 * n2;
}

long long solution(string expression) {
    long long answer = 0;
    
    string opcode = "";
    for(int i = 0; i < expression.size(); i++)
        if(expression[i] < '0')
            opcode += expression[i];
    int opcode_length = opcode.length();
    
    sort(opcode.begin(), opcode.end());
    
    opcode.erase(unique(opcode.begin(), opcode.end()), opcode.end());
    
    do {
        long long res = 0;
        long long num1 = 0, num2 = 0;
        int start_num1 = 0, end_num1 = 0;
        int start_num2 = 0, end_num2 = 0;
        int cnt = 0;
        string tmp = expression;
        
        for(int i = 0; i < opcode.size(); i++) {
            printf("\nopcode : %c [%s]\n", opcode[i], tmp.c_str());
            for(int j = 0; j < tmp.size(); j++) {
                if(cnt == opcode_length)
                    break;
                if(j > 0 && tmp[j] == opcode[i]) {
                    cnt++;
                    end_num1 = j - 1;
                    start_num2 = j + 1;
                    for(int l = end_num1; l >= 0; l--) {
                        if(l == 0) {
                            start_num1 = l;
                            break;
                        }
                        if(l < end_num1 && tmp[l] < '0') {
                            start_num1 = l + 1;
                            break;
                        }
                    }
                    for(int r = start_num2; r < tmp.size(); r++) {
                        if(r == tmp.size() - 1) {
                            end_num2 = r;
                            break;
                        }
                        if(r > start_num2 && tmp[r] < '0') {
                            end_num2 = r - 1;
                            break;
                        }
                    }
                    num1 = stoll(tmp.substr(start_num1, end_num1 - start_num1 + 1));
                    num2 = stoll(tmp.substr(start_num2, end_num2 - start_num2 + 1));
                    res = calculation(num1, num2, opcode[i]);
                    printf("%lld %lld %lld\n", num1, num2, res);
                    tmp.replace(start_num1, end_num2 - start_num1 + 1, to_string(res));
                    printf("%lld%c%lld = %lld -> [%s]\n", num1, opcode[i], num2, res, tmp.c_str());
                    j = start_num1;
                }
            }
        }
        
        printf("\nres : %s\n\n", tmp.c_str());
        answer = max(answer, abs(res));
    } while(next_permutation(opcode.begin(), opcode.end()));
    
    return answer;
}

int main() {
    string s = "";

    cin >> s;

    solution(s);

    return 0;
}