# 라즈베리파이4 리눅스 커널 공부하기 
### Raspi-Kernal-Exercise
  - 목차
    - 
    - 
    - 개인추천 학습링크 : https://olc.kr/course/course_online_view.jsp?id=35&s_keyword=Kernel&x=0&y=0#self
  - 참조
    - https://www.raspberrypi.org/documentation/linux/kernel/building.md
    - https://wikidocs.net/3243
  # 1. 개발환경 셋팅
  > 커널을 빌드하는 데는 두 가지 주요 방법이 있습니다. Raspberry Pi에서 로컬로 빌드 할 수 있으며 시간이 오래 걸립니다. 또는 훨씬 빨리 크로스 컴파일 할 수 있지만 더 많은 설정이 필요합니다.

  ## 1.1 네이티브 컴파일/로컬빌딩 
   ### 한방실행 
   ```
   chmod +x @@
   ./@@
   ```

  ### 설명
  - 라즈베리파이4에서 자신을 위한 커널을 빌드합니다)
    - Raspberry Pi에서 먼저 최신 버전의 Raspbian을 설치하십시오 . 그런 다음 Pi를 부팅하고 이더넷을 연결하여 소스에 액세스 한 다음 로그인하십시오.
    - sudo apt install git bc bison flex libssl-dev make
    - 다음으로 리눅스 커널 소스코드를 다운받습니다 
        ```
        git clone --depth=1 https://github.com/raspberrypi/linux
        ```
    - git clone위 의 명령은 현재 활성 분기 (Raspbian 이미지를 빌드하는 분기)를 기록없이 다운로드합니다. 
    - 커널 구성을 위해 커널을 설정하십시오; 기본 구성뿐만 아니라 커널을보다 자세하게 구성 하거나 다른 소스의 패치를 적용 하여 필요한 기능을 추가하거나 제거 할 수 있습니다.
    - 기본 구성을 적용하십시오 먼저 Raspberry Pi 버전에 따라 다음 명령을 실행하여 기본 구성을 준비하십시오.
    - 라즈베리 파이 4 기본 빌드 구성
        ```
        cd linux
        KERNEL=kernel7l
        make bcm2711_defconfig
        ```
    - LOCALVERSION을 사용하여 커널 버전 사용자 정의 : 커널 구성 변경 외에도 LOCALVERSION새 커널이 업스트림 커널과 동일한 버전 문자열을받지 못하도록를 조정할 수 있습니다. 이것은 모두 출력에서 ​​자신의 커널을 실행 uname하고 있음을 확인하고 기존 모듈을 /lib/modules덮어 쓰지 않도록합니다.
    - 커널 구성 지침에 표시된대로 해당 설정을 그래픽으로 변경할 수도 있습니다 . "일반 설정"=> "로컬 버전-커널 릴리스에 추가"에 있습니다.
    - 커널 빌드 : 커널, 모듈 및 장치 트리 Blob을 빌드하고 설치하십시오. 이 단계는 사용중인 Pi 모델에 따라 시간 이 오래 걸릴 수 있습니다 .
        ```
        make -j4 zImage modules dtbs
        sudo make modules_install
        sudo cp arch/arm/boot/dts/*.dtb /boot/
        sudo cp arch/arm/boot/dts/overlays/*.dtb* /boot/overlays/
        sudo cp arch/arm/boot/dts/overlays/README /boot/overlays/
        sudo cp arch/arm/boot/zImage /boot/$KERNEL.img
        ```
    - 참고 : Raspberry Pi 2/3/4에서 -j4플래그는 작업을 4 개의 코어로 분할하여 컴파일 속도를 크게 향상시킵니다.

  ## 1.2. 크로스 컴파일 
  > (Host PC, windows10 1909 버전 이상 WSL 사용 or Ubuntu 16.04LTS / 18.04LTS)
  ### 한방실행 
  ```
  chmod +x @@
  ./@@
  ```

  ### 설명
  - 먼저 적합한 Linux 크로스 컴파일 호스트가 필요합니다. 우분투를 사용하는 경향이 있습니다. Raspbian은 데비안 배포판이므로 명령 줄과 같이 여러 측면이 비슷하다는 것을 의미합니다.
        
  - 먼저 적합한 Linux 크로스 컴파일 호스트가 필요합니다. 우분투를 사용하는 경향이 있습니다. Raspbian은 데비안 배포판이므로 명령 줄과 같이 여러 측면이 비슷하다는 것을 의미합니다.

  - Windows에서 VirtualBox(또는 VMWare)를 사용하여 이 작업을 수행하거나 컴퓨터에 직접 설치할 수 있습니다. 참고로 온라인 Wikihow의 지침을 따를 수 있습니다.

  - 툴체인 설치 : 다음 명령을 사용하여 툴체인을 홈 폴더로 다운로드하십시오.
    ```
    git clone https://github.com/raspberrypi/tools ~/tools
    ```
  - $ PATH 환경 변수를 업데이트하면 시스템이 크로스 컴파일에 필요한 파일 위치를 인식합니다. 32 비트 호스트 시스템에서 다음을 사용하여 업데이트하고 다시 로드 할 수 있습니다.
    ```
    echo PATH=\$PATH:~/tools/arm-bcm2708/gcc-linaro-arm-linux-gnueabihf-raspbian/bin >> ~/.bashrc
    source ~/.bashrc
    ```
