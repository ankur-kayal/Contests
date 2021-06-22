fun main() {
    val input = System.`in`.bufferedReader()
    val output = StringBuilder()
    val n = input.readLine()!!.toInt()

    var s = mutableListOf<Pair<String, Int>>()
    for(i in 0 until 2 * n - 2) {
        val si = input.readLine()!!
        s.add(Pair(si, i))
    }

    var ok = true
    var ans = CharArray(2 * n - 2){'*'}
    var used = BooleanArray(2 * n - 2){false}
    var largestSuffix = ""
    for(i in s) {
        if(i.first.length > largestSuffix.length) {
            largestSuffix = i.first
        }
    }

    for(i in 0..n-2) {
        var target = largestSuffix.subSequence(0 + i, n - 1)
        var found = false
        for (j in s) {
            if(j.first == target) {
                ans[j.second] = 'S'
                used[j.second] = true
                found = true
                break
            }
        }
        if(!found) {
            ok = false
            break
        }
    }
    if(ok) {
        var largestPrefix = ""
        for(i in s) {
            if(i.first.length > largestPrefix.length && !used[i.second]) {
                largestPrefix = i.first
            }
        }
        for(i in 0..n-2) {
            var target = largestPrefix.subSequence(0, n - 1 - i)
            var found = false
            for (j in s) {
                if(j.first == target && ans[j.second] == '*') {
                    ans[j.second] = 'P'
                    found = true
                    break
                }
            }
            if(!found) {
                ok = false
                break
            }
        }
    }

    if(!ok) {
        ans = CharArray(2 * n - 2){'S'}
        var largestPrefix = largestSuffix
        for(i in 0..n-2) {
            var target = largestPrefix.subSequence(0, n - 1 - i)
            var found = false
            for (j in s) {
                if(j.first == target) {
                    ans[j.second] = 'P'
                    found = true
                    break
                }
            }
            if(!found) {
                ok = false
                break
            }
        }
    }

    output.append("${ans.joinToString("")}\n")

    print(output)
}