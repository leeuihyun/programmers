#include <string>
#include <vector>
#include <cmath>
#include <iostream>

using namespace std;

int solution(vector<vector<int>> triangle) {
    int answer = 0;
    int size = triangle.size();
    for(int i=1;i<triangle.size();i++){
        for(int j=0;j<triangle[i].size();j++){
            if(j==0){
                triangle[i][j] += triangle[i-1][j];
            }
            else if(j==triangle[i].size()-1){
                triangle[i][j] += triangle[i-1][j-1];
            }
            else{
                triangle[i][j]+= max(triangle[i-1][j-1],triangle[i-1][j]);
            }
            
        }
    }
    answer = 0;
    for(int i=0;i<triangle[size-1].size();i++){
        answer = max(triangle[size-1][i],answer);
    }
    return answer;
}