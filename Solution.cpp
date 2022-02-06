
#include<queue>
#include<vector>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {

    struct CompareValue {
        bool operator()(ListNode* nodeOne, ListNode* nodeTwo) {
            return nodeOne->val > nodeTwo->val;
        }
    };

public:

    ListNode* mergeKLists(vector<ListNode*>& lists) {

        if (lists.size() == 0) {
            return nullptr;
        }

        priority_queue<ListNode*, vector<ListNode*>, CompareValue> minHeap;
        for (const auto& node : lists) {
            if (node != nullptr) {
                minHeap.push(node);
            }
        }

        if (minHeap.empty()) {
            return nullptr;
        }

        ListNode* current = new ListNode();
        ListNode* head = current;

        while (!minHeap.empty()) {
            
            ListNode* node = minHeap.top();
            minHeap.pop();
            current->next = node;
            current = current->next;
            
            if (node->next != nullptr) {
                minHeap.push(node->next);
            }
        }
        return head->next;
    }
};
