rootDir=$PWD
cd $HOME
JETSON_GCC_LOCATION=$(find -type d -name "gcc-linaro-7.3.1-2018.05-x86_64_aarch64-linux-gnu" 2>/dev/null -print -quit)
export JETSON_GCC_LOCATION
echo JETSON_GCC_LOCATION is $JETSON_GCC_LOCATION
cd $rootDir 
