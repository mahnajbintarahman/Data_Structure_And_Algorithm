#include <iostream> // For cout, cin, etc.
#include <queue>    // For priority_queue (min-heap)
#include <vector>   // For storing characters and frequencies
using namespace std;
// Structure that represents a node in the Huffman Tree
struct Node
{
    char ch;     // The character (A, B, C...)
    int freq;    // Frequency of that character
    Node *left;  // Pointer to left child
    Node *right; // Pointer to right child
    // Constructor to create a new tree node
    Node(char c, int f)
    {
        ch = c;
        freq = f;
        left = right = nullptr; // No children initially
    }
};
// Comparator function for the priority_queue (min-heap)
struct Compare
{
    // Returns true when freq(a) > freq(b) → this makes smallest freq first
    bool operator()(Node *a, Node *b)
    {
        return a->freq > b->freq;
    }
};
// Function to print Huffman Codes by traversing the tree
void printCodes(Node *root, string code)
{
    // Base case: if tree is empty
    if (root == nullptr)
        return;
    // If this is a leaf node, print character and its huffman code
    if (root->left == nullptr && root->right == nullptr)
    {
        cout << root->ch << " : " << code << endl;
    }
    // Traverse left subtree, adding '0' to the code
    printCodes(root->left, code + "0");
    // Traverse right subtree, adding '1' to the code
    printCodes(root->right, code + "1");
}
int main()
{
    // Input characters
    vector<char> chars = {'A',
                          'B',
                          'C',
                          'D',
                          'E',
                          'F'};
    // Corresponding frequencies
    vector<int> freq = {5, 9, 12, 13, 16, 45};
    // Priority queue (min-heap) that keeps smallest frequencies on top
    priority_queue<Node *, vector<Node *>, Compare> pq;
    // Step 1: Create individual leaf nodes and push into priority_queue
    for (int i = 0; i < chars.size(); i++)
    {
        pq.push(new Node(chars[i], freq[i]));
    }
    // Step 2: Build the Huffman Tree
    while (pq.size() > 1)
    {
        // Remove node with smallest frequency
        Node *left = pq.top();
        pq.pop();
        // Remove node with second smallest frequency
        Node *right = pq.top();
        pq.pop();
        // Create a new combined internal node ('-' means no character)
        Node *newNode = new Node('-', left->freq + right->freq);
        // Set the two smallest nodes as children
        newNode->left = left;
        newNode->right = right;
        // Push the new combined node back into the priority queue
        pq.push(newNode);
    }
    // Step 3: The remaining node in pq is the root of the Huffman Tree
    Node *root = pq.top();
    // Step 4: Print all Huffman codes by tree traversal
    cout << "Huffman Codes:\n";
    printCodes(root,
               "");
    return 0; // End of program
}