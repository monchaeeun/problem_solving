#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
#define MAX 100

using namespace std;

struct Node {
    int x, y;
};

int n, m;
char map[MAX][MAX];
vector<Node> adj[MAX][MAX];
int dist[MAX][MAX];
int startX, startY, endX, endY;
queue<Node> q;

void BFS() {
    memset(dist, -1, sizeof(dist)); // 거리 초기화
    dist[startX][startY] = 0; // 시작점의 거리는 0

    q.push({ startX, startY }); // 시작점을 큐에 추가

    while (!q.empty()) {
        Node curr = q.front(); // 큐의 맨 앞에서부터 노드 하나를 꺼냄
        q.pop();

        for (Node next : adj[curr.x][curr.y]) { // 현재 노드의 인접한 노드들에 대해
            int nx = next.x;
            int ny = next.y;

            if (dist[nx][ny] == -1) { // 아직 방문하지 않은 경우
                dist[nx][ny] = dist[curr.x][curr.y] + 1; // 거리
                q.push({ nx, ny }); // 다음 노드를 큐에 추가
            }
        }
    }
}

int main() {
    cin >> n >> m;

    // 지도 입력
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> map[i][j];
            if (map[i][j] == 'S') { // 시작점인 경우
                startX = i;
                startY = j;
            }
            else if (map[i][j] == 'E') { // 도착점인 경우
                endX = i;
                endY = j;
            }
        }
    }

    // 인접한노드 찾기
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (map[i][j] != '#') { // 벽이 아닌 경우
                if (i > 0 && map[i - 1][j] != '#') { // 위쪽 노드
                    adj[i][j].push_back({ i - 1, j });
                    adj[i - 1][j].push_back({ i, j });
                }
                if (j > 0 && map[i][j - 1] != '#') { // 왼쪽 노드
                    adj[i][j].push_back({ i, j - 1 });
                    adj[i][j - 1].push_back({ i, j });
                }
                if (i < n - 1 && map[i + 1][j] != '#') { // 아래쪽 노드
                    adj[i][j].push_back({ i + 1, j });
                    adj[i + 1][j].push_back({ i, j });
                }
                if (j < m - 1 && map[i][j + 1] != '#') { // 오른쪽 노드
                    adj[i][j].push_back({ i, j + 1 });
                    adj[i][j + 1].push_back({ i, j });
                }
            }
        }
    }

    BFS(); // BFS 호출

    cout << "Minimum distance: " << dist[endX][endY] << endl; // 최단 거리 출력

    return 0;
