#include <unistd.h>
#include <fcntl.h>

/* lseek1.c */
char buf1[] = "abcdefghij";
char buf2[] = "ABCDEFGHIJ";
int main() {
int fd;
if ( (fd = creat("file"/*.hole*/, 0644)) < 0)
{ perror("file.hole"); exit(-1); }
if (write(fd, buf1, 10) != 10) /* offset now = 10 */
perror("buf1");
if (lseek(fd, 40, SEEK_SET) == -1) /* offset now = 40 */
perror("lseek");
if (write(fd, buf2, 10) != 10) /* offset now = 50 */
perror("buf2");
}
