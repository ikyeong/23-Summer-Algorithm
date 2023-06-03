#include <iostream>
#include <deque>
using namespace std;
int n, k, visit[100001];
deque<int> dq;

int main(){
    cin>>n>>k;
    visit[n] = 1;
    dq.push_back(n);
    //solve
    while (!dq.empty()){
        int loc = dq.front();
        dq.pop_front();

        if (loc == k) {
            cout<<visit[loc]-1<<endl;
            break;
        }

        if (loc * 2 <= 100000 && !visit[loc*2]){
            visit[loc*2] = visit[loc];
            dq.push_front(loc*2);
        }
        if (loc + 1 <= 100000 && !visit[loc+1]){
            visit[loc+1] = visit[loc] + 1;
            dq.push_back(loc+1);
        }
        if (loc - 1 >= 0 && !visit[loc-1]){
            visit[loc-1] = visit[loc] + 1;
            dq.push_back(loc-1);
        }
    }
    return 0;
}
