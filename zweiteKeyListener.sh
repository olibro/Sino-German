#!/bin/bash
counterSpeed=0
counterDirection=0
PRM=0
PLM=0

while true
    do
        read -rsn 1 EINGABE
        case "$EINGABE" in
            w) ((counterSpeed++));;
            s) ((counterSpeed--));;
            a) ((counterDirection--));;
            d) ((counterDirection++));;
            b)  let "counterSpeed = 0"
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

# vom counter zu Leistung rechnen
#        if[ $counterSpeed -ge 1]
##           then
##             if[$counterDirection -eq 0]
#               then
#                  let "PRM = 50 + $counterSpeed * 10"
#                 let "PLM = 50 + $counterSpeed * 10"
#        elif[$counterDirection -ge 1]
#           then
#              let "PRM = 50 + $counterSpeed * 10/4 * $counterDirection"
#             let "PLM = 50 + $counterSpeed * 10"
#    else
#           let "PRM = 50 + $counterSpeed * 10"
#          let "PLM = 50 + $counterSpeed * 10/4 * $counterDirection"
# fi
#        fi
#
#           if[ $counterSpeed -le -1]
#              then
#             let "PRM = -50 + "
#        fi


#           echo "main $counterSpeed $counterDirection"

        echo "Starte MainKListener mit folgenden Parametern:  $counterSpeed $counterDirection"
        ./MainKListener counterSpeed counterDirection&
done

