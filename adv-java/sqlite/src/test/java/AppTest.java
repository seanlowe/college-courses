import org.junit.Test;

import java.util.concurrent.TimeUnit;

import static org.junit.Assert.*;

public class AppTest {

    @org.junit.Test
    public void insert() {
        App p = new App("inserttest.db");
        p.createNewDatabase();
        p.createNewTable();
        p.deleteAll();
        boolean b4 = p.find("Bricks");
        //System.out.println(b4);
        p.insert("Bricks", 500);
        boolean after = p.find("Bricks");
        assertNotEquals(b4, after);
    }

    @org.junit.Test
    public void update() {
        App p = new App("updatetest.db");
        p.createNewDatabase();
        p.createNewTable();
        p.deleteAll();
        String name = "Granite";
        p.insert(name, 250);
        double first = p.getCapacity(name);
        int id = p.getId(name);
        p.update(id, name, 500);
        double second = p.getCapacity(name);
        assertNotEquals(first, second);
    }

    @org.junit.Test
    public void delete() {
        App p = new App("deletetest.db");
        p.createNewDatabase();
        p.createNewTable();
        p.insert("Cobblestone", 500);
        p.delete("Cobblestone");
        boolean found = p.find("Cobblestone");
        assertFalse(found);
    }

    @org.junit.Test
    public void select() {
        String result = "Obsidian";
        App p = new App("selecttest.db");
        p.createNewDatabase();
        p.createNewTable();
        p.insert(result, 150);
        String actual = p.select(result);
        assertEquals(result, actual);
    }
}