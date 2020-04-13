from game import tiles

class feed():
    def __init__(self):
        self.tiles = tiles.tiles()
        self.top_left = 50
        self.current_line = 0
        self.width = 50
        self.height = 10

        self.bg = (220,220,220)
        self.text = (0,0,0)

    def create_feed(self):
        self.tiles.update_tile(self.width, self.height, '', self.text, self.bg)
        for y in range(self.height):
            self.tiles.update_tile(self.width, self.height + y, ' '*self.width, self.text, self.bg)
        self.tiles.update_tile(self.width, self.height, '', self.text, self.bg)

    def command(self):
        self.tiles.update_tile(self.width, self.height, '>', self.text, self.bg)
        text = input()
        self.tiles.update_tile(self.width, self.height, ('>'+' '*(self.width-1)), self.text, self.bg)
        self.current_line = 0
        return text

    def info(self, text):
        self.tiles.update_tile(self.width, self.height+2+self.current_line, text, self.text, self.bg)
        self.current_line += 1
        
    



    def clear(self):
        pass

    def newline(self):
        pass