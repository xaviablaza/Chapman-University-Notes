'''
Created on 17 Sept 2015

@author: Xavi
'''
import math
print "Welcome to Xavi's Quadratic Roots Calculator!"

result1 = 0
result2 = 0
results = ""

while True:
    a = raw_input("Enter coefficient a: ")
    try:
        a = float(a)
    except ValueError:
        print "Error! " + a + " could not be converted to a float!"
        continue
    
    b = raw_input("Enter coefficient b: ")
    try:
        b = float(b)
    except ValueError:
        print "Error! " + b + " could not be converted to a float!"
        continue
    
    c = raw_input("Enter coefficient c: ")
    try:
        c = float(c)
    except ValueError:
        print "Error! " + c + " could not be converted to a float!"
        continue
    
    # Calculate determinant and denominator
    determinant = (b**2)-(4*a*c)
    denominator = 2*a
    
    # Error checks
    if denominator == 0:
        print "Error! 2a cannot be 0."
        continue
    
    if determinant >= 0:
        # Calculate first result
        result1 = ((-b+math.sqrt(determinant)))/(denominator)
        
        # Calculate second result
        result2 = ((-b-math.sqrt(determinant)))/(denominator)
        
        # Print Results
        results = "Roots: " + str(result1) + ", " + str(result2)
    else:
        # Need to determine whether or not to put a plus or minus before imaginary coefficient
        real_coef = -b/denominator
        imag_coef = determinant/denominator
        if imag_coef < 0:
            results = "Roots: " + str(real_coef) + str(imag_coef) + "i, "
            results += str(real_coef) + "+" + str(-imag_coef) + "i"
        else:
            results = "Roots: " + str(real_coef) + "+" + str(imag_coef) + "i, "
            results += str(real_coef) + "-" + str(imag_coef) + "i"
    break;

print results