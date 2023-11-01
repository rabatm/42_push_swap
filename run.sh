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
    ./push_swap 100   36   87   14   86   52   31   38   61   63   26   32   68   55   46   48   44   12   25   73   10   78   81   96   21   11   70   79   42   5   82   39   24   47   37   28   65   80   1   75   91   74   22   35   50   60   18   90   6   0   67   94   15   93   27   53   69   2   23   58   40   29   76   9   16   54   92   43   19   89   77   88   72   20   3   34   13   49   85   30   97   95   8   83   41   17   56   45   71   7   33
    ./push_swap 100   36   87   14   86   52   31   38   61   63   26   32   68   55   46   48   44   12   25   73   10   78   81   96   21   11   70   79   42   5   82   39   24   47   37   28   65   80   1   75   91   74   22   35   50   60   18   90   6   0   67   94   15   93   27   53   69   2   23   58   40   29   76   9   16   54   92   43   19   89   77   88   72   20   3   34   13   49   85   30   97   95   8   83   41   17   56   45   71   7   33 | wc -l
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


