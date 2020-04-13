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
    
    def action(self, action):
        actions.action_handler(self, action)

    def load_world(self, filename):
        self.world = maps.tilemap()
        self.world.load_map(filename)

    def save_game(self, filename):
        pass
