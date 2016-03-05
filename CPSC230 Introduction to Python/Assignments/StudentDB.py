# Create your student class
class Student:
    def __init__(self, first_name, last_name, age, gpa):
        self.first_name = first_name
        self.last_name = last_name
        self.age = age
        self.gpa = gpa
    def __str__(self):
        return "{},{},{},{}".format(self.first_name, self.last_name, self.age, self.gpa)
    def update_gpa(self, gpa):
        self.gpa = gpa

def validate_float(message):
    while True:
        val = raw_input(message)
        try:
            float_val = float(val)
            if (float_val > 4.0):
                print "GPA cannot be greater than 4.0. Try again."
                continue
            elif (float_val < 0):
                print "GPA cannot be negative. Try again."
                continue
        except ValueError:
            print "Error! " + val + " could not be converted to a float!"
            continue
        return float_val

def validate_int(message):
    while True:
        val = raw_input(message)
        try:
            int_val = int(val)
        except ValueError:
            print "Error! " + val + " could not be converted to a int!"
            continue
        return int_val

def addStudent(students):
    first_name = raw_input("First name: ")
    last_name = raw_input("Last name: ")
    age = validate_int("Age: ")
    gpa = validate_float("GPA: ")
    student = Student(first_name, last_name, age, gpa)
    students.append(student)

def editStudentGpa(students):
    first_name = raw_input("First name: ")
    last_name = raw_input("Last name: ")
    gpa = validate_float("New GPA: ")
    found = False
    for student in students:
        if (student.first_name == first_name and student.last_name == last_name):
            student.gpa = gpa
            found = True
            break
    if found == False:
        print "Oh no! Student with that name not found!"

def printAverageGpa(students):
    count = 0
    gpa = 0
    for student in students:
        count+=1
        gpa+=float(student.gpa)
    avg_gpa = gpa/count
    print "The average GPA is " + str(avg_gpa)

def printAllStudentInfo(students):
    print "Students:"
    print
    for student in students:
        print "{} {} is a {} year old with a {} GPA".format(student.first_name, student.last_name, student.age, student.gpa)

fileExists = False
students = []
try:
    # Attempt to read already existing students.db
    db_file = open("students.db", "r")
    for line in db_file:
        line = line.strip("\n")
        s = line.split(',')
        students.append(Student(s[0],s[1],s[2],s[3]))
    fileExists = True
    db_file.close()
except IOError:
    # Doesn't exist? Create a new file
    print "students.db does not exist! Creating new file..."
    db_file = open("students.db", "w")

if (fileExists):
    print "1. Add a student"
    print "2. Edit a student's GPA"
    print "3. Print the average GPA"
    print "4. Print all students' info"
    while True:
        option = raw_input("Enter your choice: ")
        if (option == "1"):
            addStudent(students)
        elif (option == "2"):
            editStudentGpa(students)
        elif (option == "3"):
            printAverageGpa(students)
            break
        elif (option == "4"):
            printAllStudentInfo(students)
            break
        else:
            print option + " is not an option! Try again."
            continue
        db_file = open("students.db", "w")
        db_file.writelines(str(student)+"\n" for student in students)
        db_file.close()
        break
else:
    print "1. Add a student"
    while True:
        option = raw_input("Enter your choice: ")
        if (option == "1"):
            addStudent(students)
            db_file.write(str(students[0])+"\n")
            db_file.close()
            break
        else:
            print option + " is not an option! Try again."
            continue
