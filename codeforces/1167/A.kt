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

    var n = readInt()
    var s = readLn()
    s = s.reversed()
    var cnt = 0
    var head = 0
    for (i in s) {
        cnt++
        if(i == '8') {
            head = cnt
        }
    }
    if(head >= 11) {
        output.append("YES\n")
    } else {
        output.append("NO\n")
    }
}


fun main(args: Array<String>) {

    var t: Int = 1
    t = readInt()
    repeat(t) {
        runCase()
    }

    print(output)
}

