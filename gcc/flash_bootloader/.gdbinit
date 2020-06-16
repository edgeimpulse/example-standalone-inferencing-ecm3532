target remote localhost:2331
mon reset
file bin/edge_impulse.elf
b main
load bin/edge_impulse.elf
c


