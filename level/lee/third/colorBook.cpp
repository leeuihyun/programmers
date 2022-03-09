#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>

using namespace std;

int dx[] = { 0, 0, 1, -1 };
int dy[] = { 1, -1, 0, 0 };

bool visited[100][100];

int solve(int x,int y,int m,int n,vector<vector<int>> v){
    int first = v[x][y];
    queue<pair<int,int>> q;
    int cnt = 1;
    q.push({x,y});
    visited[x][y] = true;
    while(!q.empty()){
        int cx = q.front().first;
        int cy = q.front().second;
        q.pop();
        for(int i=0;i<4;i++){
            int nx = cx+dx[i];
            int ny = cy+dy[i];
            if(nx>=0 && ny>=0 && nx < m && ny < n){
                if(v[nx][ny] == first && !visited[nx][ny]){
                    q.push({nx,ny});
                    visited[nx][ny] = true;
                    cnt+=1;
                }    
            }
            
        }
    }
    return cnt;
}
// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
vector<int> solution(int m, int n, vector<vector<int>> picture) {
    int number_of_area = 0;
    int max_size_of_one_area = 0;
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            visited[i][j] = false;
        }
    }
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(picture[i][j]!=0 && !visited[i][j]){
                int tmp = solve(i,j,m,n,picture);                
                if(tmp>max_size_of_one_area) max_size_of_one_area= tmp;
                number_of_area+=1;
            }
        }
    }
    
    vector<int> answer(2);
    answer[0] = number_of_area;
    answer[1] = max_size_of_one_area;
    return answer;
}