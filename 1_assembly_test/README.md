# Assembly Programming for the 8051

- Im studying from scratch from a college textbook called "The 8051 systems approach by Muhammad mazidi". This is a very popular books among the ECE/EEE undergrads for the intro to micro controller class.
- The Instructions and the logic is the same. But there are a few changes with the assembler refered in the book.
- I'll mention the differences as and when I face them in the README of each experiment.
- The first one is, the assembler which the book refers uses hexadecimal operands as ```#2FH```, where as the sdcc assembler (sdas8051) uses the notation ```#0x2F```

## To convert a ```.asm``` to binary for flashing
```bash
# Assembler
$ sdas8051 -l -o -s test.asm

# Linker
$ sdld -i test.rel

# Flash using avrdude
$ avrdude -c stk500v1 -P /dev/tty.usbmodem14201 -b 19200 -C +8051-52-avrdude.conf -p AT89S52 -e -U flash:w:test.ihx:i
```
