fun main() {
    val input = System.`in`.bufferedReader()
    val output = StringBuilder()
    val t = readLine()!!.toInt()
    repeat(t) {
        val(a, b, k) = readLine()!!.split(' ').map { it.toLong() }
        val diff = a - b
        var ans = diff * (k / 2)
        if(k % 2 == 1L) {
            ans += a
        }
        output.append("$ans\n")
    }
    print(output)
}