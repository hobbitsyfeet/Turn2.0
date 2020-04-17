import numpy as np
import sys, os

from game import tiles


class tilemap():
    """
    A map consists of a Numpy Array of integers. This array contains the ID's of tiles to be displayed. 
    Tiles are loaded from file into a dictionary of id's to names, ascii symbol and colours.

    A tilemap is used as reference to the units so they can navigate the world. 
    The tilemap is dynamic, such that when objects or units exist on a specific tile, display is overlayed, but effects still exist.
    """

    def __init__(self):
        self.name =""

        self.map_tiles = tiles.tiles()
        self.map_tiles.load_tiles(self.map_tiles.file_loc)
        self.width = 0
        self.height = 0
        self.world = None

        self.portals = {} #portal name/id, (x,y)from, target_mapname, (x,y) target location

    def display_map(self):
        """
        Takes the unit 
        """
        sys.stdout.write("\x1B[2J\x1B[H")
        for y in range(self.height):
            #print(y, end=" ")
            #print(self.world[y])
            for x in range(self.width):
                #print(self.world[y][x])
                self.map_tiles.display_tile(self.world[y][x])
            sys.stdout.write("\n")

    def load_map(self, file):
        """
        """
        self.name = os.path.splitext(file)[0]
        #clear previous map
        #sys.stdout.write("\x1B[2J\x1B[H")

        file = open(file,'r')
        lines = [line.rstrip() for line in file]
        
        self.height = len(lines)

        lengths = []
        for line in lines:
            temp = line.split('\t')
            lengths.append(len(temp))
        #print(max(lengths))
        self.width = max(lengths)

        #print(self.width, self.height)
        self.world = np.full((self.height, self.width), -1)
        
        i = 0
        for line in lines:
            j = 0
            line = line.split('\t')
            #print(line)
            for symbol in line:
                #print(i,j)
                if symbol == ' ' or symbol == '':
                    symbol = -1
                #print(symbol)
                self.world[i][j] = int(symbol)
                #print(self.world)
                
                j += 1

            i += 1

    def load_portals(self, filename):
        """

        """
        file = open(filename, 'r')
        next(file) #skip first line. This is used for user

        lines = [line.rstrip() for line in file]
        for line in lines:

            #get rid of repeating tabs
            while "\t\t" in line:
                line = line.replace("\t\t", "\t")

            #split by single tabs into a list
            line = line.split('\t')
            print(line)
            #should be formatted id: ("name","symbol",r,g,b)
            self.portals[(int(line[0]), int(line[1]))] = {"portal_name":str(line[2]),
                                                          "target_world":str(line[3]),
                                                          "target_loc":(int(line[4]), int(line[5]))
                                                }


    def update_tile(self, x, y):
        tile = self.map_tiles.get_tile(self.world[y][x])
        colour = (tile["red"],tile["green"],tile["blue"])
        self.map_tiles.update_tile(x, y, tile["symbol"], colour)

    def get_tile(self, x, y):
        tile = self.map_tiles.get_tile(self.world[y][x])
        return tile

if __name__ == "__main__":


    world = tilemap()
    world.load_map("C:/Users/legom/Documents/GitHub/Turn2.0/saves/maps/Starting")
    #print(world.grid)
