def dfs_recursive(graph, node, visited):
    if node not in visited:
        print(node) 
        visited.add(node)
        for neighbor in graph[node]:
            dfs_recursive(graph, neighbor, visited)


def dfs_iterative(graph, start):
    visited = set()
    stack = [start]
    
    while stack:
        node = stack.pop()
        if node not in visited:
            print(node)
            visited.add(node)
            for neighbor in graph[node]:
                stack.append(neighbor)



graph = {
    'A': ['B', 'C'],
    'B': ['A', 'D', 'E'],
    'C': ['A', 'F'],
    'D': ['B'],
    'E': ['B', 'F'],
    'F': ['C', 'E']
}
visited = set()
print("Recursive DFS:")
dfs_recursive(graph, 'A', visited)
print("\nIterative DFS:")
dfs_iterative(graph, 'A')