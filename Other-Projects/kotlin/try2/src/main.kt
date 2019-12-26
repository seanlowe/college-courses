/*
X --- recursion
X --- iterative function
X --- for loop
    decrement for loop
X --- while loop
X --- if else if
    when
X --- strings
    search a string for occurrences
    sort a string per character
math
X --- class
inheritance
X ---- input
tests
 */
import java.util.Scanner


class Hitbox(var hit: Int, var mis: Int)

fun evaluate() {
    while (true) {
        val reader = Scanner(System.`in`)
        print("\n\nEnter an equation: (-1 to exit)\n > ")
        val str: String = reader.nextLine()
        if (str.equals("-1")) break
        println("\nYou Entered: $str")
        val p = Parser(str, ' ')
        p.parse()
    }
}

// search a string for number of occurrences of a certain letter
fun strSearch(str: String, c: Char, d: Char) : Int {
    val h = Hitbox(0,0)
    for (i in 0 until str.length) {
        when (str[i] == c || str[i] == d) {
            true -> h.hit++
            false -> h.mis++
        }
    }
    return h.hit
}

fun sortString(str: String) : String {
   val str1 = str.toCharArray().let {
        for (i in 0 until it.lastIndex) {
            for (j in 0 until it.lastIndex) {
                if (it[j] > it[j + 1]) {
                    val temp = it[j]
                    it[j] = it[j + 1]
                    it[j + 1] = temp
                }
            }
        }
        String(it)
    }
    return str1
}

fun printstars(n: Int) {
    var str = ""
    if ( n == 0 ) return
    for (i in 0 until n) {
        str += "*"
    }
    println(str)
}

fun stars(n: Int) {
    if ( n == 0) return
    printstars(n)
    stars(n-1)
    printstars(n)
}

fun factorial(n: Int) : Int {
    when (n != 0) {
        true -> return n * factorial(n-1)
        false -> return 1
    }
}

fun fact(n: Int) : Int {
    var sum = 1
    for (i in n downTo 2) {
        sum *= i
    }
    return sum
}

fun main(args: Array<String>) {
    // Variable Declarations
    var counter = 0
    val mode = 0
    val str = "aaaaabbbbbbbccddddddscottseanlowefaljfojohoqhtoihqtbowbqobtnz"

    // ----------------------------------------------------------------
    // Code
    /* for (i in 0..5) { /* println(i) */  } */
    /* while (counter < 10) { /* println("This is a while loop, loop #" + (counter+1)) */ counter++  } */
    if (mode == 1) {
        println("The factorial of 7 recursively is: " + factorial(7))
        println("The factorial of 4 iteratively is: " + fact(4))
        // ----------------------
        println("\nAn hourglass!"); stars(4)
        // ----------------------
        val hits = strSearch(str, 's', 'z')
        println("there are $hits s's and z's in $str")
        // ----------------------
        val newstr = sortString(str)
        println("$str \ngot sorted into \n$newstr")
    }
    else {
        evaluate()
    }
}