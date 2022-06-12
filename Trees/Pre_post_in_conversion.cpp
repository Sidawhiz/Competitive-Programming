#include <iostream>
using namespace std;
 
// A utility function to search x in arr[] of size n
int search(int arr[], int x, int n)
{
    for (int i = 0; i < n; i++)
        if (arr[i] == x)
            return i;
    return -1;
}

// Preorder - root left right
// Inorder - left root right
// Postorder - left right root
 
// Prints postorder traversal from given inorder and preorder traversals
void printPostOrder(int in[], int pre[], int n)
{
    // The first element in pre[] is always root, search it
    // in in[] to find left and right subtrees
    int root = search(in, pre[0], n);
 
    // If left subtree is not empty, print left subtree
    if (root != 0)
        printPostOrder(in, pre + 1, root);
 
    // If right subtree is not empty, print right subtree
    if (root != n - 1)
        printPostOrder(in + root + 1, pre + root + 1, n - root - 1);
 
    // Print root
    cout << pre[0] << " ";
}
 
// Driver program to test above functions

void printPreOrder(int in[], int pos[], int n)
{
    // The first element in pre[] is always root, search it
    // in in[] to find left and right subtrees
    int root = search(in, pos[n-1], n);

    // Print root
    cout << pos[n-1] << " ";
 
    // If left subtree is not empty, print left subtree
    if (root != 0)
        printPreOrder(in, pos, root);
 
    // If right subtree is not empty, print right subtree
    if (root != n - 1)
        printPreOrder(in + root + 1, pos + root, n - root - 1);
 
}

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    int in[] = { 4, 2, 5, 1, 3, 6 };
    int pre[] = { 1, 2, 4, 5, 3, 6 };
    int pos[] = { 4, 5, 2, 6, 3, 1 };
    int n = sizeof(in) / sizeof(in[0]);
    cout << "Postorder traversal " << endl;
    printPostOrder(in, pre, n);
    cout << "\nPreorder traversal " << endl;
    printPreOrder(in, pos, n);
    return 0;
}

