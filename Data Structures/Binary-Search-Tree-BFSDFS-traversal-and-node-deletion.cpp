#include <iostream>
#include <queue>

using namespace std;

class BinaryNode
{
  public:
    BinaryNode(int val)
    {
      data = val;
    }
    ~BinaryNode(){}
    
    BinaryNode* left = nullptr;
    BinaryNode* right = nullptr;
    int data;
};

class BinaryTree
{
  public:
    BinaryTree(){}
    ~BinaryTree(){}
    
    void addData(int data)
    {
      if(!root)
      {
        root = new BinaryNode(data);
        return;
      }
      
      addData(data, root);
    }
    
    void addData(int data, BinaryNode* node)
    {
      if(data <= node->data)
      {
        if(node->left)
        {
          addData(data, node->left); 
        }
        else
        {
          node->left = new BinaryNode(data);
          return;
        }
      }
      else if(data > node->data)
      {
        if(node->right)
        {
          addData(data, node->right); 
        }
        else
        {
          node->right = new BinaryNode(data);
          return;
        }
      }
    }
    
    void BFSTraverse(BinaryNode* node)
    {
      if(!node)
      {
        cout << "Empty tree\n";
      }
      queue<BinaryNode*> binaryQueue;
      cout << node->data << endl;
      if(node->left) binaryQueue.push(node->left);
      if(node->right) binaryQueue.push(node->right);
      
      while(!binaryQueue.empty())
      {
        cout << binaryQueue.front()->data << endl;
        if(binaryQueue.front()->left) binaryQueue.push(binaryQueue.front()->left);
        if(binaryQueue.front()->right) binaryQueue.push(binaryQueue.front()->right);
        binaryQueue.pop();
      }
    }
    
    void InOrderTraverse(BinaryNode* node)
    {
      if(!node)
      {
        if(node == root)
          cout << "Empty tree\n";
        return;
      }
      InOrderTraverse(node->left);
      cout << node->data << endl;
      InOrderTraverse(node->right);
    }
    
    void PreOrderTraverse(BinaryNode* node)
    {
      if(!node)
      {
        if(node == root)
          cout << "Empty tree\n";
        return;
      }
      cout << node->data << endl;
      PreOrderTraverse(node->left);
      PreOrderTraverse(node->right);
    }
    
    void PostOrderTraverse(BinaryNode* node)
    {
      if(!node)
      {
        if(node == root)
          cout << "Empty tree\n";
        return;
      }
      PostOrderTraverse(node->left);
      PostOrderTraverse(node->right);
      cout << node->data << endl;
    }
    
    int getLeafNodes(BinaryNode* node)
    {
      if(!node)
      {
        return 0;
      }
      if(   !node->left
         && !node->right
        )
      {
        return 1;
      }
      
      return (  getLeafNodes(node->left)
              + getLeafNodes(node->right)
             );
    }
    
    void deleteNode(int val)
    {
      if(!root)
      {
        cout << "Empty tree\n";
        return;
      }
      deleteNode(val, root);
    }
    
    void deleteNode(int val, BinaryNode*& node)
    {
      if(val == node->data)
      {
        if(   (!node->left)
           && (!node->right)
          )
        {
          int delVal = node->data;
          delete node;
          node = nullptr;
          cout << delVal << " is deleted" << endl;
          return;
        }
        else if(   !node->left
                && node->right
               )
        {
          BinaryNode* temp = node->right;
          delete node;
          node = temp;
          cout << val << " is deleted" << endl;
          return;
        }
        else if(   !node->right
                && node->left
               )
        {
          BinaryNode* temp = node->left;
          delete node;
          node = temp;
          cout << val << " is deleted" << endl;
          return;
        }
        else
        {
          BinaryNode* maxNode = findMax(node->left);
          node->data = maxNode->data;
          deleteNode(maxNode->data, node->left);
          return;
        }
      }
      else if(val < node->data)
      {
        if(node->left)
          deleteNode(val, node->left);
        else
          cout << val << " is not in this tree" << endl;
      }
      else if(val > node->data)
      {
        if(node->right)
          deleteNode(val, node->right);
        else
          cout << val << " is not in this tree" << endl;
      }
      else
      {
        cout << val << " is not in this tree" << endl;
      }
    }
    
    BinaryNode* findMax(BinaryNode* node)
    {
      BinaryNode* temp = node;
      BinaryNode* prev = nullptr;
      while(temp != nullptr)
      {
        prev = temp;
        temp = temp->right;
      }
      return prev;
    }
    
    BinaryNode* root = nullptr;
};

int main() 
{
  BinaryTree newTree;
  newTree.addData(10);
  newTree.addData(20);
  newTree.addData(1);
  newTree.addData(2);
  newTree.addData(16);
  newTree.addData(11);
  newTree.addData(8);
  newTree.addData(5);
  newTree.addData(18);
  newTree.addData(14);
  newTree.addData(3);
  newTree.addData(4);
  newTree.addData(0);
  newTree.addData(12);
  newTree.addData(13);
  cout << "BFS Traversal\n";
  newTree.BFSTraverse(newTree.root);
  
   cout << "InOrder Traversal\n";
   newTree.InOrderTraverse(newTree.root);
  
  int nLeafNodes = newTree.getLeafNodes(newTree.root);
  cout << "No. of leaf nodes: " << nLeafNodes << endl;
  
  cout << "PreOrder Traversal\n";
  newTree.PreOrderTraverse(newTree.root);
  
  cout << "PostOrder Traversal\n";
  newTree.PostOrderTraverse(newTree.root);
  
  newTree.deleteNode(22);
  newTree.deleteNode(10);
  newTree.deleteNode(16);
  newTree.deleteNode(11);
  
  cout << "InOrder Traversal\n";
   newTree.InOrderTraverse(newTree.root);
  
  newTree.InOrderTraverse(newTree.root);
  
  cout << "Root node : " << newTree.root->data << endl;
}