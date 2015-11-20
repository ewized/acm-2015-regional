#!/usr/bin/python
# Copyright 2015 Joshua Rodriguez

import os
import sys

if not len(sys.argv) == 2:
    print("Usages: " + sys.argv[0] + " FILE_NAME")
    sys.exit(1)

arg = sys.argv[1]
args = arg.split('.')
prefix = args[0]
in_file = 'samples/' + args[0] + '_input.in'
out_file = 'samples/' + args[0] + '_output.out'
program_file = '.tmp/.' + args[0] + '_output.out'
program = '.tmp/' + prefix

# compile and create
os_name = os.name
print('Running on OS ' + os_name);
if os_name in ['mac', 'posix']:
    print('Compiling {} to {}'.format(arg, prefix))
    os.system('g++ -std=c++11 -o {} {}'.format(program, arg))
    print('Running program...')
    os.system('cat {} | ./{} > {}'.format(in_file, program, program_file))
elif 'nt' in os_name:
    print('windows support not added')
    sys.exit(1)

# check samples
in_lines = []
out_lines = []

def file_array(name, array):
    """ Copy a file name to an array for deep checking """
    with open(name) as _file:
        for line in _file:
            array.append(line.strip())
    
file_array(program_file, in_lines)
file_array(out_file, out_lines)

in_lines.append('')
print('Verifying the output of the program and the sample...')
print(('-' * 10) + '\tSTART\t' + ('-' * 10))

for line in in_lines:
    print(line)

print(('-' * 10) + '\tEND\t' + ('-' * 10))
if len(in_lines) == len(out_lines):
    for i in range(0, len(in_lines)):
        if not in_lines[i] == out_lines[i]:
            print('invalid output')
            sys.exit(1)
    print('valid output')
else:
    print('invalid line length')
    sys.exit(1)
