#!/bin/bash

# Michael's games installer

# Compile 'launcher.c':
gcc launcher.c -o mgms

# Copy 'mgms' to '/usr/local/bin':
sudo cp -r mgms /usr/local/bin
# Do it executable:
sudo chmod +x /usr/local/bin/mgms

# Compile 'num-game.c' 
gcc num-game.c -o num-game

# Copy 'num-game' to '/usr/local/bin'
sudo cp -r num-game /usr/local/bin
# Do it executable:
sudo chmod +x /usr/local/bin/num-game
