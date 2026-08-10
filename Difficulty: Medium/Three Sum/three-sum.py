class Solution:
    def triplets(self, arr ):
        n=len(arr)
        s=set()
        arr.sort()
        for i in range(n):
            left=i+1
            right=n-1
            while left<right:
                total=arr[left]+arr[right]+arr[i]
                if total==0:
                    s.add((arr[i],arr[left],arr[right]))
                    left+=1
                    right-=1
                elif total<0:
                    left+=1
                else:
                    right-=1
        return sorted([list(x) for x in s])
        
