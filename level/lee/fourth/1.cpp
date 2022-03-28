#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector <char> str = {'*','+','-'}; //*,+,- 넣을 벡터
vector <char> str_list; //나오는 부호 넣을 벡터
vector <long long> number; //숫자 넣을 벡터

long long calc(long long a,long long b, char op)
{
    if(op == '-') return a-b;
    else if(op == '+') return a+b;
    else return a*b;
}

long long solution(string ex) {
    long long answer = 0;
    long long _max = 0;
    string tmp = "";
    for(int i=0;i<ex.size();i++){
        if(ex[i]>='0' && ex[i]<='9'){
            tmp+=ex[i];
        }
        else{
            number.push_back(atoi(tmp.c_str()));
            str_list.push_back(ex[i]);
            tmp = "";
        }
    }
    number.push_back(atoi(tmp.c_str())); //마지막에 끝나니까 한번더 있을듯?
    do{
        vector <char> str_list2 = str_list;
        vector <long long> number2 = number;
        for(int i=0;i<str.size();i++){
            for(int j=0;j<str_list2.size();j++){
                if(str_list2[j]==str[i]){
                    number2[j] = calc(number2[j],number2[j+1],str[i]);
                    number2.erase(number2.begin()+j+1);
                    str_list2.erase(str_list2.begin()+j);
                    j--;
                }                
            }
        }
        if(_max < abs(number2[0])) _max = abs(number2[0]);
    }while(next_permutation(str.begin(),str.end()));
    answer = _max;
    return answer;
}