import sys

def get_drops(eggs, floors):
    if (floors==0):
        print("%s eggs and 0 floors: 0 minimum drops" % (eggs))
    else:
        eggDrops = [[0 for x in range(floors+1)] for y in range(eggs+1)]

        # base case 1; if no drops if there are zero floors
        # if floors = 1, then one drop is needed
        for i in range(1, eggs+1):
            eggDrops[i][0] = 0
            eggDrops[i][1] = 1

        # base case 2; if there is only one egg, then number of drops = floors
        for i in range(1, floors+1):
            eggDrops[1][i] = i

        for i in range(2, eggs+1):
            for j in range(2, floors+1):
                eggDrops[i][j] = sys.maxsize
                tempResult = 0
                for k in range(1, j+1):
                    tempResult = 1 + max(eggDrops[i-1][k-1], eggDrops[i][j-k])
                    eggDrops[i][j] = min(tempResult, eggDrops[i][j])

        print("%s eggs and %s floors: %s minimum drops" % (eggs, floors, eggDrops[eggs][floors]))

get_drops(1, 0)
get_drops(1, 100)
get_drops(2, 71)
