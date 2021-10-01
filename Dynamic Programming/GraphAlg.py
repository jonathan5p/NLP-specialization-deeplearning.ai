
# grafo = {
#     'a':['b','c'],
#     'b':['d'],
#     'c':['e'],
#     'd':['f'],
#     'e':[],
#     'f':[],

# }


grafo = {
    '0':['8','1','5'],
    '1':['0'],
    '5':['0','8'],
    '8':['0','5'],
    '2':['3','4'],
    '3':['2','4'],
    '4':['3','2'],
}

def DFS(graph,initial_node):
    stack = [initial_node]
    ended = False 
    while not ended:
        curr_node = stack.pop(0)
        if len(graph[curr_node])>0:
            stack = graph[curr_node] + stack
        print(curr_node)
        print(stack)
        ended=len(stack)==0

def RDFS(graph,node):
    print(node)
    for n_node in graph[node]:
        RDFS(graph,n_node)

def BFS(graph,initial_node):
    queue = [initial_node]
    ended = False 
    while not ended:
        curr_node = queue.pop(0)
        if len(graph[curr_node])>0:
            queue = queue + graph[curr_node]
        print(curr_node)
        print(queue)
        ended=len(queue)==0



def largestComponent(graph,visited=None):
    if visited == None:
        visited = []
    
    max_component = 0
    for node in graph:
        init_size = len(visited)
        NDDFS(graph,node,visited)
        max_component=max(max_component,len(visited)-init_size)
    return max_component

def NDDFS(graph,node,visited):
    if node in visited: return False

    visited.append(node)

    for n_node in graph[node]:
        print(node,'->',n_node)
        NDDFS(graph,n_node,visited)

edges = [
    ['w','x'],
    ['x','y'],
    ['z','y'],
    ['z','v'],
    ['w','v']
]

def shortest_path(graph,source,target):

    visited=[]

    queue = [(source,0)]
    ended = False 
    while not ended:
        
        curr_node,cost = queue.pop(0)
        if curr_node==target:
            min_cost = cost
            break

        if curr_node in visited:
            continue
        
        visited.append(curr_node)

        if len(graph[curr_node])>0:
            queue = queue + [(node,cost+1) for node in graph[curr_node]]
        
        print(curr_node,cost)
        print(queue)
        ended = len(queue)==0

    return min_cost

def edges2adjlist(edges):
    adj_list = {}

    for edge in edges:
        nodes,cost = edge
        nodeA,nodeB = nodes
        if nodeA in adj_list:
            adj_list[nodeA].append({'destination':nodeB,'cost':cost})
        else:
            adj_list[nodeA]=[{'destination':nodeB,'cost':cost}]

        if nodeB in adj_list:
            adj_list[nodeB].append({'destination':nodeA,'cost':cost})
        else:
            adj_list[nodeB]=[{'destination':nodeA,'cost':cost}]
    
    return adj_list


edges = [
    (['a','b'],1),
    (['a','c'],3),
    (['b','e'],4),
    (['c','e'],1),
    (['b','d'],5),
    (['c','d'],3),
    (['e','f'],2),
    (['d','f'],3),
]


def dijkstra(graph, source, target):
    path = []

    visited = {source:(None,0)}
    queue = {source:(None,0)}

    ended = False
    curr_node=source
    while not ended:
        _, curr_node_cost = queue.pop(curr_node)
        for neighbor in graph[curr_node]:
            if neighbor['destination']  not in visited:
                if neighbor['destination'] in queue:
                    if curr_node_cost+neighbor['cost']<queue[neighbor['destination']][1]:
                        queue[neighbor['destination']]=(curr_node,curr_node_cost+neighbor['cost'])
                else:
                    queue.update({neighbor['destination']:(curr_node,curr_node_cost+neighbor['cost'])})

        curr_node = searchMin(queue)
        visited.update({curr_node:queue[curr_node]})
        print(visited)
        ended = len(queue)==0
        if curr_node == target:
            ended = True     
            print('path')
            print(recoverpath(visited,target))

    return path


def recoverpath(visited,target,path=None):
    if path == None:
        path = {}
    
    if target==None:
        return False

    path.update({target:visited[target]})
    recoverpath(visited,visited[target][0],path)
    return path
    


def searchMin(queue):
    min_node = None
    min_cost = 1000000000
    for key,value in queue.items():
        if value[1]<min_cost:
            min_node=key
            min_cost = value[1]
    return min_node



print(dijkstra(edges2adjlist(edges),'a','f'))