#include<iostream>
#define MAX 1<<25
//#define print {cout<<low<<' '<<high<<endl; for(int i=1; i<=n; i++) cout<<dist[i]<<' '<<v[i].price<<endl; cout<<endl;}
using namespace std;

struct edge{
    int n, price;
    struct edge *next;
};

struct vertice{
    int level, price;
};

struct edge e[101];
struct vertice v[101];
bool visit[101];
int dist[101];
int n, low, high, result = MAX;

void dijkstra()
{
    int i, j, min, k = 0;
    memset(visit, 0, sizeof(visit));
    for (i = 1; i <= n; i++)
        dist[i] = MAX;
    dist[1] = 0;
    visit[1] = 1;
    edge * A = new edge;
    A = e[1].next;
    while (A){
        if (v[A->n].level >= low && v[A->n].level <= high)
            dist[A->n] = A->price;
        A = A->next;
    }
    for (i = 1; i <= n; i++){
        min = MAX;
        for (j = 1; j <= n; j++){
            if (!visit[j] && dist[j]<min){
                min = dist[j];
                k = j;
            }
        }
        visit[k] = 1;
        edge *B = new edge;
        B = e[k].next;
        while (B){
            if (!visit[B->n] && v[B->n].level >= low && v[B->n].level <= high && dist[B->n] > dist[k] + B->price){
                dist[B->n] = dist[k] + B->price;
                //print;
            }
            B = B->next;
        }
    }
    for (i = 1; i <= n; i++){
        if (result > dist[i] + v[i].price)
            result = dist[i] + v[i].price;
    }
}

int main()
{
    int m, i, j, p, l, x, t, s;
    memset(e, 0, sizeof(e));
    memset(v, 0, sizeof(v));
    cin >> m >> n;
    for (i = 1; i <= n; i++)
        e[i].next = 0;
    for (i = 1; i <= n; i++){
        cin >> p >> l >> x;
        v[i].level = l;
        v[i].price = p;
        for (j = 0; j < x; j++){
            cin >> t >> s;
            edge *ptr = new edge;
            ptr->n = t;
            ptr->price = s;
            ptr->next = e[i].next;
            e[i].next = ptr;
        }
    }
    for (i = v[1].level - m; i <= v[1].level; i++){
        low = i;
        high = i + m;
        dijkstra();
    }
    cout << result << endl;
    //system("pause");
    return 0;
}