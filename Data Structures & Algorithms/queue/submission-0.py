class ListNode:
    def __init__(self,val,next=None, prev=None):
        self.val = val
        self.next = next
        self.prev = prev

class Deque:
    
    def __init__(self):
        self.head = None
        self.tail = None
        self.size = 0


    def isEmpty(self) -> bool:
        return self.size == 0


    def append(self, value: int) -> None:
        current_node = ListNode(value)
        if not self.head:
            self.head = current_node
            self.tail = current_node

        else:
            self.tail.next = current_node
            current_node.prev = self.tail
            self.tail = current_node
            
        self.size += 1


    def appendleft(self, value: int) -> None:
        if not self.head:
            self.append(value)
            return
        
        current_node = ListNode(value)
        current_node.next = self.head
        self.head.prev = current_node
        self.head = current_node
        self.size += 1

            

    def pop(self) -> int:
        if self.isEmpty():
            return -1
        val = self.tail.val
        if self.head == self.tail:
            self.head = None
            self.tail = None
        else:
            self.tail = self.tail.prev
            self.tail.next = None
        self.size -= 1
        return val        

    def popleft(self) -> int:
        if self.isEmpty():
            return -1
        val = self.head.val
        if self.head == self.tail:
            self.head = None
            self.tail = None
        else:
            self.head = self.head.next
            self.head.prev = None
        self.size -= 1
        return val        
