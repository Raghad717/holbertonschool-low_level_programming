Hash Tables in C
This project implements a hash table data structure in C, complete with various operations for creating, manipulating, and managing hash tables. The implementation includes collision handling, memory management, and utility functions.

Overview
A hash table (also known as a hash map) is a data structure that implements an associative array abstract data type, a structure that can map keys to values. This implementation uses separate chaining to handle collisions.

Functions
1. hash_table_t *hash_table_create(unsigned long int size)
Creates a new hash table with the specified size.

Parameters:

size: The size of the hash table array

Returns:

Pointer to the newly created hash table

NULL if memory allocation fails

2. unsigned long int hash_djb2(const unsigned char *str)
Implements the djb2 hash algorithm.

Parameters:

str: The string to hash

Returns:

The computed hash value

3. unsigned long int key_index(const unsigned char *key, unsigned long int size)
Computes the index for a key in the hash table.

Parameters:

key: The key to compute index for

size: The size of the hash table array

Returns:

The index where the key should be stored

4. int hash_table_set(hash_table_t *ht, const char *key, const char *value)
Adds or updates a key-value pair in the hash table.

Parameters:

ht: The hash table

key: The key (cannot be empty)

value: The value (can be empty, will be duplicated)

Returns:

1 on success

0 on failure

Features:

Handles collisions by adding new nodes at the beginning of the list

Updates existing keys by replacing their values

Duplicates key and value strings

5. char *hash_table_get(const hash_table_t *ht, const char *key)
Retrieves a value associated with a key.

Parameters:

ht: The hash table

key: The key to search for

Returns:

The value associated with the key

NULL if key is not found

6. void hash_table_print(const hash_table_t *ht)
Prints the contents of the hash table.

Parameters:

ht: The hash table to print

Output Format:

{'key1': 'value1', 'key2': 'value2', ...}

{} for empty hash table

No output if ht is NULL

7. void hash_table_delete(hash_table_t *ht)
Deletes a hash table and frees all allocated memory.

Parameters:

ht: The hash table to delete

Memory Management
The hash table implementation:

Duplicates all key and value strings to maintain ownership

Frees all allocated memory when deleting the hash table

Handles memory allocation failures gracefully

Uses malloc and free for dynamic memory management

Requirements
C compiler (gcc recommended)

Standard C libraries

Valgrind for memory leak checking (optional but recommended)

Author
Raghad Alamlki 

License
This project is part of the Holberton School curriculum.


