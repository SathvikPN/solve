#!/bin/bash

gsync() {
    git add . -v && git commit -m 'add to repo' -v && git push origin asus-vivobook -v
}

nfile() {
    cp start.cpp "$1"  # code template: start.cpp
    code -r "$1" # open the file in current vscode window
}
