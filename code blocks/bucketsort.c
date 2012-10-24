#include < iostream >
using namespace std;
#define m 10
void bucketsort (int *a, int n)
{
        int buckets [m];

        for (int j=0; j < m; ++j)
                buckets[j]=0;
        for (int i=0; i < n; ++i)
                ++buckets[a[i]];
        for (int i=0, j=0; j < m; ++j)
                for (int k=buckets[j]; k > 0; --k)
                        a[i++]=j;

}
int main ()
{
        int n;
        int *a;
        cout << "Please insert the number of elements to be sorted: ";
        cin >> n;       // The total number of elements
        a = (int *)calloc(n, sizeof(int));
        cout << "nThe elements must be lower than the value of m = " << m << endl;
        for(int i=0;i< n;i++)
        {

                cout << "Input " << i << " element: ";
                cin >>a[i]; // Adding the elements to the array
        }
        cout << "Unsorted list:" << endl;       // Displaying the unsorted array
        for(int i=0;i< n;i++)
        {
                cout << a[i] << " ";
        }

        bucketsort(a,n);
        cout << "nSorted list:" << endl;        // Display the sorted array
        for(int i=0;i < n;i++)
        {
                cout << a[i] << " ";
        }
        return 0;
}
