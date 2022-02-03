#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

vector<int> solution(vector<int> answers) {
    vector<int> answer;
    int mn = 0;
    vector <int> first = {1,2,3,4,5};
    vector <int> second = {2,1,2,3,2,4,2,5};
    vector <int> third = {3,3,1,1,2,2,4,4,5,5};
    
    int first_res = 0;
    int second_res = 0;
    int third_res = 0;
    
    for(int i=0;i<answers.size();i++){
        if(answers[i]==first[i%first.size()]){
            first_res+=1;    
        }
        if(answers[i]==second[i%second.size()]){
            second_res+=1;    
        }
        if(answers[i]==third[i%third.size()]){
            third_res+=1;    
        }
        
    }
    mn = max(first_res,max(second_res,third_res));
    if(mn==first_res){
        answer.push_back(1);
    }
    if(mn==second_res){
        answer.push_back(2);
    }
    if(mn==third_res){
        answer.push_back(3);
    }
    sort(answer.begin(),answer.end());
    
    return answer;
}