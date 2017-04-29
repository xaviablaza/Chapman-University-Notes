package assignment7.c8p6;

/**
 * Created by Xavi on 4/29/2017.
 */
public class Rectangle extends Figure {

    @Override
    public void draw() {
        super.draw();
        for (int i=0; i<5; ++i) {
            for (int j=0; j<3; ++j) {
                System.out.print('*');
            }
            System.out.println();
        }
    }

    @Override
    public void erase() {
        super.erase();

    }

    @Override
    public void center() {
        super.center();
    }
}
