'''
Created on 17 Sept 2015

@author: Xavi
'''
import math
print "Welcome to Xavi's Quadratic Roots Calculator!"

result1 = 0
result2 = 0

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
    else:
        print "Error! Cannot get the square root of a negative number."
        continue
    
    break;

print "Roots: " + str(result1) + ", " + str(result2)