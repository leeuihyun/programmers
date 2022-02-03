#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int checkPrime(int n){
    if(n==0 || n==1) return 0;
    for(int i=2;i<=sqrt(n);i++){
        if(n%i==0) return 0;
    }
    return 1;
}
int solution(string numbers) {
    int arr[9999999] = {0,};
    bool visited[9999999] = {false,};
    vector<int> answer;
    //int mn = 0;
    //sort(numbers.begin(),numbers.end(),greater<>());
    //mn = stoi(numbers);
    sort(numbers.begin(),numbers.end());
    //에라토스테네스의체
    /*
    arr[0] = -1;
    arr[1] = -1;
    for(int i=2;i<=mn;i++){
        if(arr[i]==-1) continue;
        for(int j=i*i;j<=mn;j+=i){
            arr[j] = -1;
        }
    }*/
    do{
        for(int i=1;i<=numbers.size();i++){
            
            
            int num = stoi(numbers.substr(0,i));
            if(checkPrime(num) && !visited[num]) {
                answer.push_back(num);
                cout << num << "\n";
            }
            
            /*if(arr[num]==0 && !visited[num]){
                answer+=1;
                visited[num] = true;
            }*/
        }
    }while(next_permutation(numbers.begin(),numbers.end()));
    sort(answer.begin(),answer.end());
    answer.erase(unique(answer.begin(),answer.end()),answer.end());
    return answer.size();
}