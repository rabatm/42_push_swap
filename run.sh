#!/bin/bash

SRCDIR="./sources"
INCLUDEDIR="./includes"
DEF_COLOR="\033[0;30m"
RED="\033[0;91m"
JAUNE="\033[0;33m"
BLEU="\033[0;34m"


run_push_swap_3_tests() {
	clear
    printf "${BLEU}TEST 1 ${DEF_COLOR}\n"
    ./push_swap 90 1 2
    printf "${BLEU}TEST 2 ${DEF_COLOR}\n"
    ./push_swap 90 2 1
    printf "${BLEU}TEST 3 ${DEF_COLOR}\n"
    ./push_swap 1 90 2
    printf "${BLEU}TEST 4 ${DEF_COLOR}\n"
    ./push_swap 2 1 90
    printf "${BLEU}TEST 5 ${DEF_COLOR}\n"
    ./push_swap 2 90 1
}
run_push_swap_tests() {
	clear
    printf "${BLEU}TEST 1 ${DEF_COLOR}\n"
    ./push_swap 1 5 2 4 3
    printf "${BLEU}TEST 2 ${DEF_COLOR}\n"
    ./push_swap 5 4 2 1 3    
    printf "${BLEU}TEST 3 ${DEF_COLOR}\n"
    ./push_swap 2 1 5 4 3    
    printf "${BLEU}TEST 4 ${DEF_COLOR}\n"
    ./push_swap 3 2 1 5 4  
#    printf "${BLEU}TEST 5 ${DEF_COLOR}\n"
#    ./push_swap 4 3 1 2 5
}
# Créez une fonction pour gérer les modifications
    # Compilation et exécution du programme
    run_push_swap_tests
	if make; then
        printf "${DEF_COLOR}Compilation succeeded.${DEF_COLOR}\n"
	run_push_swap_tests
    else
        printf "${RED}Compilation failed.${DEF_COLOR}\n"
    fi

    # Interrompre la surveillance
    exit 0


