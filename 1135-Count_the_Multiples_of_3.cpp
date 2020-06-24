#include <iostream>
using namespace std;

const int nax = 4e5+500;
struct node {
    int ara[3];
};

node tree[nax];
int lazy[nax];

node add(node a, node b) {
    int i = 0;
    node c;
    c.ara[0] = 0, c.ara[1] = 0, c.ara[2] = 0;
    while(i < 3) {
        c.ara[i] += b.ara[i] + a.ara[i];
        ++i;
    }
    return c;
}

void build(int cur, int lo, int hi) {
    if(lo == hi) {
        tree[cur].ara[0] = 1; tree[cur].ara[1] = tree[cur].ara[2] = 0;
        return;
    }
    int mid = (lo+hi)/2;
    build(cur*2, lo, mid);
    build((cur*2)+1, mid+1, hi);
    tree[cur] = add(tree[cur*2], tree[(cur*2)+1]);
}

void swap_n(int n) {
    swap(tree[n].ara[0], tree[n].ara[2]);
    swap(tree[n].ara[1], tree[n].ara[2]);
}

void update(int cur, int lo, int hi, int i, int j) {
    if(lazy[cur] > 0) {
        int incre = lazy[cur];
        lazy[cur] = 0;
        if(lo != hi) {
            lazy[cur*2] += incre;
            lazy[(cur*2)+1] += incre;
        }
        incre %= 3;

        while(incre--) {
            swap_n(cur);
        }
    }
    if(lo > j || hi < i) {
        return;
    }
    if(lo >= i && hi <= j) {
        swap_n(cur);
        if(lo != hi) {
            lazy[cur*2]++;
            lazy[(cur*2)+1]++;
        }
        return;
    }
    int mid = (lo+hi)/2;
    update(cur*2, lo, mid, i, j);
    update((cur*2)+1, mid+1, hi, i, j);
    tree[cur] = add(tree[cur*2], tree[(cur*2)+1]);
}

int cnt(int cur, int lo, int hi, int i, int j) {
    if(lazy[cur] > 0){
        int incre = lazy[cur];
        lazy[cur] = 0;
        if(lo != hi) {
            lazy[cur * 2] += incre;
            lazy[(cur*2)+1] += incre;
        }
        incre %= 3;

        while(incre --) {
            swap_n(cur);
        }
    }
    if(lo > j || hi < i) {
        return 0;
    }
    if(lo >= i && hi <= j) {
        return tree[cur].ara[0];
    }
    int mid = (lo+hi)/2;
    int sum1 = cnt(cur*2, lo, mid, i, j);
    int sum2 = cnt((cur*2)+1, mid+1, hi, i, j);
    return sum2+sum1;
}

void reset() {
    for (int i = 0; i < nax; ++i) {
        tree[i].ara[0] = 1;
        tree[i].ara[1] = tree[i].ara[2] = 0;   
        lazy[i] = 0;
    }
}

void run() {
    int n, q;
    scanf("%d%d", &n, &q);
    build(1, 1, n);

    while(q--) {
        int t, i, j;
        scanf("%d%d%d", &t, &i, &j);
        ++i, ++j;
        if(t == 1) {
            printf("%d\n", cnt(1, 1, n, i, j));
        }
        else {
            update(1, 1, n, i, j);
        }
    }
    reset();
}

int main() 
{
    int t;
    scanf("%d", &t);

    for (int i = 1; i <= t; ++i) {
        printf("Case %d:\n", i);
        run();
    }
    return 0;
}