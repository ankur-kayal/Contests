fun main() {
    val n = readLine()!!.toInt()
    val a = readLine()!!.split(" ").map { it.toInt() }

    val ans = mutableListOf<Int>()

    val cnt = HashMap<Int, Int>()

    for (i in n-1 downTo 0) {
        if(!cnt.containsKey(a[i])) {
            ans.add(a[i])
            cnt[a[i]] = 1
        }
    }
    ans.reverse()
    println(ans.size)
    for (i in ans) {
        print(i)
        print(" ")
    }

}