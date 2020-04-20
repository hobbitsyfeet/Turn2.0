from game import tiles #character gains info about specific tiles that exist in map
from game import inventory

class character():
    def __init__(self, name=""):
        self.name = name
        self.uuid = None

        self.abilities = {}

        self.tiles = tiles.tiles()
        self.inventory = inventory.inventory()
        
        self.define_health(20,20)
        self.define_stamina(5,5)
        self.define_mana(0,0)

        self.weight = 10
        
        self.stealth = 1
        self.experience = 0

        self.x = 10
        self.y = 10

        self.symbol = 'Ü'
        self.colour = (255,255,255)
        

    #CHARACTER STATS
    def define_health(self, current, maximum):
        self.health = current
        self.max_health = maximum
    
    def define_stamina(self, current, maximum):
        self.stamina = current
        self.max_stamina = maximum
    
    def define_mana(self, current, maximum):
        self.mana = current
        self.max_mana = maximum
    


    #CHARACTER ACTIONS
    
    def display(self):
        ##string = "\033["+str(self.y+self.tiles.offset_y)+";"+str(self.x+self.tiles.offset_x)+"H" #the added values for offsets
        self.tiles.update_tile(self.x, self.y, self.symbol, self.colour)

    def pickup(self, item):
        self.inventory.add(item)

    def drop(self, item):
        return self.inventory.remove(item)

    def load_character(self, filename):
        pass