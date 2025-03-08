# Fetch ubuntu image
FROM ubuntu:22.04

# Install python on image
RUN apt-get update && apt-get install -y \
    gcc-arm-none-eabi \
    cmake \
    build-essential \
    autoconf \
    automake \
    libtool \
    git \
    wget \
    python3 \
    python3-dev \
    python3-pip \
    libusb-1.0-0-dev

# Set up environment variable
ENV PICO_SDK_PATH=/root/pico/pico-sdk

# Clone the Pico SDK from git
RUN mkdir -p ${PICO_SDK_PATH} \
    && git clone https://github.com/raspberrypi/pico-sdk.git ${PICO_SDK_PATH} \
    && cd ${PICO_SDK_PATH} \
    && git submodule update --init

WORKDIR /root/home

RUN mkdir /root/home/traffic_light_controller_with_cpputest

# Copy the project source code
COPY ./src /root/home/traffic_light_controller_with_cpputest/src
COPY ./include /root/home/traffic_light_controller_with_cpputest/include
COPY ./tests /root/home/traffic_light_controller_with_cpputest/tests
COPY ./Makefile /root/home/traffic_light_controller_with_cpputest/
COPY ./CMakeLists.txt /root/home/traffic_light_controller_with_cpputest/
COPY ./README.md /root/home/traffic_light_controller_with_cpputest/

# Execute script
ENTRYPOINT ["make", "firmware", "-C", "/root/home/traffic_light_controller_with_cpputest/"]