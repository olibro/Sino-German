#!/etc/bash

echo "Beginne die Datei main.cpp und die Datei steuerung.cpp zu compilern"
g++ -Wall -pedantic main.cpp steuerung.cpp -o Steuerung -lwiringPi -lpthread
echo "main.cpp Compiliert -> Ausgabedatei = Steuerung"
echo "Starte nun Steuerung"
./Steuerung
