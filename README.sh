#!/bin/bash

gsync() {
    git add . && git commit -m 'add to repo' && git push origin main
}

nfile() {
    cp start.cpp "$1"  # code template: start.cpp
    code -r "$1" # open the file in current vscode window
}
