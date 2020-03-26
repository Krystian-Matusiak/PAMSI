#include <iostream>
#include <time.h>

using namespace std;

///////////////////////////////////   MERGE
template <typename type>
bool merge( type* table, type* tmp_table, int beg, int mid, int end){
  
  int first_tab = beg;
  int second_tab = mid+1;
  int real_position = beg;

  for( int c = beg ; c<=end ; c++)
    tmp_table[c] = table[c];

  while( first_tab <= mid && second_tab <= end ){

    
        if( tmp_table[first_tab] < tmp_table[second_tab] )
          table[ real_position++ ] = tmp_table[ first_tab++];
        else
          table[ real_position++ ] = tmp_table[ second_tab++];

    
  }
  while( first_tab <= mid )
    table[ real_position++ ] = tmp_table[ first_tab++];

  
  return 0;
}

////////////////////////////////// MSort
template <typename type>
void MSort( type* table, type* tmp_table, int beg, int end){
  
  if( beg < end){

    
        int mid = (int) (beg + end)/2 ;
    
        MSort( table , tmp_table , beg , mid);
        MSort( table , tmp_table , mid+1 , end);
        if (  merge( table, tmp_table , beg, mid , end)  )
	  cout<<"Blad\n";
 
  }
}


template void MSort<int>( int*, int*, int , int );
