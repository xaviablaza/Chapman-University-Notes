import org.junit.Test;
import org.junit.Ignore;
import static org.junit.Assert.assertEquals;
import se300.Queue;

public class TestJunit3 {

   @Test
   public void testGetSize() {
      Queue queue = new Queue();
      assertEquals(0, queue.getSize());
   }

   @Test
   public void testSingleAddRemove() {
     System.out.println("Testing adding");
     Queue queue = new Queue();
     queue.addToRear(1);
     assertEquals(1, queue.getSize());
     assertEquals(1, queue.get(0));
     int a = queue.removeFromFront();
     assertEquals(1,a);
     assertEquals(0,queue.getSize());
   }

   @Test
   public void testGet() {
       System.out.println("Testing getting");
       Queue queue = new Queue();
       for (int i=0; i<5; ++i) {
            queue.addToRear(i);
            assertEquals(i,queue.get(i));
        }
        assertEquals(5,queue.getSize());
   }

   @Test
   public void testMultiAddRemove() {
       System.out.println("Testing adding and removing values");
       Queue queue = new Queue();
       for (int i=0; i<5; ++i) {
            queue.addToRear(i);
            assertEquals(i,queue.get(i));
        }
        assertEquals(5,queue.getSize());
        for (int i=0; i<5; ++i) {
            assertEquals(i,queue.removeFromFront());
        }
   }

}
