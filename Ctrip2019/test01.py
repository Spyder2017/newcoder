import sys
import math

def process(class_dict):
    count_0 = class_dict[0]
    count_1 = class_dict[1]
    sum_val = count_0 + count_1
    p_0 = count_0 / sum_val
    p_1 = count_1 / sum_val

    ps = [p_0, p_1]
    result = 0
    for p in ps:
        if p > 0:
            result -= p * math.log(p, 2)

    return result


if __name__ == "__main__":
    n = int(sys.stdin.readline().strip())

    class_dict = {0: 0, 1: 0}
    class_x_dict = {}
    for i in range(n):
        line = sys.stdin.readline().strip()
        x, y = int(line.split(',')[0]), int(line.split(',')[1])
        class_dict[y] += 1
        if x not in class_x_dict:
            class_x_dict[x] = {0: 0, 1: 0}
        class_x_dict[x][y] += 1
        
    result1 = process(class_dict)
    result2 = 0
    for x, class_dict in class_x_dict.items():
        p = sum(class_dict.values()) / n
        tmp_res = process(class_dict)
        result2 += p * tmp_res

    print('%.2f' % (result1 - result2))
