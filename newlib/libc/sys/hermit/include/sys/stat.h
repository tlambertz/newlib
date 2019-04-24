#ifndef _SYS_STAT_H_
#define _SYS_STAT_H_

#include <sys/time.h>

struct stat {
    dev_t   st_dev;  /* inode's device */
    ino_t   st_ino;  /* inode's number */
    mode_t   st_mode;  /* inode protection mode */
    nlink_t   st_nlink;  /* number of hard links */
    uid_t   st_uid;  /* user ID of the file's owner */
    gid_t   st_gid;  /* group ID of the file's group */
    dev_t   st_rdev;  /* device type */
    off_t   st_size;  /* file size, in bytes */
    time_t   st_atime;  /* time of last access */
    time_t   st_mtime;  /* time of last data modification */
    time_t   st_ctime;  /* time of last file status change */
    int64_t   st_blocks;  /* blocks allocated for file */
    u_int32_t st_blksize;  /* optimal blocksize for I/O */
};


#define S_ISUID 0004000   /* set user id on execution */
#define S_ISGID 0002000   /* set group id on execution */

#define S_IRWXU 0000700   /* RWX mask for owner */
#define S_IRUSR 0000400   /* R for owner */
#define S_IWUSR 0000200   /* W for owner */
#define S_IXUSR 0000100   /* X for owner */

#define S_IRWXG 0000070   /* RWX mask for group */
#define S_IRGRP 0000040   /* R for group */
#define S_IWGRP 0000020   /* W for group */
#define S_IXGRP 0000010   /* X for group */

#define S_IRWXO 0000007   /* RWX mask for other */
#define S_IROTH 0000004   /* R for other */
#define S_IWOTH 0000002   /* W for other */
#define S_IXOTH 0000001   /* X for other */

#define S_IFMT   0170000  /* type of file mask */
#define S_IFIFO  0010000  /* named pipe (fifo) */
#define S_IFCHR  0020000  /* character special */
#define S_IFDIR  0040000  /* directory */
#define S_IFBLK  0060000  /* block special */
#define S_IFREG  0100000  /* regular */
#define S_IFLNK  0120000  /* symbolic link */
#define S_IFSOCK 0140000  /* socket */
#define S_IFWHT  0160000  /* whiteout */
#define S_ISVTX  0001000  /* save swapped text even after use */

#define S_ISDIR(m) ((m & 0170000) == 0040000) /* directory */
#define S_ISCHR(m) ((m & 0170000) == 0020000) /* char special */
#define S_ISBLK(m) ((m & 0170000) == 0060000) /* block special */
#define S_ISREG(m) ((m & 0170000) == 0100000) /* regular file */
#define S_ISFIFO(m) ((m & 0170000) == 0010000 || \
        (m & 0170000) == 0140000) /* fifo or socket */
#define S_ISLNK(m) ((m & 0170000) == 0120000) /* symbolic link */
// #define S_ISSOCK(m) ((m & 0170000) == 0010000 || \
// (m & 0170000) == 0140000) [> fifo or socket <]
// #define S_ISWHT(m) ((m & 0170000) == 0160000) [> whiteout <]
#define S_TYPEISMQ(m)  (0)
#define S_TYPEISSEM(m) (0)
#define S_TYPEISSHM(m) (0)


int chmod (const char *path , mode_t mode) ;
int fchmod (int filedes, mode_t mode);
int fstat (int filedes, struct stat *buf) ;
int lstat (const char *path, struct stat *buf);
int mkdir (const char *path, mode_t mode);
int mkfifo (const char *path, mode_t mode);
// mknod might go here
int stat (const char *path, struct stat *buf);
mode_t umask (mode_t mode);

#endif //_SYS_STAT_H_
