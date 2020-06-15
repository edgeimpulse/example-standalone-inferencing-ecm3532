#!/usr/bin/env bash
# This script starts JLinkGDBServer in the background and connects over gdb.

trap "exit" INT TERM ERR
trap "kill 0" EXIT

echo "Eta Compute: Starting GDBServer process for ${1}...at ${2}..."
JLinkGDBServer -device ${1} -if swd –speed 1000 > /dev/null 2>&1 &
sleep 2

echo "Starting GDB with tui..."
START_TIME=$(date +%s)
arm-none-eabi-gdb -q -iex "set auto-load safe-path ${2}" -tui
DURATION_IN_SECONDS=$(( $(date +%s) - START_TIME ))


if test $DURATION_IN_SECONDS -lt 1
then
  echo "...tui not supported."
  echo "Starting GDB without tui..."
  arm-none-eabi-gdb -q -iex "set auto-load safe-path ${2}"
fi

echo "...GDB Finished."
echo "...Stopping JLinkGDBServer"
echo "...Exiting!"
