

SYSCALL_DEFINE4(SYS_kernel_2d_memcpy, float *, kak, float *, kaka, int, row, int, col)
{   float tempr[row][col];
    int first = __copy_from_user(tempr, kaka, sizeof(tempr));
    if (first){return -1;}
    int second = __copy_to_user(kak, tempr, sizeof(tempr));
    if (second){return -1;}
    return 0;
}