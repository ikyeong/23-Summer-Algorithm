#include <iostream>
using namespace std;
int n, count;
bool board[15][15];

bool promising(int x, int y){
    for (int i=1;i<=x;i++){
        //세로
        if (board[x-i][y]) return false;
        //왼쪽 대각선
        if (y-i>=0 && board[x-i][y-i]) return false;
        //오른쪽 대각선
        if (y+i<n && board[x-i][y+i]) return false;
    }
    return true;
}

void queen(int x){
    if (x==n){
        count++;
        return;
    }
    for (int i=0;i<n;i++){
        if (promising(x,i)){
            board[x][i] = true;
            queen(x+1);
            board[x][i] = false;
        }
    }
}

int main(){
    cin>>n;
    queen(0);
    cout<<count<<endl;
    return 0;
}
