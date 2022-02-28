#include <string>
#include <vector>

using namespace std;

int rank_lotto(int n) {
    switch (n) {
    case 6:
        return 1;
    case 5:
        return 2;
    case 4:
        return 3;
    case 3:
        return 4;
    case 2:
        return 5;
    default:
        return 6;
    }
}

vector<int> solution(vector<int> lottos, vector<int> win_nums) {
    vector<int> answer;
    
    int zero_cnt = 0, num_cnt = 0;
    
    for(int i = 0; i < 6; i++) {
        if(lottos[i] == 0) {
            zero_cnt++;
            continue;
        }
        for(int j = 0; j < 6; j++) {
            if(lottos[i] == win_nums[j]) {
                num_cnt++;
                break;
            }
        }
    }
    
    answer.push_back(rank_lotto(num_cnt + zero_cnt));
    answer.push_back(rank_lotto(num_cnt));
    
    return answer;
}