fun main() {
    val input = System.`in`.bufferedReader()
    val output = StringBuilder()

    val t = input.readLine()!!.toInt()
    repeat(t) {
        var(n, k) = input.readLine()!!.split(' ').map { it.toInt() }
        var ans = 0
        repeat(n) {
            var(l, r) = input.readLine()!!.split(' ').map { it.toInt() }
            if(l <= k)
                ans = maxOf(ans, r - k + 1)
        }
        output.append("$ans\n")
    }
    print(output)
}
