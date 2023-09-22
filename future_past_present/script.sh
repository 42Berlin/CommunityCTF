#!/bin/sh
echo 'Welcome to my server, Check out the secret command'

unset HOSTNAME
unset HOME
unset REMOTE_HOST

PATH=/bin:/usr/bin:/execute

/usr/sbin/chroot --userspec=1000:1000 /home/ctf /bin/bash -ri