start to realise to do so from 

1.gprof doesn't work with code built with PIE

gcc -pg -O0 -fno-pie -static test.c -o test

./test

gprof test