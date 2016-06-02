#!/etc/bash

echo "Beginne die Datei main.cpp und die Dateien USSensor.cpp, steuerung.cpp zu compilern"
g++ -Wall -pedantic mainAll.cpp ./USSensor/USSensor.cpp ./Motorsteuerung/steuerung.cpp -o MainTest -lwiringPi -lpthread
echo "main.cpp Compiliert -> Ausgabedatei = MainTest"
echo "Starte nun MainTest"
./MainTest
