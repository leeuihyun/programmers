#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <iostream>
#include <cstring>

using namespace std;
vector <string> v1;
vector <string> v2;

string div(string str){
    for(int i=0;i<str.size();i++){
        str[i] = toupper(str[i]);
    }
    return str;
}
int solution(string str1, string str2) {
    int max_number = 0;
    int min_number = 0;
    double answer;
    str1 = div(str1);
    str2 = div(str2);
    cout << str1 << "\n";
    cout << str2 << "\n";
    for(int i=0;i<str1.size()-1;i++){
        string s = "";
        if(str1[i]>='A' && str1[i]<='Z'){
            if(str1[i+1]>='A' && str1[i+1]<='Z'){
                s+=str1[i];
                s+=str1[i+1];
                v1.push_back(s);
            }
        }
    }
    for(int i=0;i<v1.size();i++){
        cout << v1[i] << " ";
    }
    cout << "\n";
    for(int i=0;i<str2.size()-1;i++){
        string s = "";
        if(str2[i]>='A' && str2[i]<='Z'){
            if(str2[i+1]>='A' && str2[i+1]<='Z'){
                s+=str2[i];
                s+=str2[i+1];
                v2.push_back(s);
            }
        }
    }
    for(int i=0;i<v2.size();i++){
        cout << v2[i] << " ";
    }
    cout << "\n";
    
    if(v1.size()==0 && v2.size()==0) return 65536;
    max_number += v1.size();
    max_number += v2.size();
    
    if(v1.size() < v2.size()){
        for(int i=0;i<v1.size();i++){
            for(int j=0;j<v2.size();j++){
                if(v1[i]==v2[j]) {
                    min_number+=1;   
                    v2.erase(v2.begin()+j);
                    break;
                }
            }        
        }
    }
    else{
        for(int i=0;i<v2.size();i++){
            for(int j=0;j<v1.size();j++){
                if(v2[i]==v1[j]) {
                    min_number+=1;
                    v1.erase(v1.begin()+j);
                    break;
                }
            }
        }
    }
    max_number -= min_number;
    cout <<max_number << " " << min_number << "\n";
    if(max_number==0) return 65536;
    answer = (double)min_number/(double)max_number;
    return answer*65536;
}