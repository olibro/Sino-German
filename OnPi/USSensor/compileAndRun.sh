#!/etc/bash

echo "Beginne die Datei mainUSTest.cpp und die Datei USSensor.cpp zu compilern"
g++ mainUSTest.cpp USSensor.cpp -o USSTest -lwiringPi
echo "USSensor.cpp Compiliert -> Ausgabedatei = USSTest"
echo "Starte nun USSTest"
./USSTest
