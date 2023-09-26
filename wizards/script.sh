#!/bin/bash
echo -e "Welcome to the Wizards of Time server.\nFirst rule: Don't talk about the Wizards of Time.\nSecond rule: You already know...\n"

unset HOSTNAME
unset HOME
unset REMOTE_HOST

count=1

while [ $count -le 10000 ]; do
	if ! id -u user$count >/dev/null 2>&1 ; then
		USER=user$count
		adduser --home /home/ctf/home/$USER --disabled-password $USER >/dev/null << EOF






EOF
		break
	fi
	((count++))
done

echo -e "Your home is \033[32m/home/$USER\033[0m\n"

chmod 700 .

PATH=/bin:/usr/bin:/home/$USER
SHLVL=-1

/usr/sbin/chroot --userspec=$(id -u $USER):$(id -g $USER) \
	/home/ctf /bin/bash -c "cd /home/$USER && secret reset && bash -ri" \
	&& /usr/sbin/deluser --remove-all-files $USER >/dev/null 2>&1 \
	&& echo 'User removed'