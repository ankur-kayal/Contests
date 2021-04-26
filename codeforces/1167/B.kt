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

private fun query(i: Int, j: Int): Int {
    println("? $i $j");
    System.out.flush()
    return readInt()
}

private fun runCase() {

    var ans = IntArray(6)
    var a = query(1, 2)
    var b = query(2, 3)
    var s = listOf(4, 8, 15, 16, 23, 42).toSet()

    for(i in listOf(4, 8, 15, 16, 23, 42)) {
        if((a * b) % (i * i) == 0) {
            ans[1] = i
            ans[0] = a / i
            ans[2] = b / i

            if(s.contains(ans[0]) && s.contains(ans[1]) && s.contains(ans[2]) && ans[1] != ans[2] && ans[2] != ans[0] && ans[0] != ans[1]) {
                break
            }
        }
    }
    a = query(4, 5)
    b = query(5, 6)
    for(i in listOf(4, 8, 15, 16, 23, 42)) {
        if((a * b) % (i * i) == 0) {
            ans[4] = i
            ans[3] = a / i
            ans[5] = b / i
            if(s.contains(ans[3]) && s.contains(ans[4]) && s.contains(ans[5]) && ans[3] != ans[4] && ans[4] != ans[5] && ans[3] != ans[5]) {
                break
            }
        }
    }
    print("! ")
    println(ans.joinToString(" "))
}


fun main(args: Array<String>) {

    var t: Int = 1
//    t = readInt()
    repeat(t) {
        runCase()
    }

//    print(output)
}

