#include <iostream>
#include <cstring>
#include <cstdio>
#include <queue>
using namespace std;

int maze[5][5];
int visited[5][5];

struct Node {
	int x, y;
	int steps;
	int dire[30];
};

int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };

bool canWalk(Node& n) {
	if (n.x < 0 || n.x > 4 || n.y < 0 || n.y > 4) {
		return false;
	}
	if (maze[n.x][n.y]) {
		return false;
	}
	if (visited[n.x][n.y]) {
		return false;
	}
	return true;
}

Node bfs() {
	queue<Node> q;
	Node head;
	head.x = 0;
	head.y = 0;
	head.steps = 0;
	q.push(head);
	visited[head.x][head.y] = 1;
	Node cur, next;
	while (!q.empty()) {
		cur = q.front();
		q.pop();
		if (cur.x == 4 && cur.y == 4)
			return cur;
		else {
			for (int i = 0; i < 4; i++) {
				next.x = cur.x + dx[i];
				next.y = cur.y + dy[i];
				if (canWalk(next)) {
					next.steps = cur.steps + 1;
					next.dire[cur.steps] = i;
					q.push(next);
					visited[next.x][next.y] = 1;
				}
			}
		}
	}
}

int main() {
	memset(maze, 0, sizeof(maze));
	memset(visited, 0, sizeof(visited));
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			cin >> maze[i][j];
		}
	}
	Node res = bfs();
	int x = 0, y = 0;
	char out[30];
	cout << "(0, 0)" << endl;
	for (int i = 0; i < res.steps; i++) {
		x += dx[res.dire[i]];
		y += dy[res.dire[i]];
		sprintf(out, "(%d, %d)", x, y);
		cout << out << endl;
	}
	return 0;
}