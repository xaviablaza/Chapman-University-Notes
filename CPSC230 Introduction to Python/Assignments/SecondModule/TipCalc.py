'''
Created on 2 de oct. de 2015

@author: Xavi
'''
print "Welcome to Xavi's Tip Calculator!"

price = 0
score = 0
tip = 0

while True:
    
    # Ask for the price of the meal (can be float)
    price = raw_input("Enter the total price of your meal: ")
    
    try:
        # Try converting to a float
        price = float(price)
        break
        
    # If it fails, ask for price again
    except ValueError:
        print "Error! " + price + " could not be converted to a float!"
        continue
    
while True:

    # Ask for their meal score (int only)
    score = raw_input("Enter a meal score from 1 to 10 (1 lowest, 10 highest): ")

    try:
        # Try converting to an int
        score = int(score)
        break
        
    # If it fails, ask for score again
    except ValueError:
        print "Error! " + score + " could not be converted to an int!"
        continue

if (1 <= score <= 3):
    tip = price*0.1
elif (4 <= score <= 5):
    tip = price*0.13
elif (6 <= score <= 7):
    tip = price*0.15
elif (8 <= score <= 9):
    tip = price*0.2
elif (score >= 10):
    tip = price*0.25
    
print "You should tip $" + str(tip)