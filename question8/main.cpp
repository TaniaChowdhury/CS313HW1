//question number : 8
//assigned to Tania Chowdhury
//GROUP number : 01
//team members name : Brown,Jacob A
//Chowdhury,Tamzid
//Chowdhury,Tania
//Cortes,Victoria Danyel
//Deciutiis II,James Hugo
//

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
template<typename T>
class SumCombinaton
{
public:
    // Function to find all combination
    // of the given elements
    void findAllCombinations(vector<T> arr, int sum) {
        // Sort the given elements
        sort(arr.begin(), arr.end());
        // To store combination
        vector<T> local;
        bool find = false;
        uniqueCombination(0, 0, sum, local, arr, find);
        if (find == false) {
            cout << "NO COMBINATION FOUND";
        }
    }
private:
    void uniqueCombination(int x, T sum, T y, vector<T>& local, vector<T>& arr, bool& find)
    {
        // If arr unique combination is found
        if (sum == y) {
            cout << "{";
            for (int i = 0; i < local.size(); i++) {
                if (i != 0)
                    cout << " ";
                cout << local[i];
                if (i != local.size() - 1)
                    cout << ", ";
            }
            cout << "}" << endl;
            if (find == false) {
                find = true;
            }
        }
        // For all other combinations
        for (int i = x; i < arr.size(); i++) {
            // Check if the sum exceeds y
            if (sum + arr[i] > y)
                continue;
            // Check if it is repeated or not
            if (i and arr[i] == arr[i - 1] and i > x)
                continue;
            // Take the element into the combination
            local.push_back(arr[i]);
            // Recursive call
            uniqueCombination(i + 1, sum + arr[i], y, local, arr, find);
            // Remove element from the combination
            local.pop_back();
        }
    }

};
int main()
{
    SumCombinaton<int> comb;
    vector<int> arr;
    int n;
    cout << "Enter size of array: ";
    cin >> n;
    for (int i = 0; i < n; i++) {
        int num;
        cout << "arrr[" << i << "]: ";
        cin >> num;
        arr.push_back(num);
    }
    int sum;
    cout << "Enter Sum: ";
    cin >> sum;
    cout << endl;
    comb.findAllCombinations(arr, sum);
    return 0;
}
