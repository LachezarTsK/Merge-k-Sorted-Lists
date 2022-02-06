
function ListNode(val, next) {
    this.val = (val === undefined ? 0 : val);
    this.next = (next === undefined ? null : next);
}

const {PriorityQueue} = require('@datastructures-js/priority-queue');

/**
 * @param {ListNode[]} lists
 * @return {ListNode}
 */
var mergeKLists = function (lists) {

    if (lists.length === 0) {
        return null;
    }

    const minHeap = new MinPriorityQueue({compare: (x, y) => x.val - y.val});
    for (let node of lists) {
        if (node !== null) {
            minHeap.enqueue(node);
        }
    }

    if (minHeap.isEmpty()) {
        return null;
    }

    let current = new ListNode();
    let head = current;

    while (!minHeap.isEmpty()) {
        
        let node = minHeap.dequeue();
        current.next = node;
        current = current.next;
        
        if (node.next !== null) {
            minHeap.enqueue(node.next);
        }
    }
    return head.next;
};
