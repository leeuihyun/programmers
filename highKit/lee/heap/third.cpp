#include <string>
#include <vector>
#include <queue>
using namespace std;

vector<int> solution(vector<string> operations) {
        vector <int> answer;
        int result_number = 0;
        priority_queue <int, vector <int>, greater<int>> q1; //오름차순 큐
        priority_queue <int, vector<int>> q2;  //내림차순 큐
        for(int i=0;i<operations.size();i++){
            string s = operations[i];
            if(result_number==0) { 
                while(!q1.empty()) q1.pop(); 
                while(!q2.empty()) q2.pop(); 
            }

            if(s[0]=='D'){
                if(!result_number) continue;
                if(s[2]=='1'){
                    q2.pop();
                    result_number-=1;
                }
                else{
                    q1.pop();
                    result_number-=1;
                }
            }
            else{
                result_number+=1;
                int number = stoi(s.substr(2));
                q1.push(number);
                q2.push(number);
            }
        }
        if(result_number){
            answer.push_back(q2.top());
            answer.push_back(q1.top());
        }else{
            answer.push_back(0);
            answer.push_back(0);
        }
        return answer;
    }