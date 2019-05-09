/*
* @author sean-lowe
* @purpose Advanced Programming: Java Final Project
* @summary Top-Down Recursive Parser for left associativity                     ( v1.0 )
* ** that displays the end result of the parsed equation                        ( v1.1 )
* * ** or right associativity                                                   ( v1.2 )
* ** and ability to change the parser's grammar rules via class members (?)     ( v1.3 )
 */

//import java.util.Scanner
import java.util.Scanner
import kotlin.system.exitProcess

enum class Assoc {
    RIGHT, LEFT, NONE
}

class Parser(private var tk : Char = ' ', var token : String = " ", private var mode : Assoc = Assoc.NONE) {
    var result : Int = 0 // result of parsed equation TODO
    private val reader = Scanner(System.`in`)
    private var fpc : Char = '*' // character to take greater precedence
    private var spc : Char = '+' // character to take lesser precedence

    fun getAssoc() : Assoc { return mode }
    fun getFirstOp() : Char { return fpc }
    fun getSecondOp() : Char { return spc }

    // Debugging function
    fun DISPLAYTOKEN() {
        println(this.token);
        exitProcess(0)
    }

    // FUTURE UPDATE?
    fun setAssoc(m : String) {
        // set the associativity of the parser program
        when (m) {
            "left" -> this.mode = Assoc.LEFT
            "right" -> this.mode = Assoc.RIGHT
            "none" -> this.mode = Assoc.NONE
        }
    }

    /* INTERNAL FUNCTIONS */
    fun swapper() { swapOperators() }
    fun Token(str : String) { setTokenExpr(str) }

    private fun error() {
        println("Error!")
        exitProcess(1)
    }

    private fun menu() {
        println("\n\nPlease choose an option:")
        println("  1. Parse an Equation")
        println("  2. Switch Operator Rules")
        println("  3. Display Current Parsing Grammar")
        println("  4. Exit Program")
        val tempstr = getInput()
        when (tempstr) {
            "1" -> startParser()
            "2" -> swapOperators()
            "3" -> printGrammar()
            "4" -> exitProcess(0)
            //"5" -> { print("\u001b[H\u001b[2J"); System.out.flush() } /* how to clear the console screen? */
        }
    }

    private fun startParser() {
        println("\nEnter an Equation to Parse:")
        setTokenExpr(getInput())
        parse()
    }

    private fun printGrammar() {
        println("\n\nCurrent Rules for Top-Down Recursive Parser:")
        println("  1. E -> E $fpc T | T")
        println("  2. T -> T $spc F | F")
        println("  3. F -> (E) | N")
        println("  4. N -> D")
        println("  5. D | [end]")
    }

    private fun getInput() : String {
        print("\n > ")
        return reader.nextLine()
    }

    private fun setTokenExpr(str : String) {
        // set the token to parse
        this.token = str
    }

    private fun swapOperators() {
        val temp : Char = fpc
        fpc = spc
        spc = temp
    }
    /* END INTERNAL FUNCTIONS */

    /* PARSING FUNCTIONS */
    private fun getToken() {
        if ( token.isNotEmpty() ) {
            tk = token.elementAt(0)
            token = token.removeRange(0,1)
            if ( tk.isDefined() ) print("\n<gettoken> $tk")
        } else {
            tk = '$'
        }
    }

    private fun digit() {
        print(" <digit> ")
        if ( tk.isDigit() ) {
            getToken()
        } else {
            error()
        }
    }

    private fun number() {
        print(" <number> ")
        digit()
        while( tk.isDigit() ) {
            digit()
        }
        return
    }

    private fun factor() {
        print(" <factor> ")
        if ( tk == '(') {
            getToken()
            exp()
            if ( tk == ')') {
                getToken()
            } else {
                error()
            }
        } else {
            number()
        }
    }

    private fun term() {
        print(" <term> ")
        factor()
        while(tk == fpc) {
            getToken()
            factor()
        }
    }

    private fun exp() {
        print(" <exp> ")
        term()
        while (tk == spc) {
            getToken()
            term()
        }
    }

    private fun parse() {
        print("<parse> ")
        getToken()
        exp()
        println("\nNo Errors This Time!")
    }
    /* END PARSING FUNCTIONS */

    /* ENTRY FUNCTION */
    fun run() {
        while (true) {
            menu()
        }
    }

} // end of class [ Parser ]