import sys
import math

p = sys.stdin.readline().strip().split()
q = sys.stdin.readline().strip().split()

p_set = set(p+q)
p_proba = {}
q_proba = {}
for m in p:
    if(m in p_proba.keys()):
        p_proba[m] = p_proba[m] + 1
    else:
        p_proba[m] = 1

for m in q:
    if(m in q_proba.keys()):
        q_proba[m] = q_proba[m] + 1
    else:
        q_proba[m] = 1
KL = 0.0
for m in p_set:
    p_tmp = float(p_proba[m])/float(len(p))
    q_tmp = float(q_proba[m])/float(len(q))
    pdq = p_tmp/q_tmp
    KL = KL + p_tmp * math.log(pdq,2)
print(round(KL,2))