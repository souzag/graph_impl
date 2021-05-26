#include<bits/stdc++.h>

using namespace std;

const int MAX = 1e6-1;
int root[MAX];

pair <long long, pair<int, int> > p[MAX];

//Encontre o parente do nó dado
int parent(int a)
{
    while(root[a] != a)
    {
        root[a] = root[root[a]];
        a = root[a];
    }
    return a;
}

//Verifique se os dois vértices dados estão na mesma "união" ou não
void union_find(int a, int b)
{
    int d = parent(a);
    int e = parent(b);
    
    root[d] = root[e];
}

long long kruskal(int edges)
{
    int a, b;
    long long cost, minCost = 0;

    for(int i = 0 ; i < edges ; ++i)
    {
        a = p[i].second.first;
        b = p[i].second.second;
        cost = p[i].first;

        //Apenas selecione a aresta se ela não criar um ciclo (i.e, os dois nós que a formam têm raízes diferentes)
        if(parent(a) != parent(b))
        {
            minCost += cost;
            union_find(a, b);
        }
    }
    return minCost;
}

void read()
{
    int n, m, i, a, b, c;
    long long minCost;

    cout << "Type the desired number of vertices: \n";
    cin >> n;

    cout << "Type the desired number of edges: \n";
    cin >> m;

    cout << "Now, create your graph. Note: enter the weight and then a pair of edges.\n";
    for(i = 0; i < m; i++)
    {
        cin >> a >> b >> c;
        p[i] = make_pair(a, make_pair(b, c));
    }

    //Fazendo o sort do array de arestas
    sort(p, p + m);
    minCost = kruskal(m);
    cout << "\nMinimum cost is: \n"<< minCost << endl;
}

int main()
{
    //Inicializando o array
    for(int i = 0; i < MAX; ++i)
    {
        root[i] = i;
    }

    read();
    return 0;
}