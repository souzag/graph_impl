#include<iostream> 
#include<stack>
#include<list>  

using namespace std; 
  
class graph
{ 
    int no_of_vertices;
    list <int>* l1;  
    
    public:
    graph(int n) 
    { 
        no_of_vertices = n; 
        l1 = new list <int> [n]; 
    } 
    
    //A função push_back é usada para adicionar um novo elemento no final da lista
    void add_edge(int x, int y)
    {
        l1[x].push_back(y);
    }

    void topological(int, int [], stack <int>& );
    void topological_sort(); 
}; 
  
void graph::topological(int vertex_no, int visited[], stack<int>& s) 
{ 
    //Marcando o vértice como visitado
    visited[vertex_no] = 1; 
    
    //Não podemos iterar pela lista usando um inteiro normal. Portanto, usamos um iterador
    list <int>::iterator i; 
    for (i = l1[vertex_no].begin(); i != l1[vertex_no].end(); i++)
    { 
        if(visited[*i] == 0)
        { 
            topological(*i, visited, s);
        }
    }
    
    //Faz o push do vértice atual na pilha
    s.push(vertex_no); 
} 
  
void graph::topological_sort() 
{ 
    stack <int> s; 
    int i, visited[no_of_vertices];
        
    //'0' significa 'não visitado' e '1' significa 'visitado'. Inicializamos com todos os vértices sendo 'não visitado'
    for(i = 0; i < no_of_vertices; i++)
    {
        visited[i] = 0; 
    } 

    //Chamando o topological para cada vértice
    for(i = 0; i < no_of_vertices; i++)
    {
        if(visited[i] == 0)
        {
            topological(i, visited, s); 
        } 
    } 
    
    //Loop para mostrar o conteúdo da pilha
    while(!s.empty()) 
    {
        int k = s.top(); 
        cout << k << " "; 
        s.pop(); 
    }
}

void read()
{
    int n, m, i, a, b;

    cout << "Type the desired number of vertices: \n";
    cin >> n;
    graph p(n);

    cout << "Type the desired number of edges: \n";
    cin >> m;

    cout << "Now, create your graph. Note: use pairs.\n";
    for(i = 0; i < m; i++)
    {
        cin >> a >> b;
        p.add_edge(a, b);
    }

    cout <<"\nThe Topological order of the vertices of the graph is: \n"; 
    p.topological_sort();
}

int main() 
{ 
    read();
    return 0; 
}