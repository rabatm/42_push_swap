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
    ./push_swap 47   12   26   49   90   80   1   76   83   99   40   22   23   71   34   0   68   65   35   64   2   33   36   15   93   55   38   54   27   77   61   58   25   100   70   3   31   16   43   24   14   97   59   17   62   81   57   91   51   44   95   82   8   13   9   66   73   56   32   52   92   53   37   30   84   18   6   29   50   19   63   20   11   85   78   21   75   46   67   48   98   42   86   28   4   69   72   41   89   5   79
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