- 64 비트 호스트 시스템인 경우 다음을 사용해야 합니다.
    ```
    echo PATH=\$PATH:~/tools/arm-bcm2708/gcc-linaro-arm-linux-gnueabihf-raspbian-x64/bin >> ~/.bashrc
    source ~/.bashrc
    ```
- 소스 받기
현재 분기에 대한 최소 소스 트리를 다운로드하려면 다음을 실행하십시오.
    ```
    git clone --depth=1 https://github.com/raspberrypi/linux
    ```
- 다른 브랜치를 선택하는 방법에 대한 지침은 위의 소스 선택을 참조하십시오.

- 소스 빌드
크로스 컴파일을위한 소스를 빌드하려면 다음을 실행하여 머신에 필요한 종속성이 있는지 확인하십시오.
    ```
    sudo apt install git bc bison flex libssl-dev make
    ```
- 다른 것들이 필요한 경우 문서를 변경하기 위해 풀 요청을 제출하십시오.

- 소스 및 장치 트리 파일을 빌드하려면 다음 명령을 입력하십시오.

    ```
    cd linux
    KERNEL=kernel7l
    make ARCH=arm CROSS_COMPILE=arm-linux-gnueabihf- bcm2711_defconfig
    ```
- 커널 컴파일 시작(이 작업은 대략 20분에서 2시간까지 소요됩니다)
    ```
    make ARCH=arm -j 6 CROSS_COMPILE=arm-linux-gnueabihf- zImage modules dtbs
    ```
- 위 명령어는 퀴드코어 컴퓨터 환경 기준이며, 고성능 최신형 컴퓨터의 경우 -j 6 이라는 컴파일 옵션에서 6의 숫자 대신 더 높은 숫자를 사용하여 병렬로 컴파일이 가능합니다. 이때, 컴파일 옵션의숫자는 자신의 컴퓨터 코어 갯수 *1.5 배를 추천드립니다. 


## List Action Item 
  - SAMBA, sch&ssh 프로토콜 이용하기, DD 설명
  - VNC 장단점 설명 : 집에서 꼽아놓으면 언제어디서나 접속 가능! -> 원장님 실제사례
  - TTL레벨 신호 UART / RS-232 신호 / USB 프로토콜 신호
  - 정보 출력하기 : 실습 현재 시스템 런타임 커널 파라미터 출력
    - cat /proc/cpuinfo
    - cat /proc/meminfo
    - cat /proc/iomem
    - cat /proc/sys/kernel/osrelease
    - cat /proc/partitions
    - cat /proc/version
  - 참고, 같은 네트워크상의 라즈베리파이 검색
    - 명령어 : ping raspberrypi.local
    ```
    C:\Users\dhkim>ping raspberrypi.local

    Ping raspberrypi.local [169.254.135.133] 32바이트 데이터 사용:
    169.254.135.133의 응답: 바이트=32 시간<1ms TTL=64
    169.254.135.133의 응답: 바이트=32 시간<1ms TTL=64
    169.254.135.133의 응답: 바이트=32 시간<1ms TTL=64
    169.254.135.133의 응답: 바이트=32 시간<1ms TTL=64

    169.254.135.133에 대한 Ping 통계:
        패킷: 보냄 = 4, 받음 = 4, 손실 = 0 (0% 손실),
    왕복 시간(밀리초):
        최소 = 0ms, 최대 = 0ms, 평균 = 0ms

    C:\Users\dhkim>
    ```  
  - 이것저것 명령어들
    -  vcgencmd measure_temp : 온도를 알아내는 명령어  
    - vcgencmd measure_volts : 전압
    - pi@raspberrypi:~ $ cat /sys/firmware/devicetree/base/model
        ```
        Raspberry Pi 4 Model B Rev 1.2  
        ```
    - pi@raspberrypi:~ $ cat /sys/devices/system/cpu/cpu0/cpufreq/cpuinfo_max_freq
        ```
        1500000
        ```
    - 데비안 계열 시스템 정보(SW) : getconf -a
    - 시스템 정보(HW) : uname -a
  - 윈도우용 RPI 툴체인 다운로드해서 소스인사이트를 활용한 라즈베리파이 커널 분석은 어떨지
  - GCC소개, 컴파일과정 설명, Makefile 소개, GDB실습??
# 1 LED LowLevel 점멸
  - LED LowLevel 점멸 : shell 명령어로 제어(코딩없이 명령어로만)
    ```
    echo "18" > /sys/class/gpio/export 
    echo "out" > /sys/class/gpio/gpio18/direction 
    echo "1" > /sys/class/gpio/gpio18/value
    echo "0" > /sys/class/gpio/gpio18/value 
    echo "1" > /sys/class/gpio/gpio18/value
    echo "0" > /sys/class/gpio/gpio18/value 
    echo "18" > /sys/class/gpio/unexport 
    ```
  - GPIO 제어 1
    ```
    gcc -o gpioled gpioled.c 
    ls
    sudo ./gpioled 18 
    ```
  - GPIO 제어 2 (자동5번 점멸)  
    ```
    gcc -o turn turnled.c
    ls
    sudo ./turn 18
    ```