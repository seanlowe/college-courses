import org.junit.jupiter.api.Test;
import static org.junit.jupiter.api.Assertions.*;

class BagTest {

    @Test
    void contains() {
        Bag b = new Bag();
        b.add("apple");
        assertEquals(false, b.contains("berry"));
    }

    @Test
    void countOf() {
        Bag b = new Bag();
        b.add("apple"); b.add("pear");
        b.add("blueberry"); b.add("apple");
        int res = b.countOf("apple");
        assertEquals(2, res);
    }

    @Test
    void length() {
        Bag b = new Bag();
        b.add("to"); b.add("be");
        b.add("or"); b.add("not");
        b.add("to"); b.add("be");
        int exp = 6;
        int res = b.length();
        assertEquals(exp, res);
    }

    @Test
    void addSingle() {
        Bag b = new Bag();
        b.add("test_object");
        assertEquals(1, b.length());
    }

    @Test
    void addArray() {
        Bag b = new Bag();
        String[] n = {"this", "is", "a", "test"};
        b.add( n );
        assertEquals(4, b.length());
    }

    @Test
    void delete() {
        Bag b = new Bag();
        b.add("string");
        assertEquals(1, b.length());
        b.delete("string");
        assertEquals(0, b.length());
    }

    @Test
    void erase() {
        Bag b = new Bag();
        b.add("eraser"); b.add("pencil"); b.add("eraser");
        assertEquals(2, b.countOf("eraser"));
        b.erase("eraser");
        assertEquals(1, b.countOf("eraser"));
    }

    @Test
    void clean() {
        Bag b = new Bag();
        b.add("Once"); b.add("Upon"); b.add("A"); b.add("Time");
        b.add("There"); b.add("Were"); b.add("Three"); b.add("Brothers");
        assertEquals(8, b.length());
        b.clean();
        assertEquals(0, b.length());
    }
}