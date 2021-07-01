import kotlin.math.sqrt

fun main() {
    val input = System.`in`.bufferedReader()
    val output = StringBuilder()

    val t = input.readLine()!!.toInt()
    repeat(t) {
        var n = input.readLine()!!.toInt()
        var copy = n
        val primeFactors = mutableListOf<Int>()
        var first = -1
        for(i in 2..sqrt(n.toDouble()).toInt()) {
            if(n % i == 0) {
                first = i
                break
            }
        }
        if(first != -1) {
            n /= first
            var second = -1
            for(i in 2..sqrt(n.toDouble()).toInt()) {
                if(n % i == 0 && i > first && n / i > first && n / i > i) {
                    second = i
                    break
                }
            }
            if(second != -1) {
                output.append("YES\n$first $second ${copy / (first * second)}\n")
            } else {
                output.append("NO\n")
            }

        } else {
            output.append("NO\n")
        }
    }

    print(output)
}
