#include <string>
#include <vector>
#include <stack>

using namespace std;

int solution(vector<vector<int>> board, vector<int> moves) {
    int answer = 0, size = board.size();
    
    vector<stack<int>> dollBox(size);
    
    for(int i = size - 1; i >= 0; i--)
        for(int j = 0; j < board[i].size(); j++)
            if(board[i][j])
                dollBox[j].push(board[i][j]);
    
    stack<int> basket;
    
    for(int i = 0; i < moves.size(); i++) {
        int num = moves[i] - 1;
        if(dollBox[num].empty())
            continue;
        int doll = dollBox[num].top();
        dollBox[num].pop();
        
        if(!basket.empty() && basket.top() == doll) {
            basket.pop();
            answer += 2;
        }
        else
            basket.push(doll);
    }
    
    return answer;
}