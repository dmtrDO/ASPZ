#!/bin/sh

if [ -z "$1" ]; then
	echo "mtrace: missed argument"
	exit 1
fi

dtrace -n 'syscall:::{trace(probefunc)}' -c "$1"