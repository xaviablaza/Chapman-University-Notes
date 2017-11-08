import org.junit.Test;
import org.junit.Ignore;
import static org.junit.Assert.assertEquals;
import se300.Queue;

public class TestJunit3 {

   @Test
   /*
   Test the getSize() function if the queue has a size of 0 upon initialization.
   */
   public void testGetSize() {
      System.out.println("Testing getSize() is zero");
      Queue queue = new Queue();
      assertEquals(0, queue.getSize());
   }

   @Test
   /*
   Test adding a single value to the queue and remove it.
   */
   public void testSingleAddRemove() {
     System.out.println("Test adding single value");
     // Init the Queue
     Queue queue = new Queue();
     // Add to the queue
     queue.addToRear(1);
     // Check if the queue size is 1 and the value in the queue is 1
     assertEquals(1, queue.getSize());
     assertEquals(1, queue.get(0));
     // Remove the value from the queue
     int a = queue.removeFromFront();
     // Check if the value removed is a 1 and check if the size of the queue is 0
     assertEquals(1,a);
     assertEquals(0,queue.getSize());
   }

   @Test
   /*
   Test if getting by index returns the correct values
   */
   public void testGet() {
       System.out.println("Testing getting");
       // Init the queue
       Queue queue = new Queue();
       // Add 5 values to the queue
       for (int i=0; i<5; ++i) {
            queue.addToRear(i);
            // Check if the values are placed in the queue correctly
            assertEquals(i,queue.get(i));
        }

        // Check if the size of the queue is 5
        assertEquals(5,queue.getSize());
   }

   @Test
   /*
   Test adding and removing multiple values
   */
   public void testMultiAddRemove() {
       System.out.println("Testing adding and removing values");
       // Init the queue
       Queue queue = new Queue();
       // Add values to the queue
       for (int i=0; i<5; ++i) {
            queue.addToRear(i);
            // Check if the values are placed in the queue correctly
            assertEquals(i,queue.get(i));
        }
        // Check if the size of the queue is 5
        assertEquals(5,queue.getSize());
        // Remove values from the queue (must be in FIFO order)
        for (int i=0; i<5; ++i) {
            assertEquals(i,queue.removeFromFront());
        }
   }

}
