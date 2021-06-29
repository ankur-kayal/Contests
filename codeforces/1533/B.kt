fun main() {
    val input = System.`in`.bufferedReader()
    val output = StringBuilder()

    val t = input.readLine()!!.toInt()
    repeat(t) {
        var n = input.readLine()!!.toInt()
        var x = input.readLine()!!.split(' ').map { it.toInt() }
        var ok = false
        for(i in 0 until n - 1) {
            if((x[i + 1] - x[i]) % 2 == 0) {
                ok = true
                break
            }
        }
        if(ok) {
            output.append("YES\n")
        } else {
            output.append("NO\n")
        }
    }
    print(output)
}
