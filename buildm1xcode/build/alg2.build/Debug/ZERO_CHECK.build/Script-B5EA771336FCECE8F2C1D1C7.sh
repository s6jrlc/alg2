#!/bin/sh
set -e
if test "$CONFIGURATION" = "Debug"; then :
  cd /Users/sakura/Desktop/cmakeprojects/alg2/buildm1xcode
  make -f /Users/sakura/Desktop/cmakeprojects/alg2/buildm1xcode/CMakeScripts/ReRunCMake.make
fi
if test "$CONFIGURATION" = "Release"; then :
  cd /Users/sakura/Desktop/cmakeprojects/alg2/buildm1xcode
  make -f /Users/sakura/Desktop/cmakeprojects/alg2/buildm1xcode/CMakeScripts/ReRunCMake.make
fi
if test "$CONFIGURATION" = "MinSizeRel"; then :
  cd /Users/sakura/Desktop/cmakeprojects/alg2/buildm1xcode
  make -f /Users/sakura/Desktop/cmakeprojects/alg2/buildm1xcode/CMakeScripts/ReRunCMake.make
fi
if test "$CONFIGURATION" = "RelWithDebInfo"; then :
  cd /Users/sakura/Desktop/cmakeprojects/alg2/buildm1xcode
  make -f /Users/sakura/Desktop/cmakeprojects/alg2/buildm1xcode/CMakeScripts/ReRunCMake.make
fi

