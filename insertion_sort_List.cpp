#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* insertionSortList(ListNode* head) {
    ListNode* dummy = new ListNode(-1);

    while (head) {
        ListNode* next = head->next;
        ListNode* temp = dummy;

        while (temp->next && temp->next->val < head->val)
            temp = temp->next;

        head->next = temp->next;
        temp->next = head;
        head = next;
    }

    return dummy->next;
}

void printList(ListNode* head) {
    while (head) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    // Example list: 4 -> 2 -> 1 -> 3
    ListNode* list = new ListNode(4, new ListNode(2, new ListNode(1, new ListNode(3))));

    ListNode* sorted = insertionSortList(list);
    printList(sorted);
    return 0;
}
