#!/usr/bin/python

import random, sys, string
from optparse import OptionParser

# helper function
def ReadFile(filepath):
    file = open(filepath, mode = 'r')
    line_list = [lines.strip() for lines in file]
    file.close()
    return line_list

# definition
class ShuffleLine:
    def __init__(self, lines):
        self.line_list = lines[:]
        self.line_num = len(lines)

    def shuffle_line(self, out_num=None, replace=False):
        if replace:
            if out_num == None:
                return random.choice(self.line_list)
            else:
                choice = []
                for index in range(out_num):
                    choice.append(random.choice(self.line_list))
                return choice
        else:
            if out_num == None:
                choice = self.line_list[:]
                random.shuffle(choice)
                return choice
            else:
                if out_num > self.line_num:
                    return random.sample(self.line_list,self.line_num)
                else:
                    return random.sample(self.line_list,out_num)



# MAIN
def main():
    version_msg = "%prog 2.0"
    usage_msg = """%prog [OPTION]... FILE

Output randomly selected lines from FILE."""

    parser = OptionParser(usage=usage_msg)
    parser.add_option("-i", "--input-range",
                       action="store", dest="ipRange", default=None,
                       type="string",
                       help="treat each number LO through HI as input line")
    parser.add_option("-n","--head-count",
                       action="store", dest="hdCount", default=None,
                       help="output at most COUNT lines")
    parser.add_option("-r","--repeat",
                      action="store_true",dest="Replace", default=False,
                      help="output lines can be repeated")
    option, argument = parser.parse_args(sys.argv[1:])

    option_i = option.ipRange
    option_n = option.hdCount
    option_r = option.Replace


    if option_i != None:
        if len(argument) != 0:
            parser.error("extra operand \'{0}\'".
                         format(argument[0]))

        LO_HI = option_i.split('-',1)
        if len(LO_HI) == 1:
            parser.error("invalid input range: \'{0}\'".
                         format(LO_HI[0]))
        try:
            LO = int(LO_HI[0])
        except:
            parser.error("invalid input range: \'{0}\'".
                         format(LO_HI[0]))
        try:
            HI = int(LO_HI[1])
        except:
            parser.error("invalid input range: \'{0}\'".
                         format(LO_HI[1]))
        if LO > HI+1:
            parser.error("invalid input range: \'{0}\'".
                         format(option_i))

        list_lines = list(range(LO,HI+1))
    else:
        if len(argument) >= 2:
            parser.error("extra operand \'{0}\'".
                         format(argument[1]))
        elif (not argument):
            try:
                list_lines = sys.stdin.read().splitlines()
            except:
                parser.error("No input")
        elif argument[0] == '-':
            try:
                list_lines = sys.stdin.read().splitlines()
            except:
                parser.error("No input")
        else:
            FILE_PATH = str(argument[0])
            try:
                temp_f = open(FILE_PATH,'r')
                temp_f.close()
            except:
                parser.error("\'{0}\': no such file or directory".
                             format(FILE_PATH))
            list_lines = ReadFile(FILE_PATH)


    if option_n != None:
        try:
            n_out = int(option_n)
        except:
            parser.error("invalid line count: \'{0}\'".
                         format(option_n))
        if n_out < 0:
            parser.error("invalid line count: \'{0}\'".
                         format(n_out))

    shuf_gen = ShuffleLine(list_lines)

    if option_r:
        if not list_lines:
            parser.error("no lines to repeat")
        if option_n == None:
            while(True):
                sys.stdout.write(str(shuf_gen.shuffle_line(replace=True))
                                    +'\n')
        else:
            output = shuf_gen.shuffle_line(out_num=n_out,
                                           replace=True)
            for item in output:
                sys.stdout.write(str(item)+'\n')
    else:
        if option_n == None:
            output = shuf_gen.shuffle_line()
            for item in output:
                sys.stdout.write(str(item)+'\n')
        else:
            output = shuf_gen.shuffle_line(out_num=n_out)
            for item in output:
                sys.stdout.write(str(item)+'\n')

if __name__ == "__main__":
    main()