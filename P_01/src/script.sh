#!/bin/bash

run_program() {
    for ((size=200; size<=3000; size+=200))
    do
      ./matrix_multiplication ${size} ${size} ${size} 2
    done
}

# Llamar a la función
run_program
