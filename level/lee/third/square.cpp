#include <iostream>
//#include <cmath>
using namespace std;

long long gcd(long long w,long long h){
    if(h==0) return w;
    return gcd(h,w%h);
}
long long solution(int w,int h) {
    long long answer = 0;
    long long number = gcd((long long)w,(long long)h);
    long long mul = (long long)w*h;
    long long minus = (w+h-number);
    answer = mul - minus;
    return answer;
}