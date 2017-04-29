package assignment7.c8p6;

/**
 * Created by Xavi on 4/29/2017.
 */
public class Figure {
    private int height;
    private int width;
    private int center;

    public int getHeight() {
        return height;
    }

    public void setHeight(int height) {
        this.height = height;
    }

    public int getWidth() {
        return width;
    }

    public void setWidth(int width) {
        this.width = width;
    }

    public int getCenter() {
        return center;
    }

    public void setCenter(int center) {
        this.center = center;
    }

    public void erase() {
        System.out.println(this.getClass().toString() + " erase() called");
        for (int i=0; i<50; ++i) {
            System.out.println();
        }
    }

    public void draw() {
        System.out.println(this.getClass().toString() + " draw() called");
    }

    public void center() {
        System.out.println("center() called");
        erase();
        draw();
    }
}
