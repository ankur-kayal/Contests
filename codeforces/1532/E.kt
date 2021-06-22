fun main() {
    val input = System.`in`.bufferedReader()
    val output = StringBuilder()
    val n = input.readLine()!!.toInt()
    var a = input.readLine()!!.split(' ').map { it.toLong() }
    var sum = 0L

    var cnt = hashMapOf<Long, Long>()

    for(i in a) {
        sum += i
    }

    for(i in a) {
        cnt[i] = cnt.getOrDefault(i, 0) + 1
    }

    var ans = mutableListOf<Int>()

    for( i in 0 until n) {
        var modifiedSum = sum - a[i]
        cnt[a[i]] = cnt[a[i]]!! - 1;
        if(modifiedSum % 2 == 0L) {
            var midElement = modifiedSum / 2
            if(cnt.containsKey(midElement) && cnt[midElement]!! > 0) {
                ans.add(i + 1)
            }
        }
        cnt[a[i]] = cnt[a[i]]!! + 1;
    }

    output.append("${ans.size}\n")
    output.append("${ans.joinToString(" ")}\n")
    print(output)
}