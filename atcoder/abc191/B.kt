fun main() {
    val r = System.`in`.bufferedReader()
    val s1 = StringBuilder()
    val (n,x) = r.readLine().split(" ").map{it.toInt()}
    val a = r.readLine().split(" ").map{it.toInt()}
    for(i in a) {
        if(i != x) {
            s1.append("$i ")
        }
    }
    print(s1)
}

