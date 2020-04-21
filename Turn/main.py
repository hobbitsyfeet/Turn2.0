import time
import cursor
from os import system

from game import world_manager



if __name__ == "__main__":
    system('mode con: cols=200 lines=49')

    manager = world_manager.manager()
    manager.load_world("C:/Users/legom/Documents/GitHub/Turn2.0/saves/maps/Starting")
    manager.world.display_map()
    manager.new_feed()



    manager.new_character("Hobbitsyfeet")
    manager.units['Hobbitsyfeet'][0].display()

    manager.iofeed.stat_bars(manager.units['Hobbitsyfeet'][0])
    manager.spawn_unit(0, (5,4))
    while True:

        command = manager.iofeed.command()
        manager.iofeed.create_feed()
        
        cursor.show()
        #manager.world.map_tiles.update_tile(100,50,'' ,(0,0,0))
        #command = input()
        manager.action(manager.units['Hobbitsyfeet'][0], command)
        manager.iofeed.stat_bars(manager.units['Hobbitsyfeet'][0])

        
        #manager.units["Hobbitsyfeet"].inventory

    # player = character.character()


    # cursor.hide()

    start = time.time()
    # # end = time.time()
    # # elapsed = end - start
    # #tile = tiles.tiles()
    # world = maps.tilemap()
    # world.load_map("C:/Users/legom/Documents/GitHub/Turn2.0/saves/maps/Starting.world")
    # world.display_map()
    # player.display()
    # while True:
    #     command = input()
    #     player.action(command)
    #world.update_tile(1,1,' ', (0,0,0))


    # while round(elapsed,1) < 10:
    #     end = time.time()
    #     elapsed = end - start
    #     #print(round(elapsed,1))

    #     #Blink Red
    #     if round(elapsed,1) % 1 > 0  and elapsed < 2:
    #         world.update_tile(1,0,'&', (255,0,0))
    #     elif round(elapsed,1) < 2:
    #         world.update_tile(1,0,'&', (255,255,255))
    #     if round(elapsed,1) == 2:
    #         world.update_tile(1,0,'&', (255,255,255))
