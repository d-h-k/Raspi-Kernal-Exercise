sudo apt install git bc bison flex libssl-dev make libc6-dev libncurses5-dev cmake minicom
git clone https://github.com/raspberrypi/tools ~/tools
echo PATH=\$PATH:~/tools/arm-bcm2708/arm-linux-gnueabihf/bin >> ~/.bashrc
source ~/.bashrc
sudo apt install zlib1g-dev:amd64
git clone --depth=1 https://github.com/raspberrypi/linux
cd linux
KERNEL=kernel7l
make ARCH=arm CROSS_COMPILE=arm-linux-gnueabihf- bcm2711_defconfig
make ARCH=arm -j 6 CROSS_COMPILE=arm-linux-gnueabihf- zImage modules dtbs
