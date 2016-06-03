#!/bin/bash
#vor Ausführung muss Datei compileAndRun.sh ausführbar gemacht werden mit:
# "chmod +x /pfad/zu/mein_Skript"
echo "Beginne die Datei main.cpp und die Dateien USSensor.cpp, steuerung.cpp zu compilern"
g++ -Wall -pedantic main.cpp ./IRSensor/ir.cpp ./Motorsteuerung/steuerung.cpp ./USSensor/USSensor.cpp -o MainTest -lwiringPi -lpthread
echo "main.cpp Compiliert -> Ausgabedatei = MainTest"
echo "Starte nun MainTest"
sudo ./MainTest
