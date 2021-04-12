import java.lang.AssertionError


private val input = System.`in`.bufferedReader()
private val output = StringBuilder()


private fun readLn() = input.readLine()!! // string line
private fun readInt() = readLn().toInt() // single int
private fun readLong() = readLn().toLong() // single long
private fun readDouble() = readLn().toDouble() // single double
private fun readStrings() = readLn().split(" ") // list of strings
private fun readInts() = readStrings().map { it.toInt() } // list of ints
private fun readLongs() = readStrings().map { it.toLong() } // list of longs
private fun readDoubles() = readStrings().map { it.toDouble() } // list of doubles

private fun myAssert(x: Boolean) {
    if (!x) {
        throw AssertionError()
    }
}

private fun runCase() {

    var(n, k) = readInts()
    var a = readInts()
    var prefixSums = IntArray(n)
    prefixSums[0] = a[0]
    for (i in 1 until n) {
        prefixSums[i] = prefixSums[i-1] + a[i]
    }
    if(n == 1) {
        output.append("${a[0]}\n")
        return
    }

    var ans = 0
    var cnt = 1
    for (i in n-2 downTo 0) {
        cnt++
        var sum = 0
        if(i - 1 >= 0) {
            sum -= prefixSums[i-1]
        }
        sum += prefixSums[i + (cnt / k) - 1]
        ans = maxOf(ans, sum)
    }
    output.append("$ans\n")
}


fun main(args: Array<String>) {

    var t: Int = 1
    t = readInt()
    repeat(t) {
        runCase()
    }

    print(output)
}

