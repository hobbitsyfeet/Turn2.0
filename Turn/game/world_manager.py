from game import actions
from game import character
from game import maps
from game import feed

class manager():
    def __init__(self):
        self.units = {}
        self.world = None
        
        self.events = None #FUTURE
        self.states = None #FUTURE
        self.iofeed = feed.feed()

        self.worlds_path = "C:/Users/legom/Documents/GitHub/Turn2.0/saves/maps"



    def new_feed(self):
        self.iofeed.create_feed()

    def new_character(self, name):
        self.units[name] = character.character()

    def load_units(self, filenames):
        pass

    def save_state(self, filename):
        pass
    
    def spawn_unit(self, filename, location):
        pass
    
    def action(self, player, action):
        actions.action_handler(self, player ,action)

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
