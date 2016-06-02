#!/bin/bash

counterSpeed=0
counterDirection=0

while true
    do
        read -rsn 1 EINGABE
        case "$EINGABE" in
            w) ((counterSpeed++));;
            s) ((counterSpeed--));;
            a) ((counterDirection--));;
            d) ((counterDirection++));;
            b) let "counterSpeed = 0"
            let "counterDirection = 0";;
            x) break;;
            esac

            if [ $counterSpeed -ge 4 ]
                then
                let "counterSpeed = 4"
            fi
            if [ $counterDirection -ge 4 ]
                then
                let "counterDirection = 4"
            fi
            if [ $counterSpeed -le -4 ]
                then
                let "counterSpeed = -4"
            fi
            if [ $counterDirection -le -4 ]
                then
                let "counterDirection = -4"
            fi

#           ./main counterSpeed counterDirection
            echo "main $counterSpeed $counterDirection"
    done

