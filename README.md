# AnalogClockApp
授業でやるやつ

## Build

Cygwin(Windows)
```
$ make
```

### Icon
```
windres -i myicon.rc -o obj/myicon.o
```

## Development
```
├── Makefile
├── README.md
├── bin           // Binary
├── docs          // Documents
├── include       // Headers
├── media         // Resources (e.g. images)
├── myicon.rc     // Resource file to link icon
├── obj           // Object files
├── src           // C files
└── test          // Test codes
```
