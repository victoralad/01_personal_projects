#!/usr/bin/env python
# ----------
# User Instructions:
# 
# Define a function, search() that returns a list
# in the form of [optimal path length, row, col]. For
# the grid shown below, your function should output
# [11, 4, 5].
#
# If there is no valid path from the start point
# to the goal, your function should return the string
# 'fail'
# ----------

# Grid format:
#   0 = Navigable space
#   1 = Occupied space

grid = [[0, 0, 1, 0, 0, 0],
        [0, 0, 1, 0, 0, 0],
        [0, 0, 0, 0, 1, 0],
        [0, 0, 1, 1, 1, 0],
        [0, 0, 0, 0, 1, 0]]
init = [0, 0]
goal = [len(grid)-1, len(grid[0])-1]
cost = 1

delta = [[-1, 0], # go up
         [ 0,-1], # go left
         [ 1, 0], # go down
         [ 0, 1]] # go right

delta_name = ['^', '<', 'v', '>']

def search(grid,init,goal,cost):
    # ----------------------------------------
    # insert code here
    # ----------------------------------------

    coord = init
    OPEN = []
    CLOSED = []
    count = 0
    gV = [0]
    LIST = gV + coord
    OPEN.append(LIST)
    CLOSED.append(LIST)

    while coord is not goal:    #keep searching until current state is the goal
        halfOp = OPEN
        halfOp = zip(*halfOp)
        z = list(halfOp[0]).index(min(list(halfOp[0])))
        coord = [OPEN[z][1], OPEN[z][2]]
        
        gV[0] +=1
        for i in range(len(delta)):
            print "grid"
            successor = [coord[j]+delta[i][j] for j in range(len(delta[i]))]          
            
            if 0<=successor[0]<=4 and 0<=successor[1]<=5 and grid[successor[0]][successor[1]] == 0:
                successor1 = gV + successor
                k = 0
                while k is not len(CLOSED): 
                    if successor1[1] == CLOSED[k][1] and successor1[2] == CLOSED[k][2]:
                        break;
                    k +=1
                if k==len(CLOSED):
                    OPEN.append(successor1)
        CLOSED.append(OPEN[0])
        OPEN.pop(0)
        if len(OPEN) == 0:
            break
        
        count +=1
        if count == 20:
            break
            
    return CLOSED[len(CLOSED)-1]

search(grid, init, goal, cost)

#print search(grid, init, goal, cost)