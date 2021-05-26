#include<bits/stdc++.h>
using namespace std;
# define INF 0x3f3f3f3f
  
// iPair ==> Par de inteiros, definindo para facilitar a leitura no restante do codigo.
typedef pair<int, int> iPair;

int n, m, z;
  
// Função para adicionar arestas.
void addEdge(vector <pair<int, int> > adj[], int u,
                                     int v, int wt)
{
    adj[u].push_back(make_pair(v, wt));
    adj[v].push_back(make_pair(u, wt));
}
   
  
// Mostra o valor do caminho mais curto entre o src e os outros vértices.
void shortestPath(vector<pair<int,int> > adj[], int V, int src)
{
    // Cria uma Fila de Prioridade para fazer o processamento dos vértices.
    priority_queue< iPair, vector <iPair> , greater<iPair> > pq;
  
    // Cria um vetor de distancias e inicializa ele por completo com infinito.
    vector<int> dist(V, INF);
  
    // Insere o vértice src na fila de prioridade e seu valor como 0.
    pq.push(make_pair(0, src));
    dist[src] = 0;
  
    // loop até que a fila de prioridade se torne vazia.
    while (!pq.empty())
    {
        // O primeiro vértice no par é o vértice de menor distância,
        // é feita a extração dele da fila de prioridade.
        // A representação do vértice é armazenada em segundo no par
        // (tem que ser feito dessa maneira para manter os vértices ordenados pela distância)
        int u = pq.top().second;
        pq.pop();
  
        // Recebe todas adjacencias de u
        for (auto x : adj[u])
        {
            // Recebe a representação do vértice e o peso da adjacência atual de u.
            int v = x.first;
            int weight = x.second;
  
            // Se tiver um caminho com menor distância atráves de u.
            if (dist[v] > dist[u] + weight)
            {
                // Atualizando a distância v.
                dist[v] = dist[u] + weight;
                pq.push(make_pair(dist[v], v));
            }
        }
    }
  
    // Mostra as distancias mais curtas armazenadas no dist[].
    printf("Distancia de cada vértice ate o vértice desejado\n");
    for (int i = 0; i < n; ++i)
        printf("%d \t\t %d\n", i, dist[i]);
}

int main()
{
    cin >> n >> m;
    vector<iPair > adj[n];
  
    for (int i = 0; i < m; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        a--, b--;
        addEdge(adj, a, b, c);
    }
    cin >> z;
    shortestPath(adj, m, z);
  
    return 0;
}