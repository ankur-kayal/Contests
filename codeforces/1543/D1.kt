
fun main() {
    val input = System.`in`.bufferedReader()
    val output = StringBuilder()

    fun kxor(aa: Int, bb: Int, k: Int) : Int {
        var a = aa
        var b = bb
        var ans = 0
        var mul = 1

        while(a > 0 || b > 0) {
            ans += ( (a % k + b % k) % k ) * mul
            mul *= k
            a /= k
            b /= k
        }
        return ans
    }

    fun kxori(aa: Int, bb: Int, k: Int) : Int {
        var a = aa
        var b = bb
        var ans = 0
        var mul = 1

        while(a > 0 || b > 0) {
            ans += ( (a % k - b % k + k) % k ) * mul
            mul *= k
            a /= k
            b /= k
        }
        return ans
    }

    val t = readLine()!!.toInt()
    repeat(t) {
        var(n, k) = readLine()!!.split(' ').map { it.toInt() }
        var x = 0
        for(ans in 0 until n) {
            var query = kxor(x, ans, k)
            if(ans % 2 == 1) {
                query = kxori(x, ans, k)
            }
            println(query)
            var r = readLine()!!.toInt()
            if(r == 1) {
                break
            }
            x = kxori(query, x, k)
        }

    }
}

