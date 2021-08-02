class SparseTable(values: LongArray) {
    var lift: Array<LongArray>
    val N: Int

    init {
        val n = values.size
        N = n
        val maxLog = Integer.numberOfTrailingZeros(Integer.highestOneBit(n)) + 2
        lift = Array(maxLog) { LongArray(n) }
        for(i in 0 until n) {
            lift[0][i] = values[i]
        }

        var lastRange = 1
        for(lg in 1 until maxLog) {
            for(i in 0 until n) {
                lift[lg][i] = combine(lift[lg -1][i], lift[lg - 1][minOf(i + lastRange, n - 1)])
            }
            lastRange *= 2
        }
    }

    private fun gcd(a: Long, b: Long): Long {
        if(b == 0L) return a
        return gcd(b, a % b)
    }

    private fun combine(a: Long, b: Long): Long {
        return gcd(a, b);
    }

    /*
    * @param l range start
    * @param r range end
    * @return query of the function defined in the range [l, r]
    * */
    fun query(l: Int, r: Int): Long {
        assert(l in 0..r && r < N)
        val range = r - l + 1
        val exp = Integer.highestOneBit(range)
        val lg = Integer.numberOfTrailingZeros(exp)
        return combine(lift[lg][l], lift[lg][r - exp + 1])
    }
}

fun main() {
    val t = readLine()!!.toInt()
    repeat(t) {
        val n = readLine()!!.toInt()
        val A = readLine()!!.split(' ').map { it.toLong() }
        val doubleA = LongArray(2 * n)
        var index = 0
        for(i in A) {
            doubleA[index] = i
            index++
        }
        for(i in A) {
            doubleA[index] = i
            index++
        }

        val st = SparseTable(doubleA)

        fun good(m: Int): Boolean {
            var prev = -1
            for(i in 0 until n) {
                if(prev == -1) {
                    prev = st.query(i, i + m - 1).toInt()
                } else {
                    val curr = st.query(i, i + m - 1).toInt()
                    if(curr != prev) {
                        return false
                    }
                }
            }
            return true
        }

        var l = 0; var r = n

        while(r > l + 1) {
            val m = (r + l) / 2
            if(good(m)) {
                r = m
            } else {
                l = m
            }
        }
        println(r - 1)
    }
}