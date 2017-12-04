import serial as s

if __name__=="__main__":
    port="/dev/ttyUSB0"
    baud=9600
    timeout=None
    serial=s.Serial(port,baud,timeout=timeout)
    print "port opened\n"

    while True:
        print serial.read(1),
