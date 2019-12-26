import kotlin.system.exitProcess

class Parser(var token: String, var tk: Char) {
    private fun error() {
        println("ERROR!")
        exitProcess(1)
    }

    private fun getToken() {
        if (token.isNotEmpty()) {
            tk = token.elementAt(0)
            token = token.removeRange(0, 1)
            if (tk.isDefined()) print("\n<gettoken> $tk ")
        } else {
            tk = '$'
        }
    }

    private fun digit() {
        print(" <digit> ")
        if (tk.isDigit()) {
            getToken()
        } else {
            error()
        }
    }

    private fun number() {
        print(" <number> ")
        digit()
        while (tk.isDigit()) {
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
        while ( tk == '*') {
            getToken()
            factor()
        }
    }

    private fun exp() {
        print(" <exp> ")
        term()
        while ( tk == '+') {
            getToken()
            term()
        }
    }

    fun parse() {
        print("<parse>")
        getToken()
        exp()
        print("\nNo errors this time!")
        return
    }
}