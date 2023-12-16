#include <iostream>

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    void reorderList(ListNode* head) {
        if (!head || !head->next || !head->next->next) {
            return;
        }

        ListNode* slow = head;
        ListNode* fast = head;

        while (fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode* prev = nullptr;
        ListNode* current = slow->next;
        slow->next = nullptr;

        while (current) {
            ListNode* temp = current->next;
            current->next = prev;
            prev = current;
            current = temp;
        }

        ListNode* first = head;
        ListNode* second = prev;

        while (second) {
            ListNode* temp1 = first->next;
            ListNode* temp2 = second->next;

            first->next = second;
            second->next = temp1;

            first = temp1;
            second = temp2;
        }
    }
};

void printList(ListNode* head) {
    ListNode* current = head;
    while (current) {
        std::cout << current->val << " ";
        current = current->next;
    }
    std::cout << std::endl;
}

int main() {
    ListNode* head1 = new ListNode(1);
    head1->next = new ListNode(2);
    head1->next->next = new ListNode(3);
    head1->next->next->next = new ListNode(4);

    Solution solution1;
    solution1.reorderList(head1);
    printList(head1);

    ListNode* head2 = new ListNode(1);
    head2->next = new ListNode(2);
    head2->next->next = new ListNode(3);
    head2->next->next->next = new ListNode(4);
    head2->next->next->next->next = new ListNode(5);

    Solution solution2;
    solution2.reorderList(head2);
    printList(head2);

    return 0;
}
