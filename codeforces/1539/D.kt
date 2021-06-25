fun main() {
    val input = System.`in`.bufferedReader()
    val output = StringBuilder()

    val n = input.readLine()!!.toInt()

    var items = Array<Pair<Long, Long>>(n) { Pair(0L, 0L) }
    var totalItems = 0L

    for(i in 0 until n) {
        val(u, v) = input.readLine()!!.split(' ').map { it.toLong() }
        items[i] = Pair(u, v)
    }
    for(i in items) {
        totalItems += i.first
    }

    items = (items.sortedWith(compareBy { it.second })).toTypedArray()

    var(l, r) = listOf(0, n - 1)

    var(current, discount) = listOf(0L, 0L)

    while(l <= r) {
        var req = maxOf(0L, items[l].second - current)

        if(req > 0L) {
            var got = minOf(items[r].first, req)
            items[r] = items[r].copy(first = items[r].first - got)
            current += got
            if(items[r].first == 0L) {
                r--;
            }
        } else {
            discount += items[l].first
            current += items[l].first
            l++
        }
    }

    output.append("${2L * totalItems - discount}\n")

    print(output)
}
