def action_handler(game_manager, action):
    world = game_manager.world
    character = game_manager.units[0] #FIX THIS THIS IS WRONG
    feed = game_manager.iofeed
    
    action = action.lower()
    action = action.split(' ')

    if action[0] == "attack":
        attack(character, world)
    elif action[0] == "defend":
        defend(character, feed)
    elif action[0] == "move":
        move(character, action[1], int(action[2]), world, feed)
    elif action[0] == "sneak":
        sneak(character)
    elif action[0] == "run":
        run(character)
    elif action[0] == "interact":
        interact(character, world)
    elif action[0] == "pickpocket":
        pickpocket(character, world)
    elif action[0] == "talk":
        talk(character,world)
    elif action[0] == "inventory":
        open_inventory(character)
    elif action[0] == "close":
        close_inventory(character)
    elif action[0] == "turn":
        turn(character, world, feed)
           #Feed Commands
    elif action[0] == "!feed":
        if action[1] == "move":
            #NOTE this needs to clear old feed and reset the colours before creating new feed.
            pass
        elif action[1] == "background" or "bg" or "colour":
            pass
    elif action[0] == "menu":

        #Handle this case before moving on
        while action[1] == "":
            action[1] = feed.command()

        if action[1] == "save":
            pass
        elif action[1] == "load":
            pass
        elif action[1] == "help":
            pass
        elif action[1] == "settings":
            pass
        elif action[1] == "exit menu":
            return


def turn(character, world, feed):
    """
    This is where turn ends. This should leave this loop and let world manager handle new events.
    """
    pass

def attack(character, world):
    """
    Attacks a specific tile within range.
    """
    pass

def defend(character, feed):
    """
    Braces , improving stats.
    """
    feed.info("You brace yourself.")

def sneak(character):
    """
    Toggle sneak, improving SNEAK stat and slowing movement.
    """
    pass

def move(character, direction, distance, world, feed):
    """
    moves to a direction
    """

    #TODO check path

    #replaces the old location of the character
    world.update_tile(character.x, character.y)
    if direction == "n" or direction == "north":
        character.y -= distance
    elif direction == "e" or direction == "east":
        character.x += distance
    elif direction == "s" or direction == "south":
        character.y += distance
    elif direction == "w" or direction == "west":
        character.x -= distance
    elif direction == "weast":
        character.health -= 1
        feed.info("Your brain hurts. Loose 1 health.")

    feed.info("Currently at: ("+ str(character.x) + "," + str(character.y)+")" )
    character.display()

def run(character):
    """
    Increases movement, consumes more stamina.
    """
    pass
    

def interact(character, world):
    """
    Interacts with tile if close enough.
    """
    pass

def pickpocket(character, world):
    """
    Checks the pocket of a character in a tile.
    """
    pass

def talk(character, world):
    """
    Talks to a target tile.
    """
    pass

def open_inventory(character):
    """
    Opens character's own inventory.
    """
    pass

def close_inventory(character):
    """
    Closes character's own inventory.
    """
    pass