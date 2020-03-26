#include <iostream>
#include <time.h>
#include <chrono>

#include "ISort.h"
#include "MSort.h"

using namespace std;

int value = 15;
/////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////   FUNCTIONS
/////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////

void ShowTable(int * table , int n){  // Function that shows table
  for(int i=0 ; i<n ; i++)
    cout << table[i] <<"  ";
  cout<<endl<<endl;
}

int SelectSize(){   // Function which selects size of tables

  int size; // size of table
  char choice;  // choise of table size

  cout<<"\n\nSelect size of the table: \n\n";
  cout<<"1.  10 000 "<<endl;
  cout<<"2.  50 000 "<<endl;
  cout<<"3.  100 000 "<<endl;
  cout<<"4.  500 000 "<<endl;
  cout<<"5.  1 000 000 "<<endl;

  cin>>choice;
  switch(choice){
    
  case '1':
    size = 10000;
    break;
  case '2':
    size = 50000;
    break;
  case '3':
    size = 100000;
    break;
  case '4':
    size = 500000;
    break;
  case '5':
    size = 1000000;
    break;
  default:
    size = SelectSize();
    break;
  }
  system("clear");
  return size;
}

template <typename type>
void FillTable( type * table , int size){   // Filling tables with random numbers
  
  for(int i=0 ; i<size ; i++)
    table[i] = rand() ;
  
}

template <typename type>
void Assign( type * t1 , type * t2 , int size ){    // Function which assigns tables 
  for( int i=0 ; i<size ; i++)
    t1[i] = t2[i];
}

void menu(){   // Main manu - sorting table options
  cout<<"=====  Select option:  =====\n\n";
  cout<<"1. Sort all elements\n";
  cout<<"2. Sort part of the table\n";
  cout<<"3. Sort all elements in other direction\n\n";
}

template <typename type>  // Sorting in reverse order based on Quick Sort
void SortReverseOrder( type * table , int left , int right){

  int pivot = table[  (left+right) / 2 ];
  int a=left;
  int b=right;
  bool True=true;
  
  while(True){

    while( table[b] < pivot ) b--;
    while( table[a] > pivot ) a++;
    
    if( a < b )
      swap( table[a++] , table[b--] );
    else
      True = false;
  }
   
  if( left < right){
    int mid = b;
    if( mid > left)
      SortReverseOrder( table , left , mid);
    if( mid < right)
      SortReverseOrder( table , mid+1 , right);
  }
  
}

double selectperc(int next){  // it returns the percentage of sorted table
  
  double part;
  //int choice;
  double percent_table[] = { 0 , 0.25 , 0.50 , 0.75 , 0.95 , 0.99 , 0.997 };

  /*
  system("clear");
  cout<<"Select percetage of elements to sort:\n\n";
  cout<<"1. 25%\n";
  cout<<"2. 50%\n";    
  cout<<"3. 75%\n";
  cout<<"4. 95%\n";
  cout<<"5. 99%\n";
  cout<<"6. 99.7%\n";
  
  cin >> choice ;
    
  if( next_perc > 6 || next_perc < 1 ) 
    part = selectperc();
  else

  */
    part = percent_table[ next ];
  
  return part;
}

int options_of_test(){
  int test_check;

  cout << "Do You want to do the sorting test or\n check are the algorithms correct?\nTest - 1\nCheck - 2\n\n";
  cin >> test_check;

  if(test_check == 1)
    return SelectSize();
  else if(test_check == 2)
    return value;
  else
    return options_of_test();
}

/////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////   MAIN
/////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////

