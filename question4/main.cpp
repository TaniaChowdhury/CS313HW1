//question number : 4
//assigned to Tania Chowdhury
//GROUP number : 01
//team members name : Brown,Jacob A
//Chowdhury,Tamzid
//Chowdhury,Tania
//Cortes,Victoria Danyel
//Deciutiis II,James Hugo
//

#include <iostream>
#include <ctime>
#include <chrono>
using namespace std;

struct Node {
    int data;
    Node* next = nullptr;
};

/* Function to sort the list */
void LLBubbleSort(struct Node** head, int n)
{
    Node** h;
    for (int i = 0; i < n; i++) {//looping through the linked list
        h = head;
        for (int j = 0; j < n - i - 1; j++) {
            Node* p1 = *h;
            Node* p2 = p1->next;
            if (p1->data > p2->data) {
                //swapping nodes
                Node* tmp = p2->next;
                p2->next = p1;
                p1->next = tmp;
                //updating link
                *h = p2;
            }
            h = &(*h)->next;
        }
    }
}


//function to implement bubble sort
void arrayBubbleSort(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++) {
        // Last i elements are already in place
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                //swapping
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}
int main() {
    srand(time(0));
    int n = 0;
    while (n < 1) {
        cout << "Enter Size: ";
        cin >> n;
    }
    int *arr = new int[n];
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 1000;//generating random numbers
    }
    Node* link = new Node();
    Node* head = link;
    for (int i = 0; i < n - 1; i++) {
        link->data = arr[i];
        link->next = new Node();
        link = link->next;
    }
    if (n) {
        link->data = arr[n - 1];
    }
    for (int i = 0; i < n; i++) {
        cout << arr[i] << ' ';
    }
    cout << endl;
    cout << "Time to sort Random Number array using bubble sort: ";
    //measuring time using std::chrono::high_resolution_clock
    auto t1 = std::chrono::high_resolution_clock::now();
    arrayBubbleSort(arr, n);
    auto t2 = std::chrono::high_resolution_clock::now();
    std::cout << chrono::duration_cast<chrono::microseconds>(t2 - t1).count() * 1000 << " ns\n";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << ' ';
    }
    cout << endl;
    cout << "Time to sort LL using bubble sort: ";
    t1 = std::chrono::high_resolution_clock::now();
    LLBubbleSort(&head, n);
    t2 = chrono::high_resolution_clock::now();
    std::cout << std::chrono::duration_cast<chrono::microseconds>(t2 - t1).count() * 1000 << " ns\n";
    while (head) {
        cout << head->data << ' ';
        head = head->next;
    }
    cout << endl;
    return 0;
}
