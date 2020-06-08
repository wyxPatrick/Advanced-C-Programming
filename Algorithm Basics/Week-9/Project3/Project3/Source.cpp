#include<stdio.h>
#include<string.h>
#include<queue>
#include<algorithm>
using namespace std;

struct node
{
    int id;
    int fish;
    int down;
    int time;
    friend bool operator < (const node& x, const node& y) {
        if (x.fish != y.fish)
            return x.fish < y.fish;
        return x.id > y.id;
    }
}a[30];
priority_queue<node> q;
int h, n, ans[30], tmp[30], maxsum;

void greedy()
{
    int i, j;
    maxsum = -1;
    for (i = 0; i < n; i++)
    {
        while (!q.empty()) q.pop();
        for (j = 0; j <= i; j++)
            q.push(a[j]);
        int left_time = h - a[i].time, sum = 0;
        memset(tmp, 0, sizeof(tmp));
        while (left_time > 0)
        {
            node temp = q.top();
            q.pop();
            if (temp.fish <= 0) break;
            sum += temp.fish;
            temp.fish -= temp.down;
            tmp[temp.id] += 5;
            q.push(temp);
            left_time -= 5;
        }
        if (left_time > 0)
            tmp[0] += left_time;
        if (sum > maxsum)
        {
            maxsum = sum;
            for (j = 0; j < n; j++)
                ans[j] = tmp[j];
        }
    }
}

int main()
{
    int i, t, cas = 0;
    while (~scanf("%d", &n) && n)
    {
        scanf("%d", &h);
        h *= 60;
        for (i = 0; i < n; i++)
        {
            scanf("%d", &a[i].fish);
            a[i].id = i;
        }
        for (i = 0; i < n; i++)
            scanf("%d", &a[i].down);
        a[0].time = 0;
        for (i = 1; i < n; i++)
        {
            scanf("%d", &t);
            a[i].time = a[i - 1].time + t * 5;
        }
        if (cas > 0)
            printf("\n");
        cas++;
        greedy();
        printf("%d", ans[0]);
        for (i = 1; i < n; i++)
            printf(", %d", ans[i]);
        printf("\n");
        printf("Number of fish expected: %d\n", maxsum);
    }
    return 0;
}