from game import tiles



class feed():
    def __init__(self):

        self.message = ""
        
        self.tiles = tiles.tiles()
        self.top_left = (0,0)
        self.current_line = 0
        self.width = 50
        self.height = 10

        self.bg = (220,220,220)
        self.cmd_bg = (80,150,150)
        self.border_bg = None
        self.text = (0,0,0)

    def create_feed(self):
        
        self.create_border()
        self.tiles.update_tile(self.top_left[0], self.top_left[1], '', self.text, self.bg)
        for y in range(self.height):
            if y == 0:
                self.tiles.update_tile(self.top_left[0], self.top_left[1] + y, ' '*self.width, self.text, self.cmd_bg)
            else:
                self.tiles.update_tile(self.top_left[0], self.top_left[1] + y, ' '*self.width, self.text, self.bg)
        self.tiles.update_tile(self.top_left[0], self.top_left[1], '', self.text, self.bg)

    def create_border(self):
        for y in range(-2,self.height):
            self.tiles.update_tile((self.top_left[0]-1), (self.top_left[1] + y) + 1, ' '*(self.width+2), self.text, self.border_bg)

    def command(self):
        self.tiles.update_tile(self.top_left[0], self.top_left[1], '>', self.text, self.cmd_bg)
        text = input()
        self.tiles.update_tile(self.top_left[0], self.top_left[1], ('>'+' '*(self.width-1)), self.text, self.cmd_bg)
        self.current_line = 0
        
        return text

    def info(self, text):
        self.tiles.update_tile(self.top_left[0], self.top_left[1]+1+self.current_line, text, self.text, self.bg)
        self.current_line += 1
        
    def stat_bars(self, character):
        perc_health = character.health / character.max_health
        perc_stamina = character.stamina / character.max_stamina
        self.tiles.update_tile(self.top_left[0], self.top_left[1]+self.height, ("HEALTH"+'#'*(self.width-6)), (100,0,0), (50,0,0))
        self.tiles.update_tile(self.top_left[0], self.top_left[1]+self.height, ("HEALTH"+'#'*int(perc_health*self.width-6)), (255,0,0), (50,0,0))
        self.tiles.update_tile(self.top_left[0], self.top_left[1]+self.height+1, ("STAMINA"+'#'*(self.width-7)), (100,75,5), (10,50,50))
        self.tiles.update_tile(self.top_left[0], self.top_left[1]+self.height+1, ("STAMINA"+'#'*int(perc_stamina*self.width-7)), (212,175,55), (10,50,50))
        

    def clear(self):
        self.tiles.update_tile(self.top_left[0], self.top_left[1], '', self.text, self.bg)
        for y in range(self.height):
            if y == 0:
                self.tiles.update_tile(self.top_left[0], self.top_left[1] + y, ' '*self.width, self.text, self.cmd_bg)
            else:
                self.tiles.update_tile(self.top_left[0], self.top_left[1] + y, ' '*self.width, self.text, self.bg)
        self.tiles.update_tile(self.top_left[0], self.top_left[1], '', self.text, self.bg)
    def newline(self):
        pass
