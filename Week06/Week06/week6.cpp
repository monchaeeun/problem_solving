#include <iostream>
#include <queue>
#include <vector>

using namespace std;

const int MAX_SIZE = 1000;

int board[MAX_SIZE][MAX_SIZE];  // 맵의 정보를 저장할 배열
bool visited[MAX_SIZE][MAX_SIZE];  // 해당 위치를 방문했는지 여부를 저장할 배열

struct Point {
    int x, y, dist;
};

// 시작 위치에서부터 BFS 탐색을 시작하는 함수
int bfs(int startX, int startY, int endX, int endY, int sizeX, int sizeY) {
    queue<Point> q;
    q.push({ startX, startY, 0 });  // 시작 위치와 거리 정보를 큐에 넣음
    visited[startX][startY] = true;  // 시작 위치는 이미 방문한 것으로 처리

    while (!q.empty()) {
        Point cur = q.front();
        q.pop();

        // 현재 위치가 목적지인 경우 거리를 반환
        if (cur.x == endX && cur.y == endY) {
            return cur.dist;
        }

        // 인접한 위치를 확인하며 BFS 탐색
        vector<pair<int, int>> directions = { {-1, 0}, {1, 0}, {0, -1}, {0, 1} };
        for (const auto& dir : directions) {
            int nextX = cur.x + dir.first;
            int nextY = cur.y + dir.second;

            // 범위를 벗어난 경우 무시
            if (nextX < 0 || nextX >= sizeX || nextY < 0 || nextY >= sizeY) {
                continue;
            }

            // 장애물이 있는 경우 무시
            if (board[nextX][nextY] == 1) {
                continue;
            }

            // 이미 방문한 위치인 경우 무시
            if (visited[nextX][nextY]) {
                continue;
            }

            // 다음 위치를 큐에 넣고 방문 처리
            q.push({ nextX, nextY, cur.dist + 1 });
            visited[nextX][nextY] = true;
        }
    }
    // 도착점에 도달할 수 없는 경우 -1 반환
    return -1;
}

int main() {
    int sizeX, sizeY;
    cin >> sizeX >> sizeY;
    int startX, startY, endX, endY;
    cin >> startX >> startY >> endX >> endY;

    for (int i = 0; i < sizeX; i++) {
        for (int j = 0; j < sizeY; j++) {
            char ch;
            cin >> ch;
            if (ch == 'S') {
                board[i][j] = 0;
                startX = i;
                startY = j;
            }
            else if (ch == 'G') {
                board[i][j] = 0;
                endX = i;
                endY = j;
            }
            else {
                board[i][j] = 1;
            }
        }
    }

    int dist = bfs(startX, startY, endX, endY, sizeX, sizeY);
    cout << dist << endl;

    return 0;
}