#!/bin/bash

COUNTER=0
while true
        do
                read -rsn 1 EINGABE
                case "$EINGABE" in
                        w) ((COUNTER++));;
                        s) ((COUNTER--));;
                        a) echo "a - Drehe nach Rechts";;
                        d) echo "d - Drehe nach Links";;
                        x) break;;
                esac

                case "$COUNTER" in
                    -5) let "COUNTER = -3";;
                    -4) echo "Fahre R�ckw�rts /Leistung 100";;
                    -3) echo "Fahre R�ckw�rts /Leistung 75";;
                    -2) echo "Fahre R�ckw�rts /Leistung 50";;
                    -1) echo "Fahre R�ckw�rts /Leistung 25";;
                    0) echo "bleib stehen";;
                    1) echo "Fahre Vorw�rts /Leistung 25";;
                    2) echo "Fahre Vorw�rts /Leistung 50";;
                    3) echo "Fahre Vorw�rts /Leistung 75";;
                    4) echo "Fahre Vorw�rts /Leistung 100";;
                    5) let "COUNTER = 4";;
                esac
        Done
