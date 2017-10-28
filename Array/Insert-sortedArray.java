// Java program to insert an 
// element in a sorted array

class Main
{ 
	// Inserts a key in arr[] of given 
	// capacity. n is current size of arr[]. 
	// This function returns n+1 if insertion
	// is successful, else n.
	//The idea is to diviide the array in two halves and check if the value to be inserted lies in first /second half.
	
	// Attempt : Reduce the time complexity to log(n)
	// While inserting in a sorted array, the solution suggested was to traverse from the end and once the insert position was known, shift and insert the key. 
	// My solutions though seems like a better approach fails to do so since, in anycase the array will need to be traversed from the end till the insertion position for shifting the elements
	// So finding the insertion position using binary search method will do no good. But add to the complexity!
	static int insertSorted(int arr[], int n, int key, int capacity)
	{
	    int i;
	    int low=0;
	    int high=n-1;
	    int mid;
	    if(n+1>capacity)
	    {
	        System.out.println("Cannot insert, capacity is over");
	    return n;
	    }
	    while(low<high)
	    {
	        mid=(low+high)/2;
	        
	        if(key==arr[mid])
	        {
	            for(i=n-1;i>mid;i--)
	            arr[i+1]=arr[i];
	            arr[mid+1]=key;
	            return n+1;
	            
	        }
	        else if (key>arr[mid])
	        {
	            low=mid+1;
	        }
	        else{
	            high=mid-1;
	        }
	        
	        
	    }
	    if(low>=high)
	    {
	        if(key>arr[low]){
	        for(i=n-1;i>low;i--)
	        arr[i+1]=arr[i];
	        arr[low+1]=key;
	        }
	        else
	        {
	            for(i=n-1;i>=low;i--)
	            arr[i+1]=arr[i];
	            arr[low]=key;
	            
	        }
	    }
		return n+1;
			}

	/* Driver program to test above function */
	public static void main (String[] args)
	{
		int arr[] = new int[20];
		arr[0] = 12;
		arr[1] = 16;
		arr[2] = 20;
		arr[3] = 40;
		arr[4] = 50;
		arr[5] = 70;
		int capacity = arr.length;
		int n = 6;
		int key = 26;

	System.out.print("\nBefore Insertion: ");
	for (int i=0; i<n; i++)
		System.out.print(arr[i] + " ");

	// Inserting key
	n = insertSorted(arr, n, key, capacity);

	System.out.print("\nAfter Insertion: ");
	for (int i=0; i<n; i++)
		System.out.print(arr[i] + " ");
	} 
}
