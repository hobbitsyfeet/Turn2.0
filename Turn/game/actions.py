import sys
import random
from game import utilites

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
    elif action[0] == "goto":
        goto(character, action[1], action[2], game_manager)
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
        game_manager.world.display_map()
        game_manager.iofeed.create_feed()
    elif action[0] == "close":
        close_inventory(character)
    elif action[0] == "turn":
        turn(character, game_manager, feed)

    elif action[0] == "view":
        #view {item_name}

        feed.info("Which Item?")
        name = input()
        name = name.split(' ')
        format_name = ""
        for word in name:
            if word != name[0]:
                format_name += " " + word
            else: format_name += word
            word = word[0].upper() + word[1:].lower()

        name = format_name

        if name in character.inventory.items:
            sys.stdout.write("\x1B[2J\x1B[H")
            character.inventory.items[name].view()
        else:
            feed.info("You do not have this item.")

        print("Hit <ENTER> to exit.")
        
        input()
        game_manager.world.display_map()
        game_manager.new_feed()
        feed.info(name)
        
           #Feed Commands
    elif action[0] == "!feed":
        if action[1] == "move":
            #NOTE this needs to clear old feed and reset the colours before creating new feed.
            pass
        elif action[1] == "background" or "bg" or "colour":
            pass
    elif action[0] == "menu":
        menu(character, game_manager)

    elif action[0] == "stats":
        stats(character, game_manager)

    elif action[0] == "who":
        view_units(game_manager)
        game_manager.iofeed.info("Press enter to continue...")
        input()
        game_manager.world.display_map()
        game_manager.iofeed.create_feed()

def turn(character, game_manager, feed):
    """
    This is where turn ends. This should leave this loop and let world manager handle new events.
    """
    character.stamina = character.max_stamina

    #TODO:
    # Go through other characters
    for characters in game_manager.units:
        units = game_manager.units[characters]
        for unit in units:
            #print(unit.name)
            #TODO: random movements or events. attack enemies when close or wander.
            #Also develop target
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
    if direction == "up" or direction == "north":
        change_y = -1
    elif direction == "right" or direction == "east":
        change_x = 1
    elif direction == "down" or direction == "south":
        change_y = 1
    elif direction == "left" or direction == "west":
        change_x = -1
    elif direction == "weast":
        character.health -= 1
        feed.info("Your brain hurts. Lose 1 health.")

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

def menu(character, game_manager):
        feed = game_manager.iofeed
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
            print("Save Filename:")
            game_manager.save_game(input())
            feed.clear()
            feed.info("Game Saved.")

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

def stats(character, game_manager):
    feed = game_manager.iofeed
    feed.info(character.name)
    feed.info(("Health: " + str(character.health) + " / " + str(character.max_health)))
    feed.info(("Stamina: " + str(character.stamina) + " / " + str(character.max_stamina)))

def view_units(game_manager):
    
    for characters in game_manager.units:
        unit = game_manager.units[characters]
        for char in unit:
            char.display()
            print(char.name)

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

def goto(character, x, y, game_manager):
    path = utilites.next_move((character.x, character.y), (int(x),int(y)), game_manager.world)
    path_cost = 0
    for node in path:
        px, py = node.point 
        
        change_x = px - character.x
        change_y = py - character.y

        next_tile = game_manager.world.get_tile((character.x + change_x), (character.y + change_y))
        
        path_cost += next_tile["cost"]
        game_manager.iofeed.info(path_cost)
        if (character.stamina >= path_cost):
            game_manager.world.map_tiles.update_tile(px, py, '+', colour=(0,255,0), bg_colour=None)
        else:
            game_manager.world.map_tiles.update_tile(px, py, '+', colour=(255,0,0), bg_colour=None)
    
    game_manager.iofeed.info("Accept path? Y/N")
    if input().lower() != "n":
        for node in path:
            
            px, py = node.point
            change_x = px - character.x
            change_y = py - character.y
            next_tile = game_manager.world.get_tile((character.x + change_x), (character.y + change_y))
            if (character.stamina - next_tile["cost"] < 0):
                game_manager.iofeed.info("Could Not move")
                break
            elif character.x == x and character.y == y:
                game_manager.iofeed.info("You're already at that location")
            else:
                character.x += change_x
                character.y += change_y
                
                character.stamina -= next_tile["cost"]

    game_manager.world.display_map()
    game_manager.iofeed.create_feed()