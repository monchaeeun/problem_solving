#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

const int MAX = 7;
int map[MAX][MAX];
int dist[MAX][MAX];
int qrev[MAX][MAX];
int dx[] = { -1, 0, 1, 0 }; // 상우하좌
int dy[] = { 0, 1, 0, -1 };
int sx, sy, ex, ey;

void BFS(int x, int y)
{
    queue<pair<int, int>> q;
    q.push(make_pair(x, y));
    dist[x][y] = 0;

    while (!q.empty())
    {
        int cx = q.front().first;
        int cy = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int nx = cx + dx[i];
            int ny = cy + dy[i];

            if (nx < 0 || nx >= MAX || ny < 0 || ny >= MAX)
                continue;

            if (dist[nx][ny] != -1 || map[nx][ny] == 0)
                continue;

            dist[nx][ny] = dist[cx][cy] + 1;
            qrev[nx][ny] = cx * 10 + cy;
            q.push(make_pair(nx, ny));
        }
    }
}

void printPath(int x, int y)
{
    if (x == sx && y == sy)
    {
        cout << "(" << x << ", " << y << ") ";
        return;
    }

    int px = qrev[x][y] / 10;
    int py = qrev[x][y] % 10;

    printPath(px, py);
    cout << "(" << x << ", " << y << ") ";
}

int main()
{
    // 맵 입력
    for (int i = 0; i < MAX; i++)
    {
        for (int j = 0; j < MAX; j++)
        {
            cin >> map[i][j];
        }
    }

    // 시작점과 도착점 입력
    cin >> sx >> sy >> ex >> ey;

    // 초기화
    memset(dist, -1, sizeof(dist));
    memset(qrev, -1, sizeof(qrev));

    // BFS 실행
    BFS(sx, sy);

    // 결과 출력
    if (dist[ex][ey] == -1)
    {
        cout << "도착점에 도달할 수 없습니다.\n";
    }
    else
    {
        cout << "최단 경로: ";
        printPath(ex, ey);
        cout << "\n최단 거리: " << dist[ex][ey] << "\n";
    }

    return 0;
}




//#include <iostream>
//#include <queue>
//using namespace std;
//
//const int MAX_SIZE = 7;
//int map[MAX_SIZE][MAX_SIZE] = {
//    {0,0,0,0,0},
//    {0,1,1,1,0},
//    {0,1,1,1,0},
//    {0,1,1,1,0},
//    {0,1,1,1,0},
//    {0,1,1,1,0},
//    {0,0,0,0,0,}
//};
//
//int sx = 1, sy = 1; // 시작점
//int ex = 3, ey = 5; // 도착점
//
//int dx[4] = { 0,0,1,-1 };
//int dy[4] = { 1,-1,0,0 };
//int qrev[MAX_SIZE][MAX_SIZE]; // 최단 경로 출력을 위한 이전 위치 저장 배열
//
//void bfs(int x, int y)
//{
//    queue<pair<int, int>> q;
//    q.push({ x, y });
//    qrev[x][y] = -1; // 시작점은 이전 위치가 없음
//
//    while (!q.empty()) {
//        int cx = q.front().first;
//        int cy = q.front().second;
//        q.pop();
//
//        for (int i = 0; i < 4; i++) {
//            int nx = cx + dx[i];
//            int ny = cy + dy[i];
//            if (nx >= 0 && nx < MAX_SIZE && ny >= 0 && ny < MAX_SIZE && map[nx][ny] == 0 && qrev[nx][ny] == 0) 
//            {
//                q.push({ nx, ny });
//                qrev[nx][ny] = cx * MAX_SIZE + cy; // 이전 위치 저장
//            }
//        }
//    }
//}
//
//int main() {
//    bfs(sx, sy);
//
//    if (qrev[ex][ey] == 0) { // 도착점에 도달할 수 없는 경우
//        cout << "도착점에 도달할 수 없습니다." << endl;
//    }
//    else { // 도착점에 도달할 수 있는 경우
//        vector<pair<int, int>> path; // 경로 저장을 위한 벡터
//        int cx = ex, cy = ey;
//
//        while (qrev[cx][cy] != -1) { // 시작점에 도달할 때까지
//            path.push_back({ cx, cy });
//            int px = qrev[cx][cy] / MAX_SIZE;
//            int py = qrev[cx][cy] % MAX_SIZE;
//            cx = px, cy = py;
//        }
//
//        path.push_back({ cx, cy }); // 시작점 추가
//        cout << "최단 경로: ";
//        for (int i = path.size() - 1; i >= 0; i--) {
//            cout << "(" << path[i].first << ", " << path[i].second << ") ";
//        }
//    }
//
//    return 0;
//}


