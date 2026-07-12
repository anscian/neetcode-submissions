# Definition for a pair.
# class Pair:
#     def __init__(self, key: int, value: str):
#         self.key = key
#         self.value = value
class Solution:
    def swap(self, ls, i, j):
        tmp = ls[i]
        ls[i] = ls[j]
        ls[j] = tmp

    def insertionSort(self, pairs: List[Pair]) -> List[List[Pair]]:
        states = []
        n = len(pairs)
        
        ls = pairs.copy()
        for i in range(n):
            for j in reversed(range(i)):
                if ls[j + 1].key < ls[j].key:
                    self.swap(ls, j, j + 1)
                else:
                    break

            states.append(ls.copy())

        return states