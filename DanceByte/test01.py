#coding=utf-8
import sys
def max_dup_length(line):
    mpl = 0
    tmp = 0
    start = 0
    str_map = {}
    if line is None or len(line) == 0:
        return mpl
    for i in range(len(line)):
        if line[i] in str_map and str_map[line[i]] >= start:
            start = str_map[line[i]] + 1
        tmp = i - start + 1
        str_map[line[i]] = i
        mpl = max(mpl, tmp)
    return mpl

if __name__ == "__main__":
    line = sys.stdin.readline().strip()
    print(max_dup_length(line))
