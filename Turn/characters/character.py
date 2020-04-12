class character():
    def __init__(self):
        self.define_health(100,100)
        self.define_stamina(100,100)
        self.weight = 10
        #health

    #CHARACTER STATS
    def define_health(self, maximum, current):
        self.health = current
        self.max_health = maximum
    
    def define_stamina(self, maximum, current):
        self.stamina = current
        self.max_stamina = maximum

    #CHARACTER ACTIONS
    def move(self, direction, distance):
        pass

    def action(self, action_func):
        action_func()