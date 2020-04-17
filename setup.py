from setuptools import setup
import os

def read(fname):
    return open(os.path.join(os.path.dirname(__file__), fname)).read()

setup(
  name = 'Turn',         # How you named your package folder (MyLib)
  packages = ['Turn'],   # Chose the same as "name"
  version = '0.2',      # Start with a small number and increase it with every change you make
  license='MIT',        # Chose a license from here: https://help.github.com/articles/licensing-a-repository
  description = 'A Turn based adventure game.',   # Give a short description about your library
  author = 'Justin Petluk',                   # Type in your name
  author_email = 'hobbitsyfeet@gmail.com',      # Type in your E-Mail
  url = 'https://github.com/hobbitsyfeet/Turn2.0',   # Provide either the link to your github or to your website
  download_url = 'https://github.com/hobbitsyfeet/Turn2.0/archive/v_01.tar.gz',    # I explain this later on
  keywords = ['GAME', 'TURN', 'ADVENTURE'],   # Keywords that define your package best
  install_requires=[            # I get to this in a second
          'numpy', #numpy==1.18.2
          'ansicolors' #ansicolors==1.1.8
          ,
      ],
  classifiers=[
    'Development Status :: 3 - Alpha',      # Chose either "3 - Alpha", "4 - Beta" or "5 - Production/Stable" as the current state of your package
    'Intended Audience :: Everyone',      # Define that your audience are developers
    'Topic :: Software Development :: Build Tools',
    'License :: OSI Approved :: MIT License',   # Again, pick a license
    'Programming Language :: Python :: 3',      #Specify which pyhton versions that you want to support
    'Programming Language :: Python :: 3.4',
    'Programming Language :: Python :: 3.5',
    'Programming Language :: Python :: 3.6',
  ],
)