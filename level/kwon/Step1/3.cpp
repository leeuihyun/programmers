#include <string>
#include <vector>

using namespace std;

string solution(string new_id) {
    string answer = "";
    
    for(int i = 0; i < new_id.length(); i++) {
        if(new_id[i] >= 97 && new_id[i] <= 122)
            continue;
        else if(new_id[i] >= 48 && new_id[i] <= 57)
            continue;
        else if(new_id[i] >= 65 && new_id[i] <= 90) {
            new_id[i] += 32;
            continue;
        }
        else if(new_id[i] == 45 || new_id[i] == 46 || new_id[i] == 95)
            continue;
        new_id.erase(i, 1);
        i--;
    }
    
    int index = 0;
    while(index < new_id.length()) {
        if(new_id[index] == 46) {
            int cnt = 0;
            for(int i = index + 1; i < new_id.length(); i++) {
                if(new_id[i] != 46)
                    break;
                cnt++;
            }
            new_id.erase(index + 1, cnt);
        }
        index++;
    }
    
    if(new_id[0] == 46)
        new_id.erase(0, 1);
    
    if(new_id[new_id.length() - 1] == 46)
        new_id.erase(new_id.length() - 1, 1);
    
    if(new_id.length() == 0)
        new_id = "a";
    
    if(new_id.length() > 15) {
        new_id.erase(15);
        if(new_id[new_id.length() - 1] == 46)
            new_id.erase(new_id.length() - 1);
    }
    else if(new_id.length() < 3) {
        char c = new_id[new_id.length() - 1];
        while(new_id.length() < 3)
            new_id += c;
    }
    
    answer = new_id;
    
    return answer;
}