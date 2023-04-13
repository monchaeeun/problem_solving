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

            // 다음 위치를 큐에 넣음
            q.push({ nextX, nextY, cur.dist + 1 });
            visited[nextX][nextY] = true;  // 방문한 위치로 처리

            // 이동한 경로를 *로 표시 (최단 경로만)
            if (nextX == endX && nextY == endY) {
                for (int i = 0; i < sizeX; i++) {
                    for (int j = 0; j < sizeY; j++) {
                        if (visited[i][j]) {
                            if (i == endX && j == endY) {
                                cout << "G ";
                            }

                            else {
                                cout << "* ";
                            }
                        }
                        else {
                            cout << board[i][j] << " ";
                        }
                    }
                    cout << endl;
                }
                return cur.dist + 1;  // 최단 경로이므로 거리에 1을 더해줌
            }
        }
    }

    // 도달할 수 없는 경우 -1 반환
    return -1;
}

int main() {
    int n, m;
    cout << "맵의 크기를 입력하세요 : ";
    cin >> n >> m;

    cout << "맵을 그려주세요(입력한 맵의 x값 입력후 엔터) : " << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> board[i][j];
        }
    }

    int startX, startY, endX, endY;
    cout << "시작 좌표와 목표 좌표를 입력해주세요(ex : 0 0 4 4)";
    cin >> startX >> startY >> endX >> endY;

    int dist = bfs(startX, startY, endX, endY, n, m);
    cout << "최단거리 : ";
    cout << dist << endl;

    return 0;
}