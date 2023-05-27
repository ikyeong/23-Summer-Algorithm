#include <iostream>
#include <deque>
using namespace std;
/*
뱀
rule
    1.뱀은 몸 길이를 늘려 다음칸에 위치
    2.벽 또는 자기자신과 부딪히면 끝
    3.이동한 칸에 사과가 있다면 사과가 없어지고 꼬리는 안움직임
    4.사과가 없으면 꼬리가 위치한 칸을 비워준다 (length 변환 없음)

*/

int n, k, l; //n : 보드의 크기, k : 사과의 개수, l : 뱀의 방향 변환 횟수
int count; // 게임 종료까지 걸린 시간
bool isApple[101][101]; // 사과 존재 여부
bool isSnake[101][101] = {true, false, }; // 뱀 존재 여부
deque<pair<int,char>> rotation; // 방향 전환 저장

int main(){
    //input
    cin>>n;
    cin>>k;
    for (int i=0;i<k;i++){
        int x,y;
        cin>>x>>y;
        isApple[x][y] = true;
    }
    cin>>l;
    for (int i=0;i<l;i++){
        int x;
        char c;
        cin>>x>>c;
        rotation.push_back(pair<int,char>(x,c));
    }

    int head = 1; // 시계방향부터 0,1,2,3
    deque<pair<int,int>> snake; // 뱀의 위치 저장
    snake.push_back(pair<int,int>(1,1));

    while (true){
        count++; // 카운트 증가
        // 한칸 이동
        int x = snake.front().first, y = snake.front().second;
        if (head == 0){
            snake.push_front(pair<int,int>(x-1,y));
        }else if (head == 1){
            snake.push_front(pair<int,int>(x,y+1));
        }else if (head == 2){
            snake.push_front(pair<int,int>(x+1,y));
        }else{
            snake.push_front(pair<int,int>(x,y-1));
        }

        // 벽에 부딪힌 경우
        x = snake.front().first;
        y = snake.front().second;
        if (x < 1 || x > n || y < 1 || y > n) break;
        //뱀에 부딪힌 경우
        if (isSnake[x][y]) break;
        //isSnake 업데이트
        isSnake[x][y] = true;

        // 사과 여부 확인
        if (isApple[x][y]) isApple[x][y] = false;
        else {
            pair<int,int> tail = snake.back();
            snake.pop_back();
            isSnake[tail.first][tail.second] = false;
        }

        //방향 바꾸기
        if (rotation.front().first == count){
            char direct = rotation.front().second;
            rotation.pop_front();
            if (direct == 'L') head = (head + 3) % 4;
            else head = (head + 1) % 4;    
        }
    }

    cout<<count<<endl;

    return 0;
}
