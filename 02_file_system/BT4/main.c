#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int main() {
    
    int fd = open("test.txt", O_WRONLY | O_APPEND, 0644);
    if (fd == -1) {
        printf("Can not open file \n");
    }

// Write some data to the end of the file
    char data1[15] = "Tuan deptrai 1\n";
    lseek(fd,0,SEEK_SET);
    if (write(fd, data1, strlen(data1)) == -1) {
        printf("Can not write 1\n");
    }
    
// Close the file
    close(fd);

    return 0;
}

/* 
- Cờ APPEND chỉ định dữ liệu luôn được ghi vào cuối tệp ( bất chấp lseek())
+ Trong VD trên, ta tạo trước file test.txt với dữ liệu mặc định là TEST APPEND
- Nếu không dùng O_APPEND thì khi lseek() lên đầu file , dữ liệu mới sẽ ghi đè lên dữ liệu cũ -> File txt sau cùng chỉ có dữ liệu mới
- Nếu dùng O_APPEND thì dù cho có lseek() thì dữ liệu mới vẫn mặc định ghi ở cuối file -> File txt sau cùng có đầy đủ cả dữ liệu mới và cũ
<<<<<<< HEAD
*/
=======

*/
>>>>>>> 856decfdcb4124c43aedd2576b67120739efbbf7
