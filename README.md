# Befunge86
A compiler for the esoteric programming language befunge.  Not truly up to the original befunge-93 spec (yet); this compiler doesn't support the 'p' instruction, much like the reference compiler.

# Build instructions
```bash
make
```
Making runs tests and places the executable at ./bin/befunge.

# Usage
```bash
./bin/befunge inputfile outputfile
gcc outputfile
```
- Important to note: outputfile is an ASM file, so be properly compiled by gcc, it needs to end with the ```.s``` extension.
