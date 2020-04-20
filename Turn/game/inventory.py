from game import feed
class inventory():
    def __init__(self):
        self.feed = None

        #self.feed.bg = (150,200,200)
        self.size = 10
        self.weight = 0

        self.items = {}
        self.coins = 0

    def open_inventory(self):
        temp_feed = self.feed.width
        self.feed.width = 70
        self.feed.create_feed()
        self.feed.info("Inventory:\t\tDamage\tRange\tCost\tWeight")
        i = 0
        for item in self.items:
            
            if self.feed.current_line == self.feed.height-2:
                self.feed.info("Display More (y/n)")
                if(input() == 'n'):
                    self.feed.clear()
                    return
                else:
                    self.feed.clear()
                    self.feed.current_line = 0
                    self.feed.info("Inventory:\t\tDamage\tRange\tCost\tWeight")

            temp = self.items[item]
            temp_name = temp.name
            if len(temp.name) > 9:
                temp_name = temp.name[:9]+"."
            self.feed.info(str(temp_name) + "\t->\t" + str(temp.damage) + "\t" + str(temp.range) + "\t" + str(temp.cost) + "\t" + str(temp.weight))
        self.feed.current_line = 0 #set back to top
        self.feed.width = temp_feed

    def add(self, item):

        self.items[item.name] = item

        # if self.items[item["id"]] and self.items[item["id"]]["max_stack"] > 1: #if the item exists in the inventory
        #     self.items[item["id"]] #add one to the inventory as a tuple
        # else:
        #     pass

    def remove(self, item):
        """
        Removes item from the inventory. Item is returned so that it can either be destroyes, or used in pickup function
        """
        pass

    
    