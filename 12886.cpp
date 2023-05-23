#include <iostream>
#include <queue>
using namespace std;
bool visit[1000][1000]; //그냥 안전하게 다 더한걸로 해주는게 나은듯...
int sum, res = 0;

void change(int x, int y){ //값이 2개만 주어지면 sum을 통해서 나머지 값을 알 수 있음
    if (x == sum/3 && y == sum/3){
        res = 1;
        return;
    }
    // cout<<"x y : "<<x<<" "<<y<<endl;
    if (visit[x][y]) return;
    visit[x][y] = true;

    int num[3] = {x,y,sum-x-y};
    for (int i=0;i<3;i++){
        for (int j=0;j<3;j++){
            if (res == 1) break;
            if (num[i] < num[j]){
                change(2*num[i],num[j]-num[i]);
            }
        }
    }
}


int main(){
    int a,b,c;
    cin>>a>>b>>c;

    sum = a+b+c;

    //3으로 나눠떨어지지 않는 경우
    if (sum % 3 != 0){
        cout<<res<<endl;
        return 0;
    }

    change(a,b);

    cout<<res<<endl;
    return 0;
}
