import numpy as np
from tiles import tiles


class tilemap():
    """
    A map consists of a Numpy Array of integers. This array contains the ID's of tiles to be displayed. 
    Tiles are loaded from file into a dictionary of id's to names, ascii symbol and colours.

    A tilemap is used as reference to the units so they can navigate the world. 
    The tilemap is dynamic, such that when objects or units exist on a specific tile, display is overlayed, but effects still exist.
    """

    def __init__(self):
        self.map_tiles = tiles()
        self.map_tiles.load_tiles(self.map_tiles.file_loc)
    def display_map(self):
        """
        Takes the unit 
        """
        pass

    def load_map(self, file):
        #clear previous map

        file = open(file,'r')
        lines = [line.rstrip() for line in file]
        height = len(lines)
        width = len(lines[0].split(' '))
        print("Width", width)
        print("Height", height)
        self.world = np.zeros((width, height))
        print(self.world.shape)
        #print(self.world)

        i = 0

        for line in lines:
            j = 0
            line = line.split(' ')
            print(i,j,end="")
            for symbol in line:     
                
                self.world[j][i] = int(symbol)
                self.map_tiles.display_tile(int(symbol))
                print("  ",end='')
                j +=1
            
            i+=1
            print("\n")
        

            

            

if __name__ == "__main__":


    world = tilemap()
    world.load_map("C:/Users/legom/Documents/GitHub/Turn2.0/saves/maps/Starting.world")
    #print(world.grid)
