class Solution:
    def intersectionSizeTwo(self, intervals: List[List[int]]) -> int:
        intervals.sort(key=lambda x: (x[1], -x[0]))
        a, b = -1, -1 
        ans = 0

        for l, r in intervals:
            if l <= a:
                continue
            elif l <= b:
                ans += 1
                a, b = b, r
            else:
                ans += 2
                a, b = r - 1, r

        return ans