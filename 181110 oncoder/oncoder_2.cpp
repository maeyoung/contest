#include <string>
#include <iostream>
#include <stdlib.h>
using namespace std;

//핵심 소스코드의 설명을 주석으로 작성하면 평가에 큰 도움이 됩니다.
class Solution{
public:
    int solution(string k, string w){
        int location[51];
        int sum = 0;
        
        for (int i=0; i<w.length();i++) { // w의 값을 차례대로 설정
            for (int j=0; j<k.length();j++) { // k의 값을 차례대로 설정
                if (w[i]==k[j]) location[i]=j; // w[i]값과 k의 값들을 순서대로 비교해서 위치값을 찾는다.
            }
        }
        for (int i=0; i<w.length()-1; i++) { // 단어의 길이-1 만큼 반복한다.
            sum += abs(location[i+1]-location[i]); 
            // 키보드 시작위치에서 다음 이동 위치의 값을 뺀만큼의 절댓값을 sum에 더해준다.
        }
        
        return sum;
    }
};