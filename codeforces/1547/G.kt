import java.util.ArrayDeque

/*
* never use input.readLine() in interactive problems
* */

/*
Strategies:
1. Do a dfs or bfs to find all reachable nodes from 1, and discard all unreachable nodes now
2. Do a topological sort on reachable nodes and find all cycles in the graph
3. Do a multi-source bfs on the cycle nodes and find all nodes that are reachable from the nodes
4. Do a dfs on the remaining nodes and find which nodes have 1 path or more than one path
*/


fun main() {
    val input = System.`in`.bufferedReader()
    val output = StringBuilder()

    val t = readLine()!!.toInt()
    repeat(t) {
        readLine()!!
        val (n, m) = readLine()!!.split(' ').map { it.toInt() }
        val adj = Array(n) { mutableListOf<Int>() }
        val indeg = IntArray(n) { 0 }
        val unreachable = BooleanArray(n) { true }
        repeat(m) {
            var (a, b) = readLine()!!.split(' ').map { it.toInt() }
            --a;--b
            adj[a].add(b)
            indeg[b]++
        }

        // find all unreachable nodes from 1 with a bfs
        val q = ArrayDeque<Int>()
        q.addLast(0)
        unreachable[0] = false
        while (!q.isEmpty()) {
            val x = q.first
            q.removeFirst()
            for (u in adj[x]) {
                if (unreachable[u]) {
                    unreachable[u] = false
                    q.addLast(u)
                }
            }
        }


        // remove the unreachable nodes from the existing graph
        for (i in 0 until n) {
            if (unreachable[i]) {
                for (x in adj[i]) {
                    indeg[x]--
                }
            }
        }


        // Do topological sort to find the cycle nodes
        val inCycle = BooleanArray(n) { false }
        val vis = BooleanArray(n) { false }
        q.clear()
        for (i in 0 until n) {
            if (!unreachable[i] && indeg[i] == 0) {
                q.addLast(i)
            }
        }

        while (!q.isEmpty()) {
            val x = q.first
            q.removeFirst()
            vis[x] = true
            for (y in adj[x]) {
                indeg[y]--
                if (indeg[y] == 0) {
                    q.addLast(y)
                }
            }
        }

        // Multi-source bfs to find all nodes reachable from cycle nodes
        q.clear()
        for (i in 0 until n) {
            if (!unreachable[i] && !vis[i]) {
                inCycle[i] = true
                q.addLast(i)
            }
        }

        while (!q.isEmpty()) {
            val x = q.first
            q.removeFirst()
            for (y in adj[x]) {
                if (!inCycle[y]) {
                    q.addLast(y)
                    inCycle[y] = true
                }
            }
        }

        val paths = IntArray(n) { -1 }
        paths[0] = 1
        q.clear()
        if (!inCycle[0]) {
            q.addLast(0)
        }

        // Count paths for all other vertices
        while (!q.isEmpty()) {
            val x = q.first
            q.removeFirst()
            for (y in adj[x]) {
                if (!inCycle[y]) {
                    if (paths[y] == -1) {
                        paths[y] = paths[x]
                        q.addLast(y)
                    } else if (paths[y] == 1) {
                        paths[y] = 2
                        q.addLast(y)
                    }
                }
            }
        }

        // Append Output
        for (i in 0 until n) {
            when {
                unreachable[i] -> {
                    output.append("0")
                }
                inCycle[i] -> {
                    output.append("-1")
                }
                else -> {
                    output.append("${paths[i]}")
                }
            }
            if (i == n - 1) {
                output.append("\n")
            } else {
                output.append(" ")
            }

        }

    }
    print(output)
}

