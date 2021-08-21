import kotlin.collections.ArrayDeque


val stack = ArrayDeque<Char>()

fun main() = with(System.`in`.bufferedReader()) {
    val str = readLine()

    for (ch in str) {
        stack.add(ch)

        if (stack.size >= 4) {
            var flag = true
            for (idx in 0..3) {
                if (stack[stack.lastIndex - idx] != (if (idx == 1) 'A' else 'P')) {
                    flag = false
                    break
                }
            }
            if (flag) {
                stack.removeLast()
                stack.removeLast()
                stack.removeLast()
            }
        }
    }

    if (stack.size == 1 && stack[0] == 'P') {
        println("PPAP")
    } else {
        println("NP")
    }
}
