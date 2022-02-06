#include <string>
#include <vector>

using namespace std;

int res =0;

void sol(vector<int> numbers,int target, int sum,int idx){
    if(numbers.size() == idx){
        if(target == sum){
            res+=1;
        }
        return;
    }
    sol(numbers,target,sum+numbers[idx], idx+1);
    sol(numbers,target,sum-numbers[idx],idx+1);
}

int solution(vector<int> numbers, int target) {
    int answer = 0;
    sol(numbers,target, 0, 0);
    answer = res;
    return answer;
}