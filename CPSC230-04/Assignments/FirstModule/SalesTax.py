'''
Created on 17 Sept 2015

@author: Xavi
'''
print "Welcome to Xavi's SalesTax Calculator!"

price_float = 0
rate_dec = 0

while True:
    # Ask for input about the price
    price = raw_input("Enter the price of your item: ")
    
    # Error checking
    try:
        # Try converting to a float
        price_float = float(price)
        break
        
    # If it fails, ask for price again
    except ValueError:
        print "Error! " + price + " could not be converted to a float!"
        continue

while True:
    # Ask for input about the rate
    rate = raw_input("Enter the tax rate as a percent (e.g. 10.01 means 10.01%): ")
    
    # Error checking
    try:
        # Convert the rate into a float
        rate_float = float(price)
                
        # Convert the rate from percent to decimal
        rate_dec = rate_float*0.01
        break
        
    # If it fails, ask for price again
    except ValueError:
        print "Error! " + rate + " could not be converted to a float!"
        continue

# Add on tax to original price
total = price_float + ((price_float)*(rate_dec))

# Print the result
print total