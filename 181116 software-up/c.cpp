#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

struct book{
    int date;
    int page;
};

int maxpage = 0;
int N, C; // N = 남은 날짜 C = chapter 수
book arr[]={};

void knapsack(int i, int page, int date);
bool promising(int i, int page, int date);

bool cmp(book a, book b){
    double r1 = (double)(a.page / a.date);
    double r2 = (double)(b.page / b.date);
    return r1>r2;
}
int main(void){
    cin >> N >> C;

    for(int i=0;i<C;i++){
        cin >> arr[i].date >> arr[i].page;
    }
    arr[C].date = 0;
    arr[C].page = 0;
    sort(arr, arr+C, cmp);
    knapsack(0, arr[0].page, arr[0].date);
    cout<<maxpage<<endl;
    return 0;
}

void knapsack(int i, int page, int date){
    if(date <= N && page > maxpage){
        maxpage = page;
    }
    if(promising(i,  page, date)){
        knapsack(i+1, page + arr[i+1].page, date+arr[i+1].date); // include
        knapsack(i+1, page, date); // not include
    }
}

bool promising(int i, int page, int date){
    int j;
    int totdate;
    float bound;
    if(date >= N){
        return false;
    }
    else{
        j = i+1;
        bound = page;
        totdate = date;
        while((j <= C) && (totdate+arr[j].date <= N)){
            totdate = totdate + arr[j].date;
            bound = bound + arr[j].page;
            j++;
        }
        if(j <= C){
            bound = bound + (N - totdate)*(arr[j].page/arr[j].date);
        }
    }
    return bound > maxpage;
}