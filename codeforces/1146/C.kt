
fun main() {
    val input = System.`in`.bufferedReader()
    val output = StringBuilder()

    val t = input.readLine()!!.toInt()
    repeat(t) {
        var n = input.readLine()!!.toInt()

        var ans = -1

        for(i in 0..6) {
            var a = mutableListOf<Int>(); var b = mutableListOf<Int>()
            for(v in 1..n) {
                if((v and (1 shl i)) != 0) {
                    a.add(v)
                } else {
                    b.add(v)
                }
            }
            if(a.isEmpty() || b.isEmpty()) {
                break
            }
            output.append("${a.size} ${b.size}")
            for(i in a) {
                output.append(" $i")
            }
            for(i in b) {
                output.append(" $i")
            }
            println(output)
            output.clear()
            ans = maxOf(ans, input.readLine()!!.toInt())
        }

        println("-1 $ans")
    }
}
