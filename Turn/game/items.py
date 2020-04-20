RARITY_COMMON = 0
RARITY_UNCOMMON = 1
RARITY_RARE = 2
RARITY_VERY_RARE = 3

import random
import time
from game import utilites

from game import aciify

class item():
    def __init__(self, item_dict):
        self.id = item_dict["id"]
        self.name = item_dict["name"]

        self.damage = item_dict["damage"]
        self.range = item_dict["range"]

        self.durability = item_dict["durability"]
        self.cost = item_dict["cost"]

        self.max_stack = item_dict["max_stack"]
        self.stack = 1
        self.weight = item_dict["weight"]

        self.chance = item_dict["chance"]

        self.ability = item_dict["ability"]
        self.modifiers = item_dict["modifiers"]

        self.description = item_dict["description"]


    def use(self):
        pass
    
    def view(self):
        directory = "./Turn/game/assets/images/"
        file = self.name + ".png"
        file_path = directory + file
        aciify.runner(file_path)

class item_spawn():
    def __init__(self):
        self.item_dict = {} #contains all info of items by ID
        self.rarity_dict = {"common":set(), "uncommon":set(), "rare":set(), "very rare":set()} #contains all items by sets of rarity

        self.dir = "./Turn/game/assets/"
        self.file = "items.txt"
        self.file_path = (self.dir+self.file)

        self.load_items(self.file_path)

    def load_items(self, filename):
        """
        loads items from the database
        """
        lines = utilites.parse_input(filename)

        for line in lines:
            try:
                self.item_dict[int(line[0])] = {"id":int(line[0]),
                                                "name":str(line[1]),
                                                "damage":float(line[2]),
                                                "range":int(line[3]),
                                                "durability":int(line[4]),
                                                "cost":float(line[5]),
                                                "max_stack":int(line[6]),
                                                "equip_location":str(line[7]),
                                                "weight":float(line[8]),
                                                "chance":float(line[9]),
                                                "ability":str(line[10]),
                                                "effect_amount":float(line[11]),
                                                "modifiers":str(line[12]),
                                                "description":str(line[13])
                                                }
            except:
                print("Error loading:", line)

    def spawn(self, item_id, amount=1):
        spawn_item = item(self.item_dict[item_id])
        spawn_item.stack = amount
        return spawn_item

    

    def spawn_random(self, item_id, spawnable_ids):
        """
        Creates a subset dictionary of spawnable items.
        Within this spawnable set, it generates a random value. 
        This value further subsets the items based on their "chance" value.
        """
        spawnable_dict = {}
        for item_id in spawnable_ids:
            spawnable_dict[item_id] = self.item_dict[item_id]

