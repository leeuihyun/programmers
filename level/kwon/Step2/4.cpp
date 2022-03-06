#include <string>
#include <vector>

using namespace std;

vector<vector<int>> keyInit() {
    vector<vector<int>> key(13, vector<int>(13, 0));
    int data = 0;
    
    for(int i = 1; i < 13; i++) {
        for(int j = 1; j < 13; j++) {
            if(i >= j)
                data = (i - j) / 3 + (i - j) % 3;
            else
                data = (j - i) / 3 + (j - i) % 3;
            key[i][j] = data;
        }
    }
    
    return key;
}

string solution(vector<int> numbers, string hand) {
    string answer = "";
    
    int l = 10, r = 12;
    
    vector<vector<int>> key;
    
    key = keyInit();
    
    for(auto num : numbers) {
        if(num == 0)
            num = 11;
        else if(num == 1 || num == 4 || num == 7) {
            answer += 'L';
            l = num;
            continue;
        }
        else if(num == 3 || num == 6 || num == 9) {
            answer += 'R';
            r = num;
            continue;
        }
        
        if(key[l][num] == key[r][num])
            if(hand == "left") {
                answer += 'L';
                l = num;
            }
            else {
                answer += 'R';
                r = num;
            }
        else if(key[l][num] < key[r][num]) {
            answer += 'L';
            l = num;
        }
        else {
            answer += 'R';
            r = num;
        }
    }
    
    return answer;
}