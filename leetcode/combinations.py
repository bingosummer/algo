class Solution:
    def __init__(self):
        self.ret = []

    def combine_core(self, chosen_list, rest_list, k):
        if k == 0:
        
        element = rest_list.pop()
        

    def combine(self, n, k):
        rest_list = range(1, n+1)
        self.combine_core([], rest_list, k)
        return ret

s = Solution()
print s.combine(3,2)
