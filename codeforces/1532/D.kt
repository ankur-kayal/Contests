fun main() {
    val input = System.`in`.bufferedReader()
    val output = StringBuilder()
    val n = input.readLine()!!.toInt()
    var a = input.readLine()!!.split(' ').map { it.toInt() }
    a = a.sorted()
    var ans = 0
    var i = 0
    while(i < n) {
        ans += a[i + 1] - a[i]
        i += 2
    }
    println(ans)
}