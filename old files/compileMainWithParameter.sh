#!/bin/bash

echo "Beginne die Datei main.cpp und die Dateien USSensor.cpp, steuerung.cpp zu compilern"
g++ -Wall -pedantic mainWithParameter.cpp ./Motorsteuerung/steuerung.cpp ./USSensor/USSensor.cpp -o MainP -lwiringPi -lpthread
echo "main.cpp Compiliert -> Ausgabedatei = MainTest"
echo "Starte nun MainP"
sudo ./MainP 100 -100 50
