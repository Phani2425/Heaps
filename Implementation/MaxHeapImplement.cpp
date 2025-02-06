// here we will implement max heap using array

// before moving forward just think that why even we took array for creating a tree like structure??? can we do it using normal nodes [left,data,right] as we were implemnting the binarry tree, bst and AVL tree using them

// what are the two constarinbts you faced while implementing it using nodes and how array solved them seamlessly??

#include <bits/stdc++.h>
using namespace std;

class MaxHeap
{
public:
    int *arr;
    int size;
    int total_size;

    MaxHeap(int n)
    {
        arr = new int[n];
        size = 0;
        total_size = n;
    }

    void Insert(int val)
    {

        if (size == total_size)
        {
            cout << "Heap overflowed" << endl;
            return;
        }

        arr[size] = val;
        int index = size;
        size++;

        while (index > 0 && arr[index] > arr[(index - 1) / 2])
        {
            swap(arr[index], arr[(index - 1) / 2]);
            index = (index - 1) / 2;
        }

        cout << val << " got inserted in the maxHeap" << endl;
    }

    // function for step down heapify
    void heapify(int index)
    {

        int largest = index;
        int left = 2 * index + 1;
        int right = 2 * index + 2;

        // I WAS MAKING A MISTAKE HERE AS I WAS COMPARING THE ARR[LEFT] WITH THE ARR[INDEX]
        // EMITI LEFT SAHA KALE TA CHALIJIBA AS JADI LEFT RA VALUE INDEX VALUE THU ADHIKA THIBA THEN LARGEST RE LEFT INDEX PALEIASIBA BUT PROBLEM KOUTHU ASIBA KI
        // AME JADI RIGHT SSHS BI INDEX KU COMPARE KARIBA SETEBELE LEFT AU RIGHT BHITARE KIE BADA THILA AMAKKU JANA HNI PADIBANI
        // AMAKU ACTUALY INDEX , LEFT AU RIGHT EI 3 TA BHITARU FIND AKRIBARA THILA BADA KOUTA BUT AME JADI DITA LEFT AU RIGHT KU INDEX SAHA HNI COMPARE KARINABA THEN AMAKU SE CORRECT ANSWER KEBE MILIBANI
        if (left < size && arr[left] > arr[largest])
        {
            largest = left;
        }
        if (right < size && arr[right] > arr[largest])
        {
            largest = right;
        }

        // basically here the largest variable will store the index which contains the largest value among the current index and its both childs
        // and this is needed because with that index only we will swap the value at current index and then also it will get comapred with its further childrens for finding its correct position
        // for which we will use recursion

        // there will be two cases:- either the largest will not get changes means that among the parent and boyth of its child the parent have the highest value
        //  then kuch swap ki jarurat nehi hai so return
        if (largest == index)
        {
            return;
        }
        else
        {
            swap(arr[index], arr[largest]);
            heapify(largest);
        }
    }

    // think that why we took D but not d {it was a keyword that is why}
    void Delete()
    {

        if (size == 0)
        {
            cout << "Max Heap is underflowed" << endl;
            return;
        }

        cout << arr[0] << " got deleted from the maxHeap" << endl;

        arr[0] = arr[size - 1];
        size--;

        // esa ho saktba hai ki sirf ek hi node present ho pure tree me so hame kya karna hai agar ek hib node hai bas then
        //  use hepify kane ki koi jarurat hi nehihai kain na seta ta already ta correct position re achi au kn haba

        //  so simply return

        if (size == 0)
        {
            return;
        }

        heapify(0);
    }

    void print()
    {

        cout << "printing the array :- " << endl;

        for (int i = 0; i < size; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main()
{

    int choice;
    cout << "enter your choice:- " << endl;
    cout << "0. exit" << endl;
    cout << "1. insertion" << endl;
    cout << "2. deletion" << endl;
    cout << "3. print" << endl;

    // creating an object of maxheap class in whihc we will  do everything
    MaxHeap H1(6);

    while (1)
    {
        cout << "enter a choice to proceed:- ";
        cin >> choice;
        switch (choice)
        {

        case 0:
        {
            exit(0);
            break;
        }
        case 1:
        {
            int num;
            cout << "enter numvber to be inserted:- ";
            cin >> num;
            H1.Insert(num);
            break;
        }

        case 2:
        {
            H1.Delete();
            break;
        }

        case 3:
        {
            H1.print();
            break;
        }

        default:
        {
            cout << "invalid choice" << endl;
        }
        }
    }

    return 0;
}
