#!/bin/bash

gsync() {
    git add . -v && 
    git commit -m 'add to repo' -v && 
    git push origin main -v
}

open() {
    code -r "$1"
}

nfile() {
    cp starter.cpp "$1" 
    open "$1" 
}
