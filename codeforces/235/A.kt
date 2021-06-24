private fun lcm(i: Long, j: Long): Long {
    return i * j / hcf(i, j);
}

private fun hcf(i: Long, j: Long): Long {
    if(j == 0L) {
        return i
    }
    return hcf(j, i % j)
}

private fun getLcm(i: Long, j: Long, k: Long): Long {
    return lcm(lcm(i, j), k)
}

fun main() {
    val input = System.`in`.bufferedReader()
    val output = StringBuilder()

    val n = input.readLine()!!.toInt()
    var ans = 1L
    for(i in n downTo maxOf(1, n - 100)) {
        for(j in n downTo maxOf(1, n - 100)) {
            for(k in n downTo maxOf(1, n - 100)) {
                ans = maxOf(ans, getLcm(i.toLong(), j.toLong(), k.toLong()))
            }
        }
    }
    output.append("$ans\n")

    print(output)
}
