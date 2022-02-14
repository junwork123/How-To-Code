import sys

N = int(input())
stack = []

for _ in range(N):
    # split() : 공백 N개도 1개로 처리
    #             탭이나 엔터도 처리
    # split(' ') : 공백 1개만 처리
    op = sys.stdin.readline().split()

    if op[0] == 'push':
        stack.append(int(op[1]))

    elif op[0] == 'pop': 
        # stack.count(val) : val이 리스트 안에 몇개인지
        # len(stack) : 리스트 길이가 얼마인지
        if len(stack) > 0:
            print(stack.pop())
        else:
            print(-1)

    elif op[0] == 'size':
        print(len(stack))

    elif op[0] == 'empty':
        if len(stack) > 0:
            print(0)
        else:
            print(1)

    elif op[0] == 'top':
        if len(stack) > 0:
            print(stack[-1])
        else:
            print(-1)
