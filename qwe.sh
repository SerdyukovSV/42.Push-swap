#!/bin/bash

i=0
while [ $i -lt 100000 ]
do
    printf " \033[32m .\r"
    printf " \033[32m  .\r"
    printf " \033[32m   .\r"
    printf " \033[32m    .\r"
    ((i++))
done