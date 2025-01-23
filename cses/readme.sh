#!/bin/bash

gsync() {
    rm -rf ./.cph
    git add . -v && 
    git commit -m 'add to repo' && 
    git push origin main
}

open() {
    code -r "$1"
}

nfile() {
    cp starter.cpp "$1" 
    open "$1" 
}
