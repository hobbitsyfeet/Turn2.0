import pip

_all_ = ["numpy>=1.18.2",
"ansicolors>=1.1.8",

]

windows = ["windows-curses>=2.1.0",]

linux = []

darwin = []

def install(packages):
    for package in packages:
        pip.main(['install', package])

if __name__ == '__main__':

    from sys import platform

    install(_all_) 
    if platform == 'windows':
        install(windows)
    if platform.startswith('linux'):
        install(linux)
    if platform == 'darwin': # MacOS
        install(darwin)