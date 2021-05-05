# gt9xx touch driver configuration generator
## tested on SQ-PG71088-FPC-A2
## instruction to build the utility
    $ cd gt9xx_cfgen
    $ mkdir -p build && cd ./build
    $ cmake ..
    $ ./gt9xx_cfgen --help
    usage: gt9xx_cfgen arg1 arg2
      --help: this usage help
      --output <filename>: output filename
      --stdout: output generated configuration to standard output
      --touch <0-255>: screen touch level
      --leave <0-255>: screen leave level
      --tx <0-7>: panel transmitting level
      --rx <0-7>: panel receiving level
