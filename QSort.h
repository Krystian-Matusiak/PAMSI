#include <iostream>
#include <time.h>

using namespace std;

//  Quick Sort  //


template <typename type>   //  Equal to swap but slower - not used
void Change( type* table, int one, int two){
  int tmp = table[one];
  table[one] = table[two];
  table[two] = tmp;
}

template <typename type>
int Div( type* table , int left, int right){   


  
  //  Check why is Lomuto slower that Hoar
  
  /*     ALGORYTM LOMUTO
  int id = (int) (left+right)/2;
  Change(table, id , right);

  //int id = right;
  int curr=left;         // current index
  
  for( int i=left; i<right ; i++){
    if( table[i] < table[ right ] ){
      
      //swap( table[curr] , table[i] );
      Change( table , curr , i );
      curr++;
      
    }
  }
  
  //swap( table[curr] , table[ right ] );
  Change( table , curr , right );
  return curr;

  */


  

  //    ALGORYTM HOARE
  int pivot = table[  (left+right) / 2 ];
  int a=left;
  int b=right;

  while(true){

    while( table[b] > pivot ) b--;
    while( table[a] < pivot ) a++;
  
    if( a < b )
      swap( table[a++] , table[b--] );
    else
      return b;
      } 
  
}
////////////////////////////////// QSort
template <typename type>
void QSort( type* table, int left, int right){
  
  if( left < right){
    int mid = Div(table , left, right);
    if( mid > left)
      QSort( table , left , mid);
    if( mid < right)
      QSort( table , mid+1 , right);
  }
}


template void QSort<int>( int*, int , int );


