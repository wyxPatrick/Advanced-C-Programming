#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct Node {
    int x, y;
    int steps;
};
const int inf = 50001;
int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };
Node head, tail;
int row, col;

int bfs(vector<vector<char> >& maze, vector<vector<int> > visited) {
    queue<Node> q; 
    q.push(head);
    visited[head.x][head.y] = 1;
    Node cur, next;
    while (!q.empty()) {
        cur = q.front();
        q.pop();
        if (cur.x == tail.x && cur.y == tail.y) {
            return cur.steps;
        }
        else {
            for (int i = 0; i < 4; i++) {
                next.x = cur.x + dx[i];
                next.y = cur.y + dy[i];
                if (next.x<1 || next.x>row || next.y<1 || next.y>col
                    || maze[next.x][next.y] == '#' || visited[next.x][next.y] == 1) {
                    continue;
                }
                else {
                    next.steps = cur.steps + 1;
                    q.push(next);
                    visited[next.x][next.y] = 1;
                }
            }
        }
    }
    return inf;
}

int main() {
    int cases;
    cin >> cases;
    while (cases--) {
        cin >> row >> col;
        vector<vector<char> > maze(row + 1, vector<char>(col + 1, '#'));
        vector<vector<int> > visited(row + 1, vector<int>(col + 1, 0));
        for (int i = 1; i <= row; i++) {
            for (int j = 1; j <= col; j++) {
                cin >> maze[i][j];
                if (maze[i][j] == 'S') {
                    head.x = i; head.y = j; head.steps = 0;
                }
                else if (maze[i][j] == 'E') {
                    tail.x = i; tail.y = j;
                }
            }
        }
        int res = bfs(maze, visited);
        if (res >= inf) {
            cout << "oop!" << endl;
        }
        else {
            cout << res << endl;
        }
    }
    return 0;
}