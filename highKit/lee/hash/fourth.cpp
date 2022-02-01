#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

bool first_compare(pair<string,pair<int,int>>a, pair<string,pair<int,int>>b){
    if(a.second.first==b.second.first){
        return a.second.second < b.second.second;
    }   
    else{
        return a.second.first > b.second.first;
    }
}

bool second_compare(pair<string,int> a, pair<string,int> b){
    return a.second > b.second;
}

vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
    vector <pair<string,pair<int,int>>> v; //genres,plays,고유번호
    map <string,int> maps;
    vector <pair<string,int>> v1;
    for(int i=0;i<genres.size();i++){
        maps[genres[i]]+=plays[i];
        v.push_back(make_pair(genres[i],make_pair(plays[i],i)));
    }
    sort(v.begin(),v.end(), first_compare);
    copy(maps.begin(),maps.end(),back_inserter(v1));
    sort(v1.begin(),v1.end(),second_compare);
    
    for(int i=0;i<v1.size();i++){
        int cnt = 0;
        for(int j = 0;j<v.size();j++){
            if(v1[i].first == v[j].first){
                cnt+=1;
                answer.push_back(v[j].second.second);
            }
            if(cnt==2) break;
        }
    }
    return answer;
}