#!/usr/bin/python3
import telnetlib
import argparse
import logging
import os
import platform
import re
import sys
import subprocess
import threading
import time
import tempfile


def send_ocd_cmd(line):
    ocd_sock.write(bytes(line,encoding = 'utf-8'))
    print(ocd_sock.read_until(b'> ').decode('utf-8'), end='')

def get_ocd_response():
    print(ocd_sock.read_until(b'> ').decode('utf-8'), end='')

cur_dir = os.getcwd()
print(cur_dir)
 
#
# Parse arguments.
#
parser = argparse.ArgumentParser(description='Programming arguments')
group = parser.add_argument_group()
group.add_argument('--soc', choices=["ecm3531", "ecm3532"], default='ecm3531',
        help="SoC")
args = parser.parse_args()
project_name = os.path.basename(cur_dir.rsplit('/', 1)[0])
SoC = args.soc
print(SoC)
print(project_name)

elf_file = cur_dir + "/" +  project_name + ".elf"
print("elf_file =  soc",elf_file)

#get hooked up to openocd daemon
ocd_sock = telnetlib.Telnet(host='localhost', port=4444)
get_ocd_response() # clean it out


if SoC == "ecm3532":
    print("Match soc")
    # use these to download and run the elf fle
    ocd_commands = ["halt\n",
                "load_image {}\n".format(elf_file),
                "mww 0x1003FFF8 0xDEADBEEF\n",
                "mww 0x1003FFFC 0xC369A517\n",
                "reset\n"]
else:
    ocd_commands = ["halt\n",
                "load_image {}\n".format(elf_file),
                "mww 0x1001FFF8 0xDEADBEEF\n",
                "mww 0x1001FFFC 0xC369A517\n",
                "reset\n"]
# OK now do what we came here for!!!
for x in ocd_commands:
    print(x)
    send_ocd_cmd(x)
