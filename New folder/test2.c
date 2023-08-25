int main()
{
int id;
pid_t pid;
pid_t ppid;
id = fork();
pid = getpid();
ppid = getppid();
printf("child :%d\n",pid);
printf("Parent :%d\n",ppid);
}