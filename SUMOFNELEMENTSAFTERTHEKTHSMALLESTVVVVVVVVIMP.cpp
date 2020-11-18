package com.foo;

import java.util.Stack;

/*
Find sum of n elements after kth smallest element in BST.
Tree is very large, you are not allowed to traverse the tree.
 */

public class BST {
    Node root;

    void insert(int data) {
        Node n = new Node(data);
        if (this.root == null) {
            this.root = n;
            return;
        }
        Node curr = this.root;
        while (true) {
            if (data < curr.data) {
                if (curr.left == null) {
                    curr.left = n;
                    return;
                } else {
                    curr = curr.left;
                }
            } else if (data > curr.data) {
                if (curr.right == null) {
                    curr.right = n;
                    return;
                } else {
                    curr = curr.right;
                }
            } else {
                System.out.println("Node already exists.");
                return;
            }
        }
    }

    int sumOfNElemsAfterKthSmallest(int k, int n) {
        Stack<Node> stack = new Stack<>();
        Node curr = this.root;
        while (curr != null) {
            stack.push(curr);
            curr = curr.left;
        }

        // find k-th smallest node.
        int count = k;
        Node node;
        while (count > 0) {
            node = stack.pop();
            count--;
            if (node.right != null) {
                curr = node.right;
                while (curr != null) {
                    stack.push(curr);
                    curr = curr.left;
                }
            }
        }

        // curr is the k-th smallest node.

        // sum numbers n times.
        count = n;
        int sum = 0;
        while (count > 0) {
            node = stack.pop();
            sum += node.data;
            count--;
            if (node.right != null) {
                curr = node.right;
                while (curr != null) {
                    stack.push(curr);
                    curr = curr.left;
                }
            }
        }

        return sum;
    }

    public static void main(String[] args) {
        BST tree = new BST();
        tree.insert(20);
        tree.insert(15);
        tree.insert(25);
        tree.insert(10);
        tree.insert(18);
        tree.insert(12);
        tree.insert(17);
        tree.insert(19);

        System.out.println(tree.root);
        System.out.println();
        System.out.println(tree.sumOfNElemsAfterKthSmallest(1,1));
        System.out.println(tree.sumOfNElemsAfterKthSmallest(1,2));
        System.out.println(tree.sumOfNElemsAfterKthSmallest(1,3));
        System.out.println();
        System.out.println(tree.sumOfNElemsAfterKthSmallest(2,1));
        System.out.println(tree.sumOfNElemsAfterKthSmallest(2,2));
        System.out.println(tree.sumOfNElemsAfterKthSmallest(2,3));
        System.out.println();
        System.out.println(tree.sumOfNElemsAfterKthSmallest(3,1));
        System.out.println(tree.sumOfNElemsAfterKthSmallest(3,2));
        System.out.println(tree.sumOfNElemsAfterKthSmallest(3,3));
    }

    class Node {
        int data;
        Node left, right;

        Node(int data) {
            this.data = data;
        }

        @Override
        public String toString() {
            StringBuilder sb = new StringBuilder();
            if (this.left != null) {
                sb.append(this.left.toString()).append(" ");
            }
            sb.append(this.data);
            if (this.right != null) {
                sb.append(" ").append(this.right.toString());
            }
            return sb.toString();
        }
    }
}