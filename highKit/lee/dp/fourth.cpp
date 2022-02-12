#include <string>
#include <vector>
#include <cmath>

using namespace std;
int answer = 0;

int solution(vector<int> money) {
   int first_answer = 0;
	int second_answer = 0;
    int first[1000001]; //처음 집 방문시
    int second[1000001]; //처음 집 방문시
    first[0] = money[0];
    first[1] = money[0];
    second[0] = 0;
    second[1] = money[1];
    int i,j;
    for(i=2;i<money.size()-1;i++){
        first[i] = max(first[i-2]+money[i], first[i-1]);
	first_answer = first[i];
    }
    for(j=2;j<money.size();j++){
        second[j] = max(second[j-2]+money[j], second[j-1]);
        second_answer = second[i];
    }
    answer = max(first_answer,second_answer);  
    return answer;
}