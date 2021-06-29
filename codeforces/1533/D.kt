import java.util.*

fun main() {
    val input = System.`in`.bufferedReader()
    val output = StringBuilder()

    var store = TreeMap<String, Long>()


    var (n, m) = input.readLine()!!.split(' ').map { it.toInt() }

    repeat(n) {
        var s = input.readLine()!!
        store[s] = store.getOrDefault(s, 0L) + 1
    }

    var q = input.readLine()!!.toInt()
    repeat(q) {
        var ans = 0L
        var s = input.readLine()
        var uni = TreeSet<String>()
        for(ignore in 0..m) {
            var gen = ""
            for(i in 0..m) {
                if(ignore == i) continue
                gen += s[i]
            }
            if(uni.contains(gen)) continue
            ans += store.getOrDefault(gen, 0L)
            uni.add(gen)
        }
        output.append("$ans\n")
    }

    print(output)
}
