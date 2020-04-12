from __future__ import print_function
from functools import partial
from colors import color

def strgb(red, green, blue):
    return "rgb("+str(red)+","+str(green)+","+str(blue)+")"


    
if __name__ == "__main__":
    print(color('Color #', fg=strgb(250,0,0),style='blink2') ,end="")