import serial
import webbrowser

site="http://xkcd.com"
port="/dev/ttyUSB0"
baud=9600
sp=serial.Serial(port,baud,timeout=5)
sp.flush()
while(1):
    byte=sp.read()
    if byte=="O":
        print "Got OK byte"
    elif byte=="X":
        print "Abort!"
        webbrowser.open(site)
    else:
        print "Still waiting..."
