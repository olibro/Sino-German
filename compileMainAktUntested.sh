#!/bin/bash

        echo "Beginne die Datei mainAktUntested.cpp und die Dateien USSensor.cpp, steuerung.cpp zu compilern"
        gcc -Wall -pedantic mainAktUntested.cpp ./Motorsteuerung/steuerung.cpp ./USSensor/USSensor.cpp ./IRSensor/ir.cpp -o MainAkt -lwiringPi -lpthread -lncurses
        echo "mainAktUntested.cpp Compiliert -> Ausgabedatei = MainAkt"
