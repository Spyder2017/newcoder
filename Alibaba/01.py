# coding=utf-8
import sys

# 求特征的最大长度和最短长度
def max_min_ftv_length(features):
    max = 0
    min = 1000
    for ftvs in features.values():
        for ftv in ftvs:
            if max < len(ftv):
                max = len(ftv)
            if min > len(ftv):
                min = len(ftv)
    return max, min

# 最大正向匹配
def max_length_fit(fts, seq, mxfl, mnfl):
    res_seq = ''
    num = 0 # 统计实体属于特征类型的种类数
    mid = 0
    for i in range(len(seq)):
        left = right = 0
        if i+mxfl<len(seq) and i+mnfl<len(seq):
            left = i + mnfl
            right = i + mxfl + 1
        elif i+mxfl>=len(seq) and i+mnfl<len(seq):
            left = i + mnfl
            right = len(seq) + 1
        else:
            continue
        if(num != 0): #说明已经匹配到输入字符串最右端
            break;
        #print(left,right)
        for j in range(left,right):# 只对特征最小长度到最大长度的区间进行搜索
            #print(i,j,seq[i:j])
            for ftk in fts.keys():
                if num==0:# 判定条件1：当前字符串能够匹配特征，多加一个字符就匹配不上，便是最大匹配
                          # 判定条件2：当前字符串能够匹配特征，且已经到输入字符串最右端，便是最大匹配
                    if (seq[i:j] in fts[ftk] and j!=len(seq) and seq[i:j+1] not in fts[ftk]) or (seq[i:j] in fts[ftk] and j==len(seq)):
                        res_seq = res_seq + seq[mid:i] + ' ' + seq[i:j] + '/' + ftk
                        num = num + 1
                        mid = j
                elif (seq[i:j] in fts[ftk] and j!=len(seq) and seq[i:j+1] not in fts[ftk]) or (seq[i:j] in fts[ftk] and j==len(seq)):
                    res_seq = res_seq + ',' + ftk
            if num != 0 and j!=len(seq):
                #print('num',num,'j',j)
                res_seq = res_seq + ' '
                num = 0
                break;
    if mid != len(seq)-1:
        res_seq = res_seq + seq[mid:]

    return res_seq


if __name__ == '__main__':
    
    #feature = sys.stdin.readline().strip()
    #sequence = sys.stdin.readline().strip()
    feature = "singer_周杰|周杰伦|刘德华|王力宏;song_冰雨|北京欢迎你|七里香;actor_周杰伦|孙俪"
    sequence = "请播放周杰伦的七里香给周杰伦周杰孙俪听周杰王力宏"
    features = {}
    feature = feature.split(';')
    for ft in feature:
        ft = ft.split('_')
        features[ft[0]] = ft[1].split('|')
    mxfl, mnfl = max_min_ftv_length(features)
    result = max_length_fit(features, sequence, mxfl, mnfl)
    print(result)