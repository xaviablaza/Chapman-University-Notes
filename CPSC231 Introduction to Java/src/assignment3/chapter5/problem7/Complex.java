package assignment3.chapter5.problem7;

/**
 * Created by Xavi on 3/7/2017.
 */
public class Complex {
    private double real, imaginary;

    private Complex() {
        this.real = 0;
        this.imaginary = 0;
    }

    private Complex(double real) {
        this.real = real;
        this.imaginary = 0;
    }

    public Complex(double real, double imaginary) {
        this.real = real;
        this.imaginary = imaginary;
    }

    public void add(Complex c) {
        real+=c.getReal();
        imaginary+=c.getImaginary();
    }

    public void minus(Complex c) {
        real-=c.getReal();
        imaginary-=c.getImaginary();
    }

    public void multiply(Complex c) {
        real = (real*c.real)-(imaginary*c.imaginary);
        imaginary = (real*c.imaginary)+(c.real*imaginary);
    }

    public static Complex add(Complex c1, Complex c2) {
        return new Complex(c1.getReal()+c2.getReal(), c1.getImaginary()+c2.getImaginary());
    }

    public static Complex minus(Complex c1, Complex c2) {
        return new Complex(c1.getReal()-c2.getReal(), c1.getImaginary()-c2.getImaginary());
    }

    public static Complex multiply(Complex c1, Complex c2) {
        return new Complex((c1.getReal()*c2.getReal())-(c1.getImaginary()*c2.getImaginary()), ((c1.getReal()*c2.getImaginary())-(c1.getImaginary()*c2.getReal())));
    }

    public double getReal() {
        return real;
    }

    public void setReal(double real) {
        this.real = real;
    }

    public double getImaginary() {
        return imaginary;
    }

    public void setImaginary(double imaginary) {
        this.imaginary = imaginary;
    }

    @Override
    public String toString() {
        return real+ " + " + imaginary+"i";
    }

    @Override
    public boolean equals(Object obj) {
        if (obj instanceof Complex) {
            Complex complex = (Complex)obj;
            return (real == complex.getReal() && imaginary == complex.getImaginary());
        } else return false;
    }
}
