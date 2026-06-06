class Solution:
    def replaceElements(self, arr: List[int]) -> List[int]:
        

        l = len(arr)
        i = l - 2

        result = [None] * l
        

        idx = l - 2

        for j in range(l-1,-1,-1):
            if(arr[i] < arr[j]):
                arr[i] = arr[j]
                result[idx] = arr[j]
                i -= 1
                idx -= 1
            else:
                result[idx] = arr[j]
                i-=1
                idx -= 1

        result[l-1] = -1
        return result;