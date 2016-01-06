#include<bits/stdc++.h>
#include<math.h>
#define ll long long int
#define R 5
#define C 4
using namespace std;
bool isValid(int i,int j){
    if(i>=0 and i<R and j>=0 and j<C){
        return 1;
    }
    return 0;
}
int getMaxCollectionUtil(int arr[R][C],int leftX,int leftY,int rightX,int rightY){
    if(leftX == R-1 and leftY == 0 and rightX == R-1 and rightY == C-1){
        return arr[leftX][leftY]+arr[rightX][rightY];
    }
    if((leftX == R-1 or rightX == R-1) and (leftY != 0  or rightY != C-1)){
        return INT_MIN;
    }
    int sum = 0;
    if(rightY == leftY){
        sum = sum + arr[leftX][leftY];
    }else{
        sum = sum +arr[rightX][rightY]+ arr[leftX][leftY];
    }
    int maximum = INT_MIN;
    //case 1
    int leftX_new = leftX+1;
    int leftY_new = leftY-1;
    int rightX_new = rightX+1;
    int rightY_new = rightY-1;
        if(isValid(leftX_new , leftY_new) and isValid(rightX_new,rightY_new)){
            int dummy = getMaxCollectionUtil(arr,leftX_new,leftY_new,rightX_new,rightY_new);
            if(dummy>=maximum){
                maximum = dummy;
            }
        }
        //case 2
     leftX_new = leftX+1;
         leftY_new = leftY-1;
         rightX_new = rightX+1;
         rightY_new = rightY+1;
        if(isValid(leftX_new , leftY_new) and isValid(rightX_new,rightY_new)){
            int dummy = getMaxCollectionUtil(arr,leftX_new,leftY_new,rightX_new,rightY_new);
            if(dummy>=maximum){
                maximum = dummy;
            }
        }
        //case 3
        leftX_new = leftX+1;
         leftY_new = leftY;
         rightX_new = rightX+1;
         rightY_new = rightY-1;
        if(isValid(leftX_new , leftY_new) and isValid(rightX_new,rightY_new)){
            int dummy = getMaxCollectionUtil(arr,leftX_new,leftY_new,rightX_new,rightY_new);
            if(dummy>=maximum){
                maximum = dummy;
            }
        }
        //case 4
        leftX_new = leftX+1;
         leftY_new = leftY;
         rightX_new = rightX+1;
         rightY_new = rightY+1;
        if(isValid(leftX_new , leftY_new) and isValid(rightX_new,rightY_new)){
            int dummy = getMaxCollectionUtil(arr,leftX_new,leftY_new,rightX_new,rightY_new);
            if(dummy>=maximum){
                maximum = dummy;
            }
        }
        //case 5
        leftX_new = leftX+1;
         leftY_new = leftY+1;
         rightX_new = rightX+1;
         rightY_new = rightY-1;
        if(isValid(leftX_new , leftY_new) and isValid(rightX_new,rightY_new)){
            int dummy = getMaxCollectionUtil(arr,leftX_new,leftY_new,rightX_new,rightY_new);
            if(dummy>=maximum){
                maximum = dummy;
            }
        }
        //case 6
        leftX_new = leftX+1;
         leftY_new = leftY+1;
         rightX_new = rightX+1;
         rightY_new = rightY+1;
        if(isValid(leftX_new , leftY_new) and isValid(rightX_new,rightY_new)){
            int dummy = getMaxCollectionUtil(arr,leftX_new,leftY_new,rightX_new,rightY_new);
            if(dummy>=maximum){
                maximum = dummy;
            }
        }
        sum+=maximum;
        return sum;
}

int getMaxCollection(int arr[R][C]){
    int leftX = 0;
    int leftY = 0;
    int rightX = 0;
    int rightY = C-1;
    int sum = 0;
    sum+=arr[leftX][leftY];
    sum+=arr[rightX][rightY];
    int maximum = INT_MIN;
    //case 1
        int leftX_new = leftX+1;
        int leftY_new = leftY;
        int rightX_new = rightX+1;
        int rightY_new = rightY;
        if(isValid(leftX_new , leftY_new) and isValid(rightX_new,rightY_new)){
            int dummy = getMaxCollectionUtil(arr,leftX_new,leftY_new,rightX_new,rightY_new);
            if(dummy>=maximum){
                maximum = dummy;
            }
        }
        //case 2
        leftX_new = leftX+1;
         leftY_new = leftY;
         rightX_new = rightX+1;
         rightY_new = rightY-1;
        if(isValid(leftX_new , leftY_new) and isValid(rightX_new,rightY_new)){
            int dummy = getMaxCollectionUtil(arr,leftX_new,leftY_new,rightX_new,rightY_new);
            if(dummy>=maximum){
                maximum = dummy;
            }
        }
        //case 3
        leftX_new = leftX+1;
         leftY_new = leftY+1;
         rightX_new = rightX+1;
         rightY_new = rightY;
        if(isValid(leftX_new , leftY_new) and isValid(rightX_new,rightY_new)){
            int dummy = getMaxCollectionUtil(arr,leftX_new,leftY_new,rightX_new,rightY_new);
            if(dummy>=maximum){
                maximum = dummy;
            }
        }
        //case 4
        leftX_new = leftX+1;
         leftY_new = leftY+1;
         rightX_new = rightX+1;
         rightY_new = rightY-1;
        if(isValid(leftX_new , leftY_new) and isValid(rightX_new,rightY_new)){
            int dummy = getMaxCollectionUtil(arr,leftX_new,leftY_new,rightX_new,rightY_new);
            if(dummy>=maximum){
                maximum = dummy;
            }
        }
        //Still need to write 3 cases
    sum+=maximum;
    return sum;
}
int main(){
    ios_base::sync_with_stdio(false);
    int arr[R][C] = {{3, 6, 8, 2},
                     {5, 2, 4, 3},
                     {1, 1, 20, 10},
                     {1, 1, 20, 10},
                     {1, 1, 20, 10},
                    };
    cout << "Maximum collection is " << getMaxCollection(arr);

    return 0;
}

