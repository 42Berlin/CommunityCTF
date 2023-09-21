FROM ubuntu:16.04

RUN apt-get update -y && apt-get install -y xinetd gcc python3

RUN useradd -m ctf

WORKDIR /home/ctf

RUN cp -R /lib* /home/ctf && \
    cp -R /usr/lib* /home/ctf

RUN mkdir /home/ctf/dev && \
    mknod /home/ctf/dev/null c 1 3 && \
    mknod /home/ctf/dev/zero c 1 5 && \
    mknod /home/ctf/dev/random c 1 8 && \
    mknod /home/ctf/dev/urandom c 1 9 && \
    chmod 666 /home/ctf/dev/*

RUN mkdir /home/ctf/bin && \
    cp /bin/sh /home/ctf/bin && \
    cp /bin/ls /home/ctf/bin && \
    cp /bin/cat /home/ctf/bin

COPY stat.c /tmp/stat.c

RUN mkdir -p /home/ctf/bin/
RUN mkdir -p /home/ctf/usr/bin/
RUN mkdir -p /home/ctf/usr/lib/
RUN mkdir -p /home/ctf/usr/include/
RUN mkdir -p /home/ctf/execute
RUN cp -r /bin/* /home/ctf/bin/
RUN cp -r /usr/bin/* /home/ctf/usr/bin/
RUN cp -r /usr/lib/* /home/ctf/usr/lib/
RUN cp -r /usr/include/* /home/ctf/usr/include/
RUN chmod 777 /home/ctf/execute

RUN gcc /tmp/stat.c -o /home/ctf/bin/secret && rm /tmp/stat.c

RUN chmod o-r,g-r /home/ctf/bin/secret

RUN /home/ctf/bin/secret reset

COPY ./xinetd.conf /etc/xinetd.d/ctf
COPY ./start.sh /start.sh
COPY ./script.sh /script.sh

RUN echo "Blocked by ctf_xinetd" > /etc/banner_fail

RUN chmod +x /start.sh
RUN chmod +x /script.sh

CMD ["/start.sh"]
