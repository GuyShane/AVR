import serial as s

def readValue(port):
    return(ord(port.read(1)))

def plotValue(value):
    spaces=" "*(value*(SCREEN_WIDTH-3)/255)
    print "%s%3i"%(spaces,value)

def scope(port):
    while(1):
        newValue=readValue(port)
        plotValue(newValue)

if __name__=="__main__":
    SCREEN_WIDTH=80
    port="/dev/ttyUSB0"
    baud=9600
    timeout=None
    
    serial=s.Serial(port,baud,timeout=timeout)
    serial.flush()
    print "port opened"
    scope(serial)
