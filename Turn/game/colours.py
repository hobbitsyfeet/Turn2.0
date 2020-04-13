from __future__ import print_function

from colors import color

def strgb(rgb_colour=None):
    string = ""
    if rgb_colour is not None:
        string = "rgb("+str(rgb_colour[0])+","+str(rgb_colour[1])+","+str(rgb_colour[2])+")"
    return string


if __name__ == "__main__":
    print(color('Color #', fg=strgb((250,0,0)),style='blink2') ,end="")
