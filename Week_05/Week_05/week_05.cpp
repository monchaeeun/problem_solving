#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

const int MAX = 7;
int map[MAX][MAX];
int dist[MAX][MAX];
int qrev[MAX][MAX];
int dx[] = { -1, 0, 1, 0 }; // �������
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
    // �� �Է�
    for (int i = 0; i < MAX; i++)
    {
        for (int j = 0; j < MAX; j++)
        {
            cin >> map[i][j];
        }
    }

    // �������� ������ �Է�
    cin >> sx >> sy >> ex >> ey;

    // �ʱ�ȭ
    memset(dist, -1, sizeof(dist));
    memset(qrev, -1, sizeof(qrev));

    // BFS ����
    BFS(sx, sy);

    // ��� ���
    if (dist[ex][ey] == -1)
    {
        cout << "�������� ������ �� �����ϴ�.\n";
    }
    else
    {
        cout << "�ִ� ���: ";
        printPath(ex, ey);
        cout << "\n�ִ� �Ÿ�: " << dist[ex][ey] << "\n";
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
//int sx = 1, sy = 1; // ������
//int ex = 3, ey = 5; // ������
//
//int dx[4] = { 0,0,1,-1 };
//int dy[4] = { 1,-1,0,0 };
//int qrev[MAX_SIZE][MAX_SIZE]; // �ִ� ��� ����� ���� ���� ��ġ ���� �迭
//
//void bfs(int x, int y)
//{
//    queue<pair<int, int>> q;
//    q.push({ x, y });
//    qrev[x][y] = -1; // �������� ���� ��ġ�� ����
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
//                qrev[nx][ny] = cx * MAX_SIZE + cy; // ���� ��ġ ����
//            }
//        }
//    }
//}
//
//int main() {
//    bfs(sx, sy);
//
//    if (qrev[ex][ey] == 0) { // �������� ������ �� ���� ���
//        cout << "�������� ������ �� �����ϴ�." << endl;
//    }
//    else { // �������� ������ �� �ִ� ���
//        vector<pair<int, int>> path; // ��� ������ ���� ����
//        int cx = ex, cy = ey;
//
//        while (qrev[cx][cy] != -1) { // �������� ������ ������
//            path.push_back({ cx, cy });
//            int px = qrev[cx][cy] / MAX_SIZE;
//            int py = qrev[cx][cy] % MAX_SIZE;
//            cx = px, cy = py;
//        }
//
//        path.push_back({ cx, cy }); // ������ �߰�
//        cout << "�ִ� ���: ";
//        for (int i = path.size() - 1; i >= 0; i--) {
//            cout << "(" << path[i].first << ", " << path[i].second << ") ";
//        }
//    }
//
//    return 0;
//}


