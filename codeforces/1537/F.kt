import kotlin.math.abs

fun main() {
    val input = System.`in`.bufferedReader()
    val output = StringBuilder()

    val t = input.readLine()!!.toInt()
    for(i in 0 until t) {
        val (n, m) = input.readLine()!!.split(' ').map { it.toInt() }
        val initial = input.readLine()!!.split(' ').map { it.toLong() }
        val target = input.readLine()!!.split(' ').map { it.toLong() }

        val adj = Array<MutableList<Int>>(n){ mutableListOf() }

        repeat(m) {
            var(u, v) = input.readLine()!!.split(' ').map { it.toInt() }
            --u; --v
            adj[u].add(v)
            adj[v].add(u)
        }

        var parity = 0L
        for(i in 0 until n) {
            parity += abs(target[i] - initial[i])
        }

        if(parity % 2 != 0L) {
            output.append("NO\n")
            continue
        }

        var bipartite = true
        val color = IntArray(n) { 0 }
        val vis = BooleanArray(n){ false }

        fun dfs(node: Int, c: Int) {
            color[node] = c
            vis[node] = true
            for(child in adj[node]) {
                if(vis[child]) {
                    if(color[child] == color[node]) {
                        bipartite = false
                        return
                    }
                } else {
                    dfs(child, c xor 1)
                }
            }
        }

        dfs(0, 0)

        if(!bipartite) {
            output.append("YES\n")
            continue
        }

        val need = LongArray(2) { 0 }
        for(i in 0 until n) {
            need[color[i]] += (target[i] - initial[i])
        }

        if(need[0] != need[1]) {
            output.append("NO\n")
        } else {
            output.append("YES\n")
        }
    }

    print(output)
}