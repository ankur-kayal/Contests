import java.util.ArrayDeque

fun main() {
    val input = System.`in`.bufferedReader()
    val output = StringBuilder()

    val t = input.readLine()!!.toInt()
    repeat(t) {
        var (n, k) = input.readLine()!!.split(' ').map { it.toInt() }
        val eaten = BooleanArray(n) { false }
        var s = input.readLine()!!

        var sweet = 0

        var ind = ArrayDeque<Int>()
        for(i in 0 until n) {
            ind.addLast(i + 1)
        }
        var ok = 0
        for(i in s) {
            if(i == '1') {
                ok++
            }
        }

        if(ok > 0) {
            sweet++
            ind.removeFirst()
            if(s[0] == '1') {
                ok--
            }
            while(ok > 0) {
//                println(ind.toString())
                var cnt = 0
                while(cnt < k - 1) {
                    ind.addLast(ind.first)
                    ind.removeFirst()
                    cnt++
                }
                if(s[ind.first() - 1] == '1') {
                    ok--
                }
                sweet++
                ind.removeFirst()

            }
        }

        output.append(("$sweet\n"))
    }
    print(output)
}
