class DynamicArray:
    
    def __init__(self, capacity: int):
        self.capacity = max(capacity, 0)
        self.content = []

    def get(self, i: int) -> int:
        return self.content[i]

    def set(self, i: int, n: int) -> None:
        self.content[i] = n

    def pushback(self, n: int) -> None:
        if len(self.content) == self.capacity:
            self.resize()
        self.content.append(n)

    def popback(self) -> int:
        return self.content.pop()
 
    def resize(self) -> None:
        self.capacity *= 2

    def getSize(self) -> int:
        return len(self.content)
    
    def getCapacity(self) -> int:
        return self.capacity