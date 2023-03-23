#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

vector<int> graph[1001]; // 그래프
bool visited[1001]; // 방문 여부 체크

// DFS 구현
void dfs(int node) {
    visited[node] = true; // 현재 노드를 방문했음을 체크
    cout << node << " "; // 현재 노드 출력
    // 현재 노드와 연결된 노드들에 대해 방문하지 않은 경우에만 DFS 호출
    for (int i = 0; i < graph[node].size(); i++) {
        int next = graph[node][i];
        if (!visited[next])
            dfs(next);
    }
}

// BFS 구현
void bfs(int start) {
    queue<int> q;
    q.push(start); // 시작 노드를 큐에 넣음
    visited[start] = true; // 시작 노드를 방문했음을 체크
    while (!q.empty()) {
        int node = q.front();
        q.pop();
        cout << node << " "; // 현재 노드 출력
        // 현재 노드와 연결된 노드들에 대해 방문하지 않은 경우에만 큐에 넣고 방문 체크
        for (int i = 0; i < graph[node].size(); i++) {
            int next = graph[node][i];
            if (!visited[next]) {
                q.push(next);
                visited[next] = true;
            }
        }
    }
}

int main() {
    int n, m, v;
    cin >> n >> m >> v;

    // 그래프 초기화
    for (int i = 1; i <= n; i++)
        visited[i] = false;
    for (int i = 0; i < m; i++) {
        int from, to;
        cin >> from >> to;
        graph[from].push_back(to);
        graph[to].push_back(from);
    }
    // 연결된 노드들의 번호를 오름차순으로 정렬
    for (int i = 1; i <= n; i++)
        sort(graph[i].begin(), graph[i].end());

    dfs(v);
    cout << endl;
    for (int i = 1; i <= n; i++)
        visited[i] = false; // visited 배열 초기화
    bfs(v);

    return 0;
}
