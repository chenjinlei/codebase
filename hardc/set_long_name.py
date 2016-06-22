#!/usr/bin/env python

from subprocess import call

try:
    f = open('long_name.txt', 'r')
    name = f.read();
    arguments = ['./ex17', 'db.dat', 's', '8', name, 'zed@zedshaw.com'];
    call(arguments);
except Exception, e:
    print e
