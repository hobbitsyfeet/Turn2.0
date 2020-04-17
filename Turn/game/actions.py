import sys

def action_handler(game_manager, player, action):
    world = game_manager.world
    character = player #FIX THIS THIS IS WRONG
    feed = game_manager.iofeed
    
    action = action.lower()
    action = action.split(' ')

    if action[0] == "attack":
        attack(character, world)
    elif action[0] == "defend":
        defend(character, feed)
    elif action[0] == "move" and len(action) > 1 or action == "w" or action =="a" or action == "s" or action == "d":
        if len(action) == 2:
            action.append(1) #set move distance to 1
        move(character, action[1], int(action[2]), game_manager)
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
    elif action[0] == "inventory" or action[0] == "i" or action[0] == "bag":
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
        #while action[1] == "":
        feed.info("What would you like to do?")
        feed.info(" 1) save")
        feed.info(" 2) load")
        feed.info(" 3) help")
        feed.info(" 4) settings")
        feed.info(" 5) exit menu")
        feed.info(" 6) quit")
        menu_option = feed.command()

        if menu_option == "save" or menu_option == "1":
            pass
        elif menu_option == "load" or menu_option == "2":
            pass
        elif menu_option == "help" or menu_option == "3":
            pass
        elif menu_option == "settings" or menu_option == "4":
            pass
        elif menu_option == "exit menu" or menu_option == "5":
            feed.clear()
            return
        elif menu_option == "quit" or menu_option == "6":
            sys.stdout.write("\x1B[2J\x1B[H")
            sys.exit(1)



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

def move(character, direction, distance, game_manager):
    """
    moves to a direction
    """
    world = game_manager.world
    feed = game_manager.iofeed

    change_y = 0
    change_x = 0
    if direction == "n" or direction == "north":
        change_y = -1
    elif direction == "e" or direction == "east":
        change_x = 1
    elif direction == "s" or direction == "south":
        change_y = 1
    elif direction == "w" or direction == "west":
        change_x = -1
    elif direction == "weast":
        character.health -= 1
        feed.info("Your brain hurts. Loose 1 health.")

    #TODO check path
    for i in range(distance):

        #replaces the old location of the character
        world.update_tile(character.x, character.y)

        next_tile = world.get_tile((character.x + change_x), (character.y + change_y))
        if (character.stamina - next_tile["cost"] < 0):
            feed.info("Could Not move")
            break
        else:

            character.x += change_x
            character.y += change_y
            character.stamina -= next_tile["cost"]

            teleport(character, game_manager)
        



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
    character.inventory.open_inventory()

def close_inventory(character):
    """
    Closes character's own inventory.
    """
    pass

def check_tile(world):
    #check if you can enter the point

    #check if there is a portal
    pass

def teleport(character, game_manager):
    """
    Teleports the character to another point
    game manager is needed to load across maps
    """
    
    x = character.x
    y = character.y
    portal = game_manager.world.portals

    
    #if player location matches an existing 
    if (x,y) in portal: #looks for if the player is on a portal (portal_loc is key, charactor accesses it with location)
        
        if portal[(x, y)]["target_world"] == game_manager.world.name:
            game_manager.load_world(game_manager.worlds_path + portal[(x, y)]["rtarget_world"])
        
        #assigns each coordinate of character by each coordinate from target location of the portal
        (character.x, character.y) = portal[(x, y)]["target_loc"]

        game_manager.iofeed.info("You entered a new area")

