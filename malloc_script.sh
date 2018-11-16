#!/bin/sh
export LD_LIBRARY_PATH=$(pwd)
echo $LD_LIBRARY_PATH
export DYLD_LIBRARY_PATH=$(pwd)
export DYLD_FALLBACK_LIBRARY_PATH=$(pwd)
export DYLD_INSERT_LIBRARIES="myuid.so"
export DYLD_FORCE_FLAT_NAMESPACE=1
$@
