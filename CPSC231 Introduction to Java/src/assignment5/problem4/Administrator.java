package assignment5.problem4;

/**
 * Created by Xavi on 4/5/2017.
 */
public class Administrator extends SalariedEmployee {
    private String title;
    private String responsibility;

    public Administrator() {
        title = "No title";
        responsibility = "No responsibility";
    }

    public String getTitle() {
        return title;
    }

    public void setTitle(String title) {
        this.title = title;
    }

    public String getResponsibility() {
        return responsibility;
    }

    public void setResponsibility(String responsibility) {
        this.responsibility = responsibility;
    }

    @Override
    public String toString() {
        return (getName() + " " + title + " with responsibility " + responsibility);
    }

    public boolean equals(Administrator other) {
        return (title.equals(other.title)
                && responsibility.equals(other.responsibility));
    }
}
