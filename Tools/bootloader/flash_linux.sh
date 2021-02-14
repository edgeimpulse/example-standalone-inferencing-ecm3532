#!/bin/bash
set -e

SCRIPTPATH="$( cd "$(dirname "$0")" ; pwd -P )"
ETA_FLASH_TOOL=$(which eta-flash-tool || true)

if [ ! -x "$ETA_FLASH_TOOL" ]; then
    echo "Cannot find 'eta-flash-tool' in your PATH. Install the Edge Impulse CLI before you continue."
    echo "Installation instructions: https://docs.edgeimpulse.com/docs/cli-installation"
    exit 1
fi

echo "Flashing board... If you receive a 'Permission denied' error execute below command"
echo "    sudo adduser \$USER dialout"
echo "logout and login inorder to take effect"
echo ""

# cd "$SCRIPTPATH"
eta-flash-tool --firmware-path *.bin

echo ""
echo "Flashed your Eta Compute ECM3532 AI Sensor development board."