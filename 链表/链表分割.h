class Partition {
public:
    ListNode* partition(ListNode* pHead, int x)
    {
        if(pHead == nullptr || pHead->next == nullptr)
            return pHead;
        ListNode* DummyHead = (ListNode*)malloc(sizeof(ListNode));
        ListNode* prev = DummyHead;
        ListNode* cur = pHead;
        ListNode* pMove = DummyHead;
        while(cur)
        {
            if(cur->val < x)
            {
                pMove->next = cur;
                pMove = cur;
                if(cur != pHead)
                {
                    prev->next = cur->next;
                    cur = cur->next;
                    
                }
                else//cur == pHead
                {
                    prev = pHead;
                    pHead = pHead->next;
                    cur = pHead;
                }
            }
            else//cur->val > x
            {
                prev = cur;
                cur = cur->next;
            }
        }
        pMove->next = pHead;
        return DummyHead->next;
    }
};


//2个头结点的（比较简单）

// class Partition {
// public:
//     ListNode* partition(ListNode* pHead, int x) {
//         // write code here
//         if(pHead==nullptr)
//             return nullptr;
//         ListNode *smallHead=new ListNode(0);
//         ListNode *bigHead=new ListNode(0);
//         ListNode *small=smallHead;
//         ListNode *big=bigHead;
//         while(pHead){
//             if(pHead->val<x){
//                 small->next=pHead;
//                 small=small->next;
//             }
//             else{
//                 big->next=pHead;
//                 big=big->next;
//             }
//             pHead=pHead->next;
//         }
//         big->next=nullptr;
//         small->next=bigHead->next;
//         return smallHead->next;
//     }
// };