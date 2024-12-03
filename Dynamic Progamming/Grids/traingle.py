from typing import List

class Solution:
    def minPathSumRecursion(self,triangle : List[List[int]]) -> int:

        def recursion(r:int,c:int) -> int:
            value = triangle[r][c]
            if r == len(triangle) - 1:
                return value
            
            one = recursion(r+1,c)
            two = recursion(r+1,c+1)

            return value + min(one,two)

        return recursion(0,0)

    def minPathSumMemoization(self,triangle : List[List[int]]) -> int:
        dp = [[-1]*len(triangle) for _ in range(len(triangle))]
        
        def recursion(r:int,c:int) -> int:
            value = triangle[r][c]
            if r == len(triangle) - 1:
                dp[r][c] = value
                return value
            
            if dp[r+1][c] != -1:
                one = dp[r+1][c]
            else:
                one = recursion(r+1,c)

            if dp[r+1][c+1] != -1:
                two = dp[r+1][c+1]
            else:
                two = recursion(r+1,c+1)

            dp[r][c] = value + min(one,two)
            return value + min(one,two)
        
        return recursion(0,0)

    def minPathSumTabulation(self,triangle : List[List[int]]) -> int:
        dp = [[0]*len(triangle) for _ in range(len(triangle))]

        dp[-1] = triangle[-1]
        i = len(triangle) - 2
        while i >= 0:
            for j in range(i+1):
                dp[i][j] = triangle[i][j] + min(dp[i+1][j],dp[i+1][j+1])
            # print(dp)
            i -= 1

        return dp[0][0]
        

    def minPathSumSpaceOptimization(self,triangle : List[List[int]]) -> int:
        dp = triangle[-1]
        i = len(triangle) - 2
        while i >= 0:
            for j in range(i+1):
                dp[j] = triangle[i][j] + min(dp[j],dp[j+1])
            
            i -= 1

        return dp[0]

ob = Solution()
triangle = [[10]]
triangle = [[10],[2,-5]]
triangle = [[2],[3,4],[6,5,7],[4,1,8,3]]
print(ob.minPathSumRecursion(triangle))
print(ob.minPathSumMemoization(triangle))
print(ob.minPathSumTabulation(triangle))
print(ob.minPathSumSpaceOptimization(triangle))