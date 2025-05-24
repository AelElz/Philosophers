#include "philo.h"

void	*ft_thread1(void *arg1)
{
	int i = *(int *)arg1;
	printf("this is from thread %d\n", i);
	return NULL;
}

int main()
{
	pthread_t thread[3];
	int ids[3] = {1, 2, 3};
	int i;

	i = 0;
	while (i < 3)
	{
		pthread_create(&thread[i], NULL, ft_thread1, &ids[i]);
		i++;
	}
	i = 0;
	while (i < 3)
	{
		pthread_join(thread[i], NULL);
		i++;
	}
	printf("all threads are finished\n");
}
