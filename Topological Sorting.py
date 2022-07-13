from collections import defaultdict

class Graph:

    def __init__(self,n):

        self.graph = defaultdict(list)

        self.N = n

    def add_Edge(self,m,n):

        self.graph[m].append(n)

    def sortUtil(self,n,visited,stack):

        visited[n] = True

        for element in self.graph[n]:

            if visited[element] == False:

                self.sortUtil(element,visited,stack)

        stack.insert(0,n)

    def topo_Sort(self):

        visited = [False]*self.N

        stack =[]

        for element in range(self.N):

            if visited[element] == False:

                self.sortUtil(element,visited,stack)

        print(stack)

graph = Graph(5)
graph.add_Edge(0,1);
graph.add_Edge(0,3);
graph.add_Edge(1,2);
graph.add_Edge(2,3);
graph.add_Edge(2,4);
graph.add_Edge(3,4);

print("The Topological Sort Of The Graph Is:  ")

graph.topo_Sort()
