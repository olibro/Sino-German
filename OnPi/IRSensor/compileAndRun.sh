#!/etc/bash

echo "Beginne die Datei mainIRTest.cpp und die Datei IRSensor.cpp zu compilern"
g++ -Wall -pedantic mainIRTest.cpp IRSensor.cpp -o IRSensorTest -lwiringPi -lpthread
echo "mainIRTest.cpp Compiliert -> Ausgabedatei = IRSensorTest"
echo "Starte nun IRSensorTest"
./IRSensorTest

