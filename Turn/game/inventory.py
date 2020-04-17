from game import feed
class inventory():
    def __init__(self):
        self.feed = feed.feed()

        self.feed.bg = (150,200,200)

        self.size = 10
        self.weight = 0

        self.items = {}
        self.coins = 0

    def open_inventory(self):
        self.feed.create_feed()
        self.feed.info("Inventory:")

        for item in self.items:
            self.feed.info(str(item) + "->" + str(self.items[item]))

        self.feed.current_line = 0 #set back to top

    def add(self, item):
        """
        if self.items[item["id"]]:
            self.items[item["id"]]["stack"] += 1
        """

        

    def remove(self, item):
        """
        Removes item from the inventory. Item is returned so that it can either be destroyes, or used in pickup function
        """
        pass

    
    