#include<iostream>
using namespace std;

/* Question is to find kth smallest element in matrix which is row and column wise sorted.
The idea is to use min heap. Following are detailed step.
1) Build a min heap of elements from first row. A heap entry also stores row number and column number.
2) Do following k times.
…a) Get minimum element (or root) from min heap.
…b) Find row number and column number of the minimum element.
…c) Replace root with the next element from same column and min-heapify the root.
3) Return the last extracted root.
*/

struct HeapNode{
int val;
int r;
int c;
};

void swap(HeapNode*x,HeapNode*y){
HeapNode temp = *x;
*x=*y;
*y=temp;
}

void minHeapify(HeapNode a[],int index,int n)
{
int left = 2*index+1;
int right = left+1;
int smallest = index;

if(left<n&&(a[left].val<a[index].val))
        smallest=left;
if(right<n&&a[right].val<a[smallest].val)
    smallest=right;
if(smallest!=index){
    swap(a[index],a[smallest]);
    minHeapify(a,smallest,n);
    }
}


void buildMinHeap(HeapNode harr[],int n){
for(int i=(n-1)/2;i>=0;i--){
    minHeapify(harr,i,n);
    }
}

int kthSmallest(int arr[4][4],int n,int k)
{
    if(k<0||k>n*n)
        return -1;

    HeapNode harr[n];
    for(int i=0;i<n;i++){
        harr[i]={arr[0][i],0,i};
    }
    buildMinHeap(harr,n);

    HeapNode root;
    //Extract the root node k times
    for(int i=0;i<k;i++){
        root = harr[0];

        int nextValue;
        if(root.r<n-1){
            nextValue = arr[root.r+1][root.c];
        }
        harr[0]={nextValue,root.r + 1,root.c};
        minHeapify(harr,0,n);
    }

    return root.val;
}

int main()
{
  int mat[4][4] = { {10, 20, 30, 40},
                    {15, 25, 35, 45},
                    {25, 29, 37, 48},
                    {32, 33, 39, 50},
                  };
  cout << "7th smallest element is " << kthSmallest(mat, 4, 7);
  return 0;
}
