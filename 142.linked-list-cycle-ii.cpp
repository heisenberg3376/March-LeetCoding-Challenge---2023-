/*
brute force : 
        iterate over the linked list and store every list element in a aux ds
        if it repeats again, then it is the head of the cycle

optimal :
        fast pointer -> initially points to head and moves 2 steps forward
        slow pointer -> initially points to head and moves 1 step forward
        create a bool variable which checks if any cycles are present, initially it is set to false
        we iterate over the list until, fast pointer becomes null or fast->next becomes null
            while(f && f->next){
                s =s->next;
                f = s->next;
                if(s == f){
                    cycle = true
                    break;
                }
            }
        if the slow and fast pointers becomes equal, it means there exists a cycle. So bool variable is set to true
        and break out of the loop
        if no cycles, return NULL
        if cycle is present
            set any one of the fast and slow pointers to head
            and move fast and slow pointers one step each, until both become equal.
            the point where they become equal is the answer


 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        
        ListNode *s = head;
        ListNode *f = head;
        bool cycle = false;
        while(f && f->next){
            s = s->next;
            f = f->next->next;
            if(s == f){
                cycle = true;
                break;
            }
        }
        if(!cycle) return NULL;
        // if cycle is found, shift any one pointer to head and move both pointers by 1 step. the point where s = f , it is thr beginning of cycle
        f = head;
        while(s!=f){
            s = s->next;
            f = f->next;
        }
        return s;
    }
};
// @lc code=end

