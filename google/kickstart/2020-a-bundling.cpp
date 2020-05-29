// C++ implementation of search and insert 
// operations on Trie 
#include <bits/stdc++.h> 
using namespace std; 
  
const int ALPHABET_SIZE = 26; 
  
// trie node 
struct TrieNode 
{ 
    struct TrieNode *children[ALPHABET_SIZE]; 
  
    // isEndOfWord is true if the node represents 
    // end of a word 
    int peso;
    bool isEndOfWord; 
}; 
  
// Returns new trie node (initialized to NULLs) 
struct TrieNode *getNode(void) 
{ 
    struct TrieNode *pNode =  new TrieNode; 
  
    pNode->isEndOfWord = false;
    pNode->peso = 1; 
  
    for (int i = 0; i < ALPHABET_SIZE; i++) 
        pNode->children[i] = NULL;
  
    return pNode; 
} 
  
// If not present, inserts key into trie 
// If the key is prefix of trie node, just 
// marks leaf node 
void insert(struct TrieNode *root, string key) 
{ 
    struct TrieNode *pCrawl = root; 
  
    for (int i = 0; i < key.length(); i++) 
    { 
        int index = key[i] - 'A'; 
        if (!pCrawl->children[index]) {
            pCrawl->children[index] = getNode();
        }
        else {
            pCrawl->children[index]->peso++;
        }
            
  
        pCrawl = pCrawl->children[index]; 
    } 
  
    // mark last node as leaf 
    pCrawl->isEndOfWord = true; 
} 
  
// Returns true if key presents in trie, else 
// false 
struct TrieNode* search(struct TrieNode *root, string key) 
{ 
    struct TrieNode *pCrawl = root; 
  
    for (int i = 0; i < key.length(); i++) 
    { 
        int index = key[i] - 'A'; 
        if (!pCrawl->children[index]) 
            return NULL; 
  
        pCrawl = pCrawl->children[index]; 
    } 
  
    return pCrawl;
} 

int DFS(TrieNode *pCrawl, int counter, int k, int max_w) {
    int puntos_fin = counter * (pCrawl->peso/k);
    int puntos = 0, flag = 0;
    for(int i=0; i < ALPHABET_SIZE; i++) {

        if(!pCrawl->children[i] || pCrawl->children[i]->peso < k) continue;
        if(max_w == -1) {
             max_w = pCrawl->children[i]->peso;
        }
        if(max_w - pCrawl->children[i]->peso >= k) {
            puntos = counter;
            max_w = pCrawl->children[i]->peso;
        }
        flag = 1;
        puntos += DFS(pCrawl->children[i], ++counter, k, max_w);

    }
     
    if (flag == 0) {
        return puntos_fin;
    }
    
    return puntos;
}

int main() {
    int t, n, k;
    cin >> t;
    struct TrieNode *root = getNode();
    string key;
    vector<string> keys;

    for(int i=0; i<t; i++) {
        cin >> n >> k;
        cin.ignore();
        for(int j=0; j<n; j++) {
            getline(cin, key);
            insert(root, key);
        }
        cout << "Case #" << i+1 << ": " << DFS(root, 0, k, -1) << endl;
    }
    return 0;
}

/*
// Driver 
int main() 
{ 
    // Input keys (use only 'a' through 'z' 
    // and lower case) 
    string keys[] = {"the", "a", "there", 
                    "answer", "any", "by", 
                     "bye", "their" }; 
    int n = sizeof(keys)/sizeof(keys[0]); 
  
    struct TrieNode *root = getNode();
    struct TrieNode *aux; 
  
    // Construct trie 
    for (int i = 0; i < n; i++) 
        insert(root, keys[i]); 
  
    aux = search(root, "the");
    if(!aux) {
        cout << "NOT FOUND" << endl;
    }
    else {
        cout << aux->peso << endl;
    }
    
    return 0; 
} */