import java.util.*

fun main() {
    val input = System.`in`.bufferedReader()
    val output = StringBuilder()
    val(n, m) = input.readLine()!!.split(" ").map { it.toInt() }
    val a = input.readLine()!!.split(" ").map { it.toInt() }
    val cnt: IntArray = IntArray(n + 1)
    val mex: TreeSet<Int> = TreeSet()
    for(i in 0..n) {
        mex.add(i)
    }

    var ans: Int = 1000000000
    var l: Int = 0
    var r: Int = 0
    while(r < l + m) {
        cnt[a[r]]++
        if(cnt[a[r]] == 1) {
            mex.remove(a[r])
        }
        r++
    }
    r--
    ans = mex.first()
    while(l < n - m) {
        cnt[a[l]]--
        if(cnt[a[l]] == 0) {
            mex.add(a[l])
        }
        l++
        r++
        cnt[a[r]]++
        if(cnt[a[r]] == 1) {
            mex.remove(a[r])
        }
        ans = minOf(ans, mex.first())
    }
    output.append("$ans")

    print(output)
}

