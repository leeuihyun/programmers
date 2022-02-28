#include <string>
#include <vector>
#include <sstream>
#include <time.h>
#include <algorithm>
#include <cmath>

using namespace std;

struct tm makeTime(int y, int m, int d, int hh, int mm, int ss, int diff_ss) {
    struct tm tm;
    
    tm.tm_year = y;
    tm.tm_mon = m;
    tm.tm_mday = d;
    tm.tm_hour = hh;
    tm.tm_min = mm;
    tm.tm_sec = ss;
        
    tm.tm_sec -= diff_ss;
        
    mktime(&tm);
    
    return tm;
}

bool chk(pair<vector<int>, vector<int>> a, vector<int> b) {
    if(b >= a.first && b <= a.second)
        return true;
    return false;
}

int solution(vector<string> lines) {
    int answer = 0;
    
    struct tm start, end, cmp_tm;
    vector<int> start_v, end_v, cmp_v;
    vector<pair<vector<int>, vector<int>>> time_v;
    vector<pair<struct tm, struct tm>> tm_v;
    
    int yyyy, mm, dd;
    int hour, min, sec, t_sec;
    double start_mSec = 0, end_mSec = 0, t_mSec = 0;
    int cnt = 0;
    
    for(auto i : lines) {
        stringstream ss(i);
        string s;
        
        ss >> s;
        yyyy = stoi(s.substr(0, 4));
        mm = stoi(s.substr(5, 2));
        dd = stoi(s.substr(8));
        
        ss >> s;
        hour = stoi(s.substr(0, 2));
        min = stoi(s.substr(3, 2));
        sec = stoi(s.substr(6, 2));
        end_mSec = stod(s.substr(6)) - sec;
        end_mSec *= 1000;
        
        ss >> s;
        s.erase(s.size() - 1, 1);
        t_sec = stoi(s.substr(0, 1));
        if(s.size() > 2)
            t_mSec = stod(s.substr(0)) - t_sec;
        else
            t_mSec = 0;
        t_mSec *= 1000;
        
        end = makeTime(yyyy, mm, dd, hour, min, sec, 0);
        
        if(end_mSec < t_mSec) {
            start_mSec = 1001 + end_mSec - t_mSec;
            start = makeTime(yyyy, mm, dd, hour, min, sec, 1 + t_sec);
        }
        else {
            start_mSec = 1 + end_mSec - t_mSec;
            start = makeTime(yyyy, mm, dd, hour, min, sec, t_sec);
        }
        
        start_v = {start.tm_year, start.tm_mon, start.tm_mday,
                   start.tm_hour, start.tm_min, start.tm_sec, (int)round(start_mSec)};
        end_v = {end.tm_year, end.tm_mon, end.tm_mday,
                end.tm_hour, end.tm_min, end.tm_sec, (int)round(end_mSec)};
        
        time_v.push_back({start_v, end_v});
        tm_v.push_back({start, end});
    }
    
    for(int i = 0; i < tm_v.size(); i++) {
        // 해당 index의 요청 시간 -1 범위
        cnt = 1;
        cmp_tm = tm_v[i].first;
        cmp_tm.tm_sec -= 1;
        mktime(&cmp_tm);
        cmp_v = {cmp_tm.tm_year, cmp_tm.tm_mon, cmp_tm.tm_mday,
                cmp_tm.tm_hour, cmp_tm.tm_min, cmp_tm.tm_sec, time_v[i].first[6] + 1};
        for(int j = 0; j < tm_v.size(); j++) {
            if(j == i)  continue;
            if(chk(time_v[j], cmp_v) || chk(time_v[j], time_v[i].first))
                cnt++;
        }
        answer = max(answer, cnt);
        
        // 해당 index의 요청시간 +1 범위
        cnt = 1;
        cmp_tm = tm_v[i].first;
        cmp_tm.tm_sec += 1;
        mktime(&cmp_tm);
        cmp_v = {cmp_tm.tm_year, cmp_tm.tm_mon, cmp_tm.tm_mday,
                cmp_tm.tm_hour, cmp_tm.tm_min, cmp_tm.tm_sec, time_v[i].first[6] - 1};
        for(int j = 0; j < tm_v.size(); j++) {
            if(j == i)  continue;
            if(chk(time_v[j], cmp_v) || chk(time_v[j], time_v[i].first))
                cnt++;
        }
        answer = max(answer, cnt);

        // 해당 index의 응답완료시간 -1 범위
        cnt = 1;
        cmp_tm = tm_v[i].second;
        cmp_tm.tm_sec -= 1;
        mktime(&cmp_tm);
        cmp_v = {cmp_tm.tm_year, cmp_tm.tm_mon, cmp_tm.tm_mday,
                cmp_tm.tm_hour, cmp_tm.tm_min, cmp_tm.tm_sec, time_v[i].first[6] + 1};
        
        for(int j = 0; j < tm_v.size(); j++) {
            if(j == i)  continue;
            if(chk(time_v[j], cmp_v) || chk(time_v[j], time_v[i].second))
                cnt++;
        }
        answer = max(answer, cnt);

        // 해당 index의 응답완료시간 +1 범위
        cnt = 1;
        cmp_tm = tm_v[i].second;
        cmp_tm.tm_sec += 1;
        mktime(&cmp_tm);
        cmp_v = {cmp_tm.tm_year, cmp_tm.tm_mon, cmp_tm.tm_mday,
                cmp_tm.tm_hour, cmp_tm.tm_min, cmp_tm.tm_sec, time_v[i].second[6] - 1};
        for(int j = 0; j < tm_v.size(); j++) {
            if(j == i)  continue;
            if(chk(time_v[j], cmp_v) || chk(time_v[j], time_v[i].second))
                cnt++;
        }
        answer = max(answer, cnt);
    }
    
    return answer;
}