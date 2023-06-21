#include <string>
#include <fstream>
#include <iostream>
#include <map>
#include <vector>
#include <bitset>

using std::string, std::ifstream, std::ofstream, std::cerr, std::cout,
    std::ios, std::map, std::swap, std::vector, std::stoi, std::bitset;

const int MAX_BYTE_VALUE = 256;

struct HuffmanNode
{
    short int left, right;
};

struct HeapNode
{
    short int idx;
    int weight;
};

int left_child(int i)
{
    return 2 * i + 1;
}

HeapNode *build_min_heap(HeapNode *heap, int &n)
{
    for (int i = n / 2 - 1; i >= 0; i--)
    {
        int parent = i;

        while (left_child(parent) < n)
        {
            int k = left_child(parent);
            int right = k + 1;

            if (right < n && heap[right].weight < heap[k].weight)
                k++;

            if (heap[k].weight < heap[parent].weight)
            {
                swap(heap[k], heap[parent]);
                parent = k;
            }
            else
                break;
        }
    }

    return heap;
}

HeapNode remove_min(HeapNode *heap, int &n)
{
    HeapNode node = heap[0];

    n--;

    swap(heap[0], heap[n]);
    if (n != 0)
        build_min_heap(heap, n);

    return node;
}

void build_encoding_table(const HuffmanNode *huffman_tree, const string &code, int node_idx, map<unsigned char, string> &encoding_table, int n)
{
    if (node_idx < 0)
        return;

    if (node_idx < n)
        encoding_table[huffman_tree[node_idx].left] = code;
    else
    {
        build_encoding_table(huffman_tree, code + "0", huffman_tree[node_idx].left, encoding_table, n);
        build_encoding_table(huffman_tree, code + "1", huffman_tree[node_idx].right, encoding_table, n);
    }
}

int main(int argc, char **argv)
{
    (void)argc;

    string flag = argv[1];
    string entry_file_path = argv[2];
    string out_file_path = argv[3];

    ifstream entry_file(entry_file_path.data(), ios::binary);
    ofstream out_file(out_file_path, ios::out | ios::binary);

    if (not entry_file.is_open())
    {
        cerr << "Error opening file \n";
        return 1;
    }

    entry_file.seekg(0, ios::end);
    if (entry_file.tellg() == 0)
        return 0;
    entry_file.seekg(0, ios::beg);

    if (flag == "-c")
    {
        int ocurrences[MAX_BYTE_VALUE] = {};

        unsigned char byte;
        while (entry_file.read(reinterpret_cast<char *>(&byte), sizeof(byte)))
            ocurrences[byte]++;

        int n = 0;
        for (int i = 0; i < MAX_BYTE_VALUE; i++)
            if (ocurrences[i] > 0)
                n++;

        HuffmanNode *huffman_tree = new HuffmanNode[(2 * n) - 1];

        int j = 0;
        for (int i = 0; i < MAX_BYTE_VALUE; i++)
        {
            if (j == n)
                break;

            if (ocurrences[i] > 0)
            {
                huffman_tree[j].left = i;
                j++;
            }
        }

        int heap_size = n;
        HeapNode *heap = new HeapNode[heap_size];

        for (int i = 0; i < n; i++)
        {
            heap[i].idx = i;
            heap[i].weight = ocurrences[huffman_tree[i].left];
        }

        build_min_heap(heap, heap_size);

        int tree_idx = n;

        while (heap_size > 1)
        {
            HeapNode left = remove_min(heap, heap_size);
            HeapNode right = remove_min(heap, heap_size);

            huffman_tree[tree_idx].left = left.idx;
            huffman_tree[tree_idx].right = right.idx;

            heap[heap_size].weight = left.weight + right.weight;
            heap[heap_size].idx = tree_idx;

            tree_idx++;
            heap_size++;

            build_min_heap(heap, heap_size);
        }

        map<unsigned char, string> encoding_table = {};
        build_encoding_table(huffman_tree, "", (2 * n) - 2, encoding_table, n);

        unsigned char file_byte;
        string code = "", encoded = "";

        entry_file.clear();
        entry_file.seekg(0);

        out_file.write((char *)(&n), sizeof(int));
        out_file.write((char *)huffman_tree, ((2 * n) - 1) * sizeof(HuffmanNode));

        while (entry_file.read((char *)&file_byte, sizeof(file_byte)))
        {
            encoded += encoding_table[file_byte];

            while (encoded.length() > 8)
            {
                code += (char)stoi(encoded.substr(0, 8), nullptr, 2);
                encoded = encoded.substr(8);
            }
        }

        int count = 8 - encoded.length();
        if (encoded.length() < 8)
            encoded.append(count, '0');

        code += (char)stoi(encoded, nullptr, 2);
        code += (char)count;

        out_file.write(code.c_str(), code.size());

        delete[] huffman_tree;
        delete[] heap;
    }

    if (flag == "-d")
    {
        int tree_size;
        entry_file.read(reinterpret_cast<char *>(&tree_size), sizeof(int));

        if (tree_size == 0)
            return 1;

        HuffmanNode *huffman_tree = new HuffmanNode[(2 * tree_size) - 1];

        for (int i = 0; i < (2 * tree_size) - 1; i++)
            entry_file.read(reinterpret_cast<char *>(&huffman_tree[i]), sizeof(HuffmanNode));

        char byte;
        vector<unsigned char> text;
        while (entry_file.read(reinterpret_cast<char *>(&byte), sizeof(byte)))
            text.push_back(byte);

        int count = text.back();
        text.pop_back();

        string code = "";
        for (vector<unsigned char>::size_type i = 0; i < text.size() - 1; i++)
            code += bitset<8>(text[i]).to_string();

        code += bitset<8>(text[text.size() - 1]).to_string().substr(0, 8 - count);

        int tree_node = 2 * tree_size - 2;
        string decoded = "";
        for (auto &ch : code)
        {
            if (ch == '0')
                tree_node = huffman_tree[tree_node].left;
            else
                tree_node = huffman_tree[tree_node].right;

            if (tree_node < tree_size)
            {
                decoded += (char)huffman_tree[tree_node].left;
                tree_node = 2 * tree_size - 2;
            }
        }

        out_file << decoded;
        out_file.close();
    }

    return 0;
}