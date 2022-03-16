#include <string>
#include <algorithm>
using namespace std;

int solution(string s) {
    int answer = 0;
    int res = s.size();
    
    for(int i=1;i<s.size()/2+1;i++){
        string cs = s.substr(0,i); 
        string new_string = ""; //압축할 단어 넣어줄 값
        int first = 1; // 압축할 때 앞에 들어갈 숫자
        
        for(int j = i;j<s.size();j+=i){
            string tmp = s.substr(j,i);
            if(cs == tmp) first+=1;
            else {
                if(first!=1)new_string += to_string(first);
                new_string += cs;
                cs = s.substr(j,i);
                first = 1;
            }
        }
        if(first!=1){
            new_string+=to_string(first);
        }
        new_string+=cs;
        int number = new_string.size();
        if(number < res) res = number;
    }
    answer = res;
    return answer;
}