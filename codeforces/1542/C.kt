
fun main() {
    val input = System.`in`.bufferedReader()
    val output = StringBuilder()

    val mod: Long = 1000000007L

    fun gcd(a: Long, b: Long): Long {
        if(b == 0L) return a
        return gcd(b, a % b)
    }

    fun lcm(a: Long, b: Long): Long {
        return (a * b / gcd(a, b))
    }

    val t = input.readLine()!!.toInt()
    repeat(t) {
        val n = input.readLine()!!.toLong()
        var ans = 0L

        var prev = 0L
        var lc = 1L
        for(i in 2..50) {
            lc = lcm(i.toLong(), lc)
            var tmp = n - n / lc
            ans += (i * (tmp - prev))
            prev = tmp
            ans %= mod
        }

        output.append("$ans\n")
    }

    print(output)
}