int main(){

  srand( time(NULL) );

  int next_perc=0;   // necessary to use all percentage options
  double perc=1;    // Percentage of sorted elements
  int opt;      // Option (sort all, % , reverse order)
  int all_opt=1;  // necessary to use all of the options
  int tsize;   // table size
  tsize = options_of_test(); 
  
  //////////////////////////////////////////////////////////////////////////
  int ** T_before = new int * [ 100 ];    // table to remeber table
  int ** T_qs = new int * [ 100 ];     // table to quick sort
  int ** T_ms = new int * [ 100 ];     // table to merge sort
  int ** T_is = new int * [ 100 ];     // table to introspective sort
  int ** T_tmp = new int * [ 100 ];     // auxiliary table 

  for( int i=0 ; i<100 ; i++){
    T_before [i] = new int [ tsize ]; 
    T_qs [i] = new int [ tsize ];     
    T_ms [i] = new int [ tsize ];    
    T_is [i] = new int [ tsize ];     
    T_tmp [i] = new int [ tsize ];     
  }
  //////////////////////////////////////////////////////////////////////////

  // Filling the tables:
           if(tsize == value){
	     for( int j=0 ; j<100 ; j++)
	       for(int i=0 ; i<value ; i++)
		 T_before[j][i] = rand() % 101 ;
	   }

	   else 
	     for(int i=0 ; i<100 ; i++)
	       FillTable( T_before[i] , tsize);

	   
 Again:   // Necessary to use all percentage options and the same tables

	   
	   for(int i=0 ; i<100 ; i++){
	     Assign( T_qs[i] , T_before[i] , tsize );
	     Assign( T_ms[i] , T_before[i] , tsize );
	     Assign( T_is[i] , T_before[i] , tsize );
	     Assign( T_tmp[i] , T_before[i] , tsize );
	   }

////////////////////////////////////////////////////////////////////////////
	   
 // Start of the program
	   if(tsize != value ){
	     if( next_perc <= 6 )
	       opt = 2;
	     else
	       opt =3;
	   }
	   else{
	     menu();
	     cin >> opt;
	   }
	   
	   if(opt == 1 ){
	     perc = 1;
	     cout << "Sorting all the elements\n\n";
	   }
	   
	   else if(opt == 2){

	     if( tsize != value)
	       perc = selectperc( next_perc );
	     else{
	       cout<<"Select percetage of elements to sort:\n\n";
	       cout<<"1. 25%\n";
	       cout<<"2. 50%\n";    
	       cout<<"3. 75%\n";
	       cout<<"4. 95%\n";
	       cout<<"5. 99%\n";
	       cout<<"6. 99.7%\n";

	       cin >> perc;
	       perc = selectperc(perc);
	     }
				 
	     for ( int i=0 ; i<100 ; i++){
	       ISort( T_qs[i] , 0  , (tsize-1)*perc );
	       ISort( T_ms[i] , 0  , (tsize-1)*perc );
	       ISort( T_is[i] , 0  , (tsize-1)*perc );
	     }
	     cout << "Sorting with " << perc*100 << "% initially sorted elements\n\n";
	     
	   }
	   
	   else if(opt == 3){
	     
	     for ( int i=0 ; i<100 ; i++){
	       SortReverseOrder( T_qs[i] , 0  , tsize-1 );
	       SortReverseOrder( T_ms[i] , 0  , tsize-1 );
	       SortReverseOrder( T_is[i] , 0  , tsize-1 );
	     }
	     cout << "Sorting tables sorted in reversed order\n";
	     all_opt = 2;  // Thanks to this we can end up all the loops
		    
	   }

	   if(tsize == value){
	     cout << "Initial table setting:\n";
	     ShowTable( T_qs[1] , tsize);
	   }
	   
  //  Testing Quick Sort
           auto q1 = chrono::high_resolution_clock::now() ;

           for ( int i=0 ; i<100 ; i++)
             QSort( T_qs[i] , 0 , tsize-1 );
  
           auto q2 = chrono::high_resolution_clock::now() ;
           auto timeq = chrono::duration_cast<std::chrono::microseconds>( q2-q1 ).count();

  //  Testing Merge Sort
           auto m1 = chrono::high_resolution_clock::now() ;
  
           for ( int i=0 ; i<100 ; i++)
             MSort( T_ms[i] , T_tmp[i] , 0 , tsize-1 );
  
           auto m2 = chrono::high_resolution_clock::now() ;
           auto timem = chrono::duration_cast<std::chrono::microseconds>( m2-m1 ).count();

 //  Testing Introspective Sort
           auto i1 = chrono::high_resolution_clock::now() ;
	   
           for ( int i=0 ; i<100 ; i++)
             ISort( T_is[i] , 0  , tsize-1 );
  
           auto i2 = chrono::high_resolution_clock::now() ;
           auto timei = chrono::duration_cast<std::chrono::microseconds>( i2-i1 ).count();


 //  Showing up the tables:
	   if(tsize == value){
	     cout<<"\nAfter Quick Sort:\n";  
	     ShowTable( T_qs[1] , tsize );
  
	     cout<<"After Merge Sort:\n";
	     ShowTable( T_ms[1] , tsize );

	     cout<<"After Intro Sort:\n";
	     ShowTable( T_is[1] , tsize );
	   }

  // Duration time:
	   cout << "\n========================================\n";
	   cout << next_perc+1 << " test " ;
	   if(opt == 2)
	     cout << "for " << perc*100 << "% of table\n";
	   else if(opt ==3 )
	     cout << "for the tables sorted in reversed order:\n";
	   
	   cout<<"Time of Quick Sort: "<<timeq/1000<<"ms\n";
	   cout<<"Time of Merge Sort: "<<timem/1000<<"ms\n";
	   cout<<"Time of Introspective Sort: "<<timei/1000<<"ms\n\n\n";


	   if( tsize != value){
	     next_perc++;

	     if( next_perc <= 6 )    // Necessary to use the same tables for each %
	       goto Again;
	     
	     opt=3;
	     
	     if( all_opt == 1)
	       goto Again;
	     
	   }
	   
	   
//////////////////////////////////////////////////////
  for(int a=0 ; a<100 ; a++){
    delete [] T_before[a];
    delete [] T_qs[a];
    delete [] T_ms[a];
    delete [] T_is[a];
    delete [] T_tmp[a];
  }

  delete [] T_before;
  delete [] T_qs;
  delete [] T_ms;
  delete [] T_is;
  delete [] T_tmp;
//////////////////////////////////////////////////////

  return 0;
} 
