# Implementação dos algoritmos de Grafos - Teoria dos Grafos.

> Alunos: Gabriel Luiz Leite Souza e Jorge Firmo Soares Neto.

## Algoritmos Implementados:
- Dijkstra;
- Union Find;
- Topological Sort;
- Kruskal.

## Utilização dos Algoritmos:
### Dijkstra:
**Entrada**:
- `n`: Quantidade de Vértices.
- `m`: Quantidade de Arestas.
- `a`: Vértice "1" da ligação de arestas.
- `b`: Vértice "2" da ligação de arestas.
- `c`: Peso da aresta.
- `z`: Vértice no qual vai ser calculada a distância para os demais vértices.

**Exemplo de Entrada**
``` 
5 7
1 2 1
1 5 2
2 3 3
2 4 4
3 4 5
3 5 6
4 5 7
2 
```

### Union Find:
**Entrada**:
- `n`: Quantidade de Vértices.
- `m`: Quantidade de Arestas.
- `a`: Vértice "1" da ligação de arestas.
- `b`: Vértice "2" da ligação de arestas.

**Exemplo de Entrada**
``` 
5 7
1 2
1 5
2 3
2 4
3 4
3 5
4 5
```

### Topological Sort:
**Entrada**:
- `v`: Quantidade de Vértices.
- `e`: Quantidade de Arestas.
- `n1`: Vértice "1" da ligação de arestas.
- `n2`: Vértice "2" da ligação de arestas.

**Exemplo de Entrada**
``` 
4
0 1 
0 2 
1 2
1 3
2 3
```

### Kruskal:
**Entrada**:
- `v`: Quantidade de Vértices.
- `e`: Quantidade de Arestas.
- `n1`: Peso da aresta.
- `n2`: Vértice "1" da ligação de arestas.
- `n3`: Vértice "2" da ligação de arestas.

**Exemplo de Entrada**
``` 
10 0 1
18 1 2
13 2 3
21 0 2
22 1 3
```
