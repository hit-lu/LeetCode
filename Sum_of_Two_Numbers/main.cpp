// 2019/8/1 Hash Table
// Problem : Find two numbers of a array(vector) whose sum is target
// Example
// Input:  array - [2, 4, 3, 6]  
//         target - 10
// Output: twoSum - {1, 3}
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

typedef int ElementType;
typedef int Index;

// establish a single linked list
typedef struct LNode* PtrToLNode;
struct LNode
{
    ElementType Data;
    PtrToLNode Next;
};
typedef PtrToLNode List;

// using linked list as hash table elements
typedef struct TableNode* HashTable;
struct TableNode
{
    int TableSize;
    List Heads;
};
const int MaxTableSize = 10000;


class Solution{
    private:
        int TableSize;
        HashTable H;
        int NextPrime(int N)   // find a prime which larger and cloest to number N
        {
            int i, p = (N % 2 == 0) ? N + 1 : N + 2;
            while(p <= MaxTableSize)
            {
                for(i = int(sqrt(p)); i > 2; i --)
                {
                    if(p % i != 0) break;
                }
                if(i == 2)  break; else p = p + 2;
            }
            return p;
        }
    public:
        Solution(int TblSize)
        {
            H = new struct TableNode;
            TableSize = NextPrime(TblSize);

            H->Heads = new struct LNode [TableSize];

            for(int i = 0; i < TableSize; i ++)
            {
                H->Heads[i].Next = NULL;
            }
        }
        ~Solution()    
        {
            List P, Tmp;

            for(int i = 0; i < TableSize; i ++)
            {
                P = H->Heads[i].Next;
                while(P != NULL)
                {
                    Tmp = P->Next;
                    delete P;
                    P = Tmp;
                }
            }
            delete [] H->Heads;     // fully free the address
            delete H;
        }

        int Hash(const ElementType Key)
        {
            return Key % TableSize;
        }
        List Find(ElementType key)
        {
            List P;
            Index Pos;

            Pos = Hash(key);
            P = H->Heads[Pos].Next;
            while(P != NULL && P->Data != key)
            {
                P = P->Next;
            }
            return P;     // return the address of key or Null for not being found
        }
        bool Insert(ElementType key)
        {
            List P, NewCell;
            Index Pos;

            P = Find(key);
            if(P == NULL)   // not find the same element and the key can be inserted
            {
                NewCell = new struct LNode;
                NewCell->Data = key;
                Pos = Hash(key);
                NewCell->Next = H->Heads[Pos].Next;
                H->Heads[Pos].Next = NewCell;
                return true;
            }
            return false;
        }

        bool remove(ElementType key)
        {
            /*add code */
            return true;
        }

        vector<int> twoSum(vector<int>& nums, int target)
        {
            List L;
            for(int i = 0; i < nums.size(); i ++)
            {
                Insert(nums[i]);
                L = Find(target - nums[i]);
                if(L != NULL)
                {
                    // return {nums[i], target - nums[i]};
                }
            }
            return {0,0};
        }
};


int main()
{
    //vector<int> a = {1,2,3,4};
    Solution s(10);
    cout << "ok" << endl;
    return 0;
}
