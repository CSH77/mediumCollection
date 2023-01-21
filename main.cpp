#include <iostream>
#include <set>
#include <vector>
#include <map>
#include <queue>
#include <stack>
#include <unordered_map>

using namespace std;


vector<int> sorted;

void merge(vector<int>& vec, int left, int mid, int right)
{
    int i, j, k, l;
    i = left;
    j = mid + 1;
    k = left;

    while(i<=mid && j<=right)
    {
        if(vec[i] <= vec[j])
            sorted[k++] = vec[i++];
        else
            sorted[k++] = vec[j++];
    }

    // 남아 있는 값들을 일괄 복사
    if(i <= mid)
    {
        for(l=i; l<=mid; l++)
            sorted[k++] = vec[l];
    }
    // 남아 있는 값들을 일괄 복사
    else
    {
        for(l=j; l<=right; l++)
            sorted[k++] = vec[l];
    }

    // 배열 sorted[](임시 배열)의 리스트를 배열 list[]로 재복사
    for(l=left; l<=right; l++)
        vec[l] = sorted[l];
}


void mergeSort(vector<int>& vec, int left, int right)
{
    if(left < right)
    {
        int mid = (left + right) / 2;
        mergeSort(vec, left, mid);
        mergeSort(vec, mid + 1 , right);
        merge(vec, left, mid, right);
    }
}

int main()
{

    vector<int> input = {5,8,7,6,4,3,1,10};

    sorted.resize(input.size(), 0);

    mergeSort(input, 0, input.size());
    // for(auto item : answer)
    //     cout << item << ", ";

    for(auto item : sorted)
        cout << item << ", ";
    cout << endl;


    return 0;
}



