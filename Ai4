import heapq
class Node:
def __init__(self, s, p=None, a=None, c=0, h=0):
self.state, self.parent, self.action = s, p, a
self.cost, self.heuristic = c, h
def __lt__(self, o):
return (self.cost + self.heuristic) < (o.cost + o.heuristic)
def parse_graph():
g = {}
for _ in range(int(input("Enter the number of edges: "))):
u, v, c = input("Enter an edge (format: u v cost): ").split()
g.setdefault(u, []).append((v, float(c)))
g.setdefault(v, [])
return g
def heuristic(s, g):
h = {'A':5,'B':3,'C':2,'D':1,'E':2,'G':0}
return h.get(s, float('inf'))
def ao_star(start, goal, graph):
pq = []
heapq.heappush(pq, Node(start, None, None, 0, heuristic(start, goal)))
visited = {}
while pq:
n = heapq.heappop(pq)
if n.state == goal:
path = []
while n.parent:
path.append((n.action, n.state))
n = n.parent
return path[::-1]
if n.state not in visited or n.cost < visited[n.state]:
visited[n.state] = n.cost
for nb, c in graph.get(n.state, []):
heapq.heappush(pq, Node(nb, n, f"Move to {nb}", n.cost+c, heuristic(nb, goal)))
return None
print("Define the graph:")
graph = parse_graph()
start = input("Enter the start state: ")
goal = input("Enter the goal state: ")
res = ao_star(start, goal, graph)
if res:
print("Path found:")
for a, s in res:
print(f"Action: {a}, State: {s}")
else:
print("No path found.")
