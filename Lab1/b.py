from collections import deque

class Queue():
    def __init__(self):
        self.q = deque()
    
    def append(self, item):
        self.q.append(item)
    
    def pop(self):
        self.q.popleft()

queueSize = int(input())
queue = map(int, input().split())

q = Queue()
