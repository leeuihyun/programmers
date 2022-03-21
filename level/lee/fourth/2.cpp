#include <string>
#include <vector>

using namespace std;
int arr[101][101];
vector<int> solution(int row, int columns, vector<vector<int>> queries) {
    vector<int> answer;
    int number= 1;
    for(int i=0;i<row;i++){
        for(int j=0;j<columns;j++){
            arr[i][j] = number;
            number+=1;
        }
    }
    for(int i=0;i<queries.size();i++){
        int y1 = queries[i][0]-1;
        int x1 = queries[i][1]-1;
        int y2 = queries[i][2]-1;
        int x2 = queries[i][3]-1;
        
        int min_number = arr[y1][x1];
        int tmp = arr[y1][x1];
        for(int i=y1;i<y2;i++){
            arr[i][x1]=arr[i+1][x1];
            min_number = min(min_number,arr[i+1][x1]);
        }
        for(int j=x1;j<x2;j++){
            arr[y2][j] = arr[y2][j+1];
            min_number = min(min_number,arr[y2][j+1]);
        }
        for(int i=y2;i>y1;i--){
            arr[i][x2] = arr[i-1][x2];
            min_number = min(min_number,arr[i-1][x2]);
        }
        for(int j=x2;j>x1+1;j--){
            arr[y1][j] = arr[y1][j-1];
            min_number = min(min_number,arr[y1][j-1]);
        }
        arr[y1][x1+1]=tmp;
        answer.push_back(min_number);
    }
    return answer;
}