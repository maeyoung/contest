#include <cstdio>
#include <iostream>
#include <string>

using namespace std;

int main(){
    long int sum = 0;
    int p = 0;
    long int submul = 1;
    string c;
    cin >> c ;
    int len = c.length();
    for(int i=len-1;i>=0;i--){
        submul = 1;
        for(int j = len-1; j>i;j--){
            submul *= 26;
        }
        sum += submul * (c[i] - 'A'+1);
    }
    cout << sum << endl;
}