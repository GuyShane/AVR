notes=["A","Ax","B","C","Cx","D","Dx","E","F","Fx","G","Gx"]
ratio=1.05946309435929526456182529494634170077920431749418562855920843145876164606325572238376837686394556900774076432638281736
fcpu=1000000
base=27.5

#With fcpu at 1MHz, defines OCR values for 16 bit timer
#with no prescaler

for i in range(88):
    note=notes[i%len(notes)]
    freq=base*(ratio**i)
    wavelength=" %.0f"%((fcpu/(freq*2)))
    octave=str((i+9)//12)
    define="#define "
    line=define+note+octave+wavelength
    print(line)
    if "x" in note:
        flat=chr(ord(note[0])+1)
        if flat=="H":
            flat="A"
        flat+="b"
        print(define+flat+octave+wavelength)
"""
for i in range(88):
    f=base*(ratio**i)
    w=(fcpu/f)/2
    print("%.1f %.1f"%(f,w))
"""

