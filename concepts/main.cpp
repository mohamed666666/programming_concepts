#include <iostream>

using namespace std;
int F(int n)
{
    if(n<=1) return 1;
    int a=n+F(n-1);
    int b=n*F(n/2);
    int c=n-2-(a+b)%2;
    int d=F(c);
 //   cout<< a <<" "<< b<<" "<<c<<endl;
    return a+b+d;
}
int a(int i , int arr[]){

      return i+arr[i-1];


}


int b(int i ,int arr[]){
    return i*arr[i/2];
}



int c( int i , int arr[]){
    return i-2-((b(i,arr)+a(i,arr))%2);
}


int fun(int n){

    int *arr = new int(n+1);
    for (int i =0;i<n+1;i++){

        arr[i]=i;
    }


     arr[0]=1;
     arr[1]=1;
     arr[2]=6;// becaus c local  variable =-1 and arr[-1] gives 0

    for (int i=3;i<n+1;i++){
        arr[i]=a(i,arr)+b(i,arr)+arr[c(i ,arr)];
        //cout<<" C= "<<(i-2-(((i*arr[i/2])+(i+arr[i-1]))%2))<<endl;


    }
    int res=arr[n];
    delete arr;
    return res;
}

/*

int fun2(int n){
    int result=0;
    int a=0;
    int b=0;
    int c=0;
    int d=0;



    int counter =0;


    while (counter < n){
        a=counter+(result);
        b=counter*(result2);





        result=a+b+d;



    conuter ++;
    }



}

*/

int main()
{


    for(int i=0;i<20;i++){
    cout << " recursion "<< F(i)<< endl;



}

        for (int i =0 ;i<20;i++){

        cout<< "nonrecursive "<<fun(i)<<endl;
        }






    return 0;
}
