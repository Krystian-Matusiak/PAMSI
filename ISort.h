#include <iostream>
#include <time.h>
#include <bits/stdc++.h>
#include <cmath>
#include "QSort.h"

using namespace std;

//  Introspective Sort  //


template <typename type>
void insert( type* table , int left, int right){

  right++;

  int i=left;

  while(i<right){
    
    int k=i;
    while( k > 0 && table[k - 1] > table[k] ){
      
      swap( table[k] , table[k-1] );
      k--;
    }
    i++;
  }
}


template <typename type>   //  Auxiliary function to heap
void H( type * table, int size_of_heap , int index){

  int left = (index)*2 + 1;
  int right = (index)*2 + 2 ;
  int largest = index;

  if (left < size_of_heap && table[left] > table[largest] )
    largest = left;
  
  if( right < size_of_heap && table[right] > table[largest] )
    largest = right;
  
  if( largest != index){
    swap( table[index] , table[largest] );
    H(table , size_of_heap , largest);
  }
}


template <typename type>  // Heap Sort
void HSort( type* table , int left , int right){

  right ++ ;
  int size_of_heap = right - left;
  
  type * tmp = new type[right-left];
  for( int i=0 ; i < size_of_heap ; i++)
    tmp[i] = table[i+left];
  
  for( int i = (size_of_heap)/2 ; i>=0 ; i--)
    H( tmp , size_of_heap , i );
  
  for( int i = right-left-1 ; i>=0 ; i--){

    swap( tmp[0] , tmp[i] );
    H( tmp , i , 0);
    
  }
  for(int i=0 ; i < size_of_heap ; i++)
    table[i+left] = tmp[i];
    
  delete [] tmp;
}



////////////////////////////////// QSort
template <typename type>
void IntroHybrid( type* table, int left, int right , int maxdepth){

  int size = right - left + 1;
  
  if( size <= 16 )
    insert( table, left , right);

  else if( maxdepth == 0 )
    HSort(table ,left , right);
  
  else if(left < right){
    int value = Div( table , left, right);
    IntroHybrid( table , left , value , --maxdepth) ;
    IntroHybrid( table , value+1 , right , --maxdepth) ;
  }
  
}

template <typename type>
void ISort( type* table, int left, int right){
  
  int maxdepth = (int) log(right-left+1)*2;
  IntroHybrid( table , left , right , maxdepth);
  
}


template void ISort<int>( int*, int , int);
