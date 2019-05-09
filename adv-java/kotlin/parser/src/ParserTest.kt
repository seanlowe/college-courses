import org.junit.jupiter.api.Assertions.*
import org.junit.jupiter.api.Test

internal class ParserTest {

    @Test
    fun setAssoc() {
        val p = Parser()
        p.setAssoc("right")
        assertEquals(Assoc.RIGHT, p.getAssoc())
    }

    @Test
    fun setToken() {
        val p = Parser()
        p.Token("3+4*7")
        assertEquals("3+4*7", p.token)
    }

    @Test
    fun swapOperators() {
        val p = Parser()
        val oldfirst = p.getFirstOp()
        p.swapper()
        assertEquals(oldfirst, p.getSecondOp())
    }
}