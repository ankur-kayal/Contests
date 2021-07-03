
fun main() {
    val input = System.`in`.bufferedReader()
    val output = StringBuilder()

    val t = input.readLine()!!.toInt()
    repeat(t) {
        val(n, a, b) = input.readLine()!!.split(' ').map { it.toLong() }
        if(a == 1L) {
            if((n - 1) % b == 0L) {
                output.append("YES\n")
            } else {
                output.append("NO\n")
            }
        } else {
            var mul = 1L
            var res = "NO"
            while(mul <= n) {
                if((n - mul) % b == 0L) {
                    res = "YES";
                }
                mul *= a
            }
            output.append("$res\n")
        }
    }

    print(output)
}

