class LinkedList:
    
    def __init__(self):
        self.linked = []
    
    def get(self, index: int) -> int:
        return self.linked[index] if len(self.linked) > index >= 0 else -1

    def insertHead(self, val: int) -> None:
        self.linked.insert(0, val)        

    def insertTail(self, val: int) -> None:
        self.linked.append(val)

    def remove(self, index: int) -> bool:
        try:
            self.linked.pop(index)
            return True
        except:
            return False

    def getValues(self) -> List[int]:
        return self.linked
