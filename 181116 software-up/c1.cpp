#include <iostream>
#include <time.h>

using namespace std;

// int p[5] = {0, 40, 30, 50, 10}; //profit
// int w[5] = {0, 2, 5, 10, 5}; //weight
// int W = 16; //max weight
int W;
int C;
int maxprofit = 0;
// int ncount = 0; // variance to count number of visited node

typedef struct node{
    int level;
    int profit;
    int weight;
    int bound;
}node;
node arr[]= {};
class Queue{ //priority queue implementation
    private:
    node* queue;
    int front, rear, capacity;
    public:
    Queue();
    bool empty();
    void push(node& item);
    node& pop();
};

Queue::Queue(){
    capacity = 40;
    queue = new node[capacity];
    front=rear=0;
}

bool Queue::empty(){return front==rear;}

void Queue::push(node& item){
    queue[rear++]=item;
    int i = 0, j = 0;
    for(i = front; i < rear-1; i++){ //sort by bound size
        for(j = i+1; j <= rear; j++){
            if(queue[j].bound > queue[i].bound){
                node tmp;
                tmp=queue[j];
                queue[j] = queue[i];
                queue[i] = tmp;
            }
        }
    }
}

node& Queue::pop(){
    return queue[front++];
}

void knapsack3(int C);
int bound(node m);

int main(void){
    cin >> W >> C;

    for(int i=0;i<C;i++){
        cin >> arr[i].weight >> arr[i].profit;
    }
    knapsack3(C);
    cout<<maxprofit<<endl;
    return 0;
}

int bound(node m, int C){
    int j, k;
    int totweight;
    int result;
    if(m.weight >= W){
        return 0;
    }
    else{
        result = m.profit;
        j = m.level+1;
        totweight=m.weight;
        while((j <= C) && (totweight+arr[j].weight <= W)){
            totweight = totweight+arr[j].weight;
            result = result + arr[j].profit;
            j++;
        }
        k = j;
        if(k <= C){
            result = result + (W-totweight)*(arr[k].profit/arr[k].weight);
        }
        return result;
    }
}

void knapsack3(int C){
    Queue q;
    node u, v;
    v.level = 0;
    v.profit = 0;
    v.weight = 0;
    v.bound = bound(v, C);

    q.push(v);
    while(!q.empty()){
        v=q.pop();
        if(v.bound > maxprofit){
            u.level = v.level + 1;
            u.profit = v.profit+arr[u.level].profit;
            u.weight = v.weight+arr[u.level].weight;
            if((u.weight <= W) && (u.profit>maxprofit)){
                maxprofit = u.profit;
            }
            u.bound = bound(u, C);
            if(u.bound > maxprofit){
                q.push(u);
             
            }
            u.weight = v.weight;
            u.profit = v.profit;
            u.bound = bound(u, C);
            if(u.bound > maxprofit){
                q.push(u);
             
            }
        }
    }
}

