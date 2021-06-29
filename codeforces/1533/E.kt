import java.util.*

fun main() {
    val input = System.`in`.bufferedReader()
    val output = StringBuilder()

    var n = input.readLine()!!.toInt()
    var a = input.readLine()!!.split(' ').map { it.toInt() }.toMutableList()
    var b = input.readLine()!!.split(' ').map { it.toInt() }.toMutableList()
    var m = input.readLine()!!.toInt()
    var c = input.readLine()!!.split(' ').map { it.toInt() }.toMutableList()

    a = (a.sortedDescending()).toMutableList()
    b = (b.sortedDescending()).toMutableList()

    var diff = IntArray(n) { 0 }
    diff[0] = b[0] - a[0]
    for(i in 1 until n) {
        diff[i] = maxOf(diff[i - 1], b[i] - a[i])
    }
    var shiftDiff = IntArray(n) { 0 }
    shiftDiff[n - 1] = b[n] - a[n - 1]
    for(i in n - 2 downTo 0) {
        shiftDiff[i] = maxOf(shiftDiff[i + 1], b[i + 1] - a[i])
    }
    /*println(a.joinToString())
    println(b.joinToString())
    println(c.joinToString())
    println(diff.joinToString())
    println(shiftDiff.joinToString())*/

    for(i in c) {
        var ans = Int.MIN_VALUE

        var r = n
        var l = -1
        while(r > l + 1) {
            var m = (l + r) / 2
            if(a[m] <= i) {
                r = m
            } else {
                l = m
            }
            // println("$r $l $m ${a[m]}\n")
        }

        // println(r)

        if(r - 1 >= 0) {
            ans = maxOf(ans, diff[r - 1])
        }
        ans = maxOf(ans, b[r] - i)
        if(r + 1 <= n) {
            ans = maxOf(ans, shiftDiff[r])
        }

        output.append("$ans ")
    }

    print(output)
}
