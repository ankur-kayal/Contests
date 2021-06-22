fun main() {
    val input = System.`in`.bufferedReader()
    val output = StringBuilder()
    val t = readLine()!!.toInt()
    repeat(t) {
        val(n, k) = input.readLine()!!.split(' ').map{it.toInt()}
        val times = n / k
        val rem = n % k
        val offset = 'a'.toInt()
        for( i in 0 until k ) {
            repeat(times) {
                val c = (offset + i).toChar()
                output.append("$c")
            }
        }
        for ( i in 0 until rem ) {
            val c = (offset + i).toChar()
            output.append("$c")
        }
        output.append("\n")
    }
    print(output)
}