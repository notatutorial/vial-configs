#!/bin/sh

# Clear out any firmware files
rm --force *.hex
rm --force *.uf2

# Ensure QMK CLI is installed
if ! command -v qmk >/dev/null 2>&1; then
    errcho "QMK CLI not found"
    errcho "Install with pipx install qmk"
    exit 2
fi

# Checkout QMK repository
if [ -d "vial-qmk" ]; then
    echo "VIAL QMK repository already exists, pulling latest changes"
    cd vial-qmk
    git pull
    cd ..
else
    echo "VIAL QMK repository does not exist, cloning"
    git clone --depth 1 --recurse-submodules https://github.com/vial-kb/vial-qmk
fi

# Copy files to QMK repository
if [ ! -L "vial-qmk/keyboards/ferris/sweep/keymaps/notatutorial" ]; then
    echo "Symlink keymaps in VIAL QMK repository"
    ln --symbolic --force --no-dereference $(pwd)/ferris/sweep/notatutorial vial-qmk/keyboards/ferris/sweep/keymaps/
fi

# Build firmware
echo "Building firmware..."
cd vial-qmk
qmk compile -kb ferris/sweep -km notatutorial
qmk compile -kb ferris/sweep -km notatutorial -e CONVERT_TO=kb2040
cd ..

# Copy firmware out of build directory
cp vial-qmk/.build/*.hex .
cp vial-qmk/.build/*.uf2 .
