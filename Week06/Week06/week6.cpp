#include <iostream>
#include <queue>
#include <vector>

using namespace std;

const int MAX_SIZE = 1000;

int board[MAX_SIZE][MAX_SIZE];  // ���� ������ ������ �迭
bool visited[MAX_SIZE][MAX_SIZE];  // �ش� ��ġ�� �湮�ߴ��� ���θ� ������ �迭

struct Point {
    int x, y, dist;
};

// ���� ��ġ�������� BFS Ž���� �����ϴ� �Լ�
int bfs(int startX, int startY, int endX, int endY, int sizeX, int sizeY) {
    queue<Point> q;
    q.push({ startX, startY, 0 });  // ���� ��ġ�� �Ÿ� ������ ť�� ����
    visited[startX][startY] = true;  // ���� ��ġ�� �̹� �湮�� ������ ó��

    while (!q.empty()) {
        Point cur = q.front();
        q.pop();

        // ���� ��ġ�� �������� ��� �Ÿ��� ��ȯ
        if (cur.x == endX && cur.y == endY) {
            return cur.dist;
        }

        // ������ ��ġ�� Ȯ���ϸ� BFS Ž��
        vector<pair<int, int>> directions = { {-1, 0}, {1, 0}, {0, -1}, {0, 1} };
        for (const auto& dir : directions) {
            int nextX = cur.x + dir.first;
            int nextY = cur.y + dir.second;

            // ������ ��� ��� ����
            if (nextX < 0 || nextX >= sizeX || nextY < 0 || nextY >= sizeY) {
                continue;
            }

            // ��ֹ��� �ִ� ��� ����
            if (board[nextX][nextY] == 1) {
                continue;
            }

            // �̹� �湮�� ��ġ�� ��� ����
            if (visited[nextX][nextY]) {
                continue;
            }

            // ���� ��ġ�� ť�� �ְ� �湮 ó��
            q.push({ nextX, nextY, cur.dist + 1 });
            visited[nextX][nextY] = true;
        }
    }
    // �������� ������ �� ���� ��� -1 ��ȯ
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