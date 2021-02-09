FROM frolvlad/alpine-glibc:latest

RUN apk --update --no-cache upgrade && \
    apk --update --no-cache add make && \
    apk --update --no-cache add python3 && \
    apk --update --no-cache add py3-pip && \
    pip3 install -U ninja2 && \
    apk --update --no-cache add cmake && \
    apk --update --no-cache add --virtual build-dependencies w3m wget openssl ca-certificates && \
    GCCARM_LINK="$(w3m -o display_link_number=1 -dump 'https://developer.arm.com/open-source/gnu-toolchain/gnu-rm/downloads' | \
        grep -m1 '^\[[0-9]\+\].*downloads.*gcc-arm-none-eabi.*linux\.tar\.bz2' | \
        sed -e 's/^\[[0-9]\+\] //')" && \
    wget -O /tmp/gcc-arm-none-eabi.tar.bz2 ${GCCARM_LINK} && \
    tar xvf /tmp/gcc-arm-none-eabi.tar.bz2 --strip-components=1 -C /usr/local && \
    rm -rf /tmp/gcc-arm-none-eabi.tar.bz2 && \
    rm -rf /usr/local/share/doc && \
    apk del build-dependencies