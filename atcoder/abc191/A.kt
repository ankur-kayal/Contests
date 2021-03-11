fun main() {
    val r = System.`in`.bufferedReader()
    val s1 = StringBuilder()
    var (v,t,s,d) = r.readLine()!!.split(" ").map{it.toInt()}
    var minDistance = t * v
    var maxDistance = s * v
    if(d in minDistance..maxDistance) {
        s1.append("No")
    }
    else {
        s1.append("Yes")
    }
    print(s1)
}