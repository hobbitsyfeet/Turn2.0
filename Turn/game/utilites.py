import numpy as np
from os import listdir
from os.path import isfile, join

    #Helper Functions
def parse_input(filename, first_line=False):
    file = open(filename, 'r')
    
    if first_line is False:
        next(file) #skip first line. This is used for user

    parsed_lines = []

    lines = [line.rstrip() for line in file]
    for line in lines:

        #get rid of repeating tabs
        while "\t\t" in line:
            line = line.replace("\t\t", "\t")

        #split by single tabs into a list
        line = line.split('\t')

    
        parsed_lines.append(line)
    return parsed_lines

def select_files(folder, extension=None):
    print("Select a file:")
    onlyfiles = [f for f in listdir(folder) if isfile(join(folder, f))]

    if extension != None:
        file_num = 0
        for file in onlyfiles:
            if file[:-3] == extension:
                print(file_num,")", file[:-4])
            else:
                del file
            file_num += 1
    else:
        file_num = 0
        for file in onlyfiles:
            print(file_num,")", file[:-4])
            file_num += 1
    
    selected = input()

    return onlyfiles[int(selected)]

class Node:
    def __init__(self, value, point):
        self.value = value #cost
        self.point = point #location
        self.parent = None #last_location?
        self.H = 0 #score
        self.G = 0 #score
    def move_cost(self, other):
        return 0 if self.value == '.' else self.value
        
def children(point,grid):
    x,y = point.point
    #print(x,y,end = "-> ")
    links = [grid[d[0]][d[1]] for d in [(x-1, y),(x,y - 1),(x,y + 1),(x+1,y)]]

    for link in links:
        if link == 0:
            links.remove(0) #takes care of any residual nodes not assigned in next_move
    return [link for link in links if link.value != 999]

def manhattan(point,point2):
    return abs(point.point[0] - point2.point[0]) + abs(point.point[1]-point2.point[0])

def aStar(start, goal, grid):
    #The open and closed sets
    openset = set()
    closedset = set()
    #Current point is the starting point
    current = start
    #Add the starting point to the open set
    openset.add(current)
    #While the open set is not empty
    while openset:
        #Find the item in the open set with the lowest G + H score
        #print(openset)
        current = min(openset, key=lambda o:o.G + o.H)

        #If it is the item we want, retrace the path and return it
        if current == goal:
            path = []
            while current.parent:
                path.append(current)
                current = current.parent
            path.append(current)
            return path[::-1]
        #Remove the item from the open set
        openset.remove(current)
        #Add it to the closed set
        closedset.add(current)
        #Loop through the node's children/siblings
        for node in children(current,grid):
            #print(node)
            #If it is already in the closed set, skip it
            if node in closedset:
                continue
            #Otherwise if it is already in the open set
            if node in openset:
                #Check if we beat the G score 
                new_g = current.G + current.move_cost(node)
                if node.G > new_g:
                    #If so, update the node to have a new parent
                    node.G = new_g
                    node.parent = current
            else:
                #If it isn't in the open set, calculate the G and H score for the node
                node.G = current.G + current.move_cost(node)
                node.H = manhattan(node, goal)
                #Set the parent to our current item
                node.parent = current
                #Add it to the set
                openset.add(node)
    #Throw an exception if there is no path
    raise ValueError('No Path Found')

def next_move(unit_location, goal_location, grid):
    temp_grid = [[0.0] * grid.width for i in range(grid.width)]

    #Convert all the points to instances of Node
    for y in range(grid.height):
            for x in range(grid.width):
                temp_grid[x][y] = Node(grid.get_tile(x,y)["cost"], (x,y))
                #print(temp_grid)
                #print(temp_grid[x][y].value,end='|')

    #Get the path
    path = aStar(temp_grid[unit_location[0]][unit_location[1]], temp_grid[goal_location[0]][goal_location[1]], temp_grid)

    return path
