from game import tiles #character gains info about specific tiles that exist in map

class character():
    def __init__(self):
        self.tiles = tiles.tiles()

        self.define_health(100,100)
        self.define_stamina(100,100)
        self.weight = 10

        self.x = 0
        self.y = 0

        self.symbol = '0'
        self.colour = (255,255,255)
        

    #CHARACTER STATS
    def define_health(self, maximum, current):
        self.health = current
        self.max_health = maximum
    
    def define_stamina(self, maximum, current):
        self.stamina = current
        self.max_stamina = maximum

    #CHARACTER ACTIONS
    
    def display(self):
        ##string = "\033["+str(self.y+self.tiles.offset_y)+";"+str(self.x+self.tiles.offset_x)+"H" #the added values for offsets
        self.tiles.update_tile(self.x, self.y, self.symbol, self.colour)
