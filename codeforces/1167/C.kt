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


private fun runCase() {

    var(n, m) = readInts()
    var adj = List(n + 1) { mutableListOf<Int>() }
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
    var friends = mutableListOf<Int>()
    var vis = BooleanArray(n + 1)
    fun dfs(node: Int) {
        vis[node] = true
        friends.add(node)
        for(child in adj[node]) {
            if(!vis[child]) {
                dfs(child)
            }
        }
    }
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
    repeat(t) {
        runCase()
    }

    print(output)
}

