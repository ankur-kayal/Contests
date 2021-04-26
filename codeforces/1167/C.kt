import java.lang.AssertionError


private val input = System.`in`.bufferedReader()
private val output = StringBuilder()


private fun readLn() = input.readLine()!! // string line
private fun readInt() = readLn().toInt() // single int
private fun readLong() = readLn().toLong() // single long
private fun readDouble() = readLn().toDouble() // single double
private fun readStrings() = readLn().split(" ") // list of strings
private fun readInts() = readStrings().map { it.toInt() } // list of ints
private fun readLongs() = readStrings().map { it.toLong() } // list of longs
private fun readDoubles() = readStrings().map { it.toDouble() } // list of doubles

private fun myAssert(x: Boolean) {
    if (!x) {
        throw AssertionError()
    }
}

private const val maxN: Int = 500000+10

private val adj: MutableList<MutableList<Int>> = mutableListOf()
private val vis: MutableList<Boolean> = mutableListOf()
private val friends: MutableList<Int> = mutableListOf()

private fun init(n: Int) {
    for (i in 1..n) {
        adj[i].clear()
        vis[i] = false
    }
}

private fun dfs(node: Int) {
    vis[node] = true
    friends.add(node)
    for(child in adj[node]) {
        if(!vis[child]) {
            dfs(child)
        }
    }
}

private fun runCase() {

    var(n, m) = readInts()
    init(n)
    repeat(m) {
        var tmp = readInts()
        if(tmp.size != 2) {
            for( i in 1 until tmp.size - 1) {
                var u = tmp[i]
                var v = tmp[i + 1]
                adj[u].add(v)
                adj[v].add(u)
            }
        }
    }
    var ans = IntArray(n + 1)
    for(i in 1..n) {

        if(!vis[i]) {
            friends.clear()
            dfs(i)
            for(friend in friends) {
                ans[friend] = friends.size
            }
        }
    }
    for (i in 1..n) {
        output.append("${ans[i]} ")
    }
}


fun main(args: Array<String>) {

    var t: Int = 1
    // t = readInt()
    for(i in 0 until maxN) {
        adj.add(mutableListOf())
        vis.add(false)
    }
    repeat(t) {
        runCase()
    }

    print(output)
}

