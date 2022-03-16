#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
#include <cmath>

using namespace std;

int solution(vector<string> lines) {
    int answer = 0;
    
    vector<pair<double, double>> log;
    
    double yyyy, mm, dd, hour, min, sec, mSec;
    
    for(auto i : lines) {
        stringstream ss(i);
        string s;
        ss >> s;
        
        yyyy = stod(s.substr(0, 4));
        mm = stod(s.substr(5, 2));
        dd = stod(s.substr(8));
        
        ss >> s;
        hour = stod(s.substr(0, 2));
        min = stod(s.substr(3, 2));
        sec = stod(s.substr(6, 2));
        mSec = stod(s.substr(6)) - sec;
        
        sec += yyyy * 365 * 24 * 60 * 60;
        sec += mm * 30 * 24 * 60 * 60;
        sec += dd * 24 * 60 * 60;
        sec += hour * 60 * 60;
        sec += min * 60;
        sec += mSec;
        
        ss >> s;
        s.erase(s.size() - 1, 1);
        
        log.push_back({sec - stod(s) + 0.001, sec});
    }
    
    for(int i = 0; i < log.size(); i++) {
        double cmp = log[i].second + 0.999;
        int cnt = 1;
        for(int j = i + 1; j < log.size(); j++) {
            if(cmp >= log[j].first)
                cnt++;
        }
        answer = max(answer, cnt);
    }
    
    return answer;
}