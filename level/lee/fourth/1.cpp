#include <iostream>
#include<string>
#include <stack>

using namespace std;

stack <char> st;

int solution(string s)
{
    int answer = 0;

    for(int i=0;i<s.size();i++){
        if(st.empty() || st.top()!=s[i]){
            st.push(s[i]);
        }
        else{
            st.pop();
        }
    }
    if(st.empty()) answer = 1;
    return answer;
}