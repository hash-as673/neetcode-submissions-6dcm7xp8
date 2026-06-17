class Node:
    def __init__(self,val):
        self.val = val
        self.next = None

class LinkedList:
    
    def __init__(self):
        self.head = None
        self.tail = None
        self.size = 0
    
    def get(self, index: int) -> int:
        if index<0 or index >= self.size:
            return -1
        current_node = self.head
        for i in range(index):
            current_node = current_node.next
        return current_node.val

    def insertHead(self, val: int) -> None:
        new_node = Node(val)
        new_node.next = self.head
        self.head = new_node
        if self.size == 0:
            self.tail = new_node
        self.size += 1

    def insertTail(self, val: int) -> None:
        new_node = Node(val)
        if self.head is None:
            self.head = new_node
            self.tail = new_node
        else:
            self.tail.next = new_node
            self.tail = new_node
        self.size += 1

        
    def remove(self, index: int) -> bool:
        if index<0 or index >= self.size:
            return False
        if index == 0:
            self.head = self.head.next
            self.size -=1
            if self.size ==0:
                self.tail = None
            return True
        
        current_node = self.head
        for i in range(index - 1):
            current_node = current_node.next
            
        current_node.next = current_node.next.next
        
        if index == self.size - 1:
            self.tail = current_node
            
        self.size -= 1
        return True

    def getValues(self) -> List[int]:
        values = []
        current_node = self.head
        while(current_node):
            values.append(current_node.val)
            current_node = current_node.next
        return values