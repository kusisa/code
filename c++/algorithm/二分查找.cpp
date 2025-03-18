#include <iostream>
#include <vector>

using namespace std;

vector<int> arr1{1, 2, 3, 4, 5, 6, 7, 8, 9};
vector<int> arr2{1, 2, 3, 4, 5, 6, 7, 8, 9};
//���ֲ���ֻ�ܲ������������ 
// ����ұ�
int binarysearch1(vector<int>& a1, int size, int target) {
    int lef = 0, rig = size - 1;
    while (lef <= rig) {
        // ��ѭ���ڲ����� mid
        int mid = lef + (rig - lef) / 2;//rig��lef�ܴ�ʱ�����Ա������ 
        if (a1[mid] > target) {
            rig = mid - 1;
        } else if (a1[mid] < target) {
            lef = mid + 1;
        } else {
            return mid;//targetֵ�������е��±� 
        }
    }
    return -1;
}

// ����ҿ�
int binarysearch2(vector<int>& a2, int size, int target) {
    int lef = 0, rig = size;
    while (lef < rig) {
        // ��ѭ���ڲ����� mid
        int mid = lef + (rig - lef) / 2;
        if (a2[mid] > target) {
            rig = mid;
        } else if (a2[mid] < target) {
            lef = mid + 1;
        } else {
            return mid;
        }
    }
    return -1;
}

int main() {
    int a = binarysearch1(arr1, arr1.size(), 4);
    if (a >= 0) {
        cout << a << endl;
    } else {
        cout << "Not found" << endl;
    }

    int b = binarysearch2(arr2, arr2.size(), 5);
    if (b >= 0) {
        cout << b << endl;
    } else {
        cout << "Not found" << endl;
    }

    return 0;
}
