from game import actions
from game import character
from game import maps
from game import feed
from game import items
from game import utilites

class manager():
    def __init__(self):
        
        #NOTE This structure allows direct access given a name, as well as iteration capabilities for Turns.
        self.units = {} #{Player1:[player],"Ghouls":[Ghoul1, Ghoul2]}


        self.world = None

        self.items = items.item_spawn()
        self.game_units = character.unit_spawn()
        
        self.events = None #FUTURE
        self.states = None #FUTURE
        self.iofeed = feed.feed()


        self.worlds_path = "C:/Users/legom/Documents/GitHub/Turn2.0/saves/maps"



    def new_feed(self):
        self.iofeed.create_feed()

    def new_character(self, name):
        self.units[name] = [character.character(name)]
        self.units[name][0].inventory.feed = self.iofeed #set inventory feed

        spawner = items.item_spawn()

        self.units[name][0].inventory.add(spawner.spawn(0)) #add a stick

    def load_units(self, filenames):
        


        #self.units[name].inventory = self.iofeed #set inventory feed
        #self.units[name].inventory = self.iofeed #set inventory feed
        pass

    def save_state(self, filename):
        pass
    
    def spawn_unit(self, unit_id, location):
        new_unit = self.game_units.spawn(unit_id, location[0], location[1])

        if new_unit.name in self.units:
            self.units[new_unit.name].append(new_unit)
        self.units[new_unit.name] = [new_unit]
        #TODO: spawn unit with items (GIVEN CHANCE!)

    
    def action(self, player, action):
        actions.action_handler(self, player, action)

        for characters in self.units:
            unit = self.units[characters]
            for char in unit:
                char.display()

    def load_world(self, filename):
        self.world = maps.tilemap()
        self.world.load_map(filename + ".world")
        self.world.load_portals(filename + ".portals")
        

        #move feed if it overlaps 1) Push right if map overlaps 2) push down when height is not overlapped
        if self.world.width > self.iofeed.top_left[0] and self.world.height > self.iofeed.top_left[1]:
            self.iofeed.top_left = (self.world.width+1,self.iofeed.top_left[1])
        elif self.world.width < self.iofeed.top_left[0] and self.world.height > self.iofeed.top_left[1]:
            self.iofeed.top_left = (self.iofeed.top_left[1],self.world.height+1)

    def save_game(self, filename):
        pass
