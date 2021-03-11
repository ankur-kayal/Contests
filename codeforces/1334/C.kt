fun main() {
    val r = System.`in`.bufferedReader()
    val s1 = StringBuilder()
    val times = r.readLine()!!.toInt()
    repeat(times) {
        val n = r.readLine()!!.toInt()
        val a = LongArray(n)
        val b = LongArray(n)
        for(i in 0 until n) {
            val(ai, bi) = r.readLine()!!.split(" ").map{it.toLong()}
            a[i] = ai
            b[i] = (bi)
        }

        var sum: Long = 0
        var combo: Long = 0

        for(i in 0 until n) {
            sum += a[i]
            var prev = (if(i == 0) n-1 else i - 1)
            combo += minOf(b[prev], a[i])
        }

        var ans: Long = Long.MAX_VALUE
        for(i in 0 until n) {
            var prev = (if(i == 0) n-1 else i - 1)
            ans = minOf(ans, sum - (combo - minOf(a[i], b[prev])))
        }
        s1.append("${ans}\n")
    }
    print(s1)
}