class Solution {
    func findDuplicate(nums: [Int]) -> Int {
        var slow = nums[0]
        var fast = nums[nums[0]]
        while(slow != fast){
            slow = nums[slow]
            fast = nums[nums[fast]]
        }
        fast = nums[0]
        slow = nums[slow]
        while(slow != fast){
            slow = nums[slow]
            fast = nums[fast]
        }
        return fast
    }
}
