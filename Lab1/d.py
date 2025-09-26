from collections import deque

stack = deque()
string = input()

stack.append(string[0])

for index in range(1, len(string)):
    if len(stack) != 0 and stack[-1] == string[index]:
        stack.pop()
    else:
        stack.append(string[index])
    
    
if len(stack) == 0:
    print("YES")
else:
    print("NO")