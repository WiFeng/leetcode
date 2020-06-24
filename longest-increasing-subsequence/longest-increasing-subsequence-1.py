class Solution(object):
    def findNumberOfLIS(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        
        numsSize = len(nums)

        if numsSize <= 1:
            return numsSize
        
        lengths = [0] * numsSize
        counts = [0] * numsSize

        for i, num in enumerate(nums):
            lengths[i] = 1
            counts[i] = 1
            for j in xrange(i):
                if nums[i] <= nums[j]:
                    continue
                if lengths[j] >= lengths[i]:
                    lengths[i] = lengths[j] + 1
                    counts[i] = counts[j]
                elif lengths[j] + 1 == lengths[i]:
                    counts[i] += counts[j]

        result = 0
        longest = max(lengths)

        for i in xrange(numsSize):
            if lengths[i] == longest:
                result += counts[i]

        return result

