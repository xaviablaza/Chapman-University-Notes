import math

def dot_prod(A,B):
    idx = 0
    tot = 0
    while idx<len(A):
        #do math
        tot+=(float(A[idx])*float(B[idx]))
        idx+=1
    return tot

def norm(vector):
    n = math.sqrt(dot_prod(vector,vector))
    return n

def sim_score(vc1,vc2):
    score = dot_prod(vc1,vc2)/(norm(vc1)*norm(vc2))
    return score

def validate_float(message):
    while True:
        val = raw_input(message)
        try:
            float_val = float(val)
        except ValueError:
            print "Error! " + val + " could not be converted to a float!"
            continue
        return float_val

# Read in the data from the iris data set as a list of lists
file = open("iris.csv", "r")
irises = []
for line in file:
    line = line.strip('\n')
    iris = line.split(",")
    irises.append(iris)

# Prompt the user for the sepal length, sepal width, petal length,
# and petal width of an example iris that they would like to predict the type of
sepal_length = validate_float("Sepal Length: ")
sepal_width = validate_float("Sepal Width: ")
petal_length = validate_float("Petal Length: ")
petal_width = validate_float("Petal Width: ")

# Construct a tuple out of the user's data
user_iris = tuple([sepal_length, sepal_width, petal_length, petal_width])

# In a loop, compare user iris with each iris row in the included data set using the Cosine
# Similarity metric. Keep track of the highest similarity value and the type associated with it.
row = 0
best_score = 0
iris_type = ""
while (row<len(irises)):
    v1 = irises[row]
    score = sim_score(v1[:-1], user_iris)
    if (score > best_score):
        best_score = score
        iris_type = v1[4]
    row+=1

print "The predicted type is " + iris_type
