# Dijktra's shortest path algorithm. Prints the path from source to target.
 
 
def dijkstra(adj, source, target):
    INF = ((1<<63) - 1)//2
    pred = { x:x for x in adj }
    dist = { x:INF for x in adj }
    dist[source] = 0
    PQ = []
    heapq.heappush(PQ, [dist[source], source])
 
    while(PQ):
        u = heapq.heappop(PQ)  # u is a tuple [u_dist, u_id]
        u_dist = u[0]
        u_id = u[1]
        if u_dist == dist[u_id]:
            #if u_id == target:
            #    break
            for v in adj[u_id]:
               v_id = v[0]
               w_uv = v[1]
               if dist[u_id] +  w_uv < dist[v_id]:
                   dist[v_id] = dist[u_id] + w_uv
                   heapq.heappush(PQ, [dist[v_id], v_id])
                   pred[v_id] = u_id
                
    if dist[target]==INF:
        stdout.write("There is no path between " + source + " and " + target)
    else:
        st = []
        node = target
        while(True):
            st.append(str(node))
            if(node==pred[node]):
                break
            node = pred[node]
        path = st[::-1]
        stdout.write("The shortest path is: " + " ".join(path))
