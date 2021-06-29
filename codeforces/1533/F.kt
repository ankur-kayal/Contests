
fun main() {
    val input = System.`in`.bufferedReader()
    val output = StringBuilder()

    val s = input.readLine()!!
    var n = s.length
    val zeroCountAt = IntArray(n) { 0 }
    val oneCountAt = IntArray(n) { 0 }
    var(zeroCount, oneCount) = listOf(0, 0)
    for(i in s.indices) {
        if(s[i] == '1') {
            oneCount++
        } else {
            zeroCount++
        }
        zeroCountAt[i] = zeroCount
        oneCountAt[i] = oneCount
    }
    for(k in 1..n) {
        var at = 0
        var parts = 0
        while(at < n) {
            parts++
            var(l, r) = listOf(at, n)
            while(r > l + 1) {
                var m = (l + r) / 2
                var count0 = zeroCountAt[m]
                var count1 = oneCountAt[m]
                if(at - 1 >= 0) {
                    count0 -= zeroCountAt[at - 1]
                    count1 -= oneCountAt[at - 1]
                }

                if(count0 <= k || count1 <= k) {
                    l = m
                } else {
                    r = m
                }
            }
            at = r
        }
        output.append("$parts ")
    }

    print(output)
}
