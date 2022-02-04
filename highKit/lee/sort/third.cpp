#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int solution(vector<int> citations) {
    int answer = 0;
    sort(citations.begin(),citations.end());
    for(int i=1;i<=citations.size();i++){
        int res = 0;
        for(int j=0;j<citations.size();j++){
            if(i<=citations[j]){
                res+=1;
            }
            
        }
        if(i <= res && answer<=i){            
            answer = i;
        }
        else continue;
    }
    return answer;
}