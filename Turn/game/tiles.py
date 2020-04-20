import sys 
import os
from colors import color
from game import colours
from game import utilites


class tiles():
    def __init__(self):
        self.dir = "./Turn/game/assets/"
        self.file = "tiles.txt"
        self.file_path = (self.dir+self.file)

        self.offset_x = 1
        self.offset_y = 1
        #try:
            #self.load_tiles(file_loc)
        #except:
        #    print("Error: Could not load tiles from: " + self.file_loc)

        self.tile_dictionary = {}

    def load_tiles(self, filename):
        """
        Loads tiles to be defined in a dictionary and used later on.
        """
        lines = utilites.parse_input(filename)
        for line in lines:

            #should be formatted id: ("name","symbol",r,g,b)
            self.tile_dictionary[int(line[0])] = {"name":str(line[1]), #symbol
                                                  "symbol":str(line[2]), #name
                                                  "red":int(line[3]), #r
                                                  "green":int(line[4]), #g
                                                  "blue":int(line[5]), #b
                                                  "cost":float(line[6]) #stamina_cost
                                                 }

    def display_tile(self, tile_id):
        #print(self.tile_dictionary[tile_id])

        symbol = self.tile_dictionary[tile_id]["symbol"]
        #'''
        r = self.tile_dictionary[tile_id]["red"]
        g = self.tile_dictionary[tile_id]["green"]
        b = self.tile_dictionary[tile_id]["blue"]

        #print(color(symbol, fg=strgb(r,g,b)),end="")
        #
        sys.stdout.write(color(symbol, fg=colours.strgb((r,g,b))))
        #'''
        #sys.stdout.write(symbol)

    def update_tile(self, x, y, symbol, colour=None, bg_colour=None):
        """- Position the Cursor:
            \033[<L>;<C>H
                Or
            \033[<L>;<C>f
            puts the cursor at line L and column C.
            - Move the cursor up N lines:
            \033[<N>A
            - Move the cursor down N lines:
            \033[<N>B
            - Move the cursor forward N columns:
            \033[<N>C
            - Move the cursor backward N columns:
            \033[<N>D

            - Clear the screen, move to (0,0):
            \033[2J
            - Erase to end of line:
            \033[K
        """

        string = ("\033[" + str(y + self.offset_y) + ";" +
                  str(x + self.offset_x) + "H") #the added values for offsets

        sys.stdout.write(string)
        sys.stdout.write(color(symbol, fg=colours.strgb(colour), bg=colours.strgb(bg_colour) ) )

    def get_tile(self, tile_id):
        """
        Gets information about a tile and returns it.
        """
        return self.tile_dictionary[tile_id]

    def display(self):
        pass

if __name__ == "__main__":

    print(os.getcwd())
    map_tiles = tiles()
    map_tiles.load_tiles(map_tiles.file_path)


    for j in range(100):
        for i in range(33):
            map_tiles.display_tile(i)
    #sys.stdout.flush()


    map_tiles.update_tile(-9, 0, '&', (255, 255, 255))
