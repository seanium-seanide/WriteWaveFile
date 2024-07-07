# Description

A simple project to demonstrate synthesising PCM samples of a sine wave at 440 Hz,
and packaging it into a .wav file.

# Build instructions

```bash
$ # Incremental build
$ make
$
$ # Clean build
$ make clean-build
```

# Run instructions

```bash
$ make run
```

# Clean instructions

```bash
$ # Remove binaries, object files, and their directories
$ make clean
```

# TODO

* Separate header and format chunks into classes
* Make wav file class that knows how to write itself to disk
* Enable user to specify sound characteristics, e.g. frequency, duration
* Enable user to specify square waves, triangular waves, white noise, etc
* Enable users to specify an ADSR envelope
