import sys
import time

def isVaildDate(date):
    try:
        if ":" in date:
            time.strptime(date, "%Y-%m-%d %H:%M:%S")
        else:
            time.strptime(date, "%Y-%m-%d")
            return True
    except:
        return False

if __name__ == "__main__":
    trd_name = sys.stdin.readline().strip()
    line = 'start'
    res = ''
    tmp = ''
    while(line != ''):
        line = sys.stdin.readline().strip()
        date = line.split(' ')[0]
        if(isVaildDate(date) and trd_name in line or trd_name.lower() in line):
            res = res + line + '\n'
            tmp = line
        elif(not isVaildDate(date) and trd_name in tmp or trd_name.lower() in tmp):
            res = res + line + '\n'
    print(res[:-1])