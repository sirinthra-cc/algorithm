//Write a recursive function that computes the sum of all numbers from 1 to n, where n is given as parameter. 
//return the sum 1+ 2+ 3+ ...+ n
int sum(int n){
    if(n == 1) return 1;
    return n + sum(n-1);
}

//Write a recursive function that finds and returns the minimum element in an array, where the array and its size are given as parameters. 
//return the minimum element in a[]
int findmin(int a[], int n){
    if(n == 1) return a[0];
    return min(a[n-1], findmin(a, n-1));
}

//Write a recursive function that computes and returns the sum of all elements in an array, where the array and its size are given as parameters. 
//return the sum of all elements in a[]
int findsum(int a[], int n){
    if(n == 1) return a[0];
    return a[n-1] + findsum(a, n-1);
}

//Write a recursive function that determines whether an array is a palindrome, where the array and its size are given as parameters. 
//returns 1 if a[] is a palindrome, 0 otherwise
int ispalindrome(char a[], int n){
    if(n <= 1) return 1;
    int ispalindrome;
    if(a[0] == a[n-1]){
        char new_a[n-2];
        for(int i=0; i<n-2; i++) new_a[i] = a[i+1];
        return ispalindrome(new_a, n-2)
    } else {
        return 0;
    }
}
