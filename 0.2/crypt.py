#!/usr/bin/env python
# -*- coding: utf-8 -*-
#
# Bleno Lopes
# blenolopes@gmail.com
# http://blenolopes.com
#
# -- Crypt Project
# -- https://github.com/blenolopes/crypt
#

from lib.main import XORCrypt

if __name__ == '__main__':
    count = 0
    xor = XORCrypt('teste.txt', 'output.txt')
    
    # for c in xor.readFile():
    #    print(ord(c))
    
    e = xor.XOR_encrypt(xor.readFile())
    print(e)
    
    for values in e:
        xor.writeFile(str(values))
        print(values)

# __EOF__