//핵심 소스코드의 설명을 주석으로 작성하면 평가에 큰 도움이 됩니다.
class Solution{
public:
    #include <cstdio>

    int find(int left, int right){
        int count = 0;
        
        for (int i=left; i<=right; i++) {
            char num[1000001];
            sprintf(num, "%1d", i); // left와 right사이에 숫자를 차례로 num[]에 저장
            for (int j=0; num[j+1]!='\0'; j++) {
                if (num[j]==51 && num[j+1]==54) {  
                    // char와 int를 비교하기 위해 3과 6에 각각 48씩 더해줌
                    count++; // 배열에 3과 6이 순서대로 종료하면 count해줌
                    break; // 36이 한번 존재하면 for문 종료
                }    
            }
        }
        
        
        return count;
    }
};