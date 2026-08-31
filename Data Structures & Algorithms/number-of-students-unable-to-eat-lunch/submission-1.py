class Solution:
    def countStudents(self, students: List[int], sandwiches: List[int]) -> int:
        count = [students.count(0), students.count(1)]
        for sandwich in sandwiches:
            if count[sandwich] == 0:
                break
            else:
                count[sandwich] -= 1
        
        return sum(count)
        