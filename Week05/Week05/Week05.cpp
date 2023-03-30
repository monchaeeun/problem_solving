#include <iostream>
#include <queue>
using namespace std;

const int MAX_SIZE = 5; // 맵 크기
int map[MAX_SIZE][MAX_SIZE] = {
    {0, 0, 0, 0, 0},
    {0, 1, 1, 1, 0},
    {0, 0, 0, 1, 0},
    {0, 1, 1, 1, 0},
    {0, 0, 0, 0, 0}
}; // 맵 데이터

// 노드 클래스
class Node {
public:
    int x;
    int y;
    Node(int x, int y) {
        this->x = x;
        this->y = y;
    }
};

// BFS 탐색 함수
void bfs(int startX, int startY) {
    queue<Node> q; // 큐 생성
    q.push(Node(startX, startY)); // 시작 노드 큐에 추가
    while (!q.empty()) { // 큐가 비어있지 않은 동안 반복
        Node curNode = q.front(); // 큐 맨 앞 노드 가져오기
        q.pop(); // 큐 맨 앞 노드 제거
        int curX = curNode.x;
        int curY = curNode.y;
        cout << "(" << curX << "," << curY << ")" << endl; // 현재 위치 출력
        // 현재 위치에서 상하좌우로 이동 가능한 위치 큐에 추가
        if (curX - 1 >= 0 && map[curX - 1][curY] == 1) { // 위로 이동 가능한 경우
            q.push(Node(curX - 1, curY));
            map[curX - 1][curY] = 2; // 이동한 위치 표시
        }
        if (curX + 1 < MAX_SIZE && map[curX + 1][curY] == 1) { // 아래로 이동 가능한 경우
            q.push(Node(curX + 1, curY));
            map[curX + 1][curY] = 2; // 이동한 위치 표시
        }
        if (curY - 1 >= 0 && map[curX][curY - 1] == 1) { // 왼쪽으로 이동 가능한 경우
            q.push(Node(curX, curY - 1));
            map[curX][curY - 1] = 2; // 이동한 위치 표시
        }
        if (curY + 1 < MAX_SIZE && map[curX][curY + 1] == 1) { // 오른쪽으로 이동 가능한 경우
            q.push(Node(curX, curY + 1));
            map[curX][curY + 1] = 2; // 이동한 위치 표시
        }
    }
}

// 맵 출력 함수
void printMap() {
    for (int i = 0; i < MAX_SIZE; i++) {
        for (int j = 0; j < MAX_SIZE; j++) {
            if (map[i][j] == 0) {
                cout << "■ "; // 벽
            }
            else if (map[i][j] == 1) {
                cout << "□ "; // 길
            }
            else if (map[i][j] == 2) {
                cout << "★ "; // 방문한 위치
            }
        }
        cout << endl;
    }
}

int main() {
    int startX = 1; // 시작 X 위치
    int startY = 1; // 시작 Y 위치
    bfs(startX, startY); // BFS 탐색 시작
    while (true) { // 사용자 입력 반복
        printMap(); // 맵 출력
        char c;
        cin >> c; // 사용자 입력 받기
        int newX = startX;
        int newY = startY;
        // 사용자 입력에 따라 새로운 위치 계산
        if (c == 'w') { // 위쪽으로 이동
            newX--;
        }
        else if (c == 's') { // 아래쪽으로 이동
            newX++;
        }
        else if (c == 'a') { // 왼쪽으로 이동
            newY--;
        }
        else if (c == 'd') { // 오른쪽으로 이동
            newY++;
        }
        else if (c == 'q') { // 종료
            break;
        }
        // 새로운 위치가 유효한지 확인
        if (newX < 0 || newX >= MAX_SIZE || newY < 0 || newY >= MAX_SIZE) {
            continue; // 유효하지 않은 위치면 무시하고 반복 계속
        }
        if (map[newX][newY] == 0) {
            continue; // 벽이면 무시하고 반복 계속
        }
        startX = newX; // 새로운 위치로 이동
        startY = newY;
    }
    return 0;
}


