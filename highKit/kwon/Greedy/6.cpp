#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> routes) {
    int answer = 0, location;
    
    struct {
        bool operator()(vector<int> a, vector<int> b) {
            return a[1] < b[1];
        }
    } cmp;
    
    sort(routes.begin(), routes.end(), cmp);
    
    location = routes[0][1];
    
    for(int i = 1; i < routes.size(); i++) {
        if(routes[i][0] > location) {
            answer++;
            location = routes[i][1];
        }
    }
    answer++;
    
    return answer;
}
