import sys 
sys.path.append('...')
import os
from colors import color
from colours import strgb

import time



class tiles():
    def __init__(self):
        self.dir = "./Turn/map/"
        self.file = "tiles.txt"
        self.file_loc = (self.dir+self.file)

        self.tile_dictionary = {}

    def load_tiles(self, filename):
        """
        Loads tiles to be defined in a dictionary and used later on.
        """
        file = open(filename, 'r')
        next(file) #skip first line. This is used for user

        lines = [line.rstrip() for line in file]
        #print(lines)

        for line in lines:

            #get rid of repeating tabs
            while "\t\t" in line:
                line = line.replace("\t\t", "\t") 
            #split by single tabs into a list
            line = line.split('\t')
            
            #should be formatted id: ("name","symbol",r,g,b)
            self.tile_dictionary[int(line[0])] = (str(line[1]), str(line[2]), int(line[3]), int(line[4]), int(line[5]))
            #print(self.tile_dictionary)


    def display_tile(self, tile_id):
        #print(self.tile_dictionary[tile_id])
        
        symbol = self.tile_dictionary[tile_id][1]
        #'''
        r = self.tile_dictionary[tile_id][2]
        g = self.tile_dictionary[tile_id][3]
        b = self.tile_dictionary[tile_id][4]
        #print(color(symbol, fg=strgb(r,g,b)),end="")
        #
        sys.stdout.write(color(symbol, fg=strgb(r,g,b)))
        #'''
        #sys.stdout.write(symbol)
        
    def update_tile(self, x ,y, symbol, colour):
        string = "\033["+str(y) +";"+str(x)+"H"
        print(string)
        sys.stdout.write(color(symbol, fg=strgb(colour[0],colour[1],colour[2])))
    
    def get_tile(self):
        """
        Gets information about a tile and returns it.
        """
        pass

    def display(self):
        pass

if __name__ == "__main__":

    print(os.getcwd())
    map_tiles = tiles()
    map_tiles.load_tiles(map_tiles.file_loc)

    for j in range(100):
        for i in range(33):
            map_tiles.display_tile(i)
    #sys.stdout.flush()

    map_tiles.update_tile(10,10,'&',(255,255,255))