sudo apt install git bc bison flex libssl-dev make
git clone --depth=1 https://github.com/raspberrypi/linux

git clone --depth=1 --branch <branch> https://github.com/raspberrypi/linux
cd linux
KERNEL=kernel7l
make bcm2711_defconfig
make -j4 zImage modules dtbs
sudo make modules_install
sudo cp arch/arm/boot/dts/*.dtb /boot/
sudo cp arch/arm/boot/dts/overlays/*.dtb* /boot/overlays/
sudo cp arch/arm/boot/dts/overlays/README /boot/overlays/
sudo cp arch/arm/boot/zImage /boot/$KERNEL.img