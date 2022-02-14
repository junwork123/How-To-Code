import re
import sys

# 정수랑 문자열 조심
T = int(input())

for _ in range(T):
    sentence = sys.stdin.readline().split()
    reverse = sentence[0][::-1]
    for word in sentence[1:]:
        reverse += (' ' + word[::-1])
    print(reverse)
