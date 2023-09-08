//Documentation in header file: sequence3.h
//Name and EMPLID: Jezlea Ortega 0846
//INTEGRITY: “The work in this assignment is my own. Any outside sources have been properly cited.”
//FILE:: sequence3.cxx

//INVARIANTS:
// 1) Numbers in the sequence are kept in a linked list.
// 2) head_ptr represents the head pointer of the list.
// 3) many_nodes stores the total number of items in the sequence
// Running time analysis listed beside each function

#include "sequence3.h"
#include "node1.h"
#include <cassert>
#include <cstdlib>
#include <algorithm>

namespace main_savitch_5
{
    sequence::sequence()  	//Run time analysis: O(1)
    { 	
        many_nodes = 0; 
        head_ptr = NULL; 		
        tail_ptr = NULL; 		
        cursor = NULL; 		
        precursor = NULL; 	  	
    } 	 	
    
    sequence::sequence(const sequence& source) 	//Run time analysis: O(n^3)
    { 	
        node* index = source.head_ptr;
        list_copy(source.head_ptr, head_ptr, tail_ptr);
        precursor = head_ptr;
        many_nodes = source.many_nodes;
        
        if (source.cursor == NULL)
        {
            if (source.precursor == NULL)
            {
                cursor = NULL;
                precursor = NULL;
            }
            else if  (source.precursor != NULL)
            {
                precursor = tail_ptr;
                cursor = NULL;
            }
        }
        else if (source.precursor == NULL)
        {
            precursor = NULL;
            cursor = head_ptr;
        }
        else
        {
            while (index != source.precursor)
            {
                precursor = precursor->link();
                index = index->link();
            } 
            
            cursor = precursor->link();
        }
                
    } 
    
    sequence::~sequence() 	   //Run time analysis: O(1)
    { 		
        list_clear(head_ptr); 
        many_nodes = 0;
        precursor = NULL;
        cursor = head_ptr;	
    } 
    
    void sequence::start() 	 //Run time analysis: O(1)
    { 	
        precursor = NULL;
        cursor = head_ptr;
    }  
    
    void sequence::advance() 	   //Run time analysis: O(n)
    { 		
        assert(is_item());
            precursor = cursor;
            cursor = cursor->link();
    } 	
    
    void sequence::insert(const value_type& entry) 	//Run time analysis: O(n^2)
    { 	
        if (head_ptr == NULL) 		
        { 			
            list_head_insert(head_ptr, entry); 			
            cursor = head_ptr;
            precursor = NULL;
            tail_ptr = head_ptr; 
        }   
        else if (cursor == head_ptr) 		
        { 			
            list_head_insert(head_ptr, entry); 	
            cursor = head_ptr;
            precursor = NULL;
        } 	
        else if (cursor == NULL) 		
        { 			
            list_head_insert(head_ptr, entry); 	
            cursor = head_ptr;
            precursor = NULL;
        }
        else 	
        { 			
            list_insert(precursor, entry); 				
            cursor = precursor->link(); 			
        } 
        many_nodes++;
    }  	
    
    void sequence::attach(const value_type& entry) 	//Run time analysis: O(n^3)
    { 		
       if (size() > 0 && cursor != NULL)
       {
           if (cursor->link()==NULL)
           {
               list_insert(cursor, entry);
               precursor = cursor;
               cursor = cursor->link();
               tail_ptr = cursor;
           }
           else
           {
               list_insert(cursor, entry);
               precursor = cursor;
               cursor = cursor->link();
           }
       }
       else if (many_nodes == 0)
       {
           list_head_insert(head_ptr, entry);
           precursor = NULL;
           cursor = head_ptr;
           tail_ptr = head_ptr;
        }
        else
        {
            list_insert(tail_ptr, entry);
            precursor = tail_ptr;
            tail_ptr = tail_ptr->link();
            cursor = tail_ptr;
        }
            
        many_nodes++;
    }
    
    void sequence::remove_current() 	//Run time analysis: O(n^3)
    { 		
        if (is_item())  		
        {	 			
            if (head_ptr == tail_ptr) 			
            { 				
                list_head_remove(head_ptr); 				
                head_ptr = NULL; 				
                tail_ptr = NULL; 				
                cursor = NULL; 				
                precursor = NULL; 			
                
            }  			
            else if (cursor == head_ptr) 			
            { 				
                list_head_remove(head_ptr); 				
                cursor = head_ptr; 			
                
            }  			
            else if (cursor == tail_ptr) 			
            { 				
                list_remove(precursor); 				
                cursor = NULL; 				
                tail_ptr = precursor; 			
                
            }
            else 			
            { 				
                list_remove(precursor); 				
                cursor = precursor->link(); 
            } 			
            many_nodes--; 		
            
        } 	
        
    }   	
     	
    void sequence::operator =(const sequence& source) 	//Run time analysis: O(n^2)
    { 		
        node* index = source.head_ptr;
        list_copy(source.head_ptr, head_ptr, tail_ptr);
        precursor = head_ptr;
        many_nodes = source.many_nodes;
        
        if (this == &source) 		
        { 			
            return; 		
        }
        
        if (source.cursor == NULL)
        {
            list_copy(source.head_ptr, head_ptr, tail_ptr);
            precursor = NULL;
            cursor = NULL;
        }
        else if (source.precursor == NULL)
        {
            cursor = head_ptr;
            precursor = NULL;
        }
        else 
        {
            while (index != source.precursor)
            {
                index = index->link();
                precursor = precursor->link();
            }
            cursor = precursor->link();
        }
        
    } 	
    
    sequence::size_type sequence::size( ) const  //Run time analyis: O(1)
    {
       return many_nodes;
    }
    
    bool sequence::is_item( ) const         //Run time analysis: O(n^2)
    {
        if (size() > 0 && cursor != NULL)   
        {
            return true;
        }
        else 
        {
            return false;
        }
    }
    
    sequence::value_type sequence::current( ) const   //Run time analysis: O(n)
    {
        assert(is_item());
        return cursor-> data();
    }

   }
    
    