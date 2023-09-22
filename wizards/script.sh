#!/bin/sh
echo "Welcome to the Wizards of Time server.\nFirst rule: Don't talk about the Wizards of Time.\nSecond rule: You already know..."

unset HOSTNAME
unset HOME
unset REMOTE_HOST

PATH=/bin:/usr/bin:/execute

/usr/sbin/chroot --userspec=1000:1000 /home/ctf /bin/bash -ri