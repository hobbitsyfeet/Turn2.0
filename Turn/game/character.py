from game import tiles #character gains info about specific tiles that exist in map
from game import inventory
from game import utilites

class character():
    def __init__(self, name=""):
        self.name = name
        self.id = None

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

    def save_character(self, Temp=True):
        '''
        Saves a character with a filename. Temp is used for AI characters while saving the game. This will save inside of a 
        Different folder from the user.
        '''
        save_string = ""
        save_file = open((self.name+"_"+self.id)) #Opens the name and ID of the character

        save_string += (self.name + '\t')
        save_string += (self.id + '\t')
        save_string += (self.symbol + '\t')
        

    def define_unit(self, unit_dict):
        self.id = unit_dict["id"]
        self.name = unit_dict["name"]
        self.symbol = unit_dict["symbol"]
        self.colour = (unit_dict["red"],unit_dict["green"],unit_dict["blue"])
        self.x = unit_dict["x"]
        self.y = unit_dict["y"]
        self.define_health(unit_dict["health"], unit_dict["max_health"])
        self.define_stamina(unit_dict["stamina"], unit_dict["max_stamina"])
        self.define_mana(unit_dict["mana"], unit_dict["max_mana"])
        self.stealth = unit_dict["stealth"]
        self.experience = unit_dict["experience"]
        self.weight = unit_dict["weight"]
        self.inventory = unit_dict["inventory"]

class unit_spawn():
    def __init__(self):
        self.unit_dict = {} #contains all info of items by ID
        self.rarity_dict = {"common":set(), "uncommon":set(), "rare":set(), "very rare":set()} #contains all items by sets of rarity

        self.dir = "./Turn/game/assets/"
        self.file = "units.txt"
        self.file_path = (self.dir+self.file)

        self.load_units(self.file_path)

    def load_units(self, filename):
        """
        loads items from the database
        """
        lines = utilites.parse_input(filename)
        for line in lines:
            try:
                self.unit_dict[int(line[0])] = {"id":int(line[0]),
                                                "name":str(line[1]),
                                                "symbol":str(line[2]),
                                                "red":int(line[3]),
                                                "green":int(line[4]),
                                                "blue":int(line[5]),
                                                "x":int(line[6]),
                                                "y":int(line[7]),
                                                "health":float(line[8]),
                                                "max_health":float(line[9]),
                                                "stamina":float(line[10]),
                                                "max_stamina":float(line[11]),
                                                "mana":float(line[12]),
                                                "max_mana":float(line[13]),
                                                "stealth":int(line[14]),
                                                "experience":int(line[15]),
                                                "weight":int(line[16]),
                                                "inventory":str(line[17]),
                                                "chance":float(line[18])
                                                }
            except:
                print("Error loading:", line)

    def spawn(self, unit_id, x, y):
        
        spawn_unit = character()

        spawn_unit.define_unit(self.unit_dict[unit_id])
        spawn_unit.x = x
        spawn_unit.y = y
        return spawn_unit

    

    def spawn_random(self, unit_id, spawnable_ids):
        """
        Creates a subset dictionary of spawnable items.
        Within this spawnable set, it generates a random value. 
        This value further subsets the items based on their "chance" value.
        """
        spawnable_dict = {}
        for unit_id in spawnable_ids:
            spawnable_dict[unit_id] = self.unit_dict[unit_id]

