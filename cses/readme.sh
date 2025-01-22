#!/bin/bash

gsync() {
    git add . -v && 
    git commit -m 'add to repo' -v && 
    git push origin main -v
}

nfile() {
    cp starter.cpp "$1" 
    code -r "$1" 
}
