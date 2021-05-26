#include<bits/stdc++.h>
using namespace std;
#define maxN 1000

int n, m;

// Criação do vetor para armazenar os parents.
int parent[maxN];

// Função para encontrar o parent de um vértice.
int Find(int i)
{
    return parent[i] == i ? i : parent[i] = Find(parent[i]);
}

// Função para fazer a união de dois vértices, tornando os dois do mesmo parent.
void Union(int x, int y)
{
    int xParent = Find(x);
    int yParent = Find(y);

    parent[xParent] = yParent;
}

// Função para inicializar o vetor de parents, transformando cada vértice tendo ele mesmo como parent.
void Initialize(int vertices)
{
    int i;

    for(i = 0; i < vertices; i++)
    {
        parent[i] = i;
    }
}

int main()
{
    cin >> n >> m;
    Initialize(n);

    // Colocação das arestas inicias no grafo
    while(m--)
    {
        int a, b;
        cin >> a >> b;
        a--, b--;
        Union(a, b);
    }
    return 0;
}