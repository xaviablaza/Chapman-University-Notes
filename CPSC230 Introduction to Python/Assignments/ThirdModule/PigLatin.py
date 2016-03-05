'''
Created on 22 de oct. de 2015

@author: Xavi
'''
# Declare vowels
VOWELS = ["a", "e", "i", "o", "u"]

# Declare line and word counters
line_count = 0
word_count = 0

def translateToPigLatin(word):
    # Get first letter
    letter = word[0]
    
    # Declare flag variable
    isVowel = False
    
    # Check if the letter is a vowel
    for vowel in VOWELS:
        if vowel == letter:
            isVowel = True
            break
        
    if isVowel:
        # Add way to end
        return word + "way"
    else:
        # Print word without first letter + first letter + "ay"
        return word[1:] + word[0] + "ay"
    
def printLineAndWordCounts():
    print "Translation finished and written to: pig_output.txt"
    print "A total of " + str(line_count) + " lines were translated successfully."
    print "A total of " + str(word_count) + " words were translated successfully."


while True:
    # Ask for path to file to be translated
    path = raw_input("Enter the path of a text file: ")
    
    try:
        # Open input file (file to be translated)
        input_file = open(path, "r")
    except IOError:
        print path + " does not exist!"
        continue
    
    # Create output file
    output_file = open("pig_output.txt", "w")
    
    output_lines = ""
    # Iterate through input file
    for line in input_file:
        line_count+=1
        
        # Handle blank line
        if line == "\n":
            output_lines += "\n"
            continue
        
        # Strip newline character and other whitespace characters
        line = line.strip(" \t\n\r")    
        # you need to assign the line :/
        
        # Create list of words on line via split
        words = line.split(" ")
        
        # Declare new empty translated_line
        translated_line = ""
        translated_word = ""
            
        # Translate each word
        for word in words:
            translated_word = translateToPigLatin(word)
            word_count+=1
            translated_line+=translated_word + " "
        
        output_lines += translated_line[:-1]+"\n"
    
    output_file.write(output_lines[:-1])
    input_file.close()
    output_file.close()
    printLineAndWordCounts()
    break