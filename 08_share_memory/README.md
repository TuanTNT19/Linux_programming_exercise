Created by TuanTNT19

*BT16 : Compare betwen two mapping method in POSIX share memory ( Private file mapping and Shared file mapping)

-> Explain :

- In Private File mapping, the flag is MAP_PRIAVTE in writer and MAP_SHARED in reader: when i modify in writer, the compiler would copy share mem to another memory and modify in there ( this memory only visible for writer ), the reader can not see what i just do and can not read data i just change (copy on write).

- In Shared File mapping, the flag is MAP_SHARED in writer and MAP_SHARED in reader: when i modify in writer, the compiler would modify directly in share memory, the reader can see what i just do and can read data i just change.