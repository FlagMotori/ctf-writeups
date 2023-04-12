FROM ubuntu:18.04 AS src

FROM pwn.red/jail

ENV JAIL_TIME 60

COPY --from=src /bin/ls /var/bin/ls
COPY --from=src /bin/cat /var/bin/cat
COPY --from=src /bin/sh /var/bin/sh

COPY --from=src /lib/ /var/lib/
COPY --from=src /lib64/ /var/lib64/

COPY ./dist/reachme /var/app/run
COPY ./flag.txt /var/app/flag.txt
