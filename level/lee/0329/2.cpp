#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int tt[100001] = {0,};
vector <pair<int,int>> v;
bool compare(pair<int,int> a,pair<int,int> b){
    return a.first > b.first;
}

vector<int> solution(string s) {
    vector<int> answer;
    int oc = 0; //0닫힘 1열림
    string str = "";
    for(int i=0;i<s.size();i++){
        if(s[i]=='{'){
            oc = 1;
        }
        if(s[i]=='}'){
            oc = 0;
            if(str.length()){
                tt[stoi(str)]+=1;
                str="";
            }
        }
        if(s[i]==','){
            if(oc==0) continue;
            else {
                tt[stoi(str)]+=1;
                str="";
            }
        }
        if(oc==1){
            if(s[i]>='0' && s[i] <= '9'){
                str += s[i];
            }
            else continue;
        }
    }
    for(int i=0;i<100001;i++){
        if(tt[i]!=0)
            v.push_back({tt[i],i});
    }
    sort(v.begin(),v.end(),compare);
    for(int i=0;i<v.size();i++){
        answer.push_back(v[i].second);
    }
          
    return answer;
}