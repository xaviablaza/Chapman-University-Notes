'''
Created on 2 de oct. de 2015

@author: Xavi
'''
print "Welcome to Xavi's DNASeq Complement Printer!"
seq_orig = raw_input("Enter your DNA Sequence (e.g. ACTGAGTCTTA): ")
seq_comp = ""
adenine = 0.0
thymine = 0.0
guanine = 0.0
cytosine = 0.0
total_valid = 0.0

for nucleobase in seq_orig:
    if nucleobase == "A":
        nucleobase = "T"
        thymine += 1
    elif nucleobase == "T":
        nucleobase = "A"
        adenine += 1
    elif nucleobase == "C":
        nucleobase = "G"
        guanine += 1
    elif nucleobase == "G":
        nucleobase = "C"
        cytosine += 1
    else:
        nucleobase = "N"
        total_valid-=1
    seq_comp += nucleobase
    total_valid += 1

print "Sequence: " + seq_orig
print "The complement is: " + seq_comp
print "Adenine: " + str(adenine / total_valid * 100) + "% " + "Thymine: " + str(thymine / total_valid * 100) + "% " + "Guanine: " + str(guanine / total_valid * 100) + "% " + "Cytosine: " + str(cytosine / total_valid * 100) + "%"